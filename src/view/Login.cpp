#include "Login.h"
#include "ui_Login.h"  // 必须包含此文件，以便能够访问生成的 UI 元素

#include "src/tool/Database.h"

#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);  // 初始化UI
    this->setWindowTitle("登录");

    usernameLineEdit = ui->usernameLineEdit;
    passwordLineEdit = ui->passwordLineEdit;
    loginButton = ui->loginButton;
    logonButton = ui->logonButton;

    connect(loginButton, &QPushButton::clicked, this, &Login::onLoginButtonClicked);
    connect(logonButton, &QPushButton::clicked, this, &Login::onLogonButtonClicked);
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

// 从文件中登录验证
QString Login::LoginFromFile()
{
    QFile file("../user_info.txt");
    // 尝试读取保存的用户信息（如果文件存在）
    if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString savedUsername = in.readLine();  // 读取第一行用户名
        QString savedPassword = in.readLine();  // 读取第二行密码

        // 连接到数据库
        Database db;
        bool connected = db.connect("localhost", "Audio_Video", "root", "123456");  // 使用你的数据库连接信息
        if (!connected) {
            qDebug() <<"错误：启动无法连接到数据库!";
            return 0;
        }

        // 构建查询条件，查找用户名对应的密码
        QStringList fields = {"username", "password"};  // 选择查询字段：用户名和密码
        // 构建查询条件：同时验证用户名和密码
        QString condition = QString("username = '%1' AND password = '%2'").arg(savedUsername).arg(savedPassword);

        // 执行查询
        QSqlQuery query = db.select("users", fields, condition);  // 查询users表，获取密码字段

        // 处理查询结果
        if (query.next()) {
            QString storedPassword = query.value("password").toString();  // 获取数据库中存储的密码

            // 检查输入的密码是否与数据库中的密码匹配
            if (savedPassword == storedPassword) {
                qDebug() << "登录成功，用户名：" << savedUsername;
            } else {
                // 密码错误
                qDebug() << "登录失败，用户名：" << savedUsername;
            }
        } else {
            // 用户名不存在
            qDebug() << "登录失败，用户名或密码错误";
        }

        file.close();
        return savedUsername;
    }
    return 0;
}

// 登录按钮点击事件槽函数
void Login::onLoginButtonClicked()
{
    QString username = usernameLineEdit->text();  // 获取用户名
    QString password = passwordLineEdit->text();  // 获取密码

    // 验证用户名和密码不能为空
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "登录", "请输入用户名和密码!");
        return;
    }

    // 连接到数据库
    Database db;
    bool connected = db.connect("localhost", "Audio_Video", "root", "123456");  // 使用你的数据库连接信息
    if (!connected) {
        QMessageBox::critical(this, "错误", "无法连接到数据库!");
        return;
    }

    // 构建查询条件，查找用户名对应的密码
    QStringList fields = {"username", "password"};  // 选择查询字段：用户名和密码
    // 构建查询条件：同时验证用户名和密码
    QString condition = QString("username = '%1' AND password = '%2'").arg(username).arg(password);

    // 执行查询
    QSqlQuery query = db.select("users", fields, condition);  // 查询users表，获取密码字段

    // 处理查询结果
    if (query.next()) {
        QString storedPassword = query.value("password").toString();  // 获取数据库中存储的密码

        // 检查输入的密码是否与数据库中的密码匹配
        if (password == storedPassword) {
            // 登录成功
            QMessageBox::information(this, "登录成功", "欢迎，" + username);
            qDebug() << "登录成功，用户名：" << username;

            // 保存用户名和密码到文件
            QFile file("../user_info.txt");
            // 打开文件（如果文件不存在则会自动创建）
            if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
                QTextStream out(&file);
                out << username << "\n" << password;  // 保存用户名和密码
                file.close();  // 关闭文件
            } else {
                qDebug() << "无法打开文件进行写入！";
            }

            this->destroyed();
            this->close();  // 关闭当前窗口
        } else {
            // 密码错误
            QMessageBox::warning(this, "登录失败", "用户名或密码错误！");
        }
    } else {
        // 用户名不存在
        QMessageBox::warning(this, "登录失败", "用户名或密码错误！");
    }
}


// 注册按钮点击事件槽函数
void Login::onLogonButtonClicked()
{
    // 获取用户输入的用户名和密码
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    // 检查用户名和密码是否为空
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "用户名或密码不能为空!");
        qDebug() << "用户名或密码不能为空!";
        return;
    }

    // 先查询是否有同名的用户名
    // 连接到数据库
    Database db;
    QString condition = "username = '" + username + "'";
    QSqlQuery query = db.select("users", QStringList() << "id", condition);

    if (query.next()) {
        // 如果查询结果不为空，表示用户名已存在
        QMessageBox::warning(this, "注册失败", "用户名已存在，请选择其他用户名!");
        qDebug() << "用户名已存在!";
        return;
    }

    // 如果没有同名用户，插入新用户数据
    QVariantList values;
    values << username << password;  // 传入用户名和密码
    QStringList fields;
    fields << "username" << "password";  // 对应字段名称

    bool success = db.insert("users", fields, values);
    if (success) {
        QMessageBox::information(this, "注册成功", "恭喜！您的账号已成功注册！");
        qDebug() << "注册成功!";
    } else {
        QMessageBox::critical(this, "注册失败", "注册过程中出现问题，请稍后再试！");
        qDebug() << "注册失败!";
    }
}
