#ifndef RECOMMEND_H
#define RECOMMEND_H

#include <QWidget>
#include <QTimer>
#include <QStringList>
#include <QMouseEvent>
#include <QVBoxLayout>

namespace Ui {
class Recommend;
}

class Recommend : public QWidget
{
    Q_OBJECT

public:
    explicit Recommend(QWidget *parent = nullptr);
    ~Recommend();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void nextImage();
    void onImageClicked();

private:
    Ui::Recommend *ui;

    void updateImage();

    QTimer *timer;
    QStringList images;
    int currentIndex;
};

#endif // RECOMMEND_H
