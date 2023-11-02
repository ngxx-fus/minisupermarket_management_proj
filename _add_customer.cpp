#include "_add_customer.h"
#include "ui__add_customer.h"

_add_customer::_add_customer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::_add_customer)
{
    ui->setupUi(this);
}

_add_customer::~_add_customer()
{
    delete ui;
}
