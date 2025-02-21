/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *LeftWidget;
    QPushButton *recommend;
    QPushButton *selected;
    QPushButton *podcast;
    QPushButton *roam;
    QPushButton *dynamics;
    QWidget *Theme;
    QFrame *line_2;
    QLabel *label;
    QPushButton *DownloadManagement;
    QPushButton *LocalMusic;
    QPushButton *collect;
    QPushButton *RecentlyPlayed;
    QPushButton *myLike;
    QPushButton *retreat;
    QWidget *DownWidget;
    QPushButton *pushButton_3;
    QPushButton *SongInformation;
    QPushButton *AddToPlaylist;
    QPushButton *ViewComments;
    QPushButton *share;
    QPushButton *download;
    QWidget *CentreDownWidget;
    QPushButton *PlayOrPause;
    QPushButton *like;
    QPushButton *PreviousSong;
    QPushButton *NextSong;
    QPushButton *ListLoop;
    QSlider *slider;
    QLabel *duration;
    QLabel *Play_duration;
    QWidget *RightDownWidget;
    QPushButton *DesktopLyrics;
    QPushButton *MemberSoundEffects;
    QPushButton *LetIsStartListeningTogether;
    QPushButton *VolumeControl;
    QPushButton *PlayList;
    QWidget *RightTopWidget;
    QPushButton *Settings;
    QPushButton *close;
    QPushButton *skinPeeler;
    QPushButton *mail;
    QPushButton *maximize;
    QPushButton *minimize;
    QFrame *line;
    QPushButton *pushButton_4;
    QPushButton *username;
    QPushButton *vip;
    QPushButton *vipText;
    QPushButton *Personal_Information;
    QPushButton *search_for;
    QLineEdit *search;
    QWidget *MainWidget;
    QSlider *VolumeSlider;
    QPushButton *nightModeButton;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1320, 940);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1320, 940));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 249, 252);"));
        LeftWidget = new QWidget(MainWindow);
        LeftWidget->setObjectName("LeftWidget");
        LeftWidget->setGeometry(QRect(0, 0, 255, 940));
        LeftWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 243, 246);"));
        recommend = new QPushButton(LeftWidget);
        recommend->setObjectName("recommend");
        recommend->setGeometry(QRect(28, 112, 196, 45));
        recommend->setCursor(QCursor(Qt::PointingHandCursor));
        recommend->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/recommend.png);\n"
"image-position: left;\n"
"border: none;\n"
""));
        selected = new QPushButton(LeftWidget);
        selected->setObjectName("selected");
        selected->setGeometry(QRect(28, 160, 196, 45));
        selected->setCursor(QCursor(Qt::PointingHandCursor));
        selected->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/selected.png);\n"
"image-position: left;\n"
"border: none;"));
        podcast = new QPushButton(LeftWidget);
        podcast->setObjectName("podcast");
        podcast->setGeometry(QRect(28, 208, 196, 45));
        podcast->setCursor(QCursor(Qt::PointingHandCursor));
        podcast->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/podcast.png);\n"
"image-position: left;\n"
"border: none;"));
        roam = new QPushButton(LeftWidget);
        roam->setObjectName("roam");
        roam->setGeometry(QRect(28, 256, 196, 45));
        roam->setCursor(QCursor(Qt::PointingHandCursor));
        roam->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/roam.png);\n"
"image-position: left;\n"
"border: none;"));
        dynamics = new QPushButton(LeftWidget);
        dynamics->setObjectName("dynamics");
        dynamics->setGeometry(QRect(28, 304, 196, 45));
        dynamics->setCursor(QCursor(Qt::PointingHandCursor));
        dynamics->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/dynamics.png);\n"
