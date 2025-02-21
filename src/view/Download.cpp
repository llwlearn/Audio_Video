#include "Download.h"
#include "ui_Download.h"

#include <QProcess>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QMessageBox>
#include <QHBoxLayout>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>
#include <QListWidget>

#include "src/tool/FfmpegWorker.h"
#include "src/tool/Player.h"

Download::Download(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Download)
    , musicMetaDataList()
{
    ui->setupUi(this);

    // 尝试从 JSON 文件中加载数据
    QString filePath = "E://音乐/music_meta_data.json";
    musicMetaDataList = loadMetaDataFromFile(filePath);

    // 如果加载失败或数据为空，则从目录中加载数据
    if (musicMetaDataList.isEmpty()) {
        loadMusicFiles("E://音乐");
    } else {
        populateList(musicMetaDataList);
    }

    // 连接刷新按钮的点击信号
    connect(ui->Refresh, &QPushButton::clicked, this, &Download::onRefreshClicked);

    // 创建一个数据库对象，避免每次查询时都连接
    db = new Database();
    bool connected = db->connect("localhost", "Audio_Video", "root", "123456");
    if (!connected) {
        qDebug() << "错误：无法连接到数据库!";
        return;
    }

}

Download::~Download()
{
    delete ui;
}

void Download::onIdButtonClicked(const QMediaMetaData &meta)
{
    // 提取歌曲信息
    QString songName = meta.value(QMediaMetaData::Title).toString();
    QString artist = meta.value(QMediaMetaData::Author).toString();
    QString album = meta.value(QMediaMetaData::AlbumTitle).toString();
    bool isVip = false; // 假设所有歌曲都不是VIP，根据实际情况调整
    QString duration = meta.value(QMediaMetaData::Duration).toString();

    // 检查是否已存在相同的歌名和歌手名字
    QString condition = QString("song_name = '%1' AND artist = '%2'").arg(songName).arg(artist);
    QSqlQuery query = db->select("playlist", {"song_name", "artist"}, condition);
    if (query.next()) {
        qDebug() << "歌曲已存在: " << songName << " - " << artist;
        return;
    }

    // 获取当前最大的 id 值
    QSqlQuery maxIdQuery = db->select("playlist", {"MAX(id)"}, "");
    int newId = 1; // 默认为1，如果没有记录
    if (maxIdQuery.next()) {
        int maxId = maxIdQuery.value(0).toInt();
        newId = maxId + 1; // 新的 id 值
    }

    // 插入新记录
    QStringList fields = {
        "id",
        "song_name",
        "artist",
        "album",
        "is_vip",
        "duration"
    };

    QVariantList values = {
        newId,
        songName,
        artist,
        album,
        isVip,
        duration
    };

    bool success = db->insert("playlist", fields, values);

    if (success) {
        qDebug() << "插入成功，新的 id 是: " << newId;
    } else {
        qDebug() << "插入失败";
    }

    Player *player = new Player();
    Player::Song newSong(newId, songName, artist, isVip, duration);
    player->addSongToPlaylist(newSong); //把新歌曲添加到播放列表
    // delete player;
}

void Download::onRefreshClicked()
{
    // 清空当前的音乐元数据列表
    musicMetaDataList.clear();

    // 从指定目录加载音乐文件
    loadMusicFiles("E://音乐");
}

void Download::saveMetaDataToFile(const QList<QMediaMetaData>& metaDataList, const QString& directoryPath)
{
    // 生成 JSON 文件的路径
    QString filePath = directoryPath + "/music_meta_data.json";

    QJsonArray jsonArray;

    for (const QMediaMetaData& metaData : metaDataList) {
        QJsonObject jsonObject;
        jsonObject["title"] = metaData.value(QMediaMetaData::Title).toString();
        jsonObject["artist"] = metaData.value(QMediaMetaData::Author).toString();
        jsonObject["album"] = metaData.value(QMediaMetaData::AlbumTitle).toString();
        // 获取 duration 值
        qint64 duration = metaData.value(QMediaMetaData::Duration).toLongLong();

        // 将 duration 转换为字符串，并截取前三位字符
        QString durationStr = QString::number(duration);
        if (durationStr.length() >= 3) {
            durationStr = durationStr.left(3);
        }

        // 将截取后的 duration 字符串添加到 jsonObject 中
        jsonObject["duration"] = durationStr;
        jsonArray.append(jsonObject);
    }

    QJsonDocument jsonDoc(jsonArray);
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << jsonDoc.toJson();
        file.close();
    } else {
        qWarning() << "Failed to open file for writing:" << filePath;
    }
}

