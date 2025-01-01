/********************************************************************************
** Form generated from reading UI file 'Recommend.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOMMEND_H
#define UI_RECOMMEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Recommend
{
public:
    QWidget *TopWidget;
    QWidget *widget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *playlist_1;
    QLabel *playlist_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLabel *playlist_3;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QLabel *playlist_4;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *CarouselImage;
    QWidget *widget_3;
    QPushButton *pushButton_5;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *Selected_1;
    QLabel *Selected_2;
    QPushButton *pushButton_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_7;
    QLabel *Selected_3;
    QPushButton *pushButton_8;
    QLabel *Selected_4;
    QLabel *label_9;
    QPushButton *pushButton_9;
    QLabel *Selected_5;
    QLabel *label_10;
    QWidget *widget_4;
    QPushButton *pushButton_20;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *Selected_16;
    QLabel *Selected_17;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QLabel *Selected_18;
    QPushButton *pushButton_23;
    QLabel *Selected_19;
    QPushButton *pushButton_24;
    QLabel *Selected_20;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;

    void setupUi(QWidget *Recommend)
    {
        if (Recommend->objectName().isEmpty())
            Recommend->setObjectName("Recommend");
        Recommend->resize(1065, 2000);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(9);
        Recommend->setFont(font);
        Recommend->setStyleSheet(QString::fromUtf8(""));
        TopWidget = new QWidget(Recommend);
        TopWidget->setObjectName("TopWidget");
        TopWidget->setGeometry(QRect(0, 0, 1065, 210));
        TopWidget->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(TopWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(547, 20, 472, 174));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 12px;"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 54, 100, 100));
        pushButton->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"background-image: url(:/new/prefix1/recommend/Chinese-laziness.png);\n"
"background-position: center;"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(28, 128, 30, 18));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(181, 181, 181, 128);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 3px;\n"
"font-size: 11px;\n"
"padding-left: 1px;"));
        playlist_1 = new QLabel(widget);
        playlist_1->setObjectName("playlist_1");
        playlist_1->setGeometry(QRect(30, 60, 80, 50));
        playlist_1->setFont(font);
        playlist_1->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        playlist_2 = new QLabel(widget);
        playlist_2->setObjectName("playlist_2");
        playlist_2->setGeometry(QRect(140, 60, 80, 50));
        playlist_2->setFont(font);
        playlist_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(138, 128, 30, 18));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(181, 181, 181, 128);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 3px;\n"
"font-size: 11px;\n"
"padding-left: 1px;"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(130, 54, 100, 100));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"background-image: url(:/new/prefix1/recommend/Pure-music.png);\n"
"background-position: center;\n"
""));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(240, 54, 100, 100));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"background-image: url(:/new/prefix1/recommend/Quaint-and-antique.png);\n"
"background-position: center;\n"
""));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(248, 128, 30, 18));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(181, 181, 181, 128);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 3px;\n"
"font-size: 11px;\n"
"padding-left: 1px;"));
        playlist_3 = new QLabel(widget);
        playlist_3->setObjectName("playlist_3");
        playlist_3->setGeometry(QRect(250, 60, 80, 50));
        playlist_3->setFont(font);
        playlist_3->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(350, 54, 100, 100));
        pushButton_4->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"background-image: url(:/new/prefix1/recommend/Romantic-moment.png);\n"
"background-position: center;\n"
""));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(358, 128, 30, 18));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgba(181, 181, 181, 128);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 3px;\n"
"font-size: 11px;\n"
"padding-left: 1px;"));
        playlist_4 = new QLabel(widget);
        playlist_4->setObjectName("playlist_4");
        playlist_4->setGeometry(QRect(360, 60, 80, 50));
        playlist_4->setFont(font);
        playlist_4->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_29 = new QLabel(widget);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(20, 10, 101, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(14);
        font2.setBold(true);
        label_29->setFont(font2);
        label_29->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(0, 0, 0);"));
        label_30 = new QLabel(widget);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(120, 15, 151, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font3.setPointSize(9);
        font3.setBold(true);
        label_30->setFont(font3);
        label_30->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(0, 0, 0);"));
        pushButton->raise();
        label->raise();
        playlist_1->raise();
        pushButton_2->raise();
        label_2->raise();
        playlist_2->raise();
        pushButton_3->raise();
        label_3->raise();
        playlist_3->raise();
        pushButton_4->raise();
        label_4->raise();
        playlist_4->raise();
        label_29->raise();
        label_30->raise();
        CarouselImage = new QLabel(TopWidget);
        CarouselImage->setObjectName("CarouselImage");
        CarouselImage->setGeometry(QRect(50, 20, 469, 173));
        CarouselImage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 12px;"));
        widget_3 = new QWidget(Recommend);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 210, 1065, 330));
        pushButton_5 = new QPushButton(widget_3);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(50, 62, 174, 239));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"background-image: url(:/new/prefix1/recommend/Selected-1.png);\n"
"background-position: center;\n"
"\n"
""));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 20, 101, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font4.setPointSize(13);
        font4.setBold(true);
        label_5->setFont(font4);
        label_6 = new QLabel(widget_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 72, 101, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font5.setPointSize(12);
        font5.setBold(true);
        label_6->setFont(font5);
        label_6->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        Selected_1 = new QLabel(widget_3);
        Selected_1->setObjectName("Selected_1");
        Selected_1->setGeometry(QRect(50, 236, 174, 65));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font6.setPointSize(10);
        Selected_1->setFont(font6);
        Selected_1->setCursor(QCursor(Qt::PointingHandCursor));
        Selected_1->setStyleSheet(QString::fromUtf8("background-color: rgba(28, 36, 56, 0.3);\n"
"color: rgb(255, 255, 255);\n"
"border-bottom-left-radius: 12px;  /* \345\267\246\344\270\213\350\247\222 */\n"
"border-bottom-right-radius: 12px; /* \345\217\263\344\270\213\350\247\222 */\n"
"padding-left: 10px;\n"
"padding-right: 10px;\n"
"padding-top: 2px;"));
        Selected_2 = new QLabel(widget_3);
        Selected_2->setObjectName("Selected_2");
        Selected_2->setGeometry(QRect(249, 236, 174, 65));
        Selected_2->setFont(font6);
        Selected_2->setCursor(QCursor(Qt::PointingHandCursor));
        Selected_2->setStyleSheet(QString::fromUtf8("background-color: rgba(28, 36, 56, 0.3);\n"
"color: rgb(255, 255, 255);\n"
"border-bottom-left-radius: 12px;  /* \345\267\246\344\270\213\350\247\222 */\n"
"border-bottom-right-radius: 12px; /* \345\217\263\344\270\213\350\247\222 */\n"
"padding-left: 10px;\n"
"padding-right: 10px;\n"
"padding-top: 2px;"));
        pushButton_6 = new QPushButton(widget_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(249, 62, 174, 239));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QString::fromUtf8("border-radius: 12px;  /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    background-image: url(:/new/prefix1/recommend/Selected-2.png);  /* \350\256\276\347\275\256\350\203\214\346\231\257\345\233\276\347\211\207 */\n"
"    background-position: center;  /* \350\203\214\346\231\257\345\233\276\347\211\207\345\261\205\344\270\255 */\n"
"    background-repeat: no-repeat;  /* \350\203\214\346\231\257\345\233\276\347\211\207\344\270\215\351\207\215\345\244\215 */\n"
"    background-size: cover;  /* \350\203\214\346\231\257\345\233\276\347\211\207\350\246\206\347\233\226\346\225\264\344\270\252\346\216\247\344\273\266\357\274\214\344\277\235\346\214\201\345\241\253\345\205\205 */"));
        label_7 = new QLabel(widget_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(259, 72, 101, 31));
        label_7->setFont(font5);
        label_7->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_8 = new QLabel(widget_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(458, 72, 101, 31));
        label_8->setFont(font5);
        label_8->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        pushButton_7 = new QPushButton(widget_3);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(448, 62, 174, 239));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"background-image: url(:/new/prefix1/recommend/Selected-3.png);\n"
