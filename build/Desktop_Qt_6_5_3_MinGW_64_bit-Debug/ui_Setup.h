/********************************************************************************
** Form generated from reading UI file 'Setup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_H
#define UI_SETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setup
{
public:
    QLabel *label;
    QFrame *line_2;
    QLabel *label_2;
    QCheckBox *regularlyCloseSoftware;
    QComboBox *hour;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *minute;
    QCheckBox *timedShutdown;
    QFrame *line_3;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *theme;
    QCheckBox *startPlayingAudio;
    QLabel *label_8;
    QComboBox *soundEffect;
    QFrame *line_4;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *playPauseShortcut;
    QLineEdit *prevSongShortcut;
    QLineEdit *nextSongShortcut;
    QLineEdit *volumeDownShortcut;
    QLineEdit *volumeUpShortcut;
    QFrame *line_5;
    QLabel *label_17;
    QTextEdit *feedbackAndSuggestions;
    QPushButton *submit;
    QPushButton *RestoreDefault;

    void setupUi(QWidget *Setup)
    {
        if (Setup->objectName().isEmpty())
            Setup->setObjectName("Setup");
        Setup->resize(1280, 850);
        label = new QLabel(Setup);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 40, 71, 41));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font-size: 30px;"));
        line_2 = new QFrame(Setup);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(60, 100, 1200, 1));
        line_2->setStyleSheet(QString::fromUtf8("border:  none;\n"
"background-color: rgba(184, 189, 198, 0.5);"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(Setup);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 110, 51, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font-size: 25px;"));
        regularlyCloseSoftware = new QCheckBox(Setup);
        regularlyCloseSoftware->setObjectName("regularlyCloseSoftware");
        regularlyCloseSoftware->setGeometry(QRect(250, 155, 145, 28));
        QFont font1;
        regularlyCloseSoftware->setFont(font1);
        regularlyCloseSoftware->setCursor(QCursor(Qt::PointingHandCursor));
        regularlyCloseSoftware->setStyleSheet(QString::fromUtf8("font-size: 15px;"));
        regularlyCloseSoftware->setIconSize(QSize(30, 30));
        hour = new QComboBox(Setup);
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->addItem(QString());
        hour->setObjectName("hour");
        hour->setGeometry(QRect(360, 193, 101, 31));
        hour->setCursor(QCursor(Qt::PointingHandCursor));
        label_3 = new QLabel(Setup);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(250, 200, 101, 21));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 20px;"));
        label_4 = new QLabel(Setup);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(470, 200, 41, 21));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 20px;"));
        label_5 = new QLabel(Setup);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(630, 200, 51, 21));
        label_5->setStyleSheet(QString::fromUtf8("font-size: 20px;"));
        minute = new QComboBox(Setup);
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->addItem(QString());
        minute->setObjectName("minute");
        minute->setGeometry(QRect(520, 193, 101, 31));
        minute->setCursor(QCursor(Qt::PointingHandCursor));
        timedShutdown = new QCheckBox(Setup);
        timedShutdown->setObjectName("timedShutdown");
        timedShutdown->setGeometry(QRect(250, 245, 151, 22));
        timedShutdown->setCursor(QCursor(Qt::PointingHandCursor));
        timedShutdown->setStyleSheet(QString::fromUtf8("font-size: 15px;"));
        line_3 = new QFrame(Setup);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(60, 280, 1200, 1));
        line_3->setStyleSheet(QString::fromUtf8("border:  none;\n"
"background-color: rgba(184, 189, 198, 0.5);"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(Setup);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(70, 290, 51, 31));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("font-size: 25px;"));
        label_7 = new QLabel(Setup);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(250, 120, 51, 21));
        label_7->setStyleSheet(QString::fromUtf8("font-size: 20px;"));
        theme = new QComboBox(Setup);
        theme->addItem(QString());
        theme->addItem(QString());
        theme->addItem(QString());
        theme->setObjectName("theme");
        theme->setGeometry(QRect(310, 113, 101, 31));
        theme->setCursor(QCursor(Qt::PointingHandCursor));
        startPlayingAudio = new QCheckBox(Setup);
        startPlayingAudio->setObjectName("startPlayingAudio");
        startPlayingAudio->setGeometry(QRect(250, 300, 161, 22));
        startPlayingAudio->setCursor(QCursor(Qt::PointingHandCursor));
        startPlayingAudio->setStyleSheet(QString::fromUtf8("font-size: 15px;"));
        label_8 = new QLabel(Setup);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(250, 330, 51, 21));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 20px;"));
        soundEffect = new QComboBox(Setup);
        soundEffect->addItem(QString());
        soundEffect->addItem(QString());
        soundEffect->addItem(QString());
        soundEffect->setObjectName("soundEffect");
        soundEffect->setGeometry(QRect(310, 330, 101, 31));
        soundEffect->setCursor(QCursor(Qt::PointingHandCursor));
        line_4 = new QFrame(Setup);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(60, 370, 1200, 1));
        line_4->setStyleSheet(QString::fromUtf8("border:  none;\n"
"background-color: rgba(184, 189, 198, 0.5);"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_9 = new QLabel(Setup);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(70, 380, 81, 31));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("font-size: 25px;"));
        label_10 = new QLabel(Setup);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(250, 390, 91, 21));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("font-size: 20px;"));
        label_11 = new QLabel(Setup);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(440, 390, 91, 21));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("font-size: 20px;"));
        label_12 = new QLabel(Setup);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(250, 440, 91, 21));
        QFont font2;
        font2.setBold(false);
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("font-size: 20px;"));
        label_13 = new QLabel(Setup);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(250, 490, 91, 21));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("font-size: 20px;"));
        label_14 = new QLabel(Setup);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(250, 540, 91, 21));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("font-size: 20px;"));
        label_15 = new QLabel(Setup);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(250, 590, 91, 21));
        label_15->setFont(font2);
        label_15->setStyleSheet(QString::fromUtf8("font-size: 20px;"));
        label_16 = new QLabel(Setup);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(250, 640, 91, 21));
        label_16->setFont(font2);
        label_16->setStyleSheet(QString::fromUtf8("font-size: 20px;"));
        playPauseShortcut = new QLineEdit(Setup);
        playPauseShortcut->setObjectName("playPauseShortcut");
        playPauseShortcut->setGeometry(QRect(440, 435, 161, 30));
        playPauseShortcut->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white; /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4CAF50;\n"
"    background-color: #f0f0f0; /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\346\265\205\347\201\260\350\211\262 */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #888888;\n"
"    background-color: #f5f5f5; /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\346\233\264\346\265\205\347\232\204\347\201\260\350\211\262 */\n"
"}"));
        prevSongShortcut = new QLineEdit(Setup);
        prevSongShortcut->setObjectName("prevSongShortcut");
        prevSongShortcut->setGeometry(QRect(440, 485, 161, 30));
        prevSongShortcut->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white; /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4CAF50;\n"
