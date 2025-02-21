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
    QPushButton *MonthlyMembership;
    QPushButton *QuarterlyMembership;
    QPushButton *AnnualMembership;
    QPushButton *purchase;

    void setupUi(QWidget *PurchaseMembership)
    {
        if (PurchaseMembership->objectName().isEmpty())
            PurchaseMembership->setObjectName("PurchaseMembership");
        PurchaseMembership->resize(490, 300);
        MonthlyMembership = new QPushButton(PurchaseMembership);
        MonthlyMembership->setObjectName("MonthlyMembership");
        MonthlyMembership->setGeometry(QRect(10, 30, 150, 171));
        MonthlyMembership->setStyleSheet(QString::fromUtf8("background-color: lightgray;"));
        QuarterlyMembership = new QPushButton(PurchaseMembership);
        QuarterlyMembership->setObjectName("QuarterlyMembership");
        QuarterlyMembership->setGeometry(QRect(170, 30, 150, 171));
        QuarterlyMembership->setStyleSheet(QString::fromUtf8("background-color: lightgray;"));
        AnnualMembership = new QPushButton(PurchaseMembership);
        AnnualMembership->setObjectName("AnnualMembership");
        AnnualMembership->setGeometry(QRect(330, 30, 150, 171));
        AnnualMembership->setStyleSheet(QString::fromUtf8("background-color: lightgray;"));
        purchase = new QPushButton(PurchaseMembership);
        purchase->setObjectName("purchase");
        purchase->setGeometry(QRect(195, 225, 100, 50));

        retranslateUi(PurchaseMembership);

        QMetaObject::connectSlotsByName(PurchaseMembership);
    } // setupUi

    void retranslateUi(QWidget *PurchaseMembership)
    {
        PurchaseMembership->setWindowTitle(QCoreApplication::translate("PurchaseMembership", "Form", nullptr));
        MonthlyMembership->setText(QCoreApplication::translate("PurchaseMembership", "\346\234\210\345\272\246\344\274\232\345\221\230(100\357\277\245)", nullptr));
        QuarterlyMembership->setText(QCoreApplication::translate("PurchaseMembership", "\345\255\243\345\272\246\344\274\232\345\221\230(300\357\277\245)", nullptr));
        AnnualMembership->setText(QCoreApplication::translate("PurchaseMembership", "\345\271\264\345\272\246\344\274\232\345\221\230(1200\357\277\245)", nullptr));
        purchase->setText(QCoreApplication::translate("PurchaseMembership", "\350\264\255\344\271\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PurchaseMembership: public Ui_PurchaseMembership {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASEMEMBERSHIP_H
