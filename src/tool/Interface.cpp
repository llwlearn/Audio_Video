#include "Interface.h"

#include <QApplication>

Interface::Interface()
{
}

Interface::~Interface()
{
}

QPair<int, int> Interface::calculateCenterPosition(QWidget *window)
{
    // 获取屏幕的尺寸
    QScreen *screen = QApplication::primaryScreen();
    QRect screenRect = screen->availableGeometry();

    // 计算居中位置
    int x = (screenRect.width() * windowInfo.dpi - window->width()) / 2;
    int y = (screenRect.height() * windowInfo.dpi - window->height()) / 2;

    // 返回坐标对
    return qMakePair(x, y);
}
