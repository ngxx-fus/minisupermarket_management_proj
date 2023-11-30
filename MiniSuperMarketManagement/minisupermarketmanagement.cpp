#include "minisupermarketmanagement.h"
#include "./ui_minisupermarketmanagement.h"
#include "managerproduct.h"
#include "InvoiceManagement.h"
#include "my_customer.h"
#include "InvoiceManagement.h"
#include "QString"
#include "commodities.h"
#include <vector>
#include <iostream>
#include <cctype>
#include <QDebug>
#include "my_customer.h"
using namespace std ;
QString fileName1 = "./App_data/ManagerCommodities_DATA";
static bool hasReadFile = false; // Biến tĩnh (static) sẽ chỉ được khởi tạo một lần và giữ giá trị qua các lần gọi hàm

MiniSupermarKetmanagement::MiniSupermarKetmanagement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MiniSupermarKetmanagement)
{
    ui->setupUi(this);

    QPixmap pix("./App_data/onepunchman.jpg");
    ui->label_pic->setPixmap(pix);

    readCommoditiesFromFile(fileName1,commoditieslist);
}

MiniSupermarKetmanagement::~MiniSupermarKetmanagement()
{
    delete ui;
}

void MiniSupermarKetmanagement::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}


void MiniSupermarKetmanagement::on_pushButton_clicked()
{

    ManagerProduct manager(this);
    manager.setModal(true);
    manager.exec();

}


void MiniSupermarKetmanagement::on_pushButton_3_clicked()
{
    InvoiceManagement InvoiceManagementWindow(this);
    InvoiceManagementWindow.setModal(true);
    InvoiceManagementWindow.exec();
}


void MiniSupermarKetmanagement::on_pushButton_2_clicked()
{
    my_customer mycustomer(this);
    mycustomer.setModal(true);
    mycustomer.exec();
}