"background-position: center;"));
        Selected_3 = new QLabel(widget_3);
        Selected_3->setObjectName("Selected_3");
        Selected_3->setGeometry(QRect(448, 236, 174, 65));
        Selected_3->setFont(font6);
        Selected_3->setCursor(QCursor(Qt::PointingHandCursor));
        Selected_3->setStyleSheet(QString::fromUtf8("background-color: rgba(28, 36, 56, 0.3);\n"
"color: rgb(255, 255, 255);\n"
"border-bottom-left-radius: 12px;  /* \345\267\246\344\270\213\350\247\222 */\n"
"border-bottom-right-radius: 12px; /* \345\217\263\344\270\213\350\247\222 */\n"
"padding-left: 10px;\n"
"padding-right: 10px;\n"
"padding-top: 2px;"));
        pushButton_8 = new QPushButton(widget_3);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(647, 62, 174, 239));
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_8->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"background-image: url(:/new/prefix1/recommend/Selected-4.png);\n"
"background-position: center;"));
        Selected_4 = new QLabel(widget_3);
        Selected_4->setObjectName("Selected_4");
        Selected_4->setGeometry(QRect(647, 236, 174, 65));
        Selected_4->setFont(font6);
        Selected_4->setCursor(QCursor(Qt::PointingHandCursor));
        Selected_4->setStyleSheet(QString::fromUtf8("background-color: rgba(28, 36, 56, 0.3);\n"
"color: rgb(255, 255, 255);\n"
"border-bottom-left-radius: 12px;  /* \345\267\246\344\270\213\350\247\222 */\n"
"border-bottom-right-radius: 12px; /* \345\217\263\344\270\213\350\247\222 */\n"
"padding-left: 10px;\n"
"padding-right: 10px;\n"
"padding-top: 2px;"));
        label_9 = new QLabel(widget_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(657, 72, 101, 31));
        label_9->setFont(font5);
        label_9->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        pushButton_9 = new QPushButton(widget_3);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(846, 62, 174, 239));
        pushButton_9->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_9->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"background-image: url(:/new/prefix1/recommend/Selected-5.png);\n"