"image-position: left;\n"
"border: none;"));
        Theme = new QWidget(LeftWidget);
        Theme->setObjectName("Theme");
        Theme->setGeometry(QRect(28, 20, 200, 50));
        Theme->setCursor(QCursor(Qt::PointingHandCursor));
        Theme->setStyleSheet(QString::fromUtf8("background: url(:/new/prefix1/log.png)"));
        line_2 = new QFrame(LeftWidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(40, 374, 173, 1));
        line_2->setStyleSheet(QString::fromUtf8("border:  none;\n"
"background-color: rgba(184, 189, 198, 0.5);"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label = new QLabel(LeftWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(41, 409, 111, 20));
        label->setStyleSheet(QString::fromUtf8("color: rgb(160, 166, 177);"));
        DownloadManagement = new QPushButton(LeftWidget);
        DownloadManagement->setObjectName("DownloadManagement");
        DownloadManagement->setGeometry(QRect(28, 587, 196, 45));
        DownloadManagement->setCursor(QCursor(Qt::PointingHandCursor));
        DownloadManagement->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/DownloadManagement.png);\n"
"image-position: left;\n"
"border: none;"));
        LocalMusic = new QPushButton(LeftWidget);
        LocalMusic->setObjectName("LocalMusic");
        LocalMusic->setGeometry(QRect(28, 635, 196, 45));
        LocalMusic->setCursor(QCursor(Qt::PointingHandCursor));
        LocalMusic->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/LocalMusic.png);\n"
"image-position: left;\n"
"border: none;"));
        collect = new QPushButton(LeftWidget);
        collect->setObjectName("collect");
        collect->setGeometry(QRect(28, 539, 196, 45));
        collect->setCursor(QCursor(Qt::PointingHandCursor));
        collect->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/collect.png);\n"
"image-position: left;\n"
"border: none;"));
        RecentlyPlayed = new QPushButton(LeftWidget);
        RecentlyPlayed->setObjectName("RecentlyPlayed");
        RecentlyPlayed->setGeometry(QRect(28, 491, 196, 45));
        RecentlyPlayed->setCursor(QCursor(Qt::PointingHandCursor));
        RecentlyPlayed->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/RecentlyPlayed.png);\n"
"image-position: left;\n"
"border: none;"));
        myLike = new QPushButton(LeftWidget);
        myLike->setObjectName("myLike");
        myLike->setGeometry(QRect(28, 443, 196, 45));
        myLike->setCursor(QCursor(Qt::PointingHandCursor));
        myLike->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/myLike.png);\n"
"image-position: left;\n"
"border: none;"));
        retreat = new QPushButton(MainWindow);
        retreat->setObjectName("retreat");
        retreat->setGeometry(QRect(304, 20, 37, 47));
        retreat->setCursor(QCursor(Qt::PointingHandCursor));
        retreat->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/return.png);\n"
"border: none;"));
        DownWidget = new QWidget(MainWindow);
        DownWidget->setObjectName("DownWidget");
        DownWidget->setGeometry(QRect(0, 840, 1320, 100));
        DownWidget->setStyleSheet(QString::fromUtf8("border-top: 1px solid rgba(184, 189, 198, 0.5);"));
        pushButton_3 = new QPushButton(DownWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(38, 13, 75, 75));
        pushButton_3->setStyleSheet(QString::fromUtf8("border: 12px solid rgb(4, 4, 4);\n"
"border-radius: 37px;"));
        SongInformation = new QPushButton(DownWidget);
        SongInformation->setObjectName("SongInformation");
        SongInformation->setGeometry(QRect(124, 23, 226, 20));
        SongInformation->setStyleSheet(QString::fromUtf8("border: none;\n"
"text-align: left;"));
        AddToPlaylist = new QPushButton(DownWidget);
        AddToPlaylist->setObjectName("AddToPlaylist");
        AddToPlaylist->setGeometry(QRect(124, 50, 35, 35));
        AddToPlaylist->setCursor(QCursor(Qt::PointingHandCursor));
        AddToPlaylist->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/AddToPlaylist.png);\n"
