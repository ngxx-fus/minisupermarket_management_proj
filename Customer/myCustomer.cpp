#include "myCustomer.h"
#include "customers.h"
#include "ui_myCustomer.h"

myCustomer::myCustomer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myCustomer)
{
    ui->setupUi(this);
}

void myCustomer::on_listWidget_itemClicked(QListWidgetItem *item)
{
    customers* cus = (customers*) item;

}

void myCustomer::addCustomer(customers* cus)//cus : customer
{
    myCustomer::m_customer.push_back(cus);
//    ui->listWidget->addItem( (QListWidgetItem*) cus );// the reason for error "Slots named on_foo_bar are error prone [clazy-connect-by-name]"
//    ui->tableWidget->
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
//    ui->listWidget->removeItemWidget(cus);
    m_customer.remove( findByPtr(cus) );
    delete cus;
}

myCustomer::~myCustomer()
{
    rep(i, 0, m_customer.size()-1){
        removeCustomer( m_customer[i] );
    }
    delete ui;
}


