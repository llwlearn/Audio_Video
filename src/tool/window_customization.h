#ifndef WINDOW_CUSTOMIZATION_H
#define WINDOW_CUSTOMIZATION_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QPoint>

class WindowCustomization : public QObject
{
    Q_OBJECT

public:
    explicit WindowCustomization(QWidget *targetWidget, QObject *parent = nullptr);

    // 设置拖动区域高度
    void setDragAreaHeight(int height);

protected:
    // 声明 eventFilter 方法，注意返回类型和参数
    bool eventFilter(QObject *watched, QEvent *event) override;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QWidget *m_targetWidget;  // 目标窗口
    bool m_isDragging;        // 是否正在拖动
    QPoint m_dragStartPos;    // 鼠标按下时的偏移量
    int m_dragAreaHeight;     // 可拖动的区域高度
};

#endif // WINDOW_CUSTOMIZATION_H
