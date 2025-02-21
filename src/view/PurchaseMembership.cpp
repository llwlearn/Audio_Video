#include "PurchaseMembership.h"
#include "ui_PurchaseMembership.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

#include "src/tool/Interface.h"
#include "src/tool/Database.h"
#include "src/tool/JsonManager.h"

PurchaseMembership::PurchaseMembership(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PurchaseMembership)
    , selectedMembershipType(None)
{
    ui->setupUi(this);
    // 创建事件过滤器对象，传入当前窗口指针
    EventFilter *filter = new EventFilter(this, this);
    this->installEventFilter(filter);  // 安装事件过滤器

    Interface interface;
    QPair<int, int> pos = interface.calculateCenterPosition(this);

    // 设置窗口初始位置 (X, Y)
    this->move(pos.first, pos.second-100);  // 将窗口移动到屏幕的居中位置

    connect(ui->AnnualMembership, &QPushButton::clicked, this, &PurchaseMembership::onAnnualMembershipClicked);
    connect(ui->MonthlyMembership, &QPushButton::clicked, this, &PurchaseMembership::onMonthlyMembershipClicked);
    connect(ui->QuarterlyMembership, &QPushButton::clicked, this, &PurchaseMembership::onQuarterlyMembershipClicked);
    connect(ui->purchase, &QPushButton::clicked, this, &PurchaseMembership::onPurchaseClicked);

    unselectedStyle = "QPushButton { background-color: lightgray; }";
    selectedStyle = "QPushButton { background-color: lightblue; }";

}

PurchaseMembership::~PurchaseMembership()
{
    delete ui;
    delete filter;  // 释放过滤器对象
}

PurchaseMembership* PurchaseMembership::getInstance(QWidget *parent)
{
    static PurchaseMembership* instance = nullptr;  // 静态局部变量，保证只有一个实例

    if (!instance) {
        instance = new PurchaseMembership(parent);  // 如果没有实例，则创建一个新的
    }

    return instance;
}

void PurchaseMembership::onPurchaseClicked()
{
    // 检查是否选择了会员类型
    if (selectedMembershipType == None) {  // 检查是否为None
        QMessageBox::warning(this, "错误", "请选择一个会员类型！");
        return;
    }

    // 根据选择的会员类型获取购买参数
    int day;
    switch (selectedMembershipType) {
    case Annual:
        day = 356;
        break;
    case Monthly:
        day = 30;
        break;
    case Quarterly:
        day = 90;
        break;
    default:
        // 如果 selectedMembershipType 是 None 或其他未定义的值，这里可以进行错误处理
        QMessageBox::warning(this, "错误", "未知的会员类型！");
        return;
    }

    // 使用 JsonManager 从文件加载用户信息
    QJsonObject userInfo = JsonManager::loadUserInfoFromFile("../../src/user_info.json");
    if (userInfo.isEmpty()) {
        qDebug() << "无法从文件加载用户信息";
        return ;
    }

    QString savedUsername = userInfo["username"].toString();
    QString savedPassword = userInfo["password"].toString();

    Database database;
    QSqlDatabase db = Database::getGlobalConnection();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "错误", "无法连接到数据库!");
        return;
    }

    QStringList fields = {"id", "username", "password", "membership_level"};
    QString condition = QString("username = '%1' AND password = '%2'").arg(savedUsername).arg(savedPassword);
    QSqlQuery query = database.select("users", fields, condition);

    if (query.next()) {
        int id = query.value("id").toInt();
        QString username = query.value("username").toString();
        QString password = query.value("password").toString();
        QString membership_level = query.value("membership_level").toString();

        int days = 0;
        if(membership_level != "当前无会员"){
            QStringList parts = membership_level.split("：");
            if (parts.size() > 1) {
                QString daysPart = parts.last().trimmed().remove(')');

                qDebug() << daysPart;
                bool ok;
                days = daysPart.toInt(&ok);
                if (ok) {
                    qDebug() << "剩余天数：" << days;
                } else {
                    qDebug() << "无法转换天数";
                    return; // 如果无法转换天数，则终止后续操作
                }
            } else {
                qDebug() << "格式不正确";
                return; // 如果格式不正确，则终止后续操作
            }
        }


        // 假设 day 是一个整数变量，代表要增加的天数
        int newDays = days + day; // 计算新的剩余天数

        QString membershipTypeStr;
        if (newDays >= 356) {
            membershipTypeStr = "年度会员";
        } else if (newDays >= 90) {
            membershipTypeStr = "季度会员";
        } else if (newDays >= 1) {
            membershipTypeStr = "月度会员";
        } else {
            // 如果 newDays 小于 30，可以根据需要设置默认值或处理异常情况
            membershipTypeStr = "非会员"; // 例如，这里设置为 "非会员"
        }

        // 更新会员等级
        QStringList fields = {"membership_level"};
        QString newMembershipLevel = membershipTypeStr + "(剩余天数：" + QString::number(newDays) + ")";
        QVariantList values = {newMembershipLevel};
        QString updateCondition = QString("id = %1").arg(id);

        bool updateResult = database.update("users", fields, values, updateCondition);
        if (updateResult) {
            qDebug() << "会员等级更新成功";
            QMessageBox::information(this, "成功", "已购买天数：" + QString::number(day) + "天！");

            QFile file("../../src/user_info.json");
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                // 清空文件内容
                file.resize(0);
                file.close();
                qDebug() << "用户信息文件已清空";
            } else {
                qDebug() << "无法打开文件进行清空！";
            }

            QJsonObject jsonUserInfo;
            jsonUserInfo["id"] = id;
            jsonUserInfo["username"] = username;
            jsonUserInfo["password"] = password;
            jsonUserInfo["membership_level"] = newMembershipLevel;

            bool success = JsonManager::saveUserInfoToFile("../../src/user_info.json", jsonUserInfo);
            if (success) {
                qDebug() << "用户信息已保存到文件";
            } else {
                qDebug() << "无法打开文件进行写入！";
            }

            this->close();
            return;
        } else {
            qDebug() << "会员等级更新失败";
            QMessageBox::critical(this, "错误", "会员等级更新失败！");
        }

        return ;
    } else {
        qDebug() << "数据库错误";
        QMessageBox::critical(this, "错误", "数据库故障！");
    }

}

void PurchaseMembership::onAnnualMembershipClicked()
{
    selectedMembershipType = Annual;
    ui->AnnualMembership->setStyleSheet(selectedStyle);
    ui->MonthlyMembership->setStyleSheet(unselectedStyle);
    ui->QuarterlyMembership->setStyleSheet(unselectedStyle);
}

void PurchaseMembership::onMonthlyMembershipClicked()
{
    selectedMembershipType = Monthly;
    ui->AnnualMembership->setStyleSheet(unselectedStyle);
    ui->MonthlyMembership->setStyleSheet(selectedStyle);
    ui->QuarterlyMembership->setStyleSheet(unselectedStyle);
}

void PurchaseMembership::onQuarterlyMembershipClicked()
{
    selectedMembershipType = Quarterly;
    ui->AnnualMembership->setStyleSheet(unselectedStyle);
    ui->MonthlyMembership->setStyleSheet(unselectedStyle);
    ui->QuarterlyMembership->setStyleSheet(selectedStyle);
}
