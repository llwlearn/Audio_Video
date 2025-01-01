#ifndef PURCHASEMEMBERSHIP_H
#define PURCHASEMEMBERSHIP_H

#include "src/tool/EventFilter.h"

#include <QWidget>

namespace Ui {
class PurchaseMembership;
}

class PurchaseMembership : public QWidget
{
    Q_OBJECT

public:
    explicit PurchaseMembership(QWidget *parent = nullptr);
    ~PurchaseMembership();

    static PurchaseMembership* getInstance(QWidget *parent = nullptr);  // 获取单例的静态方法


private:
    Ui::PurchaseMembership *ui;
    EventFilter *filter;  // 存储过滤器对象的指针
};

#endif // PURCHASEMEMBERSHIP_H
