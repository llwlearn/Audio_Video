#include "PersonalInformation.h"
#include "ui_PersonalInformation.h"
#include <QDebug>

#include "src/tool/JsonManager.h"
#include "src/tool/Database.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonDocument>

PersonalInformation::PersonalInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalInformation)
{
    ui->setupUi(this);

    // 设置昵称输入框的样式
    ui->nicknameLineEdit->setStyleSheet("QLineEdit {"
                                        "border: 2px solid #E5E5E5;"
                                        "border-radius: 10px;"
                                        "padding: 5px;"
                                        "font-size: 16px;"
                                        "}");

    // 设置简介文本区域的样式
    ui->brief_introductionTextEdit->setStyleSheet("QTextEdit {"
                                                  "border: 2px solid #E5E5E5;"
                                                  "border-radius: 10px;"
                                                  "padding: 5px;"
                                                  "font-size: 16px;"
                                                  "}");

    // 设置单选按钮的样式
    ui->maleRadioButton->setStyleSheet("QRadioButton {"
                                       "spacing: 10px;"
                                       "}");
    ui->femaleRadioButton->setStyleSheet("QRadioButton {"
                                         "spacing: 10px;"
                                         "}");

    // 设置下拉框的样式
    ui->yearComboBox->setStyleSheet("QComboBox {"
                                    "border: 2px solid #E5E5E5;"
                                    "border-radius: 10px;"
                                    "padding: 5px;"
                                    "font-size: 16px;"
                                    "}");
    ui->monthComboBox->setStyleSheet("QComboBox {"
                                     "border: 2px solid #E5E5E5;"
                                     "border-radius: 10px;"
                                     "padding: 5px;"
                                     "font-size: 16px;"
                                     "}");
    ui->dayComboBox->setStyleSheet("QComboBox {"
                                   "border: 2px solid #E5E5E5;"
                                   "border-radius: 10px;"
                                   "padding: 5px;"
                                   "font-size: 16px;"
                                   "}");
    ui->provinceComboBox->setStyleSheet("QComboBox {"
                                        "border: 2px solid #E5E5E5;"
                                        "border-radius: 10px;"
                                        "padding: 5px;"
                                        "font-size: 16px;"
                                        "}");
    ui->cityComboBox->setStyleSheet("QComboBox {"
                                    "border: 2px solid #E5E5E5;"
                                    "border-radius: 10px;"
                                    "padding: 5px;"
                                    "font-size: 16px;"
                                    "}");

    // 设置按钮的样式
    ui->saveButton->setStyleSheet("QPushButton {"
                                  "background-color: rgb(253, 60, 89);"
                                  "color: white;"
                                  "border: none;"
                                  "border-radius: 20px;"
                                  "padding: 10px 20px;"
                                  "font-size: 20px;"
                                  "}");
    ui->cancelButton->setStyleSheet("QPushButton {"
                                    "background-color: white;"
                                    "color: black;"
                                    "border: 2px solid #E5E5E5;"
                                    "border-radius: 20px;"
                                    "padding: 10px 20px;"
                                    "font-size: 20px;"
                                    "}");

    // 连接信号和槽
    connect(ui->saveButton, &QPushButton::clicked, this, &PersonalInformation::onSaveButtonClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &PersonalInformation::onCancelButtonClicked);
    connect(ui->yearComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &PersonalInformation::onYearComboBoxCurrentIndexChanged);
    connect(ui->provinceComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &PersonalInformation::onProvinceComboBoxCurrentIndexChanged);

    loadProvinceData(); // 加载下拉框数据
    QSqlDatabase db = Database::getGlobalConnection();

}

PersonalInformation::~PersonalInformation()
{
    delete ui;
}

// 获取 PersonalInformation 实例的静态方法
PersonalInformation* PersonalInformation::getInstance(QWidget *parent)
{
    static PersonalInformation* instance = nullptr;  // 静态局部变量，保证只有一个实例
    if (!instance) {
        instance = new PersonalInformation(parent);  // 如果没有实例，则创建一个新的 Login
    }
    return instance;
}

void PersonalInformation::loadProvinceData()
{
    // 使用 JsonManager 从文件加载省级数据
    QJsonObject provincesData = JsonManager::loadUserInfoFromFile("../../src/China_Provinces_Cities.json");
    if (provincesData.isEmpty()) {
        qDebug() << "无法从文件加载省级数据";
        return;
    }

    // 清空省份下拉框
    ui->provinceComboBox->clear();

    // 填充省份下拉框
    for (auto it = provincesData.begin(); it != provincesData.end(); ++it) {
        ui->provinceComboBox->addItem(it.key());
    }

    // 连接省份下拉框的信号，以便在选择省份时更新城市下拉框
    connect(ui->provinceComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, [this, provincesData](int index) {
                if (index >= 0) {
                    QString province = ui->provinceComboBox->itemText(index);
                    // 清空城市下拉框
                    ui->cityComboBox->clear();

                    // 获取对应省份的城市列表
                    if (provincesData.contains(province)) {
                        QJsonArray cities = provincesData[province].toArray();
                        for (const QJsonValue &city : cities) {
                            ui->cityComboBox->addItem(city.toString());
                        }
                    }
                }
            });

    // 如果省份下拉框有数据，自动更新城市下拉框
    if (ui->provinceComboBox->count() > 0) {
        ui->provinceComboBox->setCurrentIndex(0); // 假设默认选择第一个省份
    }
}


