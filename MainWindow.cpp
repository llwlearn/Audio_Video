#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QToolTip>
#include <QPoint>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>
#include <QApplication>
#include <QButtonGroup>
#include <memory>
#include <QSlider>
#include <QEvent>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QSettings>
#include <QPainter>      // 用于绘制图形
#include <QPixmap>       // 用于处理图像
#include <QWidget>       // 用于窗口相关的操作
#include <QPropertyAnimation>  // 用于动画效果
#include <QTimer>         // 用于定时器功能
#include <QParallelAnimationGroup>
#include <QGraphicsOpacityEffect>
#include <QShortcut>
#include <QSettings>

#include "src/tool/CustomScrollArea.h" // 滚动功能
#include "src/tool/Interface.h" // 界面设置
#include "src/view/Login.h" // 登录界面
#include "src/view/SearchFor.h" // 搜索界面
#include "src/view/PlayList.h"  // 播放列表
#include "src/view/PersonalInformation.h" // 个人信息设置
#include "src/view/UserInfo.h" // 用户信息界面

#include "src/view/Recommend.h" // 推荐界面
#include "src/view/Download.h" // 下载管理界面
#include "src/view/RecentlyPlayed.h" // 最近播放（历史记录）
#include "src/view/Setup.h" // 设置界面

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
    , player(new Player(this))
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
        connect(ui->search_for, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);
        connect(ui->mail, &QPushButton::clicked, this, &MainWindow::onMailClicked);
        connect(ui->Settings, &QPushButton::clicked, this, &MainWindow::onSettingsClicked);
        connect(ui->skinPeeler, &QPushButton::clicked, this, &MainWindow::onSkinPeelerClicked);
        connect(ui->minimize, &QPushButton::clicked, this, &MainWindow::onMinimizeClicked);
        connect(ui->maximize, &QPushButton::clicked, this, &MainWindow::onMaximizeClicked);
        connect(ui->close, &QPushButton::clicked, this, &MainWindow::onCloseClicked);

        connect(ui->PlayList, &QPushButton::clicked, this, &MainWindow::onPlayListClicked);

        startScrollingText(ui->vipText, "仅需￥5/月 学生专享价");



        // 连接夜间模式按钮的信号
        connect(ui->nightModeButton, &QPushButton::clicked, this, &MainWindow::toggleNightMode);

        this->login();
        this->setupRecommendWindow();
        // this->toggleNightMode(); // 默认白天模式
        // this->setupPlayer("SPACE", "LEFT", "RIGHT", "UP", "DOWN"); // 启动播放器
        this->loadSettings(); //在程序启动时加载保存的设置
        QSettings settings("MyCompany", "MyApp");
        // 加载快捷键设置
        QString playPauseShortcut = settings.value("playPauseShortcut").toString();
        QString prevSongShortcut = settings.value("prevSongShortcut").toString();
        QString nextSongShortcut = settings.value("nextSongShortcut").toString();
        QString volumeUpShortcut = settings.value("volumeUpShortcut").toString();
        QString volumeDownShortcut = settings.value("volumeDownShortcut").toString();
        this->setupPlayer(playPauseShortcut,
                         prevSongShortcut,
                         nextSongShortcut,
                         volumeUpShortcut,
                         volumeDownShortcut); // 加载快捷键
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 执行保存的设置
void MainWindow::saveSettings(bool enableTimerClose,
                                      int hour,
                                      int minute,
                                      QString theme,
                                      bool timedShutdown,
                                      bool autoPlay,
                                      QString soundEffect)
{
    qDebug() << "接收保存的设置："
             << "定时关闭：" << enableTimerClose
             << "小时：" << hour
             << "分钟：" << minute
             << "主题：" << theme
             << "关闭软件后关机：" << timedShutdown
             << "自动播放：" << autoPlay
             << "音效：" << soundEffect;

    // 保存设置到 QSettings
    QSettings settings("MyCompany", "MyApp");

    // 保存定时关闭设置
    settings.setValue("settings/timerEnable", enableTimerClose);
    settings.setValue("settings/timerHour", hour);
    settings.setValue("settings/timerMinute", minute);

    // 保存主题设置
    settings.setValue("settings/themeMode", theme);

    // 保存关闭软件后关机设置
    settings.setValue("settings/timedShutdown", timedShutdown);

    // 保存自动播放设置
    settings.setValue("settings/autoPlay", autoPlay);

    // 保存音效设置
    settings.setValue("settings/soundEffect", soundEffect);

    this->loadSettings();
}

