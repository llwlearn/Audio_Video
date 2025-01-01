#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QToolTip>
#include <QPoint>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QApplication>
#include <QButtonGroup>
#include <QTimer>
#include <memory>
#include <QSlider>
#include <QEvent>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QSettings>

#include "src/view/Recommend.h"
#include "src/tool/CustomScrollArea.h"
#include "src/tool/Interface.h"
#include "src/view/Login.h"
#include "src/view/UserInfo.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupUI();  // // 设置按钮的工具提示
    // 在构造函数或适当的位置设置窗口的初始状态
    setWindowState(Qt::WindowNoState);

    setWindowFlags (Qt::CustomizeWindowHint);//两个函数都可以去掉标题栏，区别是这个可以鼠标缩放窗口
    // setWindowFlags (Qt::FramelessWindowHint);
     // 连接信号和槽

    connect(ui->recommend, &QPushButton::clicked, this, [this]() { onButtonClicked(ui->recommend); });
    connect(ui->selected, &QPushButton::clicked, this, [this]() { onButtonClicked(ui->selected); });
    connect(ui->podcast, &QPushButton::clicked, this, [this]() { onButtonClicked(ui->podcast); });
    connect(ui->roam, &QPushButton::clicked, this, [this]() { onButtonClicked(ui->roam); });
    connect(ui->dynamics, &QPushButton::clicked, this, [this]() { onButtonClicked(ui->dynamics); });
    connect(ui->myLike, &QPushButton::clicked, this, [this]() { onButtonClicked(ui->myLike); });
    connect(ui->RecentlyPlayed, &QPushButton::clicked, this, [this]() { onButtonClicked(ui->RecentlyPlayed); });
    connect(ui->collect, &QPushButton::clicked, this, [this]() { onButtonClicked(ui->collect); });
    connect(ui->DownloadManagement, &QPushButton::clicked, this, [this]() { onButtonClicked(ui->DownloadManagement); });
    connect(ui->LocalMusic, &QPushButton::clicked, this, [this]() { onButtonClicked(ui->LocalMusic); });

        connect(ui->retreat, &QPushButton::clicked, this, &MainWindow::onRetreatClicked);
        connect(ui->mail, &QPushButton::clicked, this, &MainWindow::onMailClicked);
        connect(ui->Settings, &QPushButton::clicked, this, &MainWindow::onSettingsClicked);
        connect(ui->skinPeeler, &QPushButton::clicked, this, &MainWindow::onSkinPeelerClicked);
        connect(ui->minimize, &QPushButton::clicked, this, &MainWindow::onMinimizeClicked);
        connect(ui->maximize, &QPushButton::clicked, this, &MainWindow::onMaximizeClicked);
        connect(ui->close, &QPushButton::clicked, this, &MainWindow::onCloseClicked);

        startScrollingText(ui->vipText, "仅需￥5/月 学生专享价");
        startScrollingText(ui->SongInformation, "如果爱忘了（live）-  汪苏泷/单依纯");

        this->login();
        this->setupRecommendWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupRecommendWindow()
{
    // 创建 Recommend 窗口实例
    Recommend *recommend = new Recommend(this);

    // 设置推荐窗口的最小高度
    recommend->setMinimumHeight(recommend->height());

    // 创建自定义的 CustomScrollArea 实例
    CustomScrollArea *scrollArea = new CustomScrollArea(ui->MainWidget);
    scrollArea->setWidget(recommend);  // 将 Recommend 窗口放入滚动区域
    scrollArea->setWidgetResizable(true);  // 允许内容自适应滚动区域大小

    // 设置水平滚动条策略为隐藏
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 移除 CustomScrollArea 的边框
    scrollArea->setStyleSheet(
        "QScrollArea {"
        "   border: none;"  // 禁用边框
        "}"
        "QScrollBar:vertical {"
        "   border: none;"
        "   background: transparent;"  // 设置滚动条背景为透明
        "   width: 10px;"              // 滚动条宽度
        "   margin: 20px 0 20px 0;"    // 滚动条上下边距
        "   padding-right: 3px;"       // 滑块右边距
        "}"
        "QScrollBar::handle:vertical {"
        "   background: rgb(226, 229, 233);" // 滚动条滑块颜色
        "   border-radius: 3px;"             // 滚动条滑块圆角
        "   min-height: 20px;"               // 滚动条滑块最小高度
        "}"
        "QScrollBar::handle:vertical:hover {"
        "   background: rgb(195, 200, 207);" // 滚动条滑块悬停颜色
        "}"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
        "   background: none;"               // 上下按钮背景色
        "   border: none;"                   // 上下按钮边框
        "   width: 0px;"                     // 上下按钮宽度
        "   height: 0px;"                    // 上下按钮高度
        "}"
        "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {"
        "   background: none;"               // 上下箭头背景色
        "   border: none;"                   // 上下箭头边框
        "}"
        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
        "   background: none;"               // 页面背景色
        "}"
        );

    // 移除父控件的边框
    ui->MainWidget->setStyleSheet("border: none;");

    // 移除 Recommend 的边框
    recommend->setStyleSheet("border: none;");

    // 创建并设置布局
    QVBoxLayout *layout = new QVBoxLayout(ui->MainWidget);
    layout->addWidget(scrollArea);  // 将滚动区域添加到布局中
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // 确保推荐窗口的尺寸被正确调整
    recommend->adjustSize();
}

