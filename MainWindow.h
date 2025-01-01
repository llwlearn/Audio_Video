#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QEvent>
#include <QSlider>
#include <QGuiApplication>
#include <QScreen>

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

private slots:
    // 封装设置按钮的函数
    void setupButton(QPushButton *button, const QString &text);
    void startScrollingText(QPushButton *button, const QString &text);

    void setupRecommendWindow();
    void login();

private:
    Ui::MainWindow *ui;

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

    void onRetreatClicked();
    void onMailClicked();
    void onSettingsClicked();
    void onSkinPeelerClicked();
    void onMinimizeClicked();
    void onMaximizeClicked();
    void onCloseClicked();

};

#endif // MAINWINDOW_H