void MainWindow::loadSettings()
{
    QSettings settings("MyCompany", "MyApp");

    bool enableTimerClose = settings.value("settings/timerEnable", false).toBool();
    int hour = settings.value("settings/timerHour", 0).toInt();
    int minute = settings.value("settings/timerMinute", 0).toInt();
    QString theme = settings.value("settings/themeMode", "默认主题").toString();
    bool timedShutdown = settings.value("settings/timedShutdown", false).toBool();
    bool autoPlay = settings.value("settings/autoPlay", false).toBool();
    QString soundEffect = settings.value("settings/soundEffect", "默认音效").toString();

    qDebug() << "加载保存的设置："
             << "定时关闭：" << enableTimerClose
             << "小时：" << hour
             << "分钟：" << minute
             << "主题：" << theme
             << "自动播放：" << autoPlay
             << "关闭软件后关机：" << timedShutdown
             << "音效：" << soundEffect;

    qDebug() << "设置已加载！";

    // 更新主窗口的状态
    // 例如：
    if (theme == "白色主题") {
        // 白色主题
        QString dayStyle = R"(
    QWidget {
        background-color: rgb(247, 249, 252);
        color: black;
    }

        QListView {
            border: none;
        }

        QListView::item {
            height: 75px;
            border: none; /* 无边框 */
            border-radius: 20px; /* 圆角效果 */
            padding: 10px;
            font-size: 16px; /* 字体大小 */
        }

        QListView::item:selected {
            background-color: rgb(255, 255, 255); /* 选中项背景色 */
        }

        QListView::item:hover {
            background-color: rgb(255, 255, 255); /* 悬浮项背景色 */
        }
    )";
        this->setStyleSheet(dayStyle);
        ui->LeftWidget->setStyleSheet("background-color: rgb(240, 243, 246);");
        ui->Theme->setStyleSheet("background-image: url(:/new/prefix1/log.png);");
        isNightMode = false;
    } else if (theme == "黑色主题") {
        // 黑色主题
        QString nightStyle = R"(
    QWidget {
        background-color: #3a3f44;
        color: white;
    }
        QListView {
            border: none;
            color: white;
        }
        QListView::item {
            color: white;
            height: 75px;
            border: none; /* 无边框 */
            border-radius: 20px; /* 圆角效果 */
            padding: 10px;
            font-size: 16px; /* 字体大小 */

        }
        QListView::item:selected {
            background-color: rgb(119,136,153); /* 选中项背景色 */
            color: white;  /* 选中项字体颜色 */
        }

        QListView::item:hover {
            background-color: rgb(119,136,153); /* 悬浮项背景色 */
        }
    )";
        this->setStyleSheet(nightStyle);
        ui->LeftWidget->setStyleSheet("background-color: #3a3f44");
        ui->Theme->setStyleSheet("background-image: url(:/new/prefix1/log-night.png);");
        isNightMode = true;
    }

    qDebug() << "设置已加载！";
}

