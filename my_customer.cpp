#include "my_customer.h"
#include "ui_my_customer.h"



my_customer::my_customer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::my_customer)
{
    ui->setupUi(this);
    add_customer("Nguyen Thanh Phu", "0845939722", 100);
    add_customer("Nguyen Hong Son", "0845234622", 190);
    add_customer("Nguyen Minh Tuan", "0845235672", 200);
    add_customer("Hoang Xuan Bach", "0376235672", 200);
    refresh_list_view();
}

void my_customer::refresh_list_view(){

    int const max_column = 5,
        max_row = (qv_cus.size()<=10 ? qv_cus.size() : 10);

    ui->tableWidget->setRowCount(max_row);
    ui->tableWidget->setColumnCount(max_column);

    //setup column 0
    ui->tableWidget->setColumnWidth(0,150);

    //setup column 1
    ui->tableWidget->setColumnWidth(1,130);

    //setup column 2
    ui->tableWidget->setColumnWidth(2,150);

    //setup column 3
    ui->tableWidget->setColumnWidth(3,200);

    //setup column 4
    ui->tableWidget->setColumnWidth(4,170);

    for(int r = 0; r < max_row; r++){
        _customers cus = qv_cus.at(r);
        ui->tableWidget->setItem(r,0, new QTableWidgetItem(cus.getName()));
        ui->tableWidget->setItem(r,1, new QTableWidgetItem(cus.getPhoneNumber()));
        ui->tableWidget->setItem(r,2, new QTableWidgetItem(_time().int_to_QString(cus.getPoint())));
        ui->tableWidget->setItem(r,3, new QTableWidgetItem(cus.getLatestModification().get_date()));
        ui->tableWidget->setItem(r,4, new QTableWidgetItem(cus.getID()));

    }
}

void my_customer::add_customer(QString cus_name, QString cus_phoneNumber, int cus_point){
    qv_cus.push_back(_customers(cus_name, cus_phoneNumber, cus_point));
}

void my_customer::remove_by_phoneNumber(QString cus_phoneNumer){
    QVector<_customers>::iterator it = qv_cus.begin();
    //linear searching
    for(it = qv_cus.begin(); it != qv_cus.end(); it++){
        if(it->getPhoneNumber() == cus_phoneNumer) break;
    }
    QVector<_customers>::const_iterator const_it = it;
    qv_cus.erase(const_it);
}

my_customer::~my_customer()
{
    delete ui;
}

