/********************************************************************************
** Form generated from reading UI file 'PurchaseMembership.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASEMEMBERSHIP_H
#define UI_PURCHASEMEMBERSHIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PurchaseMembership
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *PurchaseMembership)
    {
        if (PurchaseMembership->objectName().isEmpty())
            PurchaseMembership->setObjectName("PurchaseMembership");
        PurchaseMembership->resize(490, 300);
        pushButton = new QPushButton(PurchaseMembership);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 30, 150, 171));
        pushButton_2 = new QPushButton(PurchaseMembership);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(170, 30, 150, 171));
        pushButton_3 = new QPushButton(PurchaseMembership);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(330, 30, 150, 171));
        pushButton_4 = new QPushButton(PurchaseMembership);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(195, 225, 100, 50));

        retranslateUi(PurchaseMembership);

        QMetaObject::connectSlotsByName(PurchaseMembership);
    } // setupUi

    void retranslateUi(QWidget *PurchaseMembership)
    {
        PurchaseMembership->setWindowTitle(QCoreApplication::translate("PurchaseMembership", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("PurchaseMembership", "\346\234\210\345\272\246\344\274\232\345\221\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PurchaseMembership", "\345\255\243\345\272\246\344\274\232\345\221\230", nullptr));
        pushButton_3->setText(QCoreApplication::translate("PurchaseMembership", "\345\271\264\345\272\246\344\274\232\345\221\230", nullptr));
        pushButton_4->setText(QCoreApplication::translate("PurchaseMembership", "\350\264\255\344\271\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PurchaseMembership: public Ui_PurchaseMembership {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASEMEMBERSHIP_H
