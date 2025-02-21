// CustomScrollArea.cpp
#include "CustomScrollArea.h"
#include <QScrollBar>
#include <QDebug>

CustomScrollArea::CustomScrollArea(QWidget *parent)
    : QScrollArea(parent), autoHideScrollBar(true)
{
    // 初始时隐藏滚动条
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 设置滚动条样式
    setStyleSheet(
        "QScrollArea {"
        "   border: none;"
        "}"
        "QScrollBar:vertical {"
        "   border: none;"
        "   background: transparent;"
        "   width: 10px;"
        "   margin: 20px 0 20px 0;"
        "   padding-right: 3px;"
        "}"
        "QScrollBar::handle:vertical {"
        "   background: rgb(226, 229, 233);"
        "   border-radius: 3px;"
        "   min-height: 20px;"
        "}"
        "QScrollBar::handle:vertical:hover {"
        "   background: rgb(195, 200, 207);"
        "}"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
        "   background: none;"
        "   border: none;"
        "   width: 0px;"
        "   height: 0px;"
        "}"
        "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {"
        "   background: none;"
        "   border: none;"
        "}"
        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
        "   background: none;"
        "}"
        );
}

void CustomScrollArea::setAutoHideScrollBar(bool enable)
{
    autoHideScrollBar = enable;
    updateScrollBarVisibility();  // 更新滚动条的显示状态
}

void CustomScrollArea::enterEvent(QEnterEvent *event)
{
    // 鼠标进入时显示滚动条
    if (autoHideScrollBar) {
        setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    }

    // 调用基类的 enterEvent
    QScrollArea::enterEvent(event);
}

void CustomScrollArea::leaveEvent(QEvent *event)
{
    // 鼠标离开时隐藏滚动条
    if (autoHideScrollBar) {
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }

    // 调用基类的 leaveEvent
    QScrollArea::leaveEvent(event);
}

void CustomScrollArea::updateScrollBarVisibility()
{
    if (autoHideScrollBar) {
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    } else {
        setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    }
}