"    background-color: #f0f0f0; /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\346\265\205\347\201\260\350\211\262 */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #888888;\n"
"    background-color: #f5f5f5; /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\346\233\264\346\265\205\347\232\204\347\201\260\350\211\262 */\n"
"}"));
        nextSongShortcut = new QLineEdit(Setup);
        nextSongShortcut->setObjectName("nextSongShortcut");
        nextSongShortcut->setGeometry(QRect(440, 535, 161, 30));
        nextSongShortcut->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white; /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4CAF50;\n"
"    background-color: #f0f0f0; /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\346\265\205\347\201\260\350\211\262 */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #888888;\n"
"    background-color: #f5f5f5; /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\346\233\264\346\265\205\347\232\204\347\201\260\350\211\262 */\n"
"}"));
        volumeDownShortcut = new QLineEdit(Setup);
        volumeDownShortcut->setObjectName("volumeDownShortcut");
        volumeDownShortcut->setGeometry(QRect(440, 635, 161, 30));
        volumeDownShortcut->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white; /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4CAF50;\n"
"    background-color: #f0f0f0; /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\346\265\205\347\201\260\350\211\262 */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #888888;\n"
"    background-color: #f5f5f5; /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\346\233\264\346\265\205\347\232\204\347\201\260\350\211\262 */\n"
"}"));
        volumeUpShortcut = new QLineEdit(Setup);
        volumeUpShortcut->setObjectName("volumeUpShortcut");
        volumeUpShortcut->setGeometry(QRect(440, 585, 161, 30));
        volumeUpShortcut->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white; /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4CAF50;\n"
