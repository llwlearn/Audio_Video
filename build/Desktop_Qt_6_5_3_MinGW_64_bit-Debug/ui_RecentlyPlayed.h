/********************************************************************************
** Form generated from reading UI file 'RecentlyPlayed.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECENTLYPLAYED_H
#define UI_RECENTLYPLAYED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecentlyPlayed
{
public:
    QFrame *line;
    QLabel *label;
    QListWidget *listWidget;

    void setupUi(QWidget *RecentlyPlayed)
    {
        if (RecentlyPlayed->objectName().isEmpty())
            RecentlyPlayed->setObjectName("RecentlyPlayed");
        RecentlyPlayed->resize(1280, 850);
        line = new QFrame(RecentlyPlayed);
        line->setObjectName("line");
        line->setGeometry(QRect(60, 85, 1200, 2));
        line->setStyleSheet(QString::fromUtf8("border:  none;\n"
"background-color: rgb(240, 243, 246);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(RecentlyPlayed);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 40, 1200, 30));
        listWidget = new QListWidget(RecentlyPlayed);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(40, 100, 1200, 750));
        listWidget->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(RecentlyPlayed);

        QMetaObject::connectSlotsByName(RecentlyPlayed);
    } // setupUi

    void retranslateUi(QWidget *RecentlyPlayed)
    {
        RecentlyPlayed->setWindowTitle(QCoreApplication::translate("RecentlyPlayed", "Form", nullptr));
        label->setText(QCoreApplication::translate("RecentlyPlayed", "#          \346\240\207\351\242\230                                                                        \346\255\214\346\211\213                                                                                 \345\226\234\346\254\242                     \346\227\266\351\225\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecentlyPlayed: public Ui_RecentlyPlayed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECENTLYPLAYED_H