"background-position: center;"));
        Selected_5 = new QLabel(widget_3);
        Selected_5->setObjectName("Selected_5");
        Selected_5->setGeometry(QRect(846, 236, 174, 65));
        Selected_5->setFont(font6);
        Selected_5->setCursor(QCursor(Qt::PointingHandCursor));
        Selected_5->setStyleSheet(QString::fromUtf8("background-color: rgba(28, 36, 56, 0.3);\n"
"color: rgb(255, 255, 255);\n"
"border-bottom-left-radius: 12px;  /* \345\267\246\344\270\213\350\247\222 */\n"
"border-bottom-right-radius: 12px; /* \345\217\263\344\270\213\350\247\222 */\n"
"padding-left: 10px;\n"
"padding-right: 10px;\n"
"padding-top: 2px;"));
        label_10 = new QLabel(widget_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(856, 72, 101, 31));
        label_10->setFont(font5);
        label_10->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        pushButton_5->raise();
        label_5->raise();
        label_6->raise();
        Selected_1->raise();
        pushButton_6->raise();
        label_7->raise();
        Selected_2->raise();
        pushButton_7->raise();
        Selected_3->raise();
        label_8->raise();
        pushButton_8->raise();
        Selected_4->raise();
        label_9->raise();
        pushButton_9->raise();
        Selected_5->raise();
        label_10->raise();
        widget_4 = new QWidget(Recommend);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(0, 540, 1065, 330));
        pushButton_20 = new QPushButton(widget_4);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(50, 62, 174, 239));
        pushButton_20->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_20->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"background-image: url(:/new/prefix1/recommend/Selected-6.png);\n"
