// CustomScrollArea.h
#ifndef CUSTOMSCROLLAREA_H
#define CUSTOMSCROLLAREA_H

// CustomScrollArea.h
#include <QScrollArea>
#include <QEnterEvent>  // 引入 QEnterEvent

class CustomScrollArea : public QScrollArea
{
    Q_OBJECT

public:
    explicit CustomScrollArea(QWidget *parent = nullptr);

protected:
    // 重载基类中的 enterEvent 方法，参数改为 QEnterEvent*
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;  // 这里还是可以保留 QEvent*
};


#endif // CUSTOMSCROLLAREA_H