void MainWindow::login()
{
    Login login;
    if(!login.LoginFromFile().isEmpty()){
        setupButton(ui->username, login.LoginFromFile());
    }else{
        setupButton(ui->username, "登录");
    }
}

void MainWindow::setupButton(QPushButton *button, const QString &text)
{
    // 获取字体的宽度和文本截断
    QFontMetrics fm(button->font());
    QString truncatedText = fm.elidedText(text, Qt::ElideRight, button->width());

    // 设置截断后的文本
    button->setText(truncatedText);

    // 设置样式表，支持鼠标移入时改变颜色
    button->setStyleSheet(
        "QPushButton { color: rgb(102, 109, 126); font-family: '微软雅黑'; background: none; border: none; }"
        "QPushButton:hover { color: rgb(40, 50, 72); }"
        );

    // 连接点击事件
    connect(button, &QPushButton::clicked, this, [this, button]() {
        qDebug() << "按钮 '" << button->text() << "' 被点击了";

        // 判断按钮文本
        if (button->text() == "登录") {
            // 获取登录窗口的单例
            Login *loginWindow = Login::getInstance();  // 使用单例模式

            // 获取屏幕的尺寸
            QScreen *screen = QApplication::primaryScreen();
            QRect screenRect = screen->availableGeometry();

            // 计算居中位置
            int x = (screenRect.width() * Interface::windowInfo.dpi - loginWindow->width()) / 2;
            int y = (screenRect.height() * Interface::windowInfo.dpi - loginWindow->height()) / 2;

            // 设置窗口初始位置 (X, Y)
            loginWindow->move(x, y - 100);  // 将窗口移动到屏幕的居中位置

            loginWindow->show();  // 显示登录窗口

            // 连接登录窗口销毁时的信号
            connect(loginWindow, &QObject::destroyed, this, [this]() {
                qDebug() << "登录窗口已销毁，用户名：";
                this->login();  // 或者其他你想执行的操作
            });

        } else {
            // 获取用户信息窗口的单例
            UserInfo *userInfoWindow = UserInfo::getInstance();  // 使用单例模式

            // 获取按钮的几何位置
            QPoint buttonPos = button->mapToGlobal(QPoint(0, 0));  // 获取按钮在全局坐标系中的位置
            int buttonWidth = button->width();  // 获取按钮的宽度
            int buttonHeight = button->height();  // 获取按钮的高度
            static int userInfoWidth = userInfoWindow->width();  // 获取用户信息窗口的宽度

            // 计算用户信息窗口的水平居中位置
            int x = buttonPos.x() + (buttonWidth - userInfoWidth) / 2;  // 居中对齐按钮
            int y = buttonPos.y() + buttonHeight;  // 垂直方向紧跟按钮下方

            userInfoWindow->move(x, y);// 设置用户信息窗口的位置
            userInfoWindow->show();// 显示用户信息窗口
        }
    });


}