// 启动播放器
void MainWindow::setupPlayer(const QString &playPauseShortcut,
                             const QString &prevSongShortcut,
                             const QString &nextSongShortcut,
                             const QString &volumeUpShortcut,
                             const QString &volumeDownShortcut)
{

    // 打印快捷键信息在一行中
    qDebug() << QString("快捷键配置：播放/暂停：%1，上一首：%2，下一首：%3，音量增加：%4，音量减小：%5")
                    .arg(playPauseShortcut)
                    .arg(prevSongShortcut)
                    .arg(nextSongShortcut)
                    .arg(volumeUpShortcut)
                    .arg(volumeDownShortcut);
    // 保存设置到 QSettings
    QSettings settings("MyCompany", "MyApp");
    settings.setValue("playPauseShortcut", playPauseShortcut);
    settings.setValue("prevSongShortcut", prevSongShortcut);
    settings.setValue("nextSongShortcut", nextSongShortcut);
    settings.setValue("volumeUpShortcut", volumeUpShortcut);
    settings.setValue("volumeDownShortcut", volumeDownShortcut);

    // 连接按钮的点击信号到相应的槽函数
    connect(ui->PlayOrPause, &QPushButton::clicked, this, &MainWindow::onPlayOrPauseClicked);
    connect(ui->like, &QPushButton::clicked, this, &MainWindow::onLikeClicked);
    connect(ui->PreviousSong, &QPushButton::clicked, this, &MainWindow::onPreviousSongClicked);
    connect(ui->NextSong, &QPushButton::clicked, this, &MainWindow::onNextSongClicked);
    connect(ui->ListLoop, &QPushButton::clicked, this, &MainWindow::onListLoopClicked);

    player = new Player();
    // 连接歌曲信息的信号
    connect(player, &Player::currentSongChanged, this, &MainWindow::onSongLoaded);
    ui->SongInformation->setText("断掉了的爱");

    player->loadMusicFromDatabase(); //加载列表音乐

    // 连接滑块的信号到相应的槽函数
    connect(ui->slider, &QSlider::valueChanged, this, &MainWindow::onProgressSliderValueChanged);
    connect(player, &Player::positionChanged, this, &MainWindow::updatePositionDisplay);// 连接当前播放时长的信号
    connect(player, &Player::durationChanged, this, &MainWindow::setSliderRange); // 设置滑块范围

    ui->slider->setOrientation(Qt::Horizontal);
    ui->slider->setTickPosition(QSlider::TicksBelow);
    ui->slider->setTickInterval(1000);  // 每秒一个刻度

    // 启动定时器，定期更新滑块
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateProgressSlider);
    timer->start(5000);  // 每秒更新一次滑块位置

    // 初始化滑块位置和可见性
    ui->VolumeSlider->hide();
    ui->VolumeSlider->setValue(50); // 默认音量
    player->setVolume(50); // 默认音量

    // 连接滑块值变化信号到槽
    connect(ui->VolumeSlider, &QSlider::valueChanged, this, &MainWindow::onVolumeSliderValueChanged);

    // 设置按钮和滑块的悬停事件
    ui->VolumeControl->installEventFilter(this);
    ui->VolumeSlider->installEventFilter(this);

    // 连接音量按钮的静音事件
    connect(ui->VolumeControl, &QPushButton::clicked, this, &MainWindow::onVolumeControlClicked);

    ffmpegWorker = new FfmpegWorker();

    // 播放/暂停
    QShortcut *getPlayPauseShortcut = new QShortcut(QKeySequence(playPauseShortcut), this);
    connect(getPlayPauseShortcut, &QShortcut::activated, this, &MainWindow::onPlayOrPauseClicked); // 或者 &Player::pause 根据需求

    // 上一首
    QShortcut *getPrevSongShortcut = new QShortcut(QKeySequence(prevSongShortcut), this);
    connect(getPrevSongShortcut, &QShortcut::activated, this, &MainWindow::onPreviousSongClicked);

    // 下一首
    QShortcut *getNextSongShortcut = new QShortcut(QKeySequence(nextSongShortcut), this);
    connect(getNextSongShortcut, &QShortcut::activated, this, &MainWindow::onNextSongClicked);

    // 音量增加
    QShortcut *getVolumeUpShortcut = new QShortcut(QKeySequence(volumeUpShortcut), this);
    connect(getVolumeUpShortcut, &QShortcut::activated, this, [this]() {
        // 获取当前音量
        int currentVolume = ui->VolumeSlider->value();
        // 增加音量
        currentVolume += 5;
        // 限制音量范围
        if (currentVolume > 100) currentVolume = 100;
        // 更新音量条
        ui->VolumeSlider->setValue(currentVolume);
    });

    // 音量减小
    QShortcut *getVolumeDownShortcut = new QShortcut(QKeySequence(volumeDownShortcut), this);
    connect(getVolumeDownShortcut, &QShortcut::activated, this, [this]() {
        // 获取当前音量
        int currentVolume = ui->VolumeSlider->value();
        // 减少音量
        currentVolume -= 5;
        // 限制音量范围
        if (currentVolume < 0) currentVolume = 0;
        // 更新音量条
        ui->VolumeSlider->setValue(currentVolume);
    });
}