"    background-color: #f0f0f0; /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\346\265\205\347\201\260\350\211\262 */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #888888;\n"
"    background-color: #f5f5f5; /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\346\233\264\346\265\205\347\232\204\347\201\260\350\211\262 */\n"
"}"));
        line_5 = new QFrame(Setup);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(60, 690, 1200, 1));
        line_5->setStyleSheet(QString::fromUtf8("border:  none;\n"
"background-color: rgba(184, 189, 198, 0.5);"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_17 = new QLabel(Setup);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(70, 700, 131, 31));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("font-size: 25px;"));
        feedbackAndSuggestions = new QTextEdit(Setup);
        feedbackAndSuggestions->setObjectName("feedbackAndSuggestions");
        feedbackAndSuggestions->setGeometry(QRect(250, 710, 571, 121));
        submit = new QPushButton(Setup);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(870, 710, 101, 41));
        submit->setCursor(QCursor(Qt::PointingHandCursor));
        submit->setStyleSheet(QString::fromUtf8("font-size: 20px;"));
        RestoreDefault = new QPushButton(Setup);
        RestoreDefault->setObjectName("RestoreDefault");
        RestoreDefault->setGeometry(QRect(640, 640, 81, 31));
        RestoreDefault->setCursor(QCursor(Qt::PointingHandCursor));
        RestoreDefault->setStyleSheet(QString::fromUtf8("font-size: 15px;"));

        retranslateUi(Setup);

        QMetaObject::connectSlotsByName(Setup);
    } // setupUi

    void retranslateUi(QWidget *Setup)
    {
        Setup->setWindowTitle(QCoreApplication::translate("Setup", "Form", nullptr));
        label->setText(QCoreApplication::translate("Setup", "\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("Setup", "\347\263\273\347\273\237", nullptr));
        regularlyCloseSoftware->setText(QCoreApplication::translate("Setup", "\345\274\200\345\220\257\345\256\232\346\227\266\345\205\263\351\227\255\350\275\257\344\273\266", nullptr));
        hour->setItemText(0, QCoreApplication::translate("Setup", "0", nullptr));
        hour->setItemText(1, QCoreApplication::translate("Setup", "1", nullptr));
        hour->setItemText(2, QCoreApplication::translate("Setup", "2", nullptr));
        hour->setItemText(3, QCoreApplication::translate("Setup", "3", nullptr));
        hour->setItemText(4, QCoreApplication::translate("Setup", "4", nullptr));
        hour->setItemText(5, QCoreApplication::translate("Setup", "5", nullptr));
        hour->setItemText(6, QCoreApplication::translate("Setup", "6", nullptr));
        hour->setItemText(7, QCoreApplication::translate("Setup", "7", nullptr));
        hour->setItemText(8, QCoreApplication::translate("Setup", "8", nullptr));
        hour->setItemText(9, QCoreApplication::translate("Setup", "9", nullptr));
        hour->setItemText(10, QCoreApplication::translate("Setup", "10", nullptr));
        hour->setItemText(11, QCoreApplication::translate("Setup", "11", nullptr));
        hour->setItemText(12, QCoreApplication::translate("Setup", "12", nullptr));
        hour->setItemText(13, QCoreApplication::translate("Setup", "13", nullptr));
        hour->setItemText(14, QCoreApplication::translate("Setup", "14", nullptr));
        hour->setItemText(15, QCoreApplication::translate("Setup", "15", nullptr));
        hour->setItemText(16, QCoreApplication::translate("Setup", "16", nullptr));
        hour->setItemText(17, QCoreApplication::translate("Setup", "17", nullptr));
        hour->setItemText(18, QCoreApplication::translate("Setup", "18", nullptr));
        hour->setItemText(19, QCoreApplication::translate("Setup", "19", nullptr));
        hour->setItemText(20, QCoreApplication::translate("Setup", "20", nullptr));
        hour->setItemText(21, QCoreApplication::translate("Setup", "21", nullptr));
        hour->setItemText(22, QCoreApplication::translate("Setup", "22", nullptr));
        hour->setItemText(23, QCoreApplication::translate("Setup", "23", nullptr));

        label_3->setText(QCoreApplication::translate("Setup", "\345\211\251\344\275\231\345\205\263\351\227\255\346\227\266\351\227\264", nullptr));
        label_4->setText(QCoreApplication::translate("Setup", "\345\260\217\346\227\266", nullptr));
        label_5->setText(QCoreApplication::translate("Setup", "\345\210\206\351\222\237", nullptr));
        minute->setItemText(0, QCoreApplication::translate("Setup", "0", nullptr));
        minute->setItemText(1, QCoreApplication::translate("Setup", "1", nullptr));
        minute->setItemText(2, QCoreApplication::translate("Setup", "2", nullptr));
        minute->setItemText(3, QCoreApplication::translate("Setup", "3", nullptr));
        minute->setItemText(4, QCoreApplication::translate("Setup", "4", nullptr));
        minute->setItemText(5, QCoreApplication::translate("Setup", "5", nullptr));
        minute->setItemText(6, QCoreApplication::translate("Setup", "6", nullptr));
        minute->setItemText(7, QCoreApplication::translate("Setup", "7", nullptr));
        minute->setItemText(8, QCoreApplication::translate("Setup", "8", nullptr));
        minute->setItemText(9, QCoreApplication::translate("Setup", "9", nullptr));
        minute->setItemText(10, QCoreApplication::translate("Setup", "10", nullptr));
        minute->setItemText(11, QCoreApplication::translate("Setup", "11", nullptr));
        minute->setItemText(12, QCoreApplication::translate("Setup", "12", nullptr));
        minute->setItemText(13, QCoreApplication::translate("Setup", "13", nullptr));
        minute->setItemText(14, QCoreApplication::translate("Setup", "14", nullptr));
        minute->setItemText(15, QCoreApplication::translate("Setup", "15", nullptr));
        minute->setItemText(16, QCoreApplication::translate("Setup", "16", nullptr));
        minute->setItemText(17, QCoreApplication::translate("Setup", "17", nullptr));
        minute->setItemText(18, QCoreApplication::translate("Setup", "18", nullptr));
        minute->setItemText(19, QCoreApplication::translate("Setup", "19", nullptr));
        minute->setItemText(20, QCoreApplication::translate("Setup", "20", nullptr));
        minute->setItemText(21, QCoreApplication::translate("Setup", "21", nullptr));
        minute->setItemText(22, QCoreApplication::translate("Setup", "22", nullptr));
        minute->setItemText(23, QCoreApplication::translate("Setup", "23", nullptr));
        minute->setItemText(24, QCoreApplication::translate("Setup", "24", nullptr));
        minute->setItemText(25, QCoreApplication::translate("Setup", "25", nullptr));
        minute->setItemText(26, QCoreApplication::translate("Setup", "26", nullptr));
        minute->setItemText(27, QCoreApplication::translate("Setup", "27", nullptr));
        minute->setItemText(28, QCoreApplication::translate("Setup", "28", nullptr));
        minute->setItemText(29, QCoreApplication::translate("Setup", "29", nullptr));
        minute->setItemText(30, QCoreApplication::translate("Setup", "30", nullptr));
        minute->setItemText(31, QCoreApplication::translate("Setup", "31", nullptr));
        minute->setItemText(32, QCoreApplication::translate("Setup", "32", nullptr));
        minute->setItemText(33, QCoreApplication::translate("Setup", "33", nullptr));
        minute->setItemText(34, QCoreApplication::translate("Setup", "34", nullptr));
        minute->setItemText(35, QCoreApplication::translate("Setup", "35", nullptr));
        minute->setItemText(36, QCoreApplication::translate("Setup", "36", nullptr));
        minute->setItemText(37, QCoreApplication::translate("Setup", "37", nullptr));
        minute->setItemText(38, QCoreApplication::translate("Setup", "38", nullptr));
        minute->setItemText(39, QCoreApplication::translate("Setup", "39", nullptr));
        minute->setItemText(40, QCoreApplication::translate("Setup", "40", nullptr));
        minute->setItemText(41, QCoreApplication::translate("Setup", "41", nullptr));
        minute->setItemText(42, QCoreApplication::translate("Setup", "42", nullptr));
        minute->setItemText(43, QCoreApplication::translate("Setup", "43", nullptr));
        minute->setItemText(44, QCoreApplication::translate("Setup", "44", nullptr));
        minute->setItemText(45, QCoreApplication::translate("Setup", "45", nullptr));
        minute->setItemText(46, QCoreApplication::translate("Setup", "46", nullptr));
        minute->setItemText(47, QCoreApplication::translate("Setup", "47", nullptr));
        minute->setItemText(48, QCoreApplication::translate("Setup", "48", nullptr));
        minute->setItemText(49, QCoreApplication::translate("Setup", "49", nullptr));
        minute->setItemText(50, QCoreApplication::translate("Setup", "50", nullptr));
        minute->setItemText(51, QCoreApplication::translate("Setup", "51", nullptr));
        minute->setItemText(52, QCoreApplication::translate("Setup", "52", nullptr));
        minute->setItemText(53, QCoreApplication::translate("Setup", "53", nullptr));
        minute->setItemText(54, QCoreApplication::translate("Setup", "54", nullptr));
        minute->setItemText(55, QCoreApplication::translate("Setup", "55", nullptr));
        minute->setItemText(56, QCoreApplication::translate("Setup", "56", nullptr));
        minute->setItemText(57, QCoreApplication::translate("Setup", "57", nullptr));
        minute->setItemText(58, QCoreApplication::translate("Setup", "58", nullptr));
        minute->setItemText(59, QCoreApplication::translate("Setup", "59", nullptr));

        timedShutdown->setText(QCoreApplication::translate("Setup", "\345\205\263\351\227\255\350\275\257\344\273\266\345\220\214\346\227\266\345\205\263\346\234\272", nullptr));
        label_6->setText(QCoreApplication::translate("Setup", "\346\222\255\346\224\276", nullptr));
        label_7->setText(QCoreApplication::translate("Setup", "\344\270\273\351\242\230\357\274\232", nullptr));
        theme->setItemText(0, QCoreApplication::translate("Setup", "\351\273\230\350\256\244\344\270\273\351\242\230", nullptr));
        theme->setItemText(1, QCoreApplication::translate("Setup", "\347\231\275\350\211\262\344\270\273\351\242\230", nullptr));
        theme->setItemText(2, QCoreApplication::translate("Setup", "\351\273\221\350\211\262\344\270\273\351\242\230", nullptr));

        startPlayingAudio->setText(QCoreApplication::translate("Setup", "\347\250\213\345\272\217\345\220\257\345\212\250\346\227\266\350\207\252\345\212\250\346\222\255\346\224\276", nullptr));
        label_8->setText(QCoreApplication::translate("Setup", "\351\237\263\346\225\210\357\274\232", nullptr));
        soundEffect->setItemText(0, QCoreApplication::translate("Setup", "\346\227\240\351\237\263\346\225\210", nullptr));
        soundEffect->setItemText(1, QCoreApplication::translate("Setup", "\351\237\263\344\271\220\345\242\236\345\274\272", nullptr));
        soundEffect->setItemText(2, QCoreApplication::translate("Setup", "\347\216\257\347\273\225\351\237\263\346\225\210", nullptr));

        label_9->setText(QCoreApplication::translate("Setup", "\345\277\253\346\215\267\351\224\256", nullptr));
        label_10->setText(QCoreApplication::translate("Setup", "\345\212\237\350\203\275\350\257\264\346\230\216", nullptr));
        label_11->setText(QCoreApplication::translate("Setup", "\345\277\253\346\215\267\351\224\256", nullptr));
        label_12->setText(QCoreApplication::translate("Setup", "\346\222\255\346\224\276/\346\232\202\345\201\234", nullptr));
        label_13->setText(QCoreApplication::translate("Setup", "\344\270\212\344\270\200\351\246\226", nullptr));
        label_14->setText(QCoreApplication::translate("Setup", "\344\270\213\344\270\200\351\246\226", nullptr));
        label_15->setText(QCoreApplication::translate("Setup", "\351\237\263\351\207\217\345\212\240", nullptr));
        label_16->setText(QCoreApplication::translate("Setup", "\351\237\263\351\207\217\345\207\217", nullptr));
        playPauseShortcut->setText(QCoreApplication::translate("Setup", "SPACE", nullptr));
        prevSongShortcut->setText(QCoreApplication::translate("Setup", "LEFT", nullptr));
        nextSongShortcut->setText(QCoreApplication::translate("Setup", "RIGHT", nullptr));
        volumeDownShortcut->setText(QCoreApplication::translate("Setup", "DOWN", nullptr));
        volumeUpShortcut->setText(QCoreApplication::translate("Setup", "UP", nullptr));
        label_17->setText(QCoreApplication::translate("Setup", "\345\217\215\351\246\210\344\270\216\345\273\272\350\256\256", nullptr));
        submit->setText(QCoreApplication::translate("Setup", "\346\217\220\344\272\244", nullptr));
        RestoreDefault->setText(QCoreApplication::translate("Setup", "\346\201\242\345\244\215\351\273\230\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Setup: public Ui_Setup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_H
