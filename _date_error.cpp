#include "_date_error.h"
#include "ui__date_error.h"

_date_error::_date_error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::_date_error)
{
    ui->setupUi(this);
}

_date_error::~_date_error()
{
    delete ui;
}
