#include "bookeyes.h"
#include "ui_bookeyes.h"

BookEyes::BookEyes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BookEyes)
{
    ui->setupUi(this);

}

BookEyes::~BookEyes()
{
    delete ui;
}