void MainWindow::toggleNightMode()
{
    // 白天模式样式
    QString dayStyle = R"(
    QWidget {
        background-color: rgb(247, 249, 252);
        color: black;
    }

        QListView {
            border: none;
        }

        QListView::item {
            height: 75px;
            border: none; /* 无边框 */
            border-radius: 20px; /* 圆角效果 */
            padding: 10px;
            font-size: 16px; /* 字体大小 */
        }

        QListView::item:selected {
            background-color: rgb(255, 255, 255); /* 选中项背景色 */
        }

        QListView::item:hover {
            background-color: rgb(255, 255, 255); /* 悬浮项背景色 */
        }
    )";

    // 夜间模式样式
    QString nightStyle = R"(
    QWidget {
        background-color: #3a3f44;
        color: white;
    }
        QListView {
            border: none;
            color: white;
        }
        QListView::item {
            color: white;
            height: 75px;
            border: none; /* 无边框 */
            border-radius: 20px; /* 圆角效果 */
            padding: 10px;
            font-size: 16px; /* 字体大小 */

        }
        QListView::item:selected {
            background-color: rgb(119,136,153); /* 选中项背景色 */
            color: white;  /* 选中项字体颜色 */
        }

        QListView::item:hover {
            background-color: rgb(119,136,153); /* 悬浮项背景色 */
        }
    )";

    if (isNightMode) {
        // 切换到白天模式
        this->setStyleSheet(dayStyle);
        ui->LeftWidget->setStyleSheet("background-color: rgb(240, 243, 246);");
        ui->Theme->setStyleSheet("background-image: url(:/new/prefix1/log.png);");
        isNightMode = false;
    } else {
        // 切换到夜间模式
        this->setStyleSheet(nightStyle);
        ui->LeftWidget->setStyleSheet("background-color: #3a3f44");
        ui->Theme->setStyleSheet("background-image: url(:/new/prefix1/log-night.png);");
        isNightMode = true;
    }
}

void MainWindow::clearLayoutAndWidgets(QWidget *widget)
{
    if (widget->layout()) {
        QLayout *layout = widget->layout();
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
        delete layout;
        widget->setLayout(nullptr); // 清除布局
    }
}

void MainWindow::onPersonalInfoSettings()
{
    qDebug("接收到个人信息设置按钮点击信号");

    // 删除现有的布局和所有子控件
    clearLayoutAndWidgets(ui->MainWidget);

    PersonalInformation *personalInformation = PersonalInformation::getInstance(ui->MainWidget);
    // 设置窗口的最小高度
    personalInformation->setMinimumHeight(personalInformation->height());

    personalInformation->show();

    personalInformation->loadingPersonalInformation();

    connect(personalInformation, &PersonalInformation::personalInformationChanged, this, [this] {
        // 更新用户名
        login();
        // 在这里可以使用newUsername进行进一步操作
        // 例如，更新MainWindow中的某些显示或状态
    });

}

void MainWindow::onVolumeControlClicked()
{
    if (!isPressed) {
        // 设置音量为0，实现静音
        player->setVolume(0);
        // 切换到按下状态的背景图片
        ui->VolumeControl->setStyleSheet("QPushButton { image: url(:/new/prefix1/mute.png); border: none; }");
        isPressed = true;
        qDebug() << "按钮切换到静音状态";
    } else {
        // 恢复上一次的音量
        player->setVolume(lastVolume);
        // 切换回正常状态的背景图片
        ui->VolumeControl->setStyleSheet("QPushButton { image: url(:/new/prefix1/VolumeControl.png); border: none; }");
        isPressed = false;
        qDebug() << "按钮切换回正常状态";
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->VolumeControl) {
        if (event->type() == QEvent::HoverEnter) {
            // 显示滑块
            QPoint buttonPosInMainWindow = ui->VolumeControl->mapTo(this, QPoint(0, 0));
            QPoint sliderPos(buttonPosInMainWindow.x(), buttonPosInMainWindow.y() - ui->VolumeSlider->height());
            ui->VolumeSlider->move(sliderPos);
            ui->VolumeSlider->show();
        }
        else if (event->type() == QEvent::HoverLeave) {
            // 延迟隐藏滑块
            QTimer::singleShot(100, this, [this]() {
                if (!ui->VolumeSlider->underMouse()) {
                    ui->VolumeSlider->hide();
                }
            });
        }
    }
    else if (obj == ui->VolumeSlider) {
        if (event->type() == QEvent::HoverLeave) {
            // 延迟隐藏滑块
            QTimer::singleShot(100, this, [this]() {
                if (!ui->VolumeControl->underMouse()) {
                    ui->VolumeSlider->hide();
                }
            });
        }
    }
    return QWidget::eventFilter(obj, event);
}