"background-position: center;"));
        label_23 = new QLabel(widget_4);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(50, 20, 101, 31));
        label_23->setFont(font4);
        label_24 = new QLabel(widget_4);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(120, 70, 91, 20));
        label_24->setFont(font3);
        label_24->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        Selected_16 = new QLabel(widget_4);
        Selected_16->setObjectName("Selected_16");
        Selected_16->setGeometry(QRect(50, 236, 174, 65));
        Selected_16->setFont(font6);
        Selected_16->setCursor(QCursor(Qt::PointingHandCursor));
        Selected_16->setStyleSheet(QString::fromUtf8("background-color: rgba(28, 36, 56, 0.3);\n"
"color: rgb(255, 255, 255);\n"
"border-bottom-left-radius: 12px;  /* \345\267\246\344\270\213\350\247\222 */\n"
"border-bottom-right-radius: 12px; /* \345\217\263\344\270\213\350\247\222 */\n"
"padding-left: 10px;\n"
"padding-right: 10px;\n"
"padding-top: 2px;"));
        Selected_17 = new QLabel(widget_4);
        Selected_17->setObjectName("Selected_17");
        Selected_17->setGeometry(QRect(249, 236, 174, 65));
        Selected_17->setFont(font6);
        Selected_17->setCursor(QCursor(Qt::PointingHandCursor));
        Selected_17->setStyleSheet(QString::fromUtf8("background-color: rgba(28, 36, 56, 0.3);\n"
"color: rgb(255, 255, 255);\n"
"border-bottom-left-radius: 12px;  /* \345\267\246\344\270\213\350\247\222 */\n"
"border-bottom-right-radius: 12px; /* \345\217\263\344\270\213\350\247\222 */\n"
"padding-left: 10px;\n"
"padding-right: 10px;\n"
"padding-top: 2px;"));
        pushButton_21 = new QPushButton(widget_4);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(249, 62, 174, 239));
        pushButton_21->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_21->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"background-image: url(:/new/prefix1/recommend/Selected-7.png);\n"
"background-position: center;"));
        pushButton_22 = new QPushButton(widget_4);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(448, 62, 174, 239));
        pushButton_22->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_22->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"background-image: url(:/new/prefix1/recommend/Selected-8.png);\n"