"border: none;"));
        ViewComments = new QPushButton(DownWidget);
        ViewComments->setObjectName("ViewComments");
        ViewComments->setGeometry(QRect(184, 50, 36, 35));
        ViewComments->setCursor(QCursor(Qt::PointingHandCursor));
        ViewComments->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/ViewComments.png);\n"
"border: none;"));
        share = new QPushButton(DownWidget);
        share->setObjectName("share");
        share->setGeometry(QRect(230, 50, 35, 35));
        share->setCursor(QCursor(Qt::PointingHandCursor));
        share->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/share.png);\n"
"border: none;"));
        download = new QPushButton(DownWidget);
        download->setObjectName("download");
        download->setGeometry(QRect(280, 50, 35, 35));
        download->setCursor(QCursor(Qt::PointingHandCursor));
        download->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/download.png);\n"
"border: none;"));
        CentreDownWidget = new QWidget(DownWidget);
        CentreDownWidget->setObjectName("CentreDownWidget");
        CentreDownWidget->setGeometry(QRect(442, 0, 474, 100));
        PlayOrPause = new QPushButton(CentreDownWidget);
        PlayOrPause->setObjectName("PlayOrPause");
        PlayOrPause->setGeometry(QRect(210, 15, 54, 54));
        PlayOrPause->setCursor(QCursor(Qt::PointingHandCursor));
        PlayOrPause->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/play.png);\n"
"border: none;\n"
""));
        like = new QPushButton(CentreDownWidget);
        like->setObjectName("like");
        like->setGeometry(QRect(101, 25, 32, 32));
        like->setCursor(QCursor(Qt::PointingHandCursor));
        like->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/like.png);\n"
"border: none;"));
        PreviousSong = new QPushButton(CentreDownWidget);
        PreviousSong->setObjectName("PreviousSong");
        PreviousSong->setGeometry(QRect(155, 25, 32, 32));
        PreviousSong->setCursor(QCursor(Qt::PointingHandCursor));
        PreviousSong->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/PreviousSong.png);\n"
"border: none;"));
        NextSong = new QPushButton(CentreDownWidget);
        NextSong->setObjectName("NextSong");
        NextSong->setGeometry(QRect(285, 25, 32, 32));
        NextSong->setCursor(QCursor(Qt::PointingHandCursor));
        NextSong->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/NextSong.png);\n"
"border: none;"));
        ListLoop = new QPushButton(CentreDownWidget);
        ListLoop->setObjectName("ListLoop");
        ListLoop->setGeometry(QRect(339, 25, 32, 32));
        ListLoop->setCursor(QCursor(Qt::PointingHandCursor));
        ListLoop->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/ListLoop.png);\n"
"border: none;"));
        slider = new QSlider(CentreDownWidget);
        slider->setObjectName("slider");
        slider->setGeometry(QRect(42, 70, 390, 30));
        slider->setCursor(QCursor(Qt::PointingHandCursor));
        slider->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    border: none;\n"
