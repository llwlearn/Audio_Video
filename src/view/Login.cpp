#include "Login.h"
#include "ui_Login.h"

#include "src/tool/Database.h"

#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>

#include "src/tool/JsonManager.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);  // 初始化UI
    this->setWindowTitle("登录");

    // 在构造函数中进行连接
    usernameLineEdit = ui->usernameLineEdit;
    passwordLineEdit = ui->passwordLineEdit;
    loginButton = ui->loginButton;
    logonButton = ui->logonButton;

    // 连接登录按钮的点击信号
    connect(loginButton, &QPushButton::clicked, this, &Login::onLoginButtonClicked);
    connect(logonButton, &QPushButton::clicked, this, &Login::onLogonButtonClicked);

    // 连接密码框的回车按下事件到登录按钮点击
    connect(passwordLineEdit, &QLineEdit::returnPressed, this, &Login::onLoginButtonClicked);

    QSqlDatabase db = Database::getGlobalConnection();
}

Login::~Login()
{
    delete ui;  // 释放内存
}

// 获取 Login 实例的静态方法
Login* Login::getInstance(QWidget *parent)
{
    static Login* instance = nullptr;  // 静态局部变量，保证只有一个实例
    if (!instance) {
        instance = new Login(parent);  // 如果没有实例，则创建一个新的 Login
    }
    return instance;
}

void Login::logoutAndClearUserInfo()
{
    QFile file("../../src/user_info.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // 清空文件内容
        file.resize(0);
        file.close();
        qDebug() << "用户信息文件已清空";
    } else {
        qDebug() << "无法打开文件进行清空！";
    }
}

// 从文件中登录验证
QString Login::LoginFromFile()
{
    // 使用 JsonManager 从文件加载用户信息
    QJsonObject userInfo = JsonManager::loadUserInfoFromFile("../../src/user_info.json");
    if (userInfo.isEmpty()) {
        qDebug() << "无法从文件加载用户信息";
        return "";
    }

    QString savedUsername = userInfo["username"].toString();
    QString savedPassword = userInfo["password"].toString();

    QStringList fields = {"id", "username", "password", "membership_level"};
    QString condition = QString("username = '%1' AND password = '%2'").arg(savedUsername).arg(savedPassword);
    QSqlQuery query = database.select("users", fields, condition);

    if (query.next()) {
        user_Info.id = query.value("id").toInt();
        user_Info.username = query.value("username").toString();
        user_Info.password = query.value("password").toString();
        user_Info.membership_level = query.value("membership_level").toString();
        qDebug() << "登录成功，用户名：" << user_Info.username;
        return user_Info.username;
    } else {
        qDebug() << "登录失败，用户名或密码错误";
    }

    return "";
}

void Login::saveUserInfoToFile(const User_Info& userInfo)
{
    QJsonObject jsonUserInfo;
    jsonUserInfo["id"] = userInfo.id;
    jsonUserInfo["username"] = userInfo.username;
    jsonUserInfo["password"] = userInfo.password;
    jsonUserInfo["membership_level"] = userInfo.membership_level;

    bool success = JsonManager::saveUserInfoToFile("../../src/user_info.json", jsonUserInfo);
    if (success) {
        qDebug() << "用户信息已保存到文件";
    } else {
        qDebug() << "无法打开文件进行写入！";
    }
}

// 登录按钮点击事件槽函数
void Login::onLoginButtonClicked()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "登录", "请输入用户名和密码!");
        return;
    }

    QStringList fields = {"id", "username", "password", "membership_level"};
    QString condition = QString("username = '%1' AND password = '%2'").arg(username).arg(password);
    QSqlQuery query = database.select("users", fields, condition);

    if (query.next()) {
        user_Info.id = query.value("id").toInt();
        user_Info.username = query.value("username").toString();
        user_Info.password = query.value("password").toString();
        user_Info.membership_level = query.value("membership_level").toString();
        QMessageBox::information(this, "登录成功", "欢迎，" + username);
        qDebug() << "登录成功，用户名：" << username;
        saveUserInfoToFile(user_Info);  // 保存用户信息到文件
        this->destroyed();
        this->close();
    } else {
        QMessageBox::warning(this, "登录失败", "用户名或密码错误！");
    }
}

// 注册按钮点击事件槽函数
void Login::onLogonButtonClicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "用户名或密码不能为空!");
        qDebug() << "用户名或密码不能为空!";
        return;
    }

    QString condition = "username = '" + username + "'";
    QSqlQuery query = database.select("users", QStringList() << "id", condition);

    if (query.next()) {
        QMessageBox::warning(this, "注册失败", "用户名已存在，请选择其他用户名!");
        qDebug() << "用户名已存在!";
        return;
    }

    QVariantList values;
    values << username << password;
    QStringList fields;
    fields << "username" << "password";

    bool success = database.insert("users", fields, values);
    if (success) {
        QMessageBox::information(this, "注册成功", "恭喜！您的账号已成功注册！");
        qDebug() << "注册成功!";
    } else {
        QMessageBox::critical(this, "注册失败", "注册过程中出现问题，请稍后再试！");
        qDebug() << "注册失败!";
    }
}
