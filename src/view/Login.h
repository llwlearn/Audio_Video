#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

#include "src/tool/Database.h"

// 用户信息结构体
struct User_Info {
    int id;                  // 用户ID
    QString username;        // 用户名
    QString password;        // 密码
    QString membership_level; // 会员等级

    // 构造函数
    User_Info() : id(0), username(""), password(""), membership_level("") {}
    User_Info(int _id, const QString& _username, const QString& _password, const QString& _membership_level)
        : id(_id), username(_username), password(_password), membership_level(_membership_level) {}
};

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);  // 只声明构造函数
    ~Login();

    QString LoginFromFile();  // 从文件中登录

    void logoutAndClearUserInfo();  // 退出登录并清空文件

    static Login* getInstance(QWidget *parent = nullptr);  // 获取单例窗口实例

    void saveUserInfoToFile(const User_Info& user_Info);  // 保存用户信息到文件

signals:
    void loginSuccessful(const QString &username);  // 定义信号

private slots:
    void onLoginButtonClicked();   // 登录按钮点击槽
    void onLogonButtonClicked();   // 注册按钮点击槽

private:
    Ui::Login *ui;                 // UI对象
    QLineEdit *usernameLineEdit;   // 用户名输入框
    QLineEdit *passwordLineEdit;   // 密码输入框
    QPushButton *loginButton;      // 登录按钮
    QPushButton *logonButton;      // 注册按钮

    Database database;

    User_Info user_Info;        // 用户信息结构体

    void initUI();                 // 初始化UI
    bool validateInput();          // 输入验证
};

#endif // LOGIN_H