"    margin-left: 8px;\n"
"    margin-right: 8px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: rgb(255, 255, 255); /* \350\256\276\347\275\256\346\273\221\345\235\227\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    margin: -6px 0;\n"
"    border-radius: 8px;\n"
"    transition: all 0.3s ease;\n"
"    box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.5) inset; /* \350\256\276\347\275\256\351\230\264\345\275\261\344\270\272\345\206\205\351\230\264\345\275\261\357\274\214\344\270\273\350\246\201\345\234\250\346\273\221\345\235\227\344\270\213\346\226\271\346\230\276\347\244\272 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"    box-shadow: 0px 6px 8px rgba(0, 0, 0, 0.5) inset; /* \346\202\254\345\201\234\346\227\266\351\230\264\345\275\261\346\225\210\346\236\234\346\233\264\346\230\216\346\230\276 */\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    background: qlineargradient(spread:pad, x1:"
                        "0, y1:0, x2:1, y2:0, stop:0 rgb(242, 107, 130), stop:1 rgb(242, 107, 130));\n"
"    height: 5px;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgb(255, 0, 0), stop:1 rgb(255, 0, 0));\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: rgb(218, 220, 223); /* \350\256\276\347\275\256\346\273\221\345\235\227\345\217\263\344\276\247\351\203\250\345\210\206\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 2px;\n"
"}"));
        slider->setOrientation(Qt::Horizontal);
        duration = new QLabel(CentreDownWidget);
        duration->setObjectName("duration");
        duration->setGeometry(QRect(430, 77, 36, 16));
        duration->setStyleSheet(QString::fromUtf8("border: none;\n"
"font-size: 11px;"));
        Play_duration = new QLabel(CentreDownWidget);
        Play_duration->setObjectName("Play_duration");
        Play_duration->setGeometry(QRect(10, 77, 36, 16));
        Play_duration->setStyleSheet(QString::fromUtf8("border: none;\n"
"font-size: 11px;"));
        RightDownWidget = new QWidget(DownWidget);
        RightDownWidget->setObjectName("RightDownWidget");
        RightDownWidget->setGeometry(QRect(1000, 0, 320, 100));
        DesktopLyrics = new QPushButton(RightDownWidget);
        DesktopLyrics->setObjectName("DesktopLyrics");
        DesktopLyrics->setGeometry(QRect(50, 30, 40, 40));
        DesktopLyrics->setCursor(QCursor(Qt::PointingHandCursor));
        DesktopLyrics->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/DesktopLyrics.png);\n"
"border: none;"));
        MemberSoundEffects = new QPushButton(RightDownWidget);
        MemberSoundEffects->setObjectName("MemberSoundEffects");
        MemberSoundEffects->setGeometry(QRect(100, 30, 40, 40));
        MemberSoundEffects->setCursor(QCursor(Qt::PointingHandCursor));
        MemberSoundEffects->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/MemberSoundEffects.png);\n"
"border: none;"));
        LetIsStartListeningTogether = new QPushButton(RightDownWidget);
        LetIsStartListeningTogether->setObjectName("LetIsStartListeningTogether");
        LetIsStartListeningTogether->setGeometry(QRect(150, 30, 40, 40));
        LetIsStartListeningTogether->setCursor(QCursor(Qt::PointingHandCursor));
        LetIsStartListeningTogether->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/LetIsStartListeningTogether.png);\n"
"border: none;"));
        VolumeControl = new QPushButton(RightDownWidget);
        VolumeControl->setObjectName("VolumeControl");
        VolumeControl->setGeometry(QRect(200, 30, 40, 40));
        VolumeControl->setCursor(QCursor(Qt::PointingHandCursor));
        VolumeControl->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/VolumeControl.png);\n"
"border: none;"));
        PlayList = new QPushButton(RightDownWidget);
        PlayList->setObjectName("PlayList");
        PlayList->setGeometry(QRect(250, 30, 40, 40));
        PlayList->setCursor(QCursor(Qt::PointingHandCursor));
        PlayList->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/PlayList.png);\n"
"border: none;"));
        RightTopWidget = new QWidget(MainWindow);
        RightTopWidget->setObjectName("RightTopWidget");
        RightTopWidget->setGeometry(QRect(738, 2, 581, 91));
        RightTopWidget->setStyleSheet(QString::fromUtf8("border: none;"));
        Settings = new QPushButton(RightTopWidget);
        Settings->setObjectName("Settings");
        Settings->setGeometry(QRect(333, 20, 37, 47));
        Settings->setCursor(QCursor(Qt::PointingHandCursor));
        Settings->setMouseTracking(false);
        Settings->setFocusPolicy(Qt::StrongFocus);
        Settings->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Settings.png);\n"
