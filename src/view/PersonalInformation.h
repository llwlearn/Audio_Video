#ifndef PERSONALINFORMATION_H
#define PERSONALINFORMATION_H

#include <QWidget>
#include <QComboBox>
#include <QRadioButton>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>

#include "src/tool/Database.h"

namespace Ui {
class PersonalInformation;
}

class PersonalInformation : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalInformation(QWidget *parent = nullptr);
    ~PersonalInformation();

    static PersonalInformation* getInstance(QWidget *parent = nullptr);  // 获取单例窗口实例

    void loadingPersonalInformation();

signals:
    void personalInformationChanged(); // 发送更新信号

private slots:
    void onSaveButtonClicked();
    void onCancelButtonClicked();
    void onYearComboBoxCurrentIndexChanged(int index);
    void onProvinceComboBoxCurrentIndexChanged(int index);

    void loadProvinceData();

private:
    Ui::PersonalInformation *ui;
    Database database;
    QString username;
    QString newUsername;
};

#endif // PERSONALINFORMATION_H
