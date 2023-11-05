#include "formaddcommodities.h"
#include "ui_formaddcommodities.h"

QString name;
QString id ;
unsigned int amount;
QString date ;
QString dateExp ;
double price ;

FormAddCommodities::FormAddCommodities(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormAddCommodities)
{
    ui->setupUi(this);
}

FormAddCommodities::~FormAddCommodities()
{
    delete ui;
}

void FormAddCommodities::on_btnSave_clicked()
{
    name = ui->txtName->text();
    id = ui->txtID->text();
    amount = ui->txtAmount->text().toUInt();
    date = ui->txtDate->text();
    dateExp = ui->txtDateExp->text();
    price = ui->txtPrice->text().toDouble();
    // You can now use these local variables within this function
    // If you want to store these values as member variables, you can assign them as follows:


    accept();  // Close the dialog
}
// Implement getter methods

QString FormAddCommodities::getName() const {
    return name;
}

QString FormAddCommodities::getId() const {
    return id;
}

unsigned int FormAddCommodities::getAmount() const {
    return amount;
}

QString FormAddCommodities::getDate() const {
    return date;
}

QString FormAddCommodities::getDateExp() const {
    return dateExp;
}

double FormAddCommodities::getPrice() const {
    return price;
}
