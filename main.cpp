#include "src/tool/Interface.h"
#include "MainWindow.h"
#include <QApplication>
#include <QWidget>
#include "src/tool/window_customization.h"
// #include <QDebug>

Interface::WindowInfo Interface::windowInfo;
MainWindow::WindowInfo MainWindow::windowInfo;

int main(int argc, char *argv[])
{

    // 初始化 QApplication
    QApplication a(argc, argv);

    qreal dpi = a.devicePixelRatio();
    // qDebug() << "Global Device Pixel Ratio (全局缩放倍率): " << dpi;

    // 设置缩放因子四舍五入策略
    a.setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::RoundPreferFloor);

    // 创建并显示主窗口
    MainWindow w;

    // 获取屏幕的尺寸
    QScreen *screen = QApplication::primaryScreen();

    QRect screenRect = screen->availableGeometry();
    // qDebug() << "Available geometry: " << screenRect;
    // qDebug() << "DPI: " << screen->logicalDotsPerInch();  // 获取逻辑 DPI

    int maxWidth = screenRect.width() * dpi, maxHeight = screenRect.height() * dpi;

    int windowWidth = screenRect.width() * dpi/1.615, windowHeight = screenRect.height() * dpi/1.418;

    // 计算居中位置
    int x = (screenRect.width() * dpi - windowWidth) / 2;
    int y = (screenRect.height() * dpi - windowHeight) / 2;

    // 设置窗口初始位置 (X, Y)
    w.move(x, y);  // 将窗口移动到屏幕的居中位置

    // 设置窗口大小
    // w.resize(windowWidth, windowHeight);
    // 设置最小窗口大小
    w.setMinimumSize(windowWidth, windowHeight);

    MainWindow::windowInfo = {maxWidth, maxHeight, windowWidth, windowHeight, x, y};

    Interface::windowInfo.dpi = dpi;
    // 创建并使用 WindowCustomization 类
    WindowCustomization windowCustomization(&w);
    windowCustomization.setDragAreaHeight(80);  // 设置拖动区域为上边 50 像素

    w.show();

    // 进入应用程序的主事件循环
    return a.exec();
}
