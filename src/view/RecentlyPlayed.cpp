#include "RecentlyPlayed.h"
#include "ui_RecentlyPlayed.h"

#include "src/tool/Database.h"

#include <QStandardItem>
#include <QIcon>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDebug>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QUrl>
#include <QTimer>

RecentlyPlayed::RecentlyPlayed(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecentlyPlayed)
{
    ui->setupUi(this);

    QSqlDatabase db = Database::getGlobalConnection();

    this->query();
}

RecentlyPlayed::~RecentlyPlayed()
{
    delete ui;
}

void RecentlyPlayed::query(){
    // 构建查询字段和查询条件：查询播放列表
    QStringList fields;  // 留空表示查询所有字段
    QString condition;   // 留空表示没有条件


    // 执行查询
    QSqlQuery query = database.select("recentlyPlayed", fields, condition);  // 查询 PlayList 表

    // 处理查询结果
    QList<Song> songList;
    if (query.next()) {
        do {
            int id = query.value("id").toInt();
            QString songName = query.value("song_name").toString();
            QString artist = query.value("artist").toString();
            QString album = query.value("album").toString(); // 新增字段
            bool isVip = query.value("is_vip").toBool();
            QString duration = query.value("duration").toString();

            // 将每首歌曲添加到 songList
            songList.append(Song(id, songName, artist, album, isVip, duration));
        } while (query.next());

        // 将查询结果传递到 populateList 函数
        populateList(songList);
    } else {
        qDebug() << "查询失败，未找到匹配的歌曲：" << query.lastError();
    }
}

void RecentlyPlayed::populateList(const QList<Song>& songs)
{
    ui->listWidget->clear();  // 清空现有内容

    // 定义一个变量来追踪 id 的自增值，从 1 开始
    int idCounter = 1;

    // 遍历歌曲列表，将每首歌的信息添加到列表中
    for (const Song& song : songs) {

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

        // 创建垂直布局用于歌名和歌手名字
        QVBoxLayout *infoLayout = new QVBoxLayout();

        // 创建标签显示歌曲信息
        QLabel *songLabel = new QLabel(this);
        songLabel->setText(song.songName);
        songLabel->setStyleSheet("font-size: 23px;");
        songLabel->setMaximumHeight(40);  // 设置歌名标签的最大高度
        songLabel->setMaximumWidth(400);  // 设置歌名标签的最大宽度

        // 创建标签显示歌手信息
        QLabel *artist = new QLabel(this);
        artist->setText(song.artist);
        artist->setStyleSheet("font-size: 20px;");
        artist->setMaximumHeight(20);     // 设置歌手标签的最大高度
        artist->setMaximumWidth(400);     // 设置歌手标签的最大宽度

        // 将歌名和歌手名字添加到垂直布局
        infoLayout->addWidget(songLabel);
        infoLayout->addWidget(artist);

        // 创建标签显示专辑信息
        QLabel *albumLabel = new QLabel(this);
        albumLabel->setText(song.album);
        albumLabel->setStyleSheet("font-size: 18px;");
        albumLabel->setMaximumHeight(30);     // 设置专辑标签的最小高度

        // 创建VIP标签并显示
        QLabel *vipLabel = new QLabel(this);
        vipLabel->setText(song.isVip ? "VIP" : "");
        vipLabel->setStyleSheet(song.isVip ? "font-size: 14px; color: red; padding: 5px;" : "font-size: 14px; color: green; padding: 5px;");
        vipLabel->setFixedWidth(50);

        // 创建喜欢按钮并连接槽函数
        QPushButton *likeButton = new QPushButton(this);
        likeButton->setFixedSize(40, 40);
        likeButton->setStyleSheet("background-color: transparent; "
                                  "color: white; "
                                  "font-size: 14px; "
                                  "padding: 0px; "
                                  "background-image: url(:/new/prefix1/like.png); "
                                  "background-position: center; "
                                  "background-repeat: no-repeat; ");
        likeButton->setCursor(Qt::PointingHandCursor);  // 设置鼠标悬停时为手形光标

        // 连接按钮点击事件
        connect(likeButton, &QPushButton::clicked, this, [song]() {
            // 在这里实现查看歌曲详情的逻辑
            qDebug() << "Song Details: " << song.songName << " by " << song.artist;
        });

        // 创建下载按钮并连接槽函数
        QPushButton *downloadButton = new QPushButton(this);
        downloadButton->setFixedSize(40, 40);
        downloadButton->setStyleSheet("background-color: transparent; "
                                      "color: white; "
                                      "font-size: 14px; "
                                      "padding: 0px; "
                                      "background-image: url(:/new/prefix1/download.png); "
                                      "background-position: center; "
                                      "background-repeat: no-repeat; ");
        downloadButton->setCursor(Qt::PointingHandCursor);  // 设置鼠标悬停时为手形光标

        // 假设 song.downloadUrl 是歌曲的下载链接
        connect(downloadButton, &QPushButton::clicked, this, [this, song]() {
            // QString coverUrl = song.coverUrl;  // 本地文件路径
            // downloadSong(coverUrl);
        });

        // 创建时长标签
        QLabel *durationLabel = new QLabel(this);

        // 获取 song.duration（假设它是字符串类型）
        QString duration = song.duration;

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
        // 将垂直布局和时长标签添加到主布局
        layout->addLayout(infoLayout);
        layout->addWidget(albumLabel);
        layout->addWidget(vipLabel);
        layout->addWidget(likeButton);
        layout->addWidget(downloadButton);  // 添加下载按钮
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

bool RecentlyPlayed::eventFilter(QObject *watched, QEvent *event)
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

void RecentlyPlayed::downloadSong(const QString &songUrl)
{
    // 创建一个QNetworkAccessManager对象来处理网络请求
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // 发起GET请求
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(songUrl)));

    // 连接信号以处理下载完成事件
    connect(reply, &QNetworkReply::finished, this, [this, reply, songUrl]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 获取下载的数据
            QByteArray data = reply->readAll();

            // 从URL中提取文件名
            QUrl url(songUrl);
            QString fileName = QFileInfo(url.path()).fileName();

            // 指定默认保存路径
            QString defaultPath = "D:/MusicDownloads/" + fileName;  // 保存到指定目录
            QFile file(defaultPath);
            if (file.open(QIODevice::WriteOnly)) {
                file.write(data);
                file.close();
                QMessageBox::information(this, "Download Complete", "Song downloaded successfully to " + defaultPath);
            } else {
                QMessageBox::critical(this, "Error", "Failed to save file to " + defaultPath);
            }
        } else {
            QMessageBox::critical(this, "Error", reply->errorString());
        }

        reply->deleteLater();  // 删除网络回复对象
    });
}

void RecentlyPlayed::initializeStyle()
{
    ui->listWidget->setStyleSheet(R"(
        QListWidget {
            border: none;
            background-color: rgb(247, 249, 252); /* 背景色 */
        }

        QListWidget::item {
            height: 75px;
            background-color: rgb(247, 249, 252); /* 默认背景色 */
            border: none; /* 无边框 */
            border-radius: 20px; /* 圆角效果 */
            padding: 10px;
            font-size: 16px; /* 字体大小 */
        }

        QListWidget::item:selected {
            background-color: rgb(255, 255, 255); /* 选中项背景色 */
            color: black;  /* 选中项字体颜色 */
        }

        QListWidget::item:hover {
            background-color: rgb(255, 255, 255); /* 悬浮项背景色 */
        }
    )");
}
