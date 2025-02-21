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

    void setAutoHideScrollBar(bool enable);  // 设置是否自动隐藏滚动条

protected:
    // 重载基类中的 enterEvent 方法，参数改为 QEnterEvent*
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;  // 这里还是可以保留 QEvent*

private:
    bool autoHideScrollBar;  // 是否自动隐藏滚动条
    void updateScrollBarVisibility();  // 更新滚动条的显示状态
};


#endif // CUSTOMSCROLLAREA_H
