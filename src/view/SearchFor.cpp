#include "SearchFor.h"
#include "ui_SearchFor.h"

SearchFor::SearchFor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchFor)
{
    ui->setupUi(this);
}

SearchFor::~SearchFor()
{
    delete ui;
}
