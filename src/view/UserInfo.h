#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>

#include <QMouseEvent>
#include <QApplication>
#include <QEvent>

#include "src/tool/EventFilter.h"

namespace Ui {
class UserInfo;
}

class UserInfo : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = nullptr);
    ~UserInfo();

    static UserInfo* getInstance(QWidget *parent = nullptr);  // 获取单例的静态方法

private slots:
    // 槽函数声明
    void onMyMembersClicked();
    void onLogOutClicked();
    void onPersonalInformationSettingsClicked();

private:
    Ui::UserInfo *ui;
    EventFilter *filter;  // 存储过滤器对象的指针
};

#endif // USERINFO_H
