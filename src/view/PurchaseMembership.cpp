#include "PurchaseMembership.h"
#include "ui_PurchaseMembership.h"

#include "src/tool/Interface.h"

PurchaseMembership::PurchaseMembership(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PurchaseMembership)
{
    ui->setupUi(this);
    // 创建事件过滤器对象，传入当前窗口指针
    EventFilter *filter = new EventFilter(this, this);
    this->installEventFilter(filter);  // 安装事件过滤器

    Interface interface;
    QPair<int, int> pos = interface.calculateCenterPosition(this);

    // 设置窗口初始位置 (X, Y)
    this->move(pos.first, pos.second-100);  // 将窗口移动到屏幕的居中位置

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