QList<QMediaMetaData> Download::loadMetaDataFromFile(const QString& filePath)
{
    QList<QMediaMetaData> metaDataList;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument jsonDoc(QJsonDocument::fromJson(data));
        QJsonArray jsonArray = jsonDoc.array();

        for (const QJsonValue& value : jsonArray) {
            QJsonObject obj = value.toObject();
            QMediaMetaData metaData;
            metaData.insert(QMediaMetaData::Title, obj["title"].toString());
            metaData.insert(QMediaMetaData::Author, obj["artist"].toString());
            metaData.insert(QMediaMetaData::AlbumTitle, obj["album"].toString());
            metaData.insert(QMediaMetaData::Duration, obj["duration"].toVariant().toLongLong());
            metaDataList.append(metaData);
        }

        file.close();
    } else {
        qWarning() << "Failed to open file for reading:" << filePath;
    }

    return metaDataList;
}


void Download::onMetaDataReady(const QMediaMetaData &meta)
{
    musicMetaDataList.append(meta);
    saveMetaDataToFile(musicMetaDataList, "E://音乐");
    populateList(musicMetaDataList);
}

void Download::loadMusicFiles(const QString &directoryPath)
{
    QDir dir(directoryPath);
    if (!dir.exists()) {
        QMessageBox::critical(this, "Error", "Directory does not exist.");
        return;
    }

    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    dir.setNameFilters(QStringList() << "*.mp3");

    QFileInfoList fileList = dir.entryInfoList();

    FfmpegWorker *worker = new FfmpegWorker(fileList);
    QThread *thread = new QThread(this);
    worker->moveToThread(thread);

    connect(worker, &FfmpegWorker::metaDataReady, this, &Download::onMetaDataReady);
    connect(worker, &FfmpegWorker::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, worker, &QObject::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    connect(thread, &QThread::started, worker, &FfmpegWorker::processFiles);
    thread->start();
}

void Download::populateList(const QList<QMediaMetaData> &metaDataList)
{
    ui->listWidget->clear();  // 清空现有内容

    // 定义一个变量来追踪 id 的自增值，从 1 开始
    int idCounter = 1;

    // 遍历歌曲列表，将每首歌的信息添加到列表中
    for (const QMediaMetaData &meta : metaDataList) {

        // 创建自定义控件作为列表项
        QWidget *widget = new QWidget();
        widget->setStyleSheet("background-color: transparent;");

        // 创建布局
        QHBoxLayout *layout = new QHBoxLayout(widget);

        // 创建 id 按钮并设置为自增的格式化值
        QPushButton *idButton = new QPushButton(this);
        idButton->setText(QString::number(idCounter, 10).rightJustified(2, '0'));  // 将 id 格式化为 2 位数
        idButton->setStyleSheet("font-size: 16px; padding: 5px; border: none;");  // 设置无边框样式
        idButton->setFixedWidth(50);  // 设置 ID 按钮的固定宽度
        idButton->setFixedHeight(70);  // 设置 ID 按钮的固定高度
        idButton->setCursor(Qt::PointingHandCursor);  // 设置鼠标悬停时为手形光标

        // 在 populateList 函数中为每个 ID 按钮连接槽函数
        connect(idButton, &QPushButton::clicked, this, [this, meta]() {
            onIdButtonClicked(meta);
        });

        // 创建垂直布局用于歌名和歌手名字
        QVBoxLayout *infoLayout = new QVBoxLayout();

        // 创建标签显示歌曲信息
        QLabel *songLabel = new QLabel(this);
        songLabel->setText(meta.value(QMediaMetaData::Title).toString());
        songLabel->setStyleSheet("font-size: 23px;");
        songLabel->setMaximumHeight(40);  // 设置歌名标签的最大高度
        songLabel->setMaximumWidth(400);  // 设置歌名标签的最大宽度

        // 创建标签显示歌手信息
        QLabel *artist = new QLabel(this);
        artist->setText(meta.value(QMediaMetaData::Author).toString());
        artist->setStyleSheet("font-size: 20px;");
        artist->setMaximumHeight(20);     // 设置歌手标签的最大高度
        artist->setMaximumWidth(400);     // 设置歌手标签的最大宽度

        // 将歌名和歌手名字添加到垂直布局
        infoLayout->addWidget(songLabel);
        infoLayout->addWidget(artist);

        // 创建标签显示专辑信息
        QLabel *albumLabel = new QLabel(this);
        albumLabel->setText(meta.value(QMediaMetaData::AlbumTitle).toString());
        albumLabel->setStyleSheet("font-size: 18px;");
        albumLabel->setMaximumHeight(30);     // 设置专辑标签的最小高度

        // 创建时长标签
        QLabel *durationLabel = new QLabel(this);

        // 获取 song.duration（假设它是字符串类型）
        QString duration = meta.value(QMediaMetaData::Duration).toString();

        // qDebug() << "Original duration:" << duration;  // 输出原始时长，检查它的格式

        // 将字符串转换为整数（秒）
        int totalSeconds = duration.toInt();

        // 计算分钟和秒
        int minutes = totalSeconds / 60;
        int seconds = totalSeconds % 60;

        // 格式化成 "mm:ss" 格式，确保分钟和秒数是两位数
        QString formattedDuration = QString("%1:%2")
                                        .arg(minutes, 2, 10, QChar('0'))
                                        .arg(seconds, 2, 10, QChar('0'));

        durationLabel->setText(formattedDuration);  // 设置显示

        durationLabel->setFixedWidth(93);
        durationLabel->setStyleSheet("font-size: 14px; padding: 5px;");
        durationLabel->setAlignment(Qt::AlignRight);  // 设置文本内容右对齐

        // 将控件添加到布局
        layout->addWidget(idButton);
        layout->addLayout(infoLayout);
        layout->addWidget(albumLabel);
        layout->addWidget(durationLabel);

        // 设置布局
        widget->setLayout(layout);  // 将布局设置到widget上

        // 创建列表项并将自定义控件添加到该项中
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        item->setSizeHint(widget->sizeHint());  // 设置列表项的大小
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, widget);  // 将控件关联到列表项

        // 为列表项添加事件过滤器
        widget->installEventFilter(this);

        // 保存 idButton 和 idCounter 的关系
        widget->setProperty("idButton", QVariant::fromValue(idButton));
        widget->setProperty("idText", idButton->text());

        // 自增 idCounter
        idCounter++;
    }
}

bool Download::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::Enter) {
        QWidget *widget = qobject_cast<QWidget*>(watched);
        if (widget) {
            QPushButton *idButton = widget->property("idButton").value<QPushButton*>();
            if (idButton) {
                idButton->setText("");
                idButton->setStyleSheet("background-image: url(:/new/prefix1/SinglePlayback.png); "
                                        "background-repeat: no-repeat; "
                                        "background-position: center;");
            }
        }
    } else if (event->type() == QEvent::Leave) {
        QWidget *widget = qobject_cast<QWidget*>(watched);
        if (widget) {
            QPushButton *idButton = widget->property("idButton").value<QPushButton*>();
            if (idButton) {
                idButton->setText(widget->property("idText").toString());
                idButton->setStyleSheet("font-size: 16px; color: black; padding: 5px; border: none;");
            }
        }
    }

    return QObject::eventFilter(watched, event);
}

