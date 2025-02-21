/********************************************************************************
** Form generated from reading UI file 'PlayList.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLIST_H
#define UI_PLAYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayList
{
public:
    QWidget *TopWidget;
    QLabel *label;
    QPushButton *clear;
    QListWidget *listWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *PlayList)
    {
        if (PlayList->objectName().isEmpty())
            PlayList->setObjectName("PlayList");
        PlayList->resize(500, 800);
        PlayList->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        TopWidget = new QWidget(PlayList);
        TopWidget->setObjectName("TopWidget");
        TopWidget->setGeometry(QRect(0, 0, 500, 70));
        TopWidget->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(TopWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 111, 30));
        label->setStyleSheet(QString::fromUtf8("font-size: 25px;"));
        clear = new QPushButton(TopWidget);
        clear->setObjectName("clear");
        clear->setGeometry(QRect(420, 30, 60, 30));
        clear->setCursor(QCursor(Qt::PointingHandCursor));
        clear->setStyleSheet(QString::fromUtf8("border: none;\n"
"font-size: 22px;"));
        listWidget = new QListWidget(PlayList);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(0, 70, 500, 730));
        listWidget->setStyleSheet(QString::fromUtf8("border: none;"));
        verticalLayoutWidget = new QWidget(PlayList);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(-1, 69, 501, 731));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(PlayList);

        QMetaObject::connectSlotsByName(PlayList);
    } // setupUi

    void retranslateUi(QWidget *PlayList)
    {
        PlayList->setWindowTitle(QCoreApplication::translate("PlayList", "Form", nullptr));
        label->setText(QCoreApplication::translate("PlayList", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        clear->setText(QCoreApplication::translate("PlayList", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayList: public Ui_PlayList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLIST_H