"background-position: center;  /* \350\203\214\346\231\257\345\233\276\347\211\207\345\261\205\344\270\255 */\n"
"    background-repeat: no-repeat;  /* \344\270\215\351\207\215\345\244\215\345\233\276\347\211\207 */\n"
"    background-size: 50% 50%;      /* \345\260\206\350\203\214\346\231\257\345\233\276\347\211\207\347\274\251\345\260\217\345\210\260\346\216\247\344\273\266\347\232\204 50% */"));
        Selected_18 = new QLabel(widget_4);
        Selected_18->setObjectName("Selected_18");
        Selected_18->setGeometry(QRect(448, 236, 174, 65));
        Selected_18->setFont(font6);
        Selected_18->setCursor(QCursor(Qt::PointingHandCursor));
        Selected_18->setStyleSheet(QString::fromUtf8("background-color: rgba(28, 36, 56, 0.3);\n"
"color: rgb(255, 255, 255);\n"
"border-bottom-left-radius: 12px;  /* \345\267\246\344\270\213\350\247\222 */\n"
"border-bottom-right-radius: 12px; /* \345\217\263\344\270\213\350\247\222 */\n"
"padding-left: 10px;\n"
"padding-right: 10px;\n"
"padding-top: 2px;"));
        pushButton_23 = new QPushButton(widget_4);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(647, 62, 174, 239));
        pushButton_23->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_23->setStyleSheet(QString::fromUtf8("border-radius: 12px;  /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    background-image: url(:/new/prefix1/recommend/Selected-9.png);  /* \350\256\276\347\275\256\350\203\214\346\231\257\345\233\276\347\211\207 */\n"
"    background-position: center;  /* \350\203\214\346\231\257\345\233\276\347\211\207\345\261\205\344\270\255 */\n"
"    background-repeat: no-repeat;  /* \350\203\214\346\231\257\345\233\276\347\211\207\344\270\215\351\207\215\345\244\215 */\n"
"    background-size: cover;  /* \350\203\214\346\231\257\345\233\276\347\211\207\350\246\206\347\233\226\346\225\264\344\270\252\346\216\247\344\273\266\357\274\214\344\277\235\346\214\201\345\241\253\345\205\205 */"));
        Selected_19 = new QLabel(widget_4);
        Selected_19->setObjectName("Selected_19");
        Selected_19->setGeometry(QRect(647, 236, 174, 65));
        Selected_19->setFont(font6);
        Selected_19->setCursor(QCursor(Qt::PointingHandCursor));
        Selected_19->setStyleSheet(QString::fromUtf8("background-color: rgba(28, 36, 56, 0.3);\n"
"color: rgb(255, 255, 255);\n"
"border-bottom-left-radius: 12px;  /* \345\267\246\344\270\213\350\247\222 */\n"
"border-bottom-right-radius: 12px; /* \345\217\263\344\270\213\350\247\222 */\n"
"padding-left: 10px;\n"
"padding-right: 10px;\n"
"padding-top: 2px;"));
        pushButton_24 = new QPushButton(widget_4);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(846, 62, 174, 239));
        pushButton_24->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_24->setStyleSheet(QString::fromUtf8("border-radius: 12px;\n"
"background-image: url(:/new/prefix1/recommend/Selected-10.png);"));
        Selected_20 = new QLabel(widget_4);
        Selected_20->setObjectName("Selected_20");
        Selected_20->setGeometry(QRect(846, 236, 174, 65));
        Selected_20->setFont(font6);
        Selected_20->setCursor(QCursor(Qt::PointingHandCursor));
        Selected_20->setStyleSheet(QString::fromUtf8("background-color: rgba(28, 36, 56, 0.3);\n"
"color: rgb(255, 255, 255);\n"
"border-bottom-left-radius: 12px;  /* \345\267\246\344\270\213\350\247\222 */\n"
"border-bottom-right-radius: 12px; /* \345\217\263\344\270\213\350\247\222 */\n"
"padding-left: 10px;\n"
"padding-right: 10px;\n"
"padding-top: 2px;"));
        label_25 = new QLabel(widget_4);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(330, 70, 81, 20));
        label_25->setFont(font3);
        label_25->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_26 = new QLabel(widget_4);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(540, 70, 71, 20));
        label_26->setFont(font3);
        label_26->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_27 = new QLabel(widget_4);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(730, 70, 81, 20));
        label_27->setFont(font3);
        label_27->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_28 = new QLabel(widget_4);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(930, 70, 81, 20));
        label_28->setFont(font3);
        label_28->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        pushButton_20->raise();
        label_23->raise();
        label_24->raise();
        Selected_16->raise();
        pushButton_21->raise();
        pushButton_22->raise();
        Selected_18->raise();
        pushButton_23->raise();
        Selected_19->raise();
        pushButton_24->raise();
        Selected_20->raise();
        Selected_17->raise();
        label_25->raise();
        label_26->raise();
        label_27->raise();
        label_28->raise();

        retranslateUi(Recommend);

        QMetaObject::connectSlotsByName(Recommend);
    } // setupUi

    void retranslateUi(QWidget *Recommend)
    {
        Recommend->setWindowTitle(QCoreApplication::translate("Recommend", "Form", nullptr));
        pushButton->setText(QString());
        label->setText(QCoreApplication::translate("Recommend", "\346\255\214\345\215\225", nullptr));
        playlist_1->setText(QCoreApplication::translate("Recommend", "\344\270\255\345\274\217\346\205\265\346\207\222", nullptr));
        playlist_2->setText(QCoreApplication::translate("Recommend", "\347\272\257\351\237\263\344\271\220", nullptr));
        label_2->setText(QCoreApplication::translate("Recommend", "\346\255\214\345\215\225", nullptr));
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        label_3->setText(QCoreApplication::translate("Recommend", "\346\255\214\345\215\225", nullptr));
        playlist_3->setText(QCoreApplication::translate("Recommend", "\345\217\244\350\211\262\345\217\244\351\246\231", nullptr));
        pushButton_4->setText(QString());
        label_4->setText(QCoreApplication::translate("Recommend", "\346\255\214\345\215\225", nullptr));
        playlist_4->setText(QCoreApplication::translate("Recommend", "\346\265\252\346\274\253\346\227\266\345\210\273", nullptr));
        label_29->setText(QCoreApplication::translate("Recommend", "\344\270\213\345\215\210\345\245\275\357\274\214", nullptr));
        label_30->setText(QCoreApplication::translate("Recommend", "\347\214\234\344\275\240\346\234\200\350\277\221\345\226\234\346\254\242\345\220\254", nullptr));
        CarouselImage->setText(QString());
        pushButton_5->setText(QString());
        label_5->setText(QCoreApplication::translate("Recommend", "\347\262\276\351\200\211\346\216\250\350\215\220", nullptr));
        label_6->setText(QCoreApplication::translate("Recommend", "\346\257\217\346\227\245\346\216\250\350\215\220", nullptr));
        Selected_1->setText(QCoreApplication::translate("Recommend", "\346\257\217\346\227\245\346\216\250\350\215\220 | \344\273\216[\351\235\236\350\212\261]\345\274\200\345\247\213\345\220\254", nullptr));
        Selected_2->setText(QCoreApplication::translate("Recommend", "\344\273\216[HEAVEN]\345\274\200\345\220\257\346\227\240\351\231\220\346\274\253\346\270\270", nullptr));
        pushButton_6->setText(QString());
        label_7->setText(QCoreApplication::translate("Recommend", "\347\247\201\344\272\272\346\274\253\346\270\270", nullptr));
        label_8->setText(QCoreApplication::translate("Recommend", "\347\247\201\344\272\272\351\233\267\350\276\276", nullptr));
        pushButton_7->setText(QString());
        Selected_3->setText(QCoreApplication::translate("Recommend", "\344\273\212\345\244\251[\347\210\261\347\232\204\351\255\224\346\263\225]\347\210\261\344\270\215\351\207\212\350\200\263", nullptr));
        pushButton_8->setText(QString());
        Selected_4->setText(QCoreApplication::translate("Recommend", "\345\244\247\347\237\263\347\242\216\350\203\270\345\217\243\343\200\201\351\202\243\345\271\264\345\271\264\345\260\221\343\200\201\351\270\263\351\270\257\345\200\272", nullptr));
        label_9->setText(QCoreApplication::translate("Recommend", "\346\221\207\346\273\232\346\227\245\346\216\250", nullptr));
        pushButton_9->setText(QString());
        Selected_5->setText(QCoreApplication::translate("Recommend", "\346\230\237\347\251\272\346\274\253\346\270\270 | \346\216\242\347\264\242\351\202\243\347\222\200\347\222\250\347\232\204\346\230\237\346\262\263\347\203\202\346\274\253", nullptr));
        label_10->setText(QCoreApplication::translate("Recommend", "\346\230\237\347\251\272\346\274\253\346\270\270", nullptr));
        pushButton_20->setText(QString());
        label_23->setText(QCoreApplication::translate("Recommend", "\346\216\250\350\215\220\346\255\214\345\215\225", nullptr));
        label_24->setText(QCoreApplication::translate("Recommend", "\360\237\216\2471714.4\344\270\207", nullptr));
        Selected_16->setText(QCoreApplication::translate("Recommend", "\347\275\221\346\230\223\344\272\221\346\234\200\345\245\275\345\220\254\347\203\255\346\255\214188\351\246\226\346\216\250\350\215\220", nullptr));
        Selected_17->setText(QCoreApplication::translate("Recommend", "\345\215\216\350\257\255\347\273\217\345\205\270|\345\261\236\344\272\2168090\347\232\204\347\276\216\345\245\275\345\233\236\345\277\206", nullptr));
        pushButton_21->setText(QString());
        pushButton_22->setText(QString());
        Selected_18->setText(QCoreApplication::translate("Recommend", "\345\245\263\345\227\223\347\273\235\345\257\271\347\202\270\350\243\202\357\274\201\345\277\205\347\202\271KTV\345\245\263\347\245\236\346\233\262", nullptr));
        pushButton_23->setText(QString());
        Selected_19->setText(QCoreApplication::translate("Recommend", "\345\270\246\344\270\212\350\200\263\346\234\272\357\274\214\344\270\226\347\225\214\344\270\216\346\210\221\346\227\240\345\205\263", nullptr));
        pushButton_24->setText(QString());
        Selected_20->setText(QCoreApplication::translate("Recommend", "\343\200\220\345\215\216\350\257\255\350\266\205\347\224\234\343\200\221\347\231\276\345\220\254\344\270\215\345\216\214\357\274\214\346\227\240\351\231\220\345\276\252\347\216\257", nullptr));
        label_25->setText(QCoreApplication::translate("Recommend", "\360\237\216\247499.5\344\270\207", nullptr));
        label_26->setText(QCoreApplication::translate("Recommend", "\360\237\216\24764048", nullptr));
        label_27->setText(QCoreApplication::translate("Recommend", "\360\237\216\247222.2\344\270\207", nullptr));
        label_28->setText(QCoreApplication::translate("Recommend", "\360\237\216\247526.8\344\270\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Recommend: public Ui_Recommend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOMMEND_H