// 封装滚动文本的函数
void MainWindow::startScrollingText(QPushButton *button, const QString &text) {
    // 初始化文本内容和偏移量
    std::shared_ptr<QString> textPtr = std::make_shared<QString>(text);  // 使用shared_ptr管理文本
    int offset = button->width();  // 初始位置设置为按钮的宽度

    // 创建定时器并设置父对象
    QTimer *timer = new QTimer(button);

    // 使用QObject::destroyed信号来确保定时器在对象销毁时被清除
    QObject::connect(button, &QPushButton::destroyed, timer, &QTimer::deleteLater);

    // 连接定时器到槽
    QObject::connect(timer, &QTimer::timeout, button, [this, textPtr, button, &offset]() {
        QString displayedText = *textPtr;  // 获取显示文本
        int textWidth = QFontMetrics(button->font()).horizontalAdvance(displayedText);  // 计算文本宽度

        // 如果文本宽度小于或等于按钮宽度，不进行滚动
        if (textWidth <= button->width()) {
            // 文本直接显示在按钮上，无需滚动
            offset = 0;  // 保持文本不滚动
            button->setText(displayedText);
            // 设置按钮样式
            if (button == ui->vipText) {
                button->setStyleSheet(QString("QPushButton { "
                                              "background-color: rgb(52, 42, 42); "
                                              "color: rgb(236, 212, 207); "
                                              "border-radius: 10px; "
                                              "border-top-left-radius: none; "
                                              "text-align: left; "
                                              "font-size: 12px;  "
                                              "font-family: '微软雅黑';  "
                                              "padding-left: %1px; "
                                              "}").arg(offset));
            } else {
                button->setStyleSheet(QString("QPushButton { "
                                              "border: none; "
                                              "text-align: left; "
                                              "font-size: 20px;  "
                                              "font-family: '微软雅黑';  "
                                              "padding-left: %1px; "
                                              "}").arg(offset));
            }
        } else {
            // 启动滚动效果
            offset -= 1;  // 每次向左移动1个像素

            // 如果文本完全滚动出按钮的左侧，重置偏移量为右侧
            if (offset < -textWidth) {
                offset = button->width();
            }

            // 设置按钮的文本，保持文本不为空
            button->setText(displayedText);
            // 设置按钮样式
            if (button == ui->vipText) {
                button->setStyleSheet(QString("QPushButton { "
                                              "background-color: rgb(52, 42, 42); "
                                              "color: rgb(236, 212, 207); "
                                              "border-radius: 10px; "
                                              "border-top-left-radius: none; "
                                              "text-align: left; "
                                              "font-size: 12px;  "
                                              "font-family: '微软雅黑';  "
                                              "padding-left: %1px; "
                                              "}").arg(offset));
            } else {
                button->setStyleSheet(QString("QPushButton { "
                                              "border: none; "
                                              "text-align: left; "
                                              "font-size: 20px;  "
                                              "font-family: '微软雅黑';  "
                                              "padding-left: %1px; "
                                              "}").arg(offset));
            }
        }
    });

    // 启动定时器
    timer->start(60);  // 每30毫秒更新一次文本位置
}


void MainWindow::onButtonClicked(QPushButton* button)
{
    setupUI();

    // 获取按钮的文本（名称）
    QString objectName = button->objectName();

    // 拼接成图像的 URL
    QString imageUrl = QString(":/new/prefix1/%1-white.png").arg(objectName);

    // 设置样式表
    button->setStyleSheet(QString(
                              "QPushButton {"
                              "background-image: url(%1);"
                              "background-repeat: no-repeat; "
                              "background-position: left; "
                              "background-color: rgb(252, 60, 87); "
                              "border: none; "
                              "border-radius: 10px;"
                              "color: rgb(255, 255, 255); "
                              "font-size: 18px; "
                              "font-family: '微软雅黑';}"
                              "QPushButton:hover { background-color: rgb(252, 60, 87); }"
                              "QPushButton:pressed { background-color: rgb(252, 60, 87); }"
                              "QPushButton:focus { background-color: rgb(252, 60, 87); }").arg(imageUrl));

    if (button) {
        // 根据不同的按钮调用不同的函数
        if (button == ui->recommend) {
            onRecommendClicked();
        } else if (button == ui->selected) {
            onSelectedClicked();
        } else if (button == ui->podcast) {
            onPodcastClicked();
        } else if (button == ui->roam) {
            onRoamClicked();
        } else if (button == ui->dynamics) {
            onDynamicsClicked();
        } else if (button == ui->myLike) {
            onMyLikeClicked();
        } else if (button == ui->RecentlyPlayed) {
            onRecentlyPlayedClicked();
        } else if (button == ui->collect) {
            onCollectClicked();
        } else if (button == ui->DownloadManagement) {
            onDownloadClicked();
        } else if (button == ui->LocalMusic) {
            onLocalMusicClicked();
        }
    }

}


