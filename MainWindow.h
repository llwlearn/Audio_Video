#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QEvent>
#include <QSlider>
#include <QGuiApplication>
#include <QScreen>

#include "src/tool/Player.h"
#include "src/tool/FfmpegWorker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupUI();
    void resizeEvent(QResizeEvent *event) override;
    void onButtonClicked(QPushButton* button);
    struct WindowInfo {
        int maxWidth, maxHeight, windowWidth, windowHeight, x, y;
    };
    // 声明静态成员变量
    static WindowInfo windowInfo;

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    // 封装设置按钮的函数
    void setupButton(QPushButton *button, const QString &text);
    void startScrollingText(QPushButton *button, const QString &text);

    void setupRecommendWindow();
    void login();

    void onRecommendClicked();
    void onSelectedClicked();
    void onPodcastClicked();
    void onRoamClicked();
    void onDynamicsClicked();
    void onMyLikeClicked();
    void onRecentlyPlayedClicked();
    void onCollectClicked();
    void onDownloadClicked();
    void onLocalMusicClicked();

    void onSearchButtonClicked();       // 点击搜索按钮
    void onRetreatClicked();
    void onMailClicked();
    void onSettingsClicked();
    void onSkinPeelerClicked();
    void onMinimizeClicked();
    void onMaximizeClicked();
    void onCloseClicked();

    void onPlayOrPauseClicked();
    void onLikeClicked();
    void onPreviousSongClicked();
    void onNextSongClicked();
    void onListLoopClicked();
    void onProgressSliderValueChanged(int value);
    void updateProgressSlider();

    void onPlayListClicked();

    void onSongLoaded(const QString &songName); //接收歌曲数据
    void updatePositionDisplay(int position); //接收当前播放时长
    void setSliderRange(qint64 duration); // 让滑块根据当前播放时长移动
    void onVolumeSliderValueChanged(int value); //调节音量
    void onVolumeControlClicked(); // 音量按钮的静音切换

    void onPersonalInfoSettings(); //打开个人信息设置窗口
    void clearLayoutAndWidgets(QWidget *widget); // 清除布局

    void toggleNightMode();  // 切换夜间模式的函数
    void setupPlayer(const QString &playPauseShortcut,
                     const QString &prevSongShortcut,
                     const QString &nextSongShortcut,
                     const QString &volumeUpShortcut,
                     const QString &volumeDownShortcut); // 启动播放器
    void saveSettings(bool enableTimerClose,
                              int hour,
                              int minute,
                              QString theme,
                              bool timedShutdown,
                              bool autoPlay,
                              QString soundEffect); // 接收保存的设置
    void loadSettings(); // 在程序启动时加载保存的设置

private:
    Ui::MainWindow *ui;

    Player *player;// 播放器对象
    bool isPressed;
    int lastVolume; // 保存上一次的音量值
    FfmpegWorker *ffmpegWorker;
    bool isNightMode = true;  // 记录当前是否为夜间模式
};

#endif // MAINWINDOW_H
