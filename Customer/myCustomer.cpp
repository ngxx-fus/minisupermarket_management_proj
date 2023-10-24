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

void myCustomer::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    customers* cus = (customers*) item;
    ui->customer_name->setText(cus->getName());
    ui->customer_ID->setText(cus->getID());
    ui->customer_phoneNumber->setText(cus->getphoneNumber());
    ui->customer_point->setNum(cus->getAccumulationPoint());
    ui->customer_BOD->setText(cus->getBirthOfDay());
}

void myCustomer::addCustomer(customers* cus)//cus : customer
{
    myCustomer::m_customer.push_back(cus);
    ui->listWidget->addItem( (QListWidgetItem*) cus );
}

void myCustomer::addCustomer(QString name)
{
    customers* cus = new customers(name);
    addCustomer(cus);
}

void myCustomer::addCustomer(QString cus_name,
                            QString cus_ID,
                            QString cus_DOB,
                            QString cus_phoneNumber,
                            int cus_accumulationPoint)
{
    customers* cus = new customers(cus_name, cus_ID, cus_DOB, cus_phoneNumber, cus_accumulationPoint);
    addCustomer(cus);
}

void myCustomer::removeCustomer(customers* cus)
{
    ui->listWidget->removeItemWidget(cus);
    m_customer.remove( findByPtr(cus) );
}

myCustomer::~myCustomer()
{
    delete ui;
}