// 实现音量调节的槽函数
void MainWindow::onVolumeSliderValueChanged(int value)
{
    // 设置播放器的音量
    qDebug() << "当前音量值:" << value;
    lastVolume = value;
    player->setVolume(value);
}

void MainWindow::setSliderRange(qint64 duration)
{
    ui->slider->setRange(0, static_cast<int>(duration)); // 设置滑块范围
}

void MainWindow::updatePositionDisplay(int position)
{
    // 将毫秒转换为分钟和秒
    int minutes = position / 60000;
    int seconds = (position % 60000) / 1000;

    // 格式化字符串，例如 "3:45"
    QString durationText = QString("%1:%2").arg(minutes).arg(seconds, 2, 10, QLatin1Char('0'));

    // 更新 QLabel 的文本
    ui->Play_duration->setText(durationText);
}

void MainWindow::onSongLoaded(const QString &songName)
{
    // 假设 mainWindow 中有一个 FfmpegWorker 类型的成员变量 ffmpegWorker
    // 如果没有，你需要创建一个或者以其他方式获取到 FfmpegWorker 的实例
    Song song = ffmpegWorker->findSongBySongPath(songName);

    // 设置 QLabel 的文本
    ui->SongInformation->setText(song.songName); // 连接切换的歌曲名字
    ui->duration->setText(song.duration);
    ui->duration->setStyleSheet("QLabel {font-size: 14px; border: none; font-family: '微软雅黑';}");
    ui->Play_duration->setStyleSheet("QLabel {font-size: 14px; border: none; font-family: '微软雅黑';}");
}

void MainWindow::setupRecommendWindow()
{
    // 删除现有的布局和所有子控件
    clearLayoutAndWidgets(ui->MainWidget);
    // 在主窗口中设置推荐窗口的滚动区域
    Recommend *recommend = new Recommend(this);

    // 设置推荐窗口的最小高度
    recommend->setMinimumHeight(recommend->height());

    // 创建自定义的 CustomScrollArea 实例
    CustomScrollArea *scrollArea = new CustomScrollArea(ui->MainWidget);
    scrollArea->setWidget(recommend);
    scrollArea->setWidgetResizable(true);  // 允许内容自适应滚动区域大小

    // 设置是否自动隐藏滚动条
    scrollArea->setAutoHideScrollBar(true);  // 自动隐藏滚动条

    // 清除现有的布局（如果已经存在）
    if (ui->MainWidget->layout()) {
        delete ui->MainWidget->layout();  // 删除原布局
    }

    // 创建并设置布局
    QVBoxLayout *layout = new QVBoxLayout(ui->MainWidget);
    layout->addWidget(scrollArea);
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

            connect(userInfoWindow, &UserInfo::PersonalInformationSettings, this, &MainWindow::onPersonalInfoSettings);
            // 连接用户信息窗口销毁时的信号
            connect(userInfoWindow, &QObject::destroyed, this, [this]() {
                qDebug() << "用户信息窗口已销毁，用户名：";
                ui->username->setText("登录");
                // this->login();  // 或者其他你想执行的操作
            });
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
    // setButtonStyle(ui->PlayOrPause, "播放", ":/new/prefix1/play.png");
    setButtonStyle(ui->NextSong, "下一首", ":/new/prefix1/NextSong.png");
    setButtonStyle(ui->ListLoop, "列表循环", ":/new/prefix1/ListLoop.png");

    setButtonStyle(ui->DesktopLyrics, "桌面歌词", ":/new/prefix1/DesktopLyrics.png");
    setButtonStyle(ui->LetIsStartListeningTogether, "会员音效", ":/new/prefix1/LetIsStartListeningTogether.png");
    setButtonStyle(ui->MemberSoundEffects, "开始一起听", ":/new/prefix1/MemberSoundEffects.png");
    setButtonStyle(ui->VolumeControl, "音量调节", ":/new/prefix1/VolumeControl.png");
    setButtonStyle(ui->PlayList, "播放列表", ":/new/prefix1/PlayList.png");
}

