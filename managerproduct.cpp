#include "managerproduct.h"
#include "commodities.h"
#include "ui_managerproduct.h"
#include "managerproduct.h"
#include <QString>
#include <string>
/*khái báo vector là toàn cục để lưu danh sách hàng hóa*/
vector<Commodities> commoditieslist;
/*Khái báo để lưu thông tin name id amount từ người dùng nhập vô*/
#include <QMessageBox>
/*  */
QString fileName = "ManagerCommodities.txt";

ManagerProduct::ManagerProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagerProduct)
{
    ui->setupUi(this);
    /* */
    for(int i=1;i<13;i++){
        ui->comboBox->addItem( QString::number(i));

    }
    for(int i=1;i<32;i++){
        ui->comboBox_2->addItem( QString::number(i));

    }
    for(int i=2023;i<2030;i++){
        ui->comboBox_3->addItem( QString::number(i));

    }
    /* */

    for(int i=1;i<13;i++){
        ui->comboBox_7->addItem( QString::number(i));

    }
    for(int i=1;i<32;i++){
        ui->comboBox_8->addItem( QString::number(i));

    }
    for(int i=2023;i<2030;i++){
        ui->comboBox_9->addItem( QString::number(i));

    }

    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
    populateTableWidget(tableWidget, commoditieslist);


}

ManagerProduct::~ManagerProduct()
{
    delete ui;
}


void ManagerProduct::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}

/* Nút nhấn thêm sản phẩm */
void ManagerProduct::on_pushButton_clicked()
{
    QString name, id;
    unsigned int amount=0;
    double price;
    QString date, dateExp;
    int day, month, year;
    int dayexp, monthexp, yearexp;

    month = ui->comboBox->currentText().toInt();
    day = ui->comboBox_2->currentText().toInt();
    year = ui->comboBox_3->currentText().toInt();

    monthexp = ui->comboBox_7->currentText().toInt();
    dayexp = ui->comboBox_8->currentText().toInt();
    yearexp = ui->comboBox_9->currentText().toInt();

    name = ui->txtName->text();
    id = ui->txtID->text();
    amount = ui->txtAmount->text().toUInt();
    price = ui->txtPrice->text().toDouble();
    date = QString::number(day) + "/" + QString::number(month) + "/" + QString::number(year);
    dateExp = QString::number(dayexp) + "/" + QString::number(monthexp) + "/" + QString::number(yearexp);

    int j =Checkbox(commoditieslist, name, id, amount, price);
    if (j==-1)
    {
        int i =  findCommodity(commoditieslist, id);
        if(i == -1){
            CompareDate(commoditieslist, day,month, year, dayexp, monthexp, yearexp,name,id ,amount,date,dateExp,price);
            QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
            populateTableWidget(tableWidget, commoditieslist);

            ui->txtName->clear();
            ui->txtID->clear();
            ui->txtAmount->clear();
            ui->txtPrice->clear();
            saveCommoditiesToFile(fileName,commoditieslist);

        }else {


            ui->txtID->clear();

            QMessageBox::information(this, "ID in Commodities", "The specified ID does not exist.");

        }

    }

   else{
        ui->txtName->clear();
        ui->txtID->clear();
        ui->txtAmount->clear();
        ui->txtPrice->clear();
        QMessageBox::information(this, "ID in Commodities", "Box emty or Wrong data type ");
   }

}

/*Nút nhấn chỉnh sửa thông tin sản phẩm*/
void ManagerProduct::on_btnrepair_clicked()
{

}