"border: none;"));
        close = new QPushButton(RightTopWidget);
        close->setObjectName("close");
        close->setGeometry(QRect(498, 20, 37, 47));
        close->setCursor(QCursor(Qt::PointingHandCursor));
        close->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/close.png);\n"
"border: none;"));
        skinPeeler = new QPushButton(RightTopWidget);
        skinPeeler->setObjectName("skinPeeler");
        skinPeeler->setGeometry(QRect(370, 20, 37, 47));
        skinPeeler->setCursor(QCursor(Qt::PointingHandCursor));
        skinPeeler->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/skin-peeler.png);\n"
"border: none;"));
        mail = new QPushButton(RightTopWidget);
        mail->setObjectName("mail");
        mail->setGeometry(QRect(296, 20, 37, 47));
        mail->setCursor(QCursor(Qt::PointingHandCursor));
        mail->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/mail.png);\n"
"border: none;\n"
""));
        maximize = new QPushButton(RightTopWidget);
        maximize->setObjectName("maximize");
        maximize->setGeometry(QRect(460, 20, 37, 47));
        maximize->setCursor(QCursor(Qt::PointingHandCursor));
        maximize->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/maximize.png);\n"
"border: none;"));
        minimize = new QPushButton(RightTopWidget);
        minimize->setObjectName("minimize");
        minimize->setGeometry(QRect(422, 20, 37, 47));
        minimize->setCursor(QCursor(Qt::PointingHandCursor));
        minimize->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/minimize.png);\n"
"border: none;"));
        line = new QFrame(RightTopWidget);
        line->setObjectName("line");
        line->setGeometry(QRect(414, 32, 1, 20));
        line->setStyleSheet(QString::fromUtf8("border:  none;\n"
"background-color: rgba(184, 189, 198, 0.5);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_4 = new QPushButton(RightTopWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(14, 24, 39, 39));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("border: 2px solid rgb(226, 229, 233);\n"
"border-radius: 19px;"));
        username = new QPushButton(RightTopWidget);
        username->setObjectName("username");
        username->setGeometry(QRect(60, 34, 62, 19));
        username->setCursor(QCursor(Qt::PointingHandCursor));
        vip = new QPushButton(RightTopWidget);
        vip->setObjectName("vip");
        vip->setGeometry(QRect(142, 33, 38, 20));
        vip->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/vip.png);\n"
"border-radius: 10px;\n"
"border-top-right-radius: 0;\n"
"border-bottom-right-radius: 0;"));
        vipText = new QPushButton(RightTopWidget);
        vipText->setObjectName("vipText");
        vipText->setGeometry(QRect(180, 33, 60, 20));
        QFont font;
        font.setPointSize(8);
        vipText->setFont(font);
        vipText->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 42, 42);\n"