void PersonalInformation::loadingPersonalInformation()
{
    // 使用 JsonManager 从文件加载用户信息
    QJsonObject userInfo = JsonManager::loadUserInfoFromFile("../../src/user_info.json");
    if (userInfo.isEmpty()) {
        qDebug() << "无法加载用户信息";
        return;
    }

    username = userInfo["username"].toString();

    QStringList fields;
    QString condition = QString("nickname = '%1'").arg(username);
    QSqlQuery query = database.select("PersonalInformation", fields, condition);

    if (query.next()) {
        // 填充控件
        ui->nicknameLineEdit->setText(query.value("nickname").toString());
        // 根据性别设置单选按钮
        if (query.value("gender").toString() == "男") {
            ui->maleRadioButton->setChecked(true);
        } else if (query.value("gender").toString() == "女") {
            ui->femaleRadioButton->setChecked(true);
        }
        ui->yearComboBox->setCurrentText(query.value("birth_year").toString());
        ui->monthComboBox->setCurrentText(query.value("birth_month").toString());
        ui->dayComboBox->setCurrentText(query.value("birth_day").toString());
        ui->provinceComboBox->setCurrentText(query.value("province").toString());
        ui->cityComboBox->setCurrentText(query.value("city").toString());
        ui->brief_introductionTextEdit->setPlainText(query.value("brief_introduction").toString());
    } else {
        QMessageBox::warning(this, "失败", "未找到用户信息！");
    }
}

void PersonalInformation::onSaveButtonClicked()
{
    qDebug() << "保存按钮被点击";
    // 获取输入信息并处理
    newUsername = ui->nicknameLineEdit->text();
    QString gender = ui->maleRadioButton->isChecked() ? "男" : "女";
    QString year = ui->yearComboBox->currentText();
    QString month = ui->monthComboBox->currentText();
    QString day = ui->dayComboBox->currentText();
    QString province = ui->provinceComboBox->currentText();
    QString city = ui->cityComboBox->currentText();
    QString briefIntroduction = ui->brief_introductionTextEdit->toPlainText();

    qDebug() << "昵称：" << newUsername;
    qDebug() << "性别：" << gender;
    qDebug() << "出生日期：" << year << "年" << month << "月" << day << "日";
    qDebug() << "省份：" << province;
    qDebug() << "城市：" << city;
    qDebug() << "简介：" << briefIntroduction;

    // 更新个人信息
    QStringList fields;
    fields << "nickname" << "gender" << "birth_year" << "birth_month" << "birth_day" << "province" << "city" << "brief_introduction";

    QVariantList values;
    values << newUsername << gender << year.toInt() << month.toInt() << day.toInt() << province << city << briefIntroduction;

    QString updateCondition = QString("nickname = '%1'").arg(username);

    bool updateResult = database.update("personalinformation", fields, values, updateCondition);
    if (updateResult) {
        qDebug() << "个人信息保存成功";
        QMessageBox::information(this, "成功", "保存成功");

        QFile file("../../src/user_info.json");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            // 清空文件内容
            file.resize(0);
            file.close();
            qDebug() << "用户信息文件已清空";
        } else {
            qDebug() << "无法打开文件进行清空！";
        }


        QStringList fields = {"id", "username", "password", "membership_level"};
        QString condition = QString("username = '%1'").arg(newUsername);
        QSqlQuery query = database.select("users", fields, condition);
        if (query.next()) {
        QJsonObject jsonUserInfo;
        jsonUserInfo["id"] = query.value("id").toInt();
        jsonUserInfo["username"] = query.value("username").toString();
        jsonUserInfo["password"] = query.value("password").toString();
        jsonUserInfo["membership_level"] = query.value("membership_level").toString();


        bool success = JsonManager::saveUserInfoToFile("../../src/user_info.json", jsonUserInfo);
        if (success) {
            qDebug() << "用户信息已保存到文件";
        } else {
            qDebug() << "无法打开文件进行写入！";
        }

        username = newUsername;

        emit personalInformationChanged(); // 发出更新信号

      }
        else {
            qDebug() << "数据库查询失败";
            QMessageBox::critical(this, "错误", "数据库错误！");
      }
    } else {
        qDebug() << "个人信息保存失败";
        QMessageBox::critical(this, "错误", "保存失败！");
    }

}

void PersonalInformation::onCancelButtonClicked()
{
    qDebug() << "取消按钮被点击";
    // 清空所有输入框
    this->close();
}

void PersonalInformation::onYearComboBoxCurrentIndexChanged(int index)
{
    qDebug() << "年份下拉框索引改变：" << index;
    // 可以根据年份改变来更新其他控件的状态
}

void PersonalInformation::onProvinceComboBoxCurrentIndexChanged(int index)
{
    qDebug() << "省份下拉框索引改变：" << index;
    // 根据省份选择更新城市下拉框的内容
    // 这里需要根据省份来动态设置城市下拉框的选项
}
