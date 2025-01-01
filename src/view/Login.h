#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

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

    static Login* getInstance(QWidget *parent = nullptr);  // 获取单例窗口实例

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

    void initUI();                 // 初始化UI
    bool validateInput();          // 输入验证
};

#endif // LOGIN_H
