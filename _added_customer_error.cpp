#include "_added_customer_error.h"
#include "ui__added_customer_error.h"

_added_customer_error::_added_customer_error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::_added_customer_error)
{
    ui->setupUi(this);
}

_added_customer_error::~_added_customer_error()
{
    delete ui;
}