void MainWindow::resizeEvent(QResizeEvent *event) {
    // 获取新的窗口尺寸
    QSize newSize = event->size();
    int newWidth = newSize.width();
    int newHeight = newSize.height();

    ui->RightTopWidget->move(newWidth-591 , 2);
    ui->LeftWidget->resize(255 , newHeight);
    ui->DownWidget->move(0 , newHeight-100);
    ui->DownWidget->resize(newWidth , 100);

    ui->RightDownWidget->move(newWidth-320 , 0);
    ui->CentreDownWidget->move((newWidth - 474) / 2, 0);

    ui->MainWidget->resize(newWidth-255 , newHeight-191);

    // qDebug() << this->windowInfo.windowWidth;
    // qDebug() << this->windowInfo.windowHeight;
    // qDebug() << "窗口新宽度：" << newWidth << "窗口新高度：" << newHeight;

    // 调用基类的 resizeEvent 确保事件被正确处理
    QWidget::resizeEvent(event);  // 确保事件传递给基类处理
    // this->update();  // 触发重绘，确保工具提示的位置正确
}

// 设置按钮样式的函数实现
void setButtonStyle(QPushButton *button, const QString &imagePath)
{
    // 使用QString::arg()来将图片路径插入到样式表中
    QString defaultStyle = QString(
                             "QPushButton {"
                             "    background-image: url(%1);"
                             "    background-repeat: no-repeat;"
                             "    color: rgb(120, 127, 141);"                // 文字颜色
                             "    border: none;"                             // 无边框
                             "   border-radius: 10px;"
                             "    font-size: 18px;"                          // 字体大小
                             "    font-family: '微软雅黑';"        // 字体设置
                             "}"
                             "QPushButton:hover {"
                             "    background-color: rgb(228, 232, 236);"   // 悬停时的背景颜色
                             "}"
                             ).arg(imagePath); // 将路径插入到样式表中

    // 设置按钮的默认样式
    button->setStyleSheet(defaultStyle);

}


void setButtonStyle(QPushButton* button, const QString& toolTip, const QString& imagePath) {
    button->setToolTip(toolTip);

    // 只设置按钮样式
    button->setStyleSheet(QString("QPushButton { image: url(%1); border: none; }").arg(imagePath));
}

// 创建按钮列表，包含所有需要设置样式的按钮
void MainWindow::setupUI() {

    QList<QPushButton*> buttons = {
        ui->recommend, ui->selected, ui->podcast, ui->roam,
        ui->dynamics, ui->myLike, ui->RecentlyPlayed, ui->collect,
        ui->DownloadManagement, ui->LocalMusic
    };

    // 创建按钮对应的图标路径列表
    QList<QString> iconPaths = {
        ":/new/prefix1/recommend.png", ":/new/prefix1/selected.png",
        ":/new/prefix1/podcast.png", ":/new/prefix1/roam.png",
        ":/new/prefix1/dynamics.png", ":/new/prefix1/myLike.png",
        ":/new/prefix1/RecentlyPlayed.png", ":/new/prefix1/collect.png",
        ":/new/prefix1/DownloadManagement.png", ":/new/prefix1/LocalMusic.png"
    };

    // 遍历每个按钮和对应的图标路径并设置样式
    for (int i = 0; i < buttons.size(); ++i) {
        setButtonStyle(buttons[i], iconPaths[i]);
    }

    setButtonStyle(ui->retreat, "后退", ":/new/prefix1/return.png");
    setButtonStyle(ui->mail, "消息中心", ":/new/prefix1/mail.png");
    setButtonStyle(ui->Settings, "设置", ":/new/prefix1/Settings.png");
    setButtonStyle(ui->skinPeeler, "换肤", ":/new/prefix1/skin-peeler.png");
    setButtonStyle(ui->minimize, "最小化", ":/new/prefix1/minimize.png");
    setButtonStyle(ui->maximize, "最大化", ":/new/prefix1/maximize.png");
    setButtonStyle(ui->close, "关闭", ":/new/prefix1/close.png");

    setButtonStyle(ui->AddToPlaylist, "收藏到歌单", ":/new/prefix1/AddToPlaylist.png");
    setButtonStyle(ui->ViewComments, "查看评论", ":/new/prefix1/ViewComments.png");
    setButtonStyle(ui->share, "分享", ":/new/prefix1/share.png");
    setButtonStyle(ui->download, "下载", ":/new/prefix1/download.png");
    setButtonStyle(ui->close, "关闭", ":/new/prefix1/close.png");

    setButtonStyle(ui->like, "喜欢", ":/new/prefix1/like.png");
    setButtonStyle(ui->PreviousSong, "上一首", ":/new/prefix1/PreviousSong.png");
    setButtonStyle(ui->pause, "暂停", ":/new/prefix1/pause.png");
    setButtonStyle(ui->NextSong, "下一首", ":/new/prefix1/NextSong.png");
    setButtonStyle(ui->ListLoop, "列表循环", ":/new/prefix1/ListLoop.png");

    setButtonStyle(ui->DesktopLyrics, "桌面歌词", ":/new/prefix1/DesktopLyrics.png");
    setButtonStyle(ui->LetIsStartListeningTogether, "会员音效", ":/new/prefix1/LetIsStartListeningTogether.png");
    setButtonStyle(ui->MemberSoundEffects, "开始一起听", ":/new/prefix1/MemberSoundEffects.png");
    setButtonStyle(ui->PlayList, "音量调节", ":/new/prefix1/PlayList.png");
    setButtonStyle(ui->VolumeControl, "播放列表", ":/new/prefix1/VolumeControl.png");
}

