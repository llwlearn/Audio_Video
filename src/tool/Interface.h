#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QScreen>
#include <QPair>

class Interface
{

public:
     // 构造函数，传入需要安装事件过滤器的窗口
    Interface();
    ~Interface();

    struct WindowInfo {
        qreal dpi;
    };

    static WindowInfo windowInfo;// 声明静态成员变量
    QPair<int, int> calculateCenterPosition(QWidget *window);//计算居中位置

private:

};

#endif // INTERFACE_H
