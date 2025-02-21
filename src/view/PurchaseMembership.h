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

private slots:
    void onAnnualMembershipClicked();
    void onMonthlyMembershipClicked();
    void onQuarterlyMembershipClicked();
    void onPurchaseClicked();

private:
    Ui::PurchaseMembership *ui;
    EventFilter *filter;  // 存储过滤器对象的指针
    enum MembershipType {
        None = -1,  // 添加一个None值作为默认值
        Annual,
        Monthly,
        Quarterly
    };
    MembershipType selectedMembershipType; // 当前选中的会员类型

    QString unselectedStyle; // 未选中样式
    QString selectedStyle;   // 选中样式
};

#endif // PURCHASEMEMBERSHIP_H
