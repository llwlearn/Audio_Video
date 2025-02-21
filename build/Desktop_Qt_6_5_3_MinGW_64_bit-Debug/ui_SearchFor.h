/********************************************************************************
** Form generated from reading UI file 'SearchFor.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHFOR_H
#define UI_SEARCHFOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchFor
{
public:
    QFrame *line;
    QListWidget *listWidget;
    QLabel *label;

    void setupUi(QWidget *SearchFor)
    {
        if (SearchFor->objectName().isEmpty())
            SearchFor->setObjectName("SearchFor");
        SearchFor->resize(1280, 850);
        SearchFor->setStyleSheet(QString::fromUtf8(""));
        line = new QFrame(SearchFor);
        line->setObjectName("line");
        line->setGeometry(QRect(60, 85, 1200, 2));
        line->setStyleSheet(QString::fromUtf8("border:  none;\n"
"background-color: rgb(240, 243, 246);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        listWidget = new QListWidget(SearchFor);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(40, 100, 1200, 750));
        listWidget->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(SearchFor);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 40, 1200, 30));

        retranslateUi(SearchFor);

        QMetaObject::connectSlotsByName(SearchFor);
    } // setupUi

    void retranslateUi(QWidget *SearchFor)
    {
        SearchFor->setWindowTitle(QCoreApplication::translate("SearchFor", "Form", nullptr));
        label->setText(QCoreApplication::translate("SearchFor", "#          \346\240\207\351\242\230                                                                        \346\255\214\346\211\213                                                                                 \345\226\234\346\254\242                     \346\227\266\351\225\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchFor: public Ui_SearchFor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFOR_H
