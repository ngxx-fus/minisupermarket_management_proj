#include "myCustomer.h"
#include "customers.h"
#include "ui_myCustomer.h"

myCustomer::myCustomer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myCustomer)
{
    ui->setupUi(this);
    customers* cus = new customers;
    cus->setName("Nguyễn Thanh Phú");
    cus->setID("22119211");
    cus->setBOD("03/02/2004");
    ui->listWidget->addItem((QListWidgetItem*) cus);

}

myCustomer::~myCustomer()
{
    delete ui;
}


void myCustomer::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    customers* cus = (customers*) item;
    ui->customer_name->setText(cus->getName());
    ui->customer_ID->setText(cus->getID());
    ui->customer_numberphone->setText(cus->getNumberPhone());
    ui->customer_point->setNum(cus->getAccumulationPoint());
    ui->customer_BOD->setText(cus->getBirthOfDay());
}

