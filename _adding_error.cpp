#include "_adding_error.h"
#include "ui__adding_error.h"

_adding_error::_adding_error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::_adding_error)
{
    ui->setupUi(this);
}

_adding_error::~_adding_error()
{
    delete ui;
}
