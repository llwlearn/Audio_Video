#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QWidget>
#include <QEvent>

class EventFilter : public QObject
{
    Q_OBJECT

public:
    // 构造函数，传入需要安装事件过滤器的窗口
    explicit EventFilter(QWidget *targetWidget, QObject *parent = nullptr);
    ~EventFilter();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QWidget *m_targetWidget;  // 目标窗口
};

#endif // EVENTFILTER_H
