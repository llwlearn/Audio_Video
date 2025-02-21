/********************************************************************************
** Form generated from reading UI file 'Download.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOAD_H
#define UI_DOWNLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Download
{
public:
    QFrame *line;
    QListWidget *listWidget;
    QPushButton *Refresh;
    QLabel *label_2;

    void setupUi(QWidget *Download)
    {
        if (Download->objectName().isEmpty())
            Download->setObjectName("Download");
        Download->resize(1280, 850);
        Download->setStyleSheet(QString::fromUtf8(""));
        line = new QFrame(Download);
        line->setObjectName("line");
        line->setGeometry(QRect(60, 85, 1200, 2));
        line->setStyleSheet(QString::fromUtf8("border:  none;\n"
"background-color: rgb(240, 243, 246);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        listWidget = new QListWidget(Download);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(40, 100, 1200, 750));
        listWidget->setStyleSheet(QString::fromUtf8(""));
        Refresh = new QPushButton(Download);
        Refresh->setObjectName("Refresh");
        Refresh->setGeometry(QRect(1220, 45, 51, 24));
        Refresh->setCursor(QCursor(Qt::PointingHandCursor));
        label_2 = new QLabel(Download);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 40, 1200, 30));
        line->raise();
        listWidget->raise();
        label_2->raise();
        Refresh->raise();

        retranslateUi(Download);

        QMetaObject::connectSlotsByName(Download);
    } // setupUi

    void retranslateUi(QWidget *Download)
    {
        Download->setWindowTitle(QCoreApplication::translate("Download", "Form", nullptr));
        Refresh->setText(QCoreApplication::translate("Download", "\345\210\267\346\226\260", nullptr));
        label_2->setText(QCoreApplication::translate("Download", "#          \346\240\207\351\242\230                                                                        \346\255\214\346\211\213                                                                                                            \346\227\266\351\225\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Download: public Ui_Download {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOAD_H
