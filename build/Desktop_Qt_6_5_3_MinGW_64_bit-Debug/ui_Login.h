/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *usernameLineEdit;
    QLabel *label_6;
    QPushButton *loginButton;
    QLabel *label_8;
    QLineEdit *passwordLineEdit;
    QPushButton *logonButton;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(400, 300);
        usernameLineEdit = new QLineEdit(Login);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setEnabled(true);
        usernameLineEdit->setGeometry(QRect(100, 50, 220, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        usernameLineEdit->setFont(font);
        usernameLineEdit->setFrame(true);
        label_6 = new QLabel(Login);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(49, 109, 51, 30));
        QFont font1;
        font1.setPointSize(10);
        label_6->setFont(font1);
        loginButton = new QPushButton(Login);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(70, 181, 100, 50));
        loginButton->setFont(font1);
        label_8 = new QLabel(Login);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(29, 59, 71, 30));
        label_8->setFont(font1);
        passwordLineEdit = new QLineEdit(Login);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEnabled(true);
        passwordLineEdit->setGeometry(QRect(100, 100, 220, 40));
        passwordLineEdit->setFont(font);
        passwordLineEdit->setFrame(true);
        logonButton = new QPushButton(Login);
        logonButton->setObjectName("logonButton");
        logonButton->setGeometry(QRect(230, 180, 100, 50));
        logonButton->setFont(font1);
        QWidget::setTabOrder(usernameLineEdit, passwordLineEdit);
        QWidget::setTabOrder(passwordLineEdit, loginButton);
        QWidget::setTabOrder(loginButton, logonButton);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        usernameLineEdit->setText(QString());
        label_6->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", nullptr));
        loginButton->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        label_8->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        passwordLineEdit->setText(QString());
        logonButton->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
