/********************************************************************************
** Form generated from reading UI file 'PersonalInformation.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONALINFORMATION_H
#define UI_PERSONALINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonalInformation
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *nicknameLineEdit;
    QTextEdit *brief_introductionTextEdit;
    QRadioButton *maleRadioButton;
    QRadioButton *femaleRadioButton;
    QComboBox *yearComboBox;
    QComboBox *monthComboBox;
    QComboBox *dayComboBox;
    QComboBox *cityComboBox;
    QComboBox *provinceComboBox;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QWidget *widget;

    void setupUi(QWidget *PersonalInformation)
    {
        if (PersonalInformation->objectName().isEmpty())
            PersonalInformation->setObjectName("PersonalInformation");
        PersonalInformation->resize(1280, 850);
        PersonalInformation->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(PersonalInformation);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 60, 171, 41));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font-size: 25px;"));
        label_2 = new QLabel(PersonalInformation);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 130, 51, 31));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 18px;"));
        label_3 = new QLabel(PersonalInformation);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 190, 51, 31));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 18px;"));
        label_4 = new QLabel(PersonalInformation);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 460, 51, 31));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 18px;"));
        label_5 = new QLabel(PersonalInformation);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 540, 51, 31));
        label_5->setStyleSheet(QString::fromUtf8("font-size: 18px;"));
        label_6 = new QLabel(PersonalInformation);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 590, 61, 31));
        label_6->setStyleSheet(QString::fromUtf8("font-size: 18px;"));
        nicknameLineEdit = new QLineEdit(PersonalInformation);
        nicknameLineEdit->setObjectName("nicknameLineEdit");
        nicknameLineEdit->setGeometry(QRect(130, 130, 681, 51));
        brief_introductionTextEdit = new QTextEdit(PersonalInformation);
        brief_introductionTextEdit->setObjectName("brief_introductionTextEdit");
        brief_introductionTextEdit->setGeometry(QRect(130, 200, 681, 231));
        maleRadioButton = new QRadioButton(PersonalInformation);
        maleRadioButton->setObjectName("maleRadioButton");
        maleRadioButton->setGeometry(QRect(130, 460, 41, 22));
        maleRadioButton->setCursor(QCursor(Qt::PointingHandCursor));
        femaleRadioButton = new QRadioButton(PersonalInformation);
        femaleRadioButton->setObjectName("femaleRadioButton");
        femaleRadioButton->setGeometry(QRect(210, 460, 41, 22));
        femaleRadioButton->setCursor(QCursor(Qt::PointingHandCursor));
        yearComboBox = new QComboBox(PersonalInformation);
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->addItem(QString());
        yearComboBox->setObjectName("yearComboBox");
        yearComboBox->setGeometry(QRect(130, 530, 151, 41));
        yearComboBox->setCursor(QCursor(Qt::PointingHandCursor));
        monthComboBox = new QComboBox(PersonalInformation);
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->setObjectName("monthComboBox");
        monthComboBox->setGeometry(QRect(400, 530, 151, 41));
        monthComboBox->setCursor(QCursor(Qt::PointingHandCursor));
        dayComboBox = new QComboBox(PersonalInformation);
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->addItem(QString());
        dayComboBox->setObjectName("dayComboBox");
        dayComboBox->setGeometry(QRect(660, 530, 151, 41));
        dayComboBox->setCursor(QCursor(Qt::PointingHandCursor));
        cityComboBox = new QComboBox(PersonalInformation);
        cityComboBox->setObjectName("cityComboBox");
        cityComboBox->setGeometry(QRect(400, 590, 151, 41));
        cityComboBox->setCursor(QCursor(Qt::PointingHandCursor));
        provinceComboBox = new QComboBox(PersonalInformation);
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->addItem(QString());
        provinceComboBox->setObjectName("provinceComboBox");
        provinceComboBox->setGeometry(QRect(130, 590, 151, 41));
        provinceComboBox->setCursor(QCursor(Qt::PointingHandCursor));
        saveButton = new QPushButton(PersonalInformation);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(230, 680, 121, 51));
        saveButton->setCursor(QCursor(Qt::PointingHandCursor));
        cancelButton = new QPushButton(PersonalInformation);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(520, 680, 121, 51));
        cancelButton->setCursor(QCursor(Qt::PointingHandCursor));
        widget = new QWidget(PersonalInformation);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1280, 850));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 249, 252);"));
        widget->raise();
        label_2->raise();
        nicknameLineEdit->raise();
        yearComboBox->raise();
        brief_introductionTextEdit->raise();
        maleRadioButton->raise();
        label_6->raise();
        label_4->raise();
        label_3->raise();
        label_5->raise();
        saveButton->raise();
        femaleRadioButton->raise();
        monthComboBox->raise();
        label->raise();
        cityComboBox->raise();
        cancelButton->raise();
        provinceComboBox->raise();
        dayComboBox->raise();

        retranslateUi(PersonalInformation);

        QMetaObject::connectSlotsByName(PersonalInformation);
    } // setupUi

    void retranslateUi(QWidget *PersonalInformation)
    {
        PersonalInformation->setWindowTitle(QCoreApplication::translate("PersonalInformation", "Form", nullptr));
        label->setText(QCoreApplication::translate("PersonalInformation", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("PersonalInformation", "\346\230\265\347\247\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("PersonalInformation", "\347\256\200\344\273\213\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("PersonalInformation", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("PersonalInformation", "\347\224\237\346\227\245\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("PersonalInformation", "\345\234\260\345\214\272\357\274\232", nullptr));
        maleRadioButton->setText(QCoreApplication::translate("PersonalInformation", "\347\224\267", nullptr));
        femaleRadioButton->setText(QCoreApplication::translate("PersonalInformation", "\345\245\263", nullptr));
        yearComboBox->setItemText(0, QCoreApplication::translate("PersonalInformation", "2000", nullptr));
        yearComboBox->setItemText(1, QCoreApplication::translate("PersonalInformation", "2001", nullptr));
        yearComboBox->setItemText(2, QCoreApplication::translate("PersonalInformation", "2002", nullptr));
        yearComboBox->setItemText(3, QCoreApplication::translate("PersonalInformation", "2003", nullptr));
        yearComboBox->setItemText(4, QCoreApplication::translate("PersonalInformation", "2004", nullptr));
        yearComboBox->setItemText(5, QCoreApplication::translate("PersonalInformation", "2005", nullptr));
        yearComboBox->setItemText(6, QCoreApplication::translate("PersonalInformation", "2006", nullptr));
        yearComboBox->setItemText(7, QCoreApplication::translate("PersonalInformation", "2007", nullptr));
        yearComboBox->setItemText(8, QCoreApplication::translate("PersonalInformation", "2008", nullptr));
        yearComboBox->setItemText(9, QCoreApplication::translate("PersonalInformation", "2009", nullptr));
        yearComboBox->setItemText(10, QCoreApplication::translate("PersonalInformation", "2010", nullptr));
        yearComboBox->setItemText(11, QCoreApplication::translate("PersonalInformation", "2011", nullptr));
        yearComboBox->setItemText(12, QCoreApplication::translate("PersonalInformation", "2012", nullptr));
        yearComboBox->setItemText(13, QCoreApplication::translate("PersonalInformation", "2013", nullptr));
        yearComboBox->setItemText(14, QCoreApplication::translate("PersonalInformation", "2014", nullptr));
        yearComboBox->setItemText(15, QCoreApplication::translate("PersonalInformation", "2015", nullptr));
        yearComboBox->setItemText(16, QCoreApplication::translate("PersonalInformation", "2016", nullptr));
        yearComboBox->setItemText(17, QCoreApplication::translate("PersonalInformation", "2017", nullptr));
        yearComboBox->setItemText(18, QCoreApplication::translate("PersonalInformation", "2018", nullptr));
        yearComboBox->setItemText(19, QCoreApplication::translate("PersonalInformation", "2019", nullptr));
        yearComboBox->setItemText(20, QCoreApplication::translate("PersonalInformation", "2020", nullptr));
        yearComboBox->setItemText(21, QCoreApplication::translate("PersonalInformation", "2021", nullptr));
        yearComboBox->setItemText(22, QCoreApplication::translate("PersonalInformation", "2022", nullptr));
        yearComboBox->setItemText(23, QCoreApplication::translate("PersonalInformation", "2023", nullptr));
        yearComboBox->setItemText(24, QCoreApplication::translate("PersonalInformation", "2024", nullptr));
        yearComboBox->setItemText(25, QCoreApplication::translate("PersonalInformation", "2025", nullptr));

        monthComboBox->setItemText(0, QCoreApplication::translate("PersonalInformation", "1", nullptr));
        monthComboBox->setItemText(1, QCoreApplication::translate("PersonalInformation", "2", nullptr));
        monthComboBox->setItemText(2, QCoreApplication::translate("PersonalInformation", "3", nullptr));
        monthComboBox->setItemText(3, QCoreApplication::translate("PersonalInformation", "4", nullptr));
        monthComboBox->setItemText(4, QCoreApplication::translate("PersonalInformation", "5", nullptr));
        monthComboBox->setItemText(5, QCoreApplication::translate("PersonalInformation", "6", nullptr));
        monthComboBox->setItemText(6, QCoreApplication::translate("PersonalInformation", "7", nullptr));
        monthComboBox->setItemText(7, QCoreApplication::translate("PersonalInformation", "8", nullptr));
        monthComboBox->setItemText(8, QCoreApplication::translate("PersonalInformation", "9", nullptr));
        monthComboBox->setItemText(9, QCoreApplication::translate("PersonalInformation", "10", nullptr));
        monthComboBox->setItemText(10, QCoreApplication::translate("PersonalInformation", "11", nullptr));
        monthComboBox->setItemText(11, QCoreApplication::translate("PersonalInformation", "12", nullptr));

        dayComboBox->setItemText(0, QCoreApplication::translate("PersonalInformation", "1", nullptr));
        dayComboBox->setItemText(1, QCoreApplication::translate("PersonalInformation", "2", nullptr));
        dayComboBox->setItemText(2, QCoreApplication::translate("PersonalInformation", "3", nullptr));
        dayComboBox->setItemText(3, QCoreApplication::translate("PersonalInformation", "4", nullptr));
        dayComboBox->setItemText(4, QCoreApplication::translate("PersonalInformation", "5", nullptr));
        dayComboBox->setItemText(5, QCoreApplication::translate("PersonalInformation", "6", nullptr));
        dayComboBox->setItemText(6, QCoreApplication::translate("PersonalInformation", "7", nullptr));
        dayComboBox->setItemText(7, QCoreApplication::translate("PersonalInformation", "8", nullptr));
        dayComboBox->setItemText(8, QCoreApplication::translate("PersonalInformation", "9", nullptr));
        dayComboBox->setItemText(9, QCoreApplication::translate("PersonalInformation", "10", nullptr));
        dayComboBox->setItemText(10, QCoreApplication::translate("PersonalInformation", "11", nullptr));
        dayComboBox->setItemText(11, QCoreApplication::translate("PersonalInformation", "12", nullptr));
        dayComboBox->setItemText(12, QCoreApplication::translate("PersonalInformation", "13", nullptr));
        dayComboBox->setItemText(13, QCoreApplication::translate("PersonalInformation", "14", nullptr));
        dayComboBox->setItemText(14, QCoreApplication::translate("PersonalInformation", "15", nullptr));
        dayComboBox->setItemText(15, QCoreApplication::translate("PersonalInformation", "16", nullptr));
        dayComboBox->setItemText(16, QCoreApplication::translate("PersonalInformation", "17", nullptr));
        dayComboBox->setItemText(17, QCoreApplication::translate("PersonalInformation", "18", nullptr));
        dayComboBox->setItemText(18, QCoreApplication::translate("PersonalInformation", "19", nullptr));
        dayComboBox->setItemText(19, QCoreApplication::translate("PersonalInformation", "20", nullptr));
        dayComboBox->setItemText(20, QCoreApplication::translate("PersonalInformation", "21", nullptr));
        dayComboBox->setItemText(21, QCoreApplication::translate("PersonalInformation", "22", nullptr));
        dayComboBox->setItemText(22, QCoreApplication::translate("PersonalInformation", "23", nullptr));
        dayComboBox->setItemText(23, QCoreApplication::translate("PersonalInformation", "24", nullptr));
        dayComboBox->setItemText(24, QCoreApplication::translate("PersonalInformation", "25", nullptr));
        dayComboBox->setItemText(25, QCoreApplication::translate("PersonalInformation", "26", nullptr));
        dayComboBox->setItemText(26, QCoreApplication::translate("PersonalInformation", "27", nullptr));
        dayComboBox->setItemText(27, QCoreApplication::translate("PersonalInformation", "28", nullptr));
        dayComboBox->setItemText(28, QCoreApplication::translate("PersonalInformation", "29", nullptr));
        dayComboBox->setItemText(29, QCoreApplication::translate("PersonalInformation", "30", nullptr));
        dayComboBox->setItemText(30, QCoreApplication::translate("PersonalInformation", "31", nullptr));

        provinceComboBox->setItemText(0, QCoreApplication::translate("PersonalInformation", "\346\262\263\345\214\227\347\234\201", nullptr));
        provinceComboBox->setItemText(1, QCoreApplication::translate("PersonalInformation", "\345\261\261\350\245\277\347\234\201", nullptr));
        provinceComboBox->setItemText(2, QCoreApplication::translate("PersonalInformation", "\350\276\275\345\256\201\347\234\201", nullptr));
        provinceComboBox->setItemText(3, QCoreApplication::translate("PersonalInformation", "\345\220\211\346\236\227\347\234\201", nullptr));
        provinceComboBox->setItemText(4, QCoreApplication::translate("PersonalInformation", "\351\273\221\351\276\231\346\261\237\347\234\201", nullptr));
        provinceComboBox->setItemText(5, QCoreApplication::translate("PersonalInformation", "\346\261\237\350\213\217\347\234\201", nullptr));
        provinceComboBox->setItemText(6, QCoreApplication::translate("PersonalInformation", "\346\265\231\346\261\237\347\234\201", nullptr));
        provinceComboBox->setItemText(7, QCoreApplication::translate("PersonalInformation", "\345\256\211\345\276\275\347\234\201", nullptr));
        provinceComboBox->setItemText(8, QCoreApplication::translate("PersonalInformation", "\347\246\217\345\273\272\347\234\201", nullptr));
        provinceComboBox->setItemText(9, QCoreApplication::translate("PersonalInformation", "\346\261\237\350\245\277\347\234\201", nullptr));
        provinceComboBox->setItemText(10, QCoreApplication::translate("PersonalInformation", "\345\261\261\344\270\234\347\234\201", nullptr));
        provinceComboBox->setItemText(11, QCoreApplication::translate("PersonalInformation", "\346\262\263\345\215\227\347\234\201", nullptr));
        provinceComboBox->setItemText(12, QCoreApplication::translate("PersonalInformation", "\346\271\226\345\214\227\347\234\201", nullptr));
        provinceComboBox->setItemText(13, QCoreApplication::translate("PersonalInformation", "\346\271\226\345\215\227\347\234\201", nullptr));
        provinceComboBox->setItemText(14, QCoreApplication::translate("PersonalInformation", "\345\271\277\344\270\234\347\234\201", nullptr));
        provinceComboBox->setItemText(15, QCoreApplication::translate("PersonalInformation", "\346\265\267\345\215\227\347\234\201", nullptr));
        provinceComboBox->setItemText(16, QCoreApplication::translate("PersonalInformation", "\345\233\233\345\267\235\347\234\201", nullptr));
        provinceComboBox->setItemText(17, QCoreApplication::translate("PersonalInformation", "\350\264\265\345\267\236\347\234\201", nullptr));
        provinceComboBox->setItemText(18, QCoreApplication::translate("PersonalInformation", "\344\272\221\345\215\227\347\234\201", nullptr));
        provinceComboBox->setItemText(19, QCoreApplication::translate("PersonalInformation", "\351\231\225\350\245\277\347\234\201", nullptr));
        provinceComboBox->setItemText(20, QCoreApplication::translate("PersonalInformation", "\347\224\230\350\202\203\347\234\201", nullptr));
        provinceComboBox->setItemText(21, QCoreApplication::translate("PersonalInformation", "\351\235\222\346\265\267\347\234\201", nullptr));
        provinceComboBox->setItemText(22, QCoreApplication::translate("PersonalInformation", "\345\217\260\346\271\276\347\234\201", nullptr));
        provinceComboBox->setItemText(23, QCoreApplication::translate("PersonalInformation", "\345\206\205\350\222\231\345\217\244\350\207\252\346\262\273\345\214\272", nullptr));
        provinceComboBox->setItemText(24, QCoreApplication::translate("PersonalInformation", "\345\271\277\350\245\277\345\243\256\346\227\217\350\207\252\346\262\273\345\214\272", nullptr));
        provinceComboBox->setItemText(25, QCoreApplication::translate("PersonalInformation", "\350\245\277\350\227\217\350\207\252\346\262\273\345\214\272", nullptr));
        provinceComboBox->setItemText(26, QCoreApplication::translate("PersonalInformation", "\345\256\201\345\244\217\345\233\236\346\227\217\350\207\252\346\262\273\345\214\272", nullptr));
        provinceComboBox->setItemText(27, QCoreApplication::translate("PersonalInformation", "\346\226\260\347\226\206\347\273\264\345\220\276\345\260\224\350\207\252\346\262\273\345\214\272", nullptr));
        provinceComboBox->setItemText(28, QCoreApplication::translate("PersonalInformation", "\345\214\227\344\272\254\345\270\202", nullptr));
        provinceComboBox->setItemText(29, QCoreApplication::translate("PersonalInformation", "\345\244\251\346\264\245\345\270\202", nullptr));
        provinceComboBox->setItemText(30, QCoreApplication::translate("PersonalInformation", "\344\270\212\346\265\267\345\270\202", nullptr));
        provinceComboBox->setItemText(31, QCoreApplication::translate("PersonalInformation", "\351\207\215\345\272\206\345\270\202", nullptr));
        provinceComboBox->setItemText(32, QCoreApplication::translate("PersonalInformation", "\351\246\231\346\270\257\347\211\271\345\210\253\350\241\214\346\224\277\345\214\272", nullptr));
        provinceComboBox->setItemText(33, QCoreApplication::translate("PersonalInformation", "\346\276\263\351\227\250\347\211\271\345\210\253\350\241\214\346\224\277\345\214\272", nullptr));

        saveButton->setText(QCoreApplication::translate("PersonalInformation", "\344\277\235\345\255\230", nullptr));
        cancelButton->setText(QCoreApplication::translate("PersonalInformation", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonalInformation: public Ui_PersonalInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALINFORMATION_H
