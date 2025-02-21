#include "PlayList.h"
#include "ui_PlayList.h"

#include "src/tool/CustomScrollArea.h"

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

PlayList::PlayList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayList)
{
    ui->setupUi(this);

    // setWindowFlags (Qt::CustomizeWindowHint);//两个函数都可以去掉标题栏，区别是这个可以鼠标缩放窗口
    setWindowFlags (Qt::FramelessWindowHint);

    // 创建CustomScrollArea并设置ListWidget作为其内容
    CustomScrollArea *customScrollArea = new CustomScrollArea(this);

    customScrollArea->setWidget(ui->listWidget);

    customScrollArea->move(0, ui->TopWidget->height());
    customScrollArea->resize(ui->listWidget->size());

    // 创建事件过滤器对象，传入当前窗口指针
    EventFilter *filter = new EventFilter(this, this);
    this->installEventFilter(filter);  // 安装事件过滤器

    // 创建一个数据库对象，避免每次查询时都连接
    db = new Database();
    bool connected = db->connect("localhost", "Audio_Video", "root", "123456");
    if (!connected) {
        qDebug() << "错误：无法连接到数据库!";
        return;
    }

    connect(ui->clear, &QPushButton::clicked, this, &PlayList::clear);//链接清空槽函数

}

PlayList::~PlayList()
{
    delete ui;
    delete filter;  // 释放过滤器对象
    delete db;
    qDebug() << "已清除";
}

// 获取 PlayList 实例的静态方法
PlayList* PlayList::getInstance(QWidget *parent)
{
    static PlayList* instance = nullptr;  // 静态局部变量，保证只有一个实例
    if (!instance) {
        instance = new PlayList(parent);  // 如果没有实例，则创建一个新的 PlayList
    }
    return instance;
}

void PlayList::clear(){
    db->remove("playlist", "");
    ui->listWidget->clear();  // 清空现有内容
}

void PlayList::showEvent(QShowEvent *event) {
    // 当窗口显示时，调用 query 函数进行数据查询
    query();
    // 调用父类的 showEvent 方法（如果有其他的显示行为需要继承）
    QWidget::showEvent(event);
}

void PlayList::query(){
    // 构建查询字段和查询条件：查询播放列表
    QStringList fields;  // 留空表示查询所有字段
    QString condition;   // 留空表示没有条件


    // 执行查询
    QSqlQuery query = db->select("playlist", fields, condition);  // 查询 PlayList 表

    // 处理查询结果
    QList<Song> songList;
    if (query.next()) {
        do {
            int id = query.value("id").toInt();
            QString songName = query.value("song_name").toString();
            QString artist = query.value("artist").toString();
            bool isVip = query.value("is_vip").toBool();
            QString duration = query.value("duration").toString();

            // 将每首歌曲添加到 songList
            songList.append(Song(id, songName, artist, isVip, duration));
        } while (query.next());

        // 将查询结果传递到 populateList 函数
        populateList(songList);
    } else {
        qDebug() << "查询失败，未找到匹配的歌曲：" << query.lastError();
    }
}

void PlayList::populateList(const QList<Song>& songs)
{
    ui->listWidget->clear();  // 清空现有内容

    // 遍历歌曲列表，将每首歌的信息添加到列表中
    for (const Song& song : songs) {

        // 创建自定义控件作为列表项
        QWidget *widget = new QWidget();
        widget->setStyleSheet("background-color: transparent;");

        // 创建布局
        QHBoxLayout *layout = new QHBoxLayout(widget);

        // 创建垂直布局用于歌名和歌手名字
        QVBoxLayout *infoLayout = new QVBoxLayout();

        // 创建标签显示歌曲信息
        QLabel *songLabel = new QLabel(this);
        songLabel->setText(song.songName);
        songLabel->setStyleSheet("font-size: 23px; color: black;");
        songLabel->setMaximumHeight(30);  // 设置歌名标签的最大高度
        songLabel->setMaximumWidth(250);  // 设置歌名标签的最大宽度

        // 创建标签显示歌手信息
        QLabel *artist = new QLabel(this);
        artist->setText(song.artist);
        artist->setStyleSheet("font-size: 20px; color: black;");
        artist->setMaximumHeight(20);     // 设置歌手标签的最大高度
        artist->setMaximumWidth(250);     // 设置歌手标签的最大宽度

        // 将歌名和歌手名字添加到垂直布局
        infoLayout->addWidget(songLabel);
        infoLayout->addWidget(artist);

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
            QString coverUrl = "E://音乐";  // 本地文件路径
            downloadSong(coverUrl);
        });

        // 创建时长标签
        QLabel *durationLabel = new QLabel(this);

        // 获取 song.duration（假设它是字符串类型）
        QString duration = song.duration;

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
        durationLabel->setFixedWidth(40);
        durationLabel->setStyleSheet("font-size: 14px; color: grey;");
        durationLabel->setAlignment(Qt::AlignRight);  // 设置文本内容右对齐

        // 将控件添加到布局
        layout->addLayout(infoLayout);
        layout->addWidget(likeButton);
        layout->addWidget(downloadButton);  // 添加下载按钮
        layout->addWidget(vipLabel);
        layout->addWidget(durationLabel);

        // 设置布局
        widget->setLayout(layout);  // 将布局设置到widget上

        // 创建列表项并将自定义控件添加到该项中
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        item->setSizeHint(widget->sizeHint());  // 设置列表项的大小
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, widget);  // 将控件关联到列表项

    }
}

void PlayList::downloadSong(const QString &songUrl)
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

void PlayList::initializeStyle()
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
