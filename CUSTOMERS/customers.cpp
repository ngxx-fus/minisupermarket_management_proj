#include "customers.h"
#include "ui_customers.h"

customers::customers(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::customers)
{
    QListWidgetItem* item = new QListWidgetItem("Name of customer");
    ui->listWidget->addItem(item);
}

customers::~customers()
{
    delete ui;
}