// 按钮点击事件的槽函数

void MainWindow::onRecommendClicked()
{
    qDebug() << "推荐按钮点击事件";
    // 处理“推荐”按钮点击事件
}

void MainWindow::onSelectedClicked()
{
    qDebug() << "精选按钮点击事件";
    // 处理“精选”按钮点击事件
}

void MainWindow::onPodcastClicked()
{
    qDebug() << "播客按钮点击事件";
    // 处理“播客”按钮点击事件
}

void MainWindow::onRoamClicked()
{
    qDebug() << "漫游按钮点击事件";
    // 处理“漫游”按钮点击事件
}

void MainWindow::onDynamicsClicked()
{
    qDebug() << "动态按钮点击事件";
    // 处理“动态”按钮点击事件
}

void MainWindow::onMyLikeClicked()
{
    qDebug() << "我喜欢的音乐按钮点击事件";
    // 处理“我喜欢的音乐”按钮点击事件
}

void MainWindow::onRecentlyPlayedClicked()
{
    qDebug() << "最近播放按钮点击事件";
    // 处理“最近播放”按钮点击事件
}

void MainWindow::onCollectClicked()
{
    qDebug() << "我的收藏按钮点击事件";
    // 处理“我的收藏”按钮点击事件
}

void MainWindow::onDownloadClicked()
{
    qDebug() << "下载管理按钮点击事件";
    // 处理“下载管理”按钮点击事件
}

void MainWindow::onLocalMusicClicked()
{
    qDebug() << "本地音乐按钮点击事件";
    // 处理“本地音乐”按钮点击事件
}

void MainWindow::onRetreatClicked()
{
    // 返回按钮点击时的行为
    qDebug() << "Return button clicked!";
}

void MainWindow::onMailClicked()
{
    // 邮件按钮点击时的行为
    qDebug() << "Mail button clicked!";
}

void MainWindow::onSettingsClicked()
{
    // 设置按钮点击时的行为
    qDebug() << "Settings button clicked!";
}

void MainWindow::onSkinPeelerClicked()
{
    // 皮肤剥离按钮点击时的行为
    qDebug() << "Skin Peeler button clicked!";
}

void MainWindow::onMinimizeClicked()
{
    // 最小化按钮点击时的行为
    qDebug() << "Minimize button clicked!";

     setWindowState(windowState() | Qt::WindowMinimized);  // 最小化窗口
}

void MainWindow::onMaximizeClicked()
{
    // 最大化按钮点击时的行为

    // 判断当前窗口是否已最大化
    if (this->width() == this->windowInfo.maxWidth) {

        // 设置新的几何大小 直接设置窗口位置和大小
        this->setGeometry(this->windowInfo.x, this->windowInfo.y, this->windowInfo.windowWidth, this->windowInfo.windowHeight);

        ui->maximize->setToolTip("最大化");  // 修改工具提示为 "最大化"
        ui->maximize->setStyleSheet("QPushButton { image: url(:/new/prefix1/maximize.png); border: none; }");  // 设置按钮图标为最大化图标
    } else {
        // 如果不是最大化状态，点击按钮后最大化
        // 设置新的几何大小
        this->setGeometry(0, 0, windowInfo.maxWidth, windowInfo.maxHeight);  // 直接设置窗口位置和大小

        ui->maximize->setToolTip("向下还原");  // 修改工具提示为 "还原"
        ui->maximize->setStyleSheet("QPushButton { image: url(:/new/prefix1/RestoreDown.png); border: none; }");  // 设置按钮图标为还原图标
    }
}

void MainWindow::onCloseClicked()
{
    // 关闭按钮点击时的行为
    qDebug() << "Close button clicked!";
    close();  // 关闭窗口
}