// 按钮点击事件的槽函数

void MainWindow::onRecommendClicked()
{
    qDebug() << "推荐按钮点击事件";
    // 处理“推荐”按钮点击事件
    this->setupRecommendWindow();
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

    RecentlyPlayed *recentlyPlayed = new RecentlyPlayed(this);


    // 设置窗口的最小高度
    recentlyPlayed->setMinimumHeight(recentlyPlayed->height());

    // 创建自定义的 CustomScrollArea 实例
    CustomScrollArea *scrollArea = new CustomScrollArea(ui->MainWidget);
    scrollArea->setWidget(recentlyPlayed);
    scrollArea->setWidgetResizable(true);  // 允许内容自适应滚动区域大小

    // 设置是否自动隐藏滚动条
    scrollArea->setAutoHideScrollBar(true);  // 自动隐藏滚动条

    // 清除现有的布局（如果已经存在）
    if (ui->MainWidget->layout()) {
        delete ui->MainWidget->layout();  // 删除原布局
    }

    // 创建并设置新的布局
    QVBoxLayout *layout = new QVBoxLayout(ui->MainWidget);
    layout->addWidget(scrollArea);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // 确保推荐窗口的尺寸被正确调整
    recentlyPlayed->adjustSize();


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

    Download *download = new Download(this);

    // 加载本地音乐文件
    // download->performDatabaseQuery(ui->search->text());

    // 设置窗口的最小高度
    download->setMinimumHeight(download->height());

    // 创建自定义的 CustomScrollArea 实例
    CustomScrollArea *scrollArea = new CustomScrollArea(ui->MainWidget);
    scrollArea->setWidget(download);
    scrollArea->setWidgetResizable(true);  // 允许内容自适应滚动区域大小

    // 设置是否自动隐藏滚动条
    scrollArea->setAutoHideScrollBar(true);  // 自动隐藏滚动条

    // 清除现有的布局（如果已经存在）
    if (ui->MainWidget->layout()) {
        delete ui->MainWidget->layout();  // 删除原布局
    }

    // 创建并设置新的布局
    QVBoxLayout *layout = new QVBoxLayout(ui->MainWidget);
    layout->addWidget(scrollArea);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // 确保推荐窗口的尺寸被正确调整
    download->adjustSize();


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

    onButtonClicked(ui->recommend);

}

