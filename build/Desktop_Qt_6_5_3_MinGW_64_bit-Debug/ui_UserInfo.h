/********************************************************************************
** Form generated from reading UI file 'UserInfo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_H
#define UI_USERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInfo
{
public:
    QWidget *widget;
    QWidget *BottomWidget;
    QPushButton *LogOut;
    QWidget *CenterWidget;
    QPushButton *Personal_Information_Settings;
    QPushButton *MyMembers;
    QWidget *TopWidget;
    QLabel *label;
    QPushButton *Profile_Picture;
    QFrame *line_3;
    QFrame *line_2;

    void setupUi(QWidget *UserInfo)
    {
        if (UserInfo->objectName().isEmpty())
            UserInfo->setObjectName("UserInfo");
        UserInfo->resize(300, 300);
        UserInfo->setStyleSheet(QString::fromUtf8("border: none;"));
        widget = new QWidget(UserInfo);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 300, 300));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        BottomWidget = new QWidget(widget);
        BottomWidget->setObjectName("BottomWidget");
        BottomWidget->setGeometry(QRect(0, 200, 300, 100));
        LogOut = new QPushButton(BottomWidget);
        LogOut->setObjectName("LogOut");
        LogOut->setGeometry(QRect(0, -1, 300, 101));
        QFont font;
        LogOut->setFont(font);
        LogOut->setCursor(QCursor(Qt::PointingHandCursor));
        LogOut->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 23px;\n"
"	border: none;\n"
"     background-color: rgb(255, 255, 255);\n"
"    }\n"
"QPushButton:hover {\n"
"    background-color: rgb(242, 243, 244);\n"
"    }"));
        CenterWidget = new QWidget(widget);
        CenterWidget->setObjectName("CenterWidget");
        CenterWidget->setGeometry(QRect(0, 100, 300, 100));
        CenterWidget->setStyleSheet(QString::fromUtf8(""));
        Personal_Information_Settings = new QPushButton(CenterWidget);
        Personal_Information_Settings->setObjectName("Personal_Information_Settings");
        Personal_Information_Settings->setGeometry(QRect(0, 50, 300, 50));
        Personal_Information_Settings->setFont(font);
        Personal_Information_Settings->setCursor(QCursor(Qt::PointingHandCursor));
        Personal_Information_Settings->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 23px;\n"
"	border: none;\n"
"     background-color: rgb(255, 255, 255);\n"
"    }\n"
"QPushButton:hover {\n"
"    background-color: rgb(242, 243, 244);\n"
"    }"));
        MyMembers = new QPushButton(CenterWidget);
        MyMembers->setObjectName("MyMembers");
        MyMembers->setGeometry(QRect(0, 0, 300, 50));
        MyMembers->setFont(font);
        MyMembers->setCursor(QCursor(Qt::PointingHandCursor));
        MyMembers->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 23px;\n"
"	border: none;\n"
"     background-color: rgb(255, 255, 255);\n"
"    }\n"
"QPushButton:hover {\n"
"    background-color: rgb(242, 243, 244);\n"
"    }"));
        TopWidget = new QWidget(widget);
        TopWidget->setObjectName("TopWidget");
        TopWidget->setGeometry(QRect(0, 0, 300, 100));
        label = new QLabel(TopWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 20, 161, 50));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font-size: 25px;"));
        Profile_Picture = new QPushButton(TopWidget);
        Profile_Picture->setObjectName("Profile_Picture");
        Profile_Picture->setGeometry(QRect(35, 15, 60, 60));
        Profile_Picture->setCursor(QCursor(Qt::PointingHandCursor));
        Profile_Picture->setStyleSheet(QString::fromUtf8("border: 2px solid rgb(226, 229, 233);\n"
"border-radius: 30px;"));
        line_3 = new QFrame(widget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(20, 199, 260, 2));
        line_3->setStyleSheet(QString::fromUtf8("border:  none;\n"
"background-color: rgba(184, 189, 198, 0.5);"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(widget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(20, 99, 260, 2));
        line_2->setStyleSheet(QString::fromUtf8("border:  none;\n"
"background-color: rgba(184, 189, 198, 0.5);"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        retranslateUi(UserInfo);

        QMetaObject::connectSlotsByName(UserInfo);
    } // setupUi

    void retranslateUi(QWidget *UserInfo)
    {
        UserInfo->setWindowTitle(QCoreApplication::translate("UserInfo", "Form", nullptr));
        LogOut->setText(QCoreApplication::translate("UserInfo", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        Personal_Information_Settings->setText(QCoreApplication::translate("UserInfo", "\344\270\252\344\272\272\344\277\241\346\201\257\350\256\276\347\275\256", nullptr));
        MyMembers->setText(QCoreApplication::translate("UserInfo", "\346\210\221\347\232\204\344\274\232\345\221\230\357\274\232\345\275\223\345\211\215\346\227\240\344\274\232\345\221\230", nullptr));
        label->setText(QCoreApplication::translate("UserInfo", "\347\222\220\347\222\220\345\256\266\346\212\225\344\272\206", nullptr));
        Profile_Picture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserInfo: public Ui_UserInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_H
