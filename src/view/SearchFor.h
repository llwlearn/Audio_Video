#ifndef SEARCHFOR_H
#define SEARCHFOR_H

#include <QWidget>

namespace Ui {
class SearchFor;
}

class SearchFor : public QWidget
{
    Q_OBJECT

public:
    explicit SearchFor(QWidget *parent = nullptr);
    ~SearchFor();

private:
    Ui::SearchFor *ui;
};

#endif // SEARCHFOR_H
