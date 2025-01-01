#include "EventFilter.h"
#include <QApplication>
#include <QMouseEvent>

// 构造函数，接收目标窗口并设置事件过滤器
EventFilter::EventFilter(QWidget *targetWidget, QObject *parent)
    : QObject(parent), m_targetWidget(targetWidget)
{
    // 安装事件过滤器
    qApp->installEventFilter(this);
}
EventFilter::~EventFilter()
{
    // 移除事件过滤器
    qApp->removeEventFilter(this);
    delete m_targetWidget;
}

bool EventFilter::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);

        // 如果点击的位置不在当前窗口内，则关闭窗口
        if (!m_targetWidget->rect().contains(mouseEvent->pos())) {
            m_targetWidget->close();  // 关闭窗口
            return false;   // 阻止事件继续传播
        }
    }

    // 默认返回父类事件处理，确保事件可以继续传递
    return QObject::eventFilter(watched, event);
}
