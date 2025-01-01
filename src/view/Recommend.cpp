#include "Recommend.h"
#include "ui_Recommend.h"

#include <QPixmap>
#include <QMessageBox>
#include <QPainter>
#include <QPainterPath>


Recommend::Recommend(QWidget *parent)
    : QWidget(parent), ui(new Ui::Recommend), timer(nullptr), currentIndex(0)
{
    ui->setupUi(this);

    // 设置 CarouselImage 的尺寸策略为忽略
    ui->CarouselImage->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->CarouselImage->setAlignment(Qt::AlignCenter); // 设置对齐方式为居中

    // 设置样式表以实现圆角
    ui->CarouselImage->setStyleSheet("border-radius: 10px;");

    // 设置图片列表（路径需要根据实际情况修改）
    images << ":/new/prefix1/recommend/CarouselImage-1.png" << ":/new/prefix1/recommend/CarouselImage-2.png"
           << ":/new/prefix1/recommend/CarouselImage-3.png" << ":/new/prefix1/recommend/CarouselImage-4.png"
           << ":/new/prefix1/recommend/CarouselImage-5.png";

    // 初始显示第一张图片
    updateImage();

    // 设置定时器每隔3秒切换一次图片
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Recommend::nextImage);
    timer->start(3000); // 每3秒切换一次

    ui->playlist_1->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->playlist_2->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->playlist_3->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->playlist_4->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    ui->Selected_1->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->Selected_1->setWordWrap(true);  // 启用自动换行
    ui->Selected_2->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->Selected_2->setWordWrap(true);
    ui->Selected_3->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->Selected_3->setWordWrap(true);
    ui->Selected_4->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->Selected_4->setWordWrap(true);
    ui->Selected_5->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->Selected_5->setWordWrap(true);

    ui->Selected_16->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->Selected_16->setWordWrap(true);
    ui->Selected_17->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->Selected_17->setWordWrap(true);
    ui->Selected_18->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->Selected_18->setWordWrap(true);
    ui->Selected_19->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->Selected_19->setWordWrap(true);
    ui->Selected_20->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->Selected_20->setWordWrap(true);

}

Recommend::~Recommend()
{
    delete ui;
    delete timer;
}

void Recommend::mousePressEvent(QMouseEvent *event)
{
    // 获取点击位置相对于 CarouselImage 的坐标
    QPoint clickPos = event->pos();
    QRect carouselRect = ui->CarouselImage->geometry();

    // 判断点击是否在 CarouselImage 内
    if (carouselRect.contains(clickPos)) {
        // 执行相关操作
        onImageClicked();
    }
}

void Recommend::nextImage()
{
    // 更新到下一张图片
    currentIndex = (currentIndex + 1) % images.size();
    updateImage();
}

void Recommend::onImageClicked()
{
    // 当图片被点击时执行的操作
    QMessageBox::information(this, "图片点击", QString("你点击了第%1张图片！").arg(currentIndex + 1));
}

void Recommend::updateImage()
{
    if (!images.isEmpty()) {
        QPixmap pixmap(images[currentIndex]);
        pixmap = pixmap.scaled(ui->CarouselImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

        // 使用 QPainter 来绘制图片，并确保它被圆角裁剪
        QPixmap roundedPixmap(pixmap.size());
        roundedPixmap.fill(Qt::transparent);  // 填充透明背景

        QPainter painter(&roundedPixmap);
        painter.setRenderHint(QPainter::Antialiasing);

        // 创建圆角矩形路径
        QPainterPath path;
        path.addRoundedRect(0, 0, pixmap.width(), pixmap.height(), 12, 12);  // 圆角半径为10

        // 裁剪区域为圆角矩形
        painter.setClipPath(path);
        painter.drawPixmap(0, 0, pixmap);  // 绘制图片

        painter.end();

        // 将裁剪后的图片设置为 QLabel 的图片
        ui->CarouselImage->setPixmap(roundedPixmap);
    }
}


void Recommend::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    updateImage();
}
