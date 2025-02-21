// UserInfo.cpp
#include "UserInfo.h"
#include "ui_UserInfo.h"

#include "PurchaseMembership.h"
#include "src/view/Login.h"
#include "src/tool/JsonManager.h"
#include "src/tool/Database.h"

#include <QMouseEvent>
#include <QApplication>
#include <QEvent>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

UserInfo::UserInfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserInfo)
{
    ui->setupUi(this);
    // 创建事件过滤器对象，传入当前窗口指针
    EventFilter *filter = new EventFilter(this, this);
    this->installEventFilter(filter);  // 安装事件过滤器

    setWindowFlags (Qt::CustomizeWindowHint);//两个函数都可以去掉标题栏，区别是这个可以鼠标缩放窗口
     // setWindowFlags (Qt::FramelessWindowHint);

    // 绑定按钮的信号与槽
    connect(ui->MyMembers, &QPushButton::clicked, this, &UserInfo::onMyMembersClicked);
    connect(ui->LogOut, &QPushButton::clicked, this, &UserInfo::onLogOutClicked);
    connect(ui->Personal_Information_Settings, &QPushButton::clicked, this, &UserInfo::onPersonalInformationSettings);

}

UserInfo::~UserInfo()
{
    delete ui;
    delete filter;  // 释放过滤器对象
}

void UserInfo::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event); // 调用基类的 showEvent 函数

    // 使用 JsonManager 从文件加载用户信息
    QJsonObject userInfo = JsonManager::loadUserInfoFromFile("../../src/user_info.json");
    if (userInfo.isEmpty()) {
        qDebug() << "无法加载会员等级";
    }

    QString username = userInfo["username"].toString();
    QString password = userInfo["password"].toString();


    QSqlDatabase db = Database::getGlobalConnection();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "错误", "无法连接到数据库!");
        return;
    }


    QStringList fields = {"id", "username", "password", "membership_level"};
    QString condition = QString("username = '%1' AND password = '%2'").arg(username).arg(password);
    QSqlQuery query(db);
    if (!query.exec(QString("SELECT %1 FROM users WHERE %2").arg(fields.join(", "), condition))) {
        QMessageBox::critical(this, "错误", "查询失败!");
        return;
    }

    if (query.next()) {
        QString membership_level = query.value("membership_level").toString();
        ui->MyMembers->setText(membership_level);
    } else {
        QMessageBox::warning(this, "失败", "数据库故障！");
    }


}

// 实现槽函数
void UserInfo::onMyMembersClicked()
{
    // 这里可以添加点击"我的会员"按钮后的处理逻辑
    qDebug("我的会员按钮被点击");

    PurchaseMembership* purchase = PurchaseMembership::getInstance();
    if (!purchase) {
        qDebug() << "purchase is null!";
        return;
    }

    purchase->show();

}

void UserInfo::onLogOutClicked()
{
    // 这里可以添加点击"退出登录"按钮后的处理逻辑
    qDebug("退出登录按钮被点击");
    // 例如，关闭窗口或执行登出操作
    this->destroyed();
    this->close();
    Login* loginInstance = Login::getInstance();
    loginInstance->logoutAndClearUserInfo();
}

void UserInfo::onPersonalInformationSettings()
{
    // 这里可以添加点击"个人信息设置"按钮后的处理逻辑
    qDebug("个人信息设置按钮被点击");
    emit PersonalInformationSettings(); // 发送信号
}

UserInfo* UserInfo::getInstance(QWidget *parent)
{
    static UserInfo* instance = nullptr;  // 静态局部变量，保证只有一个实例

    if (!instance) {
        instance = new UserInfo(parent);  // 如果没有实例，则创建一个新的
    }

    return instance;
}