"border-radius: 10px;\n"
"border-top-left-radius: none;\n"
"color: rgb(236, 212, 207);"));
        Personal_Information = new QPushButton(RightTopWidget);
        Personal_Information->setObjectName("Personal_Information");
        Personal_Information->setGeometry(QRect(250, 35, 19, 19));
        Personal_Information->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Personal_Information.png);"));
        search_for = new QPushButton(MainWindow);
        search_for->setObjectName("search_for");
        search_for->setGeometry(QRect(683, 22, 44, 44));
        search_for->setCursor(QCursor(Qt::PointingHandCursor));
        search_for->setStyleSheet(QString::fromUtf8("border: 2px solid rgb(226, 229, 233);\n"
"border-radius: 10px;\n"
"image: url(:/new/prefix1/search_for.png);"));
        search = new QLineEdit(MainWindow);
        search->setObjectName("search");
        search->setGeometry(QRect(360, 22, 300, 44));
        search->setStyleSheet(QString::fromUtf8("border: 2px solid rgb(226, 229, 233);\n"
"border-radius: 10px;"));
        MainWidget = new QWidget(MainWindow);
        MainWidget->setObjectName("MainWidget");
        MainWidget->setGeometry(QRect(255, 89, 1065, 751));
        VolumeSlider = new QSlider(MainWindow);
        VolumeSlider->setObjectName("VolumeSlider");
        VolumeSlider->setGeometry(QRect(1200, 710, 40, 160));
        VolumeSlider->setStyleSheet(QString::fromUtf8(""));
        VolumeSlider->setOrientation(Qt::Vertical);
        nightModeButton = new QPushButton(MainWindow);
        nightModeButton->setObjectName("nightModeButton");
        nightModeButton->setGeometry(QRect(0, 750, 80, 71));
        nightModeButton->setCursor(QCursor(Qt::PointingHandCursor));
        search->raise();
        retreat->raise();
        LeftWidget->raise();
        DownWidget->raise();
        RightTopWidget->raise();
        search_for->raise();
        MainWidget->raise();
        VolumeSlider->raise();
        nightModeButton->raise();
        QWidget::setTabOrder(retreat, recommend);
        QWidget::setTabOrder(recommend, selected);
        QWidget::setTabOrder(selected, podcast);
        QWidget::setTabOrder(podcast, dynamics);
        QWidget::setTabOrder(dynamics, roam);
        QWidget::setTabOrder(roam, DownloadManagement);
        QWidget::setTabOrder(DownloadManagement, LocalMusic);
        QWidget::setTabOrder(LocalMusic, collect);
        QWidget::setTabOrder(collect, RecentlyPlayed);
        QWidget::setTabOrder(RecentlyPlayed, myLike);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        recommend->setText(QCoreApplication::translate("MainWindow", "\346\216\250\350\215\220", nullptr));
        selected->setText(QCoreApplication::translate("MainWindow", "\347\262\276\351\200\211", nullptr));
        podcast->setText(QCoreApplication::translate("MainWindow", "\346\222\255\345\256\242", nullptr));
        roam->setText(QCoreApplication::translate("MainWindow", "\346\274\253\346\270\270", nullptr));
        dynamics->setText(QCoreApplication::translate("MainWindow", "\345\212\250\346\200\201", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204", nullptr));
        DownloadManagement->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275\347\256\241\347\220\206", nullptr));
        LocalMusic->setText(QCoreApplication::translate("MainWindow", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        collect->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\346\224\266\350\227\217", nullptr));
        RecentlyPlayed->setText(QCoreApplication::translate("MainWindow", "\346\234\200\350\277\221\346\222\255\346\224\276", nullptr));
        myLike->setText(QCoreApplication::translate("MainWindow", "\346\210\221\345\226\234\346\254\242\347\232\204\351\237\263\344\271\220", nullptr));
        retreat->setText(QString());
        pushButton_3->setText(QString());
        SongInformation->setText(QString());
        AddToPlaylist->setText(QString());
        ViewComments->setText(QString());
        share->setText(QString());
        download->setText(QString());
        PlayOrPause->setText(QString());
        like->setText(QString());
        PreviousSong->setText(QString());
        NextSong->setText(QString());
        ListLoop->setText(QString());
        duration->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        Play_duration->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        DesktopLyrics->setText(QString());
        MemberSoundEffects->setText(QString());
        LetIsStartListeningTogether->setText(QString());
        VolumeControl->setText(QString());
        PlayList->setText(QString());
        Settings->setText(QString());
        close->setText(QString());
        skinPeeler->setText(QString());
        mail->setText(QString());
        maximize->setText(QString());
        minimize->setText(QString());
        pushButton_4->setText(QString());
        username->setText(QCoreApplication::translate("MainWindow", "\347\222\220\347\222\220\345\256\266\346\212\225\344\272\206", nullptr));
        vip->setText(QString());
        vipText->setText(QString());
        Personal_Information->setText(QString());
        search_for->setText(QString());
        nightModeButton->setText(QCoreApplication::translate("MainWindow", "\345\244\234\351\227\264\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
