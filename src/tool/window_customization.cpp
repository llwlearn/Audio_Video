#include "window_customization.h"

WindowCustomization::WindowCustomization(QWidget *targetWidget, QObject *parent)
    : QObject(parent), m_targetWidget(targetWidget), m_isDragging(false), m_dragAreaHeight(50)
{
    // 监听目标窗口的鼠标事件
    m_targetWidget->installEventFilter(this);  // 安装事件过滤器
}

void WindowCustomization::setDragAreaHeight(int height)
{
    m_dragAreaHeight = height;  // 设置可拖动的区域高度
}

bool WindowCustomization::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == m_targetWidget) {
        switch (event->type()) {
        case QEvent::MouseButtonPress:
            mousePressEvent(static_cast<QMouseEvent *>(event));
            return true;  // 事件已处理，阻止进一步处理
        case QEvent::MouseMove:
            mouseMoveEvent(static_cast<QMouseEvent *>(event));
            return true;
        case QEvent::MouseButtonRelease:
            mouseReleaseEvent(static_cast<QMouseEvent *>(event));
            return true;
        default:
            break;
        }
    }
    return QObject::eventFilter(watched, event);  // 默认处理
}

void WindowCustomization::mousePressEvent(QMouseEvent *event)
{
    // 判断鼠标点击的位置是否在窗口上边一定区域内
    if (event->y() <= m_dragAreaHeight) {
        m_isDragging = true;
        m_dragStartPos = event->globalPos() - m_targetWidget->pos();  // 记录鼠标按下时的偏移量
    }
}

void WindowCustomization::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDragging) {
        // 根据鼠标的移动来调整窗口的位置
        m_targetWidget->move(event->globalPos() - m_dragStartPos);
    }
}

void WindowCustomization::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_isDragging = false;  // 释放鼠标时停止拖动
}
