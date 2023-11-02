#include "managerproduct.h"
#include "commodities.h"
#include "ui_managerproduct.h"
#include "managerproduct.h"
#include <QString>
#include <string>
/*khái báo vector là toàn cục để lưu danh sách hàng hóa*/
vector<Commodities> commoditieslist;
/*Khái báo để lưu thông tin name id amount từ người dùng nhập vô*/
QString name;
QString Searchname;
QString id ;
unsigned int amount;
QString date ;
QString dateExp ;
double price ;
/*  */
QString fileName = "ManagerCommodities.txt";

ManagerProduct::ManagerProduct(QWidget *parent, bool& hasReadFileFlag) :
    QDialog(parent),
    ui(new Ui::ManagerProduct)
{
    ui->setupUi(this);
    /* */
    if (!hasReadFileFlag) {
        readCommoditiesFromFile(fileName,commoditieslist);
        hasReadFileFlag = true; // Đánh dấu rằng đã đọc file
    }    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ


    // Khai báo một hàng mới (để thêm một hàng mới)
    tableWidget->setRowCount(commoditieslist.size());

    // Đặt số lượng cột cho hàng này
    tableWidget->setColumnCount(6);
    tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("ID"));
    tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Amount"));
    tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Purchase Date"));
    tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Expiration Date"));
    tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Price"));
    qDebug() << "Size: " << commoditieslist.size(); // Output the ID for debugging

    // Đặt dữ liệu cho từng cột của hàng
    for(unsigned int i = 0; i < commoditieslist.size(); i++){
        QTableWidgetItem *nameItem = new QTableWidgetItem(commoditieslist[i].getName());
        QTableWidgetItem *idItem = new QTableWidgetItem(commoditieslist[i].getID());
        qDebug() << "Name: " << nameItem->text(); // Output the name for debugging
        qDebug() << "ID: " << idItem->text(); // Output the ID for debugging
        QTableWidgetItem *amountItem = new QTableWidgetItem(QString::number(commoditieslist[i].getAmountCommodities()));
        QTableWidgetItem *dateItem = new QTableWidgetItem(commoditieslist[i].getDateCommodities());
        QTableWidgetItem *dateexpItem = new QTableWidgetItem(commoditieslist[i].getDateExpCommodities());
        QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(commoditieslist[i].getPrice()));

        // Đặt dữ liệu vào từng cột tương ứng
        tableWidget->setItem(i, 0, nameItem);
        tableWidget->setItem(i, 1, idItem);
        tableWidget->setItem(i, 2, amountItem);
        tableWidget->setItem(i, 3, dateItem);
        tableWidget->setItem(i, 4, dateexpItem);
        tableWidget->setItem(i, 5, priceItem);
    }

    int columnWidth = 160;
    for (int col = 0; col < tableWidget->columnCount(); ++col) {
        tableWidget->setColumnWidth(col, columnWidth);
    }

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

    name = ui->txtName->text();
    id = ui->txtID->text();
    amount = ui->txtAmount->text().toUInt();
    date = ui->txtDate->text();
    dateExp = ui->txtDateExp->text();
    price = ui->txtPrice->text().toDouble();

    addcommodities(commoditieslist,name,id ,amount,date,dateExp,price);
    // Truy cập vào widget bảng
    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
    // Khai báo một hàng mới (để thêm một hàng mới)
    tableWidget->setRowCount(commoditieslist.size());

    // Đặt số lượng cột cho hàng này
    tableWidget->setColumnCount(6);
    tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("ID"));
    tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Amount"));
    tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Purchase Date"));
    tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Expiration Date"));
    tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Price"));
    qDebug() << "Size: " << commoditieslist.size(); // Output the ID for debugging

    // Đặt dữ liệu cho từng cột của hàng
    for(unsigned int i = 0; i < commoditieslist.size(); i++){
        QTableWidgetItem *nameItem = new QTableWidgetItem(commoditieslist[i].getName());
        QTableWidgetItem *idItem = new QTableWidgetItem(commoditieslist[i].getID());
        qDebug() << "Name: " << nameItem->text(); // Output the name for debugging
        qDebug() << "ID: " << idItem->text(); // Output the ID for debugging
        QTableWidgetItem *amountItem = new QTableWidgetItem(QString::number(commoditieslist[i].getAmountCommodities()));
        QTableWidgetItem *dateItem = new QTableWidgetItem(commoditieslist[i].getDateCommodities());
        QTableWidgetItem *dateexpItem = new QTableWidgetItem(commoditieslist[i].getDateExpCommodities());
        QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(commoditieslist[i].getPrice()));

        // Đặt dữ liệu vào từng cột tương ứng
        tableWidget->setItem(i, 0, nameItem);
        tableWidget->setItem(i, 1, idItem);
        tableWidget->setItem(i, 2, amountItem);
        tableWidget->setItem(i, 3, dateItem);
        tableWidget->setItem(i, 4, dateexpItem);
        tableWidget->setItem(i, 5, priceItem);
    }

    int columnWidth = 160;
    for (int col = 0; col < tableWidget->columnCount(); ++col) {
        tableWidget->setColumnWidth(col, columnWidth);
    }

    ui->txtName->clear();
    ui->txtID->clear();
    ui->txtAmount->clear();
    ui->txtDate->clear();
    ui->txtDateExp->clear();
    ui->txtPrice->clear();
    saveCommoditiesToFile(fileName,commoditieslist);

 }

/*Nút nhấn chỉnh sửa thông tin sản phẩm*/
void ManagerProduct::on_btnrepair_clicked()
{

}

// Nút nhấn tìm kiếm
void ManagerProduct::on_btnSearch_clicked()
{
    Searchname = ui->txtSearch->text();
    int i = findCommodity(commoditieslist, Searchname);

    // Truy cập vào widget bảng
    QTableWidget *tableWidget1 = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ

    // Xóa dữ liệu cũ trong bảng
    tableWidget1->setRowCount(0);

    // Đặt số lượng cột cho bảng
    tableWidget1->setColumnCount(6);
    tableWidget1->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    tableWidget1->setHorizontalHeaderItem(1, new QTableWidgetItem("ID"));
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

        tableWidget1->setItem(0, 0, nameItem);
        tableWidget1->setItem(0, 1, idItem);
        tableWidget1->setItem(0, 2, amountItem);
        tableWidget1->setItem(0, 3, dateItem);
        tableWidget1->setItem(0, 4, dateexpItem);
        tableWidget1->setItem(0, 5, priceItem);
    }

    int columnWidth = 160;
    for (int col = 0; col < tableWidget1->columnCount(); ++col) {
        tableWidget1->setColumnWidth(col, columnWidth);
    }

    ui->txtSearch->clear();
}