// Nút nhấn tìm kiếm
void ManagerProduct::on_btnSearch_clicked()
{
    QString SearchID;

    SearchID = ui->txtSearch->text();
    int i = findCommodity(commoditieslist, SearchID);

    // Truy cập vào widget bảng
    QTableWidget *tableWidget1 = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ

    // Xóa dữ liệu cũ trong bảng
    tableWidget1->setRowCount(0);

    // Đặt số lượng cột cho bảng
    tableWidget1->setColumnCount(6);
    tableWidget1->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    tableWidget1->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
    tableWidget1->setHorizontalHeaderItem(2, new QTableWidgetItem("Amount"));
    tableWidget1->setHorizontalHeaderItem(3, new QTableWidgetItem("Purchase Date"));
    tableWidget1->setHorizontalHeaderItem(4, new QTableWidgetItem("Expiration Date"));
    tableWidget1->setHorizontalHeaderItem(5, new QTableWidgetItem("Price"));

    if (i != -1) {
        // Tạo một hàng mới và thêm dữ liệu tìm thấy
        tableWidget1->insertRow(0);

        QTableWidgetItem *nameItem = new QTableWidgetItem(commoditieslist[i].getName());
        QTableWidgetItem *idItem = new QTableWidgetItem(commoditieslist[i].getID());
        QTableWidgetItem *amountItem = new QTableWidgetItem(QString::number(commoditieslist[i].getAmountCommodities()));
        QTableWidgetItem *dateItem = new QTableWidgetItem(commoditieslist[i].getDateCommodities());
        QTableWidgetItem *dateexpItem = new QTableWidgetItem(commoditieslist[i].getDateExpCommodities());
        QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(commoditieslist[i].getPrice()));

        tableWidget1->setItem(0, 0, idItem);
        tableWidget1->setItem(0, 1, nameItem);
        tableWidget1->setItem(0, 2, amountItem);
        tableWidget1->setItem(0, 3, dateItem);
        tableWidget1->setItem(0, 4, dateexpItem);
        tableWidget1->setItem(0, 5, priceItem);
    }
    else {
        QMessageBox::information(this, "ID Not Found", "The specified ID does not exist.");
        populateTableWidget(tableWidget1, commoditieslist);

    }
    int columnWidth = 160;
    for (int col = 0; col < tableWidget1->columnCount(); ++col) {
        tableWidget1->setColumnWidth(col, columnWidth);
    }

    ui->txtSearch->clear();
}


void ManagerProduct::on_radioButton_clicked()
{
    SortIncrease(commoditieslist);
    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
    populateTableWidget(tableWidget, commoditieslist);
}


void ManagerProduct::on_radioButton_2_clicked()
{
    SortDecrease(commoditieslist);
    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
    populateTableWidget(tableWidget, commoditieslist);

}


void ManagerProduct::on_pushButton_2_clicked()
{
    QString SearchID;
    SearchID = ui->txtSearch->text();
    int i = findCommodity(commoditieslist, SearchID);
    QTableWidget *tableWidget1 = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ

    // Xóa dữ liệu cũ trong bảng
    tableWidget1->setRowCount(0);

    // Đặt số lượng cột cho bảng
    tableWidget1->setColumnCount(6);
    tableWidget1->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    tableWidget1->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
    tableWidget1->setHorizontalHeaderItem(2, new QTableWidgetItem("Amount"));
    tableWidget1->setHorizontalHeaderItem(3, new QTableWidgetItem("Purchase Date"));
    tableWidget1->setHorizontalHeaderItem(4, new QTableWidgetItem("Expiration Date"));
    tableWidget1->setHorizontalHeaderItem(5, new QTableWidgetItem("Price"));
    if(i != -1){
    Delete(commoditieslist, SearchID);
    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
    populateTableWidget(tableWidget, commoditieslist);
    saveCommoditiesToFile(fileName,commoditieslist);
    ui->txtSearch->clear();
    }
    else {
        QMessageBox::information(this, "ID Not Found", "The specified ID does not exist.");
        populateTableWidget(tableWidget1, commoditieslist);

    }

}


void ManagerProduct::on_pushButton_3_clicked()
{
    QString id;
    int amount;

    id = ui->txtUpdateAmount->text();
    amount = ui->txtSearchID->text().toUInt();

    int i= Checkbox(commoditieslist,"hello",id, amount, 8.8);
    if(i==-1){
     updateCommodities(commoditieslist, id, amount);
    // Truy cập vào widget bảng
    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
    populateTableWidget(tableWidget, commoditieslist);
    ui->txtUpdateAmount->clear();
    ui->txtSearchID ->clear();

    saveCommoditiesToFile(fileName, commoditieslist);
    }
    else{
     QMessageBox::information(this, "ID in Commodities", "Box emty or Wrong data type ");
     ui->txtUpdateAmount->clear();
     ui->txtSearchID->clear();
    }

}