// 搜索按钮点击的槽函数
void MainWindow::onSearchButtonClicked()
{
    qDebug() << "搜索：";

    // 在主窗口中设置推荐窗口的滚动区域
    SearchFor *searchFor = new SearchFor(this);

    // 发送查询数据
    searchFor->performDatabaseQuery(ui->search->text());

    // 设置窗口的最小高度
    searchFor->setMinimumHeight(searchFor->height());

    // 创建自定义的 CustomScrollArea 实例
    CustomScrollArea *scrollArea = new CustomScrollArea(ui->MainWidget);
    scrollArea->setWidget(searchFor);
    scrollArea->setWidgetResizable(true);  // 允许内容自适应滚动区域大小

    // 设置是否自动隐藏滚动条
    scrollArea->setAutoHideScrollBar(true);  // 自动隐藏滚动条

    // 清除现有的布局（如果已经存在）
    if (ui->MainWidget->layout()) {
        delete ui->MainWidget->layout();  // 删除原布局
    }

    // 创建并设置新的布局
    QVBoxLayout *layout = new QVBoxLayout(ui->MainWidget);
    layout->addWidget(scrollArea);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // 确保推荐窗口的尺寸被正确调整
    searchFor->adjustSize();
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

    Setup *setup = new Setup(this);

    // 设置窗口的最小高度
    setup->setMinimumHeight(setup->height());

    // 创建自定义的 CustomScrollArea 实例
    CustomScrollArea *scrollArea = new CustomScrollArea(ui->MainWidget);
    scrollArea->setWidget(setup);
    scrollArea->setWidgetResizable(true);  // 允许内容自适应滚动区域大小

    // 设置是否自动隐藏滚动条
    scrollArea->setAutoHideScrollBar(true);  // 自动隐藏滚动条

    // 清除现有的布局（如果已经存在）
    if (ui->MainWidget->layout()) {
        delete ui->MainWidget->layout();  // 删除原布局
    }

    // 创建并设置新的布局
    QVBoxLayout *layout = new QVBoxLayout(ui->MainWidget);
    layout->addWidget(scrollArea);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // 确保推荐窗口的尺寸被正确调整
    setup->adjustSize();

    connect(setup, &Setup::shortcutUpdated,
            this, &MainWindow::setupPlayer); // 接收快捷键设置
    connect(setup, &Setup::settingsUpdated, this, &MainWindow::saveSettings);

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

void MainWindow::onLikeClicked()
{
    // 切换喜欢状态
    static bool isLiked = false;

    if (isLiked) {
        // 取消喜欢
        ui->like->setStyleSheet("image: url(:/new/prefix1/like.png); border: none;");
        isLiked = false;
    } else {
        // 添加喜欢
        ui->like->setStyleSheet("image: url(:/new/prefix1/liked.png); border: none;");
        isLiked = true;
    }

    // 更新数据库或状态
}

void MainWindow::onPreviousSongClicked()
{
    if (!player->getPlaylist().isEmpty()) {
        player->previous();
        ui->PlayOrPause->setStyleSheet("image: url(:/new/prefix1/pause.png); border: none;");
    } else {
        // 显示提示信息或处理空播放列表的情况
        qDebug() << "播放列表为空";
    }
}

void MainWindow::onPlayOrPauseClicked()
{
    if (player->getState() == QMediaPlayer::PlayingState) {
         qDebug() << "暂停播放";
        player->pause();
        ui->PlayOrPause->setStyleSheet("image: url(:/new/prefix1/play.png); border: none;");
    } else {
         qDebug() << "开始播放";
        player->play();
        ui->PlayOrPause->setStyleSheet("image: url(:/new/prefix1/pause.png); border: none;");
    }
}

void MainWindow::onNextSongClicked()
{
    if (!player->getPlaylist().isEmpty()) {
        player->next();
        ui->PlayOrPause->setStyleSheet("image: url(:/new/prefix1/pause.png); border: none;");
    } else {
        // 显示提示信息或处理空播放列表的情况
        qDebug() << "播放列表为空";
    }
}

// 循环方式
void MainWindow::onListLoopClicked()
{
    static int loopMode = 0; // 0: 无循环, 1: 单曲循环, 2: 列表循环

    loopMode = (loopMode + 1) % 3;

    switch (loopMode) {
    case 0:
        // 无循环
        ui->ListLoop->setStyleSheet("image: url(:/new/prefix1/NoLoop.png); border: none;");
        break;
    case 1:
        // 单曲循环
        ui->ListLoop->setStyleSheet("image: url(:/new/prefix1/SingleLoop.png); border: none;");
        break;
    case 2:
        // 列表循环
        ui->ListLoop->setStyleSheet("image: url(:/new/prefix1/ListLoop.png); border: none;");
        break;
    }

    // 更新播放模式
}

void MainWindow::onProgressSliderValueChanged(int value)
{
    // 当用户拖动滑块时，更新播放位置
    // player.setPosition(value);
    player->setPosition(value);
}

void MainWindow::updateProgressSlider()
{
    // 获取当前播放位置
    int position = player->getCurrentPosition();
    // 更新滑块位置
    ui->slider->setValue(position);
}

// 播放列表按钮点击时的行为
void MainWindow::onPlayListClicked()
{
    static bool open = false;  // 确保 open 状态正确，初始化为 false

    // 获取 PlayList 实例
    PlayList* playList = PlayList::getInstance();
    if (!playList) {
        qDebug() << "PlayList is null!";
        return;
    }

    if (!open) {
        // 获取主窗口的位置和大小
        QRect mainWindowGeometry = this->geometry();
        int x = mainWindowGeometry.right();  // 主窗口的右边界
        int y = mainWindowGeometry.top();   // 主窗口的上边界

        // 确保窗口在主窗口右下方的位置打开
        playList->move(x - playList->width(), y + 100);
        playList->show();  // 显示窗口
        qDebug() << "PlayList window opened.";
    } else {
        playList->close();  // 关闭窗口
        qDebug() << "PlayList window closed.";
    }

    // 切换 open 状态
    open = !open;
}
