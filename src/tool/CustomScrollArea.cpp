// CustomScrollArea.cpp
#include "CustomScrollArea.h"
#include <QScrollBar>
#include <QDebug>

CustomScrollArea::CustomScrollArea(QWidget *parent)
    : QScrollArea(parent)
{
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void CustomScrollArea::enterEvent(QEnterEvent *event)
{
    // 如果鼠标进入区域，显示滚动条
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // 调用基类的 enterEvent 来保持默认行为
    QScrollArea::enterEvent(event);
}

void CustomScrollArea::leaveEvent(QEvent *event)
{
    // 鼠标离开时，隐藏滚动条
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 调用基类的 leaveEvent 来保持默认行为
    QScrollArea::leaveEvent(event);
}
