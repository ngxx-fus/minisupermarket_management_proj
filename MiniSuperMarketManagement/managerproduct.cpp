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
QString fileName = "./App_data/ManagerCommodities_DATA";
QString idedit;

ManagerProduct::ManagerProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagerProduct)
{

    ui->setupUi(this);
    ui->Editcommodities->hide();
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
    if(Checkbox1(commoditieslist,name, id, amount, price)){
        if(CheckboxID(commoditieslist, id)){

        }else{

            QMessageBox::information(this, "ERROR", " ERROR ID ");

        }
        if(CheckboxName(commoditieslist, name)){

        }else{

            QMessageBox::information(this, "ERROR", " ERROR Name ");

        }
        if(CheckboxAmount(commoditieslist, amount)){

        }else{
            ui->txtAmount->clear();

            QMessageBox::information(this, "ERROR", " ERROR Amount ");
        }
        if (CheckboxPrice(commoditieslist, price)){

        }else{
            ui->txtPrice->clear();

            QMessageBox::information(this, "ERROR", " ERROR Price ");
        }
        if (DateAnalysis(day, month, year, dayexp,  monthexp,  yearexp )){

        }else{
            QMessageBox::information(this, "ERROR", "Invalid date");
        }
        if(CompareDate(day,month, year, dayexp, monthexp, yearexp)){

        }else {

            QMessageBox::information(this, "ERROR", "ERROR ExpDate ");
        }

    }else{
          QMessageBox::information(this, "ERROR", " Box emty ");


    }

    if(Checkbox1(commoditieslist,name, id, amount, price)){
        if(CheckboxID(commoditieslist, id)){
            if(CheckboxName(commoditieslist, name)){
                if(CheckboxAmount(commoditieslist, amount)){

                    if (CheckboxPrice(commoditieslist, price)){

                        if (DateAnalysis(day, month, year, dayexp,  monthexp,  yearexp )){

                            if(CompareDate(day,month, year, dayexp, monthexp, yearexp)){

                                int i =  findCommodity(commoditieslist, id);

                                if(i == -1){

                                    addcommodities(commoditieslist, name, id, amount, date, dateExp, price );

                                    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
                                    populateTableWidget(tableWidget, commoditieslist);

                                    ui->txtName->clear();
                                    ui->txtID->clear();
                                    ui->txtAmount->clear();
                                    ui->txtPrice->clear();

                                    saveCommoditiesToFile(fileName,commoditieslist);

                                }

                                else {

                                    ui->txtID->clear();

                                    QMessageBox::information(this, "ERROR", "ID is already in the list, please enter a new ID");
                                }



                            }
                        }
                     }
                }
            }
        }
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
    if (CheckboxID(commoditieslist, SearchID)){
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
    }else{

        QMessageBox::information(this, "ERROR", "ID Empty");
        QTableWidget *tableWidget = ui->tableWidget;
        populateTableWidget(tableWidget, commoditieslist);


    }

    int columnWidth = 160;
    for (int col = 0; col < tableWidget1->columnCount(); ++col) {
        tableWidget1->setColumnWidth(col, columnWidth);
    }

    ui->txtSearch->clear();
}

/*giảm theo số lượng sản phẩm*/
void ManagerProduct::on_radioButton_clicked()
{
    SortIncrease(commoditieslist);
    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
    populateTableWidget(tableWidget, commoditieslist);
}

/*tăng theo số lượng sản phẩm*/
void ManagerProduct::on_radioButton_2_clicked()
{
    SortDecrease(commoditieslist);
    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
    populateTableWidget(tableWidget, commoditieslist);

}

/*Xóa sản phẩm*/
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
    if (CheckboxID(commoditieslist, SearchID)){
        if(i != -1){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(nullptr, "", "Are you sure you want to delete this product?",
                                              QMessageBox::Ok | QMessageBox::Cancel);

                if (reply == QMessageBox::Ok) {
                    Delete(commoditieslist, SearchID);
                    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
                    populateTableWidget(tableWidget, commoditieslist);
                    saveCommoditiesToFile(fileName,commoditieslist);
                    ui->txtSearch->clear();

                }
                else{
                    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
                    populateTableWidget(tableWidget, commoditieslist);
                    ui->txtSearch->clear();

                }

            }
            else {


                QMessageBox::information(this, "ID ERROR", "The specified ID does not exist.");
                populateTableWidget(tableWidget1, commoditieslist);

            }

    }else{

            QMessageBox::information(this, "ERROR", "ID Empty");
             QTableWidget *tableWidget = ui->tableWidget;
            populateTableWidget(tableWidget, commoditieslist);


    }

    }


/*thêm số lượng sản phẩm*/
void ManagerProduct::on_pushButton_3_clicked()
{
    QString id;
    int amount;

    id = ui->txtUpdateAmount->text();
    amount = ui->txtSearchID->text().toUInt();

    updateCommodities(commoditieslist, id, amount);
    if(CheckboxAmount(commoditieslist, amount)){
       // updateCommodities(commoditieslist, id, amount);
        // Truy cập vào widget bảng
        QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
        populateTableWidget(tableWidget, commoditieslist);
        ui->txtUpdateAmount->clear();
        ui->txtSearchID ->clear();

        saveCommoditiesToFile(fileName, commoditieslist);
    }
    else{
        QMessageBox::information(this, "ERROR", "ERROR Amount ");
        ui->txtUpdateAmount->clear();
        ui->txtSearchID->clear();
    }


}

/*Chỉnh sửa sản phẩm*/
void ManagerProduct::on_Editcommodities_clicked()
{
    ui->txtID->setReadOnly(false);
    ui->Editcommodities->hide();
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

    if (Checkbox(commoditieslist, name, id, amount, price))
    {
        if (DateAnalysis(day, month, year, dayexp,  monthexp,  yearexp )){

            if(CompareDate(day,month, year, dayexp, monthexp, yearexp)){

            EditCommodities(commoditieslist,id, name,amount ,date, dateExp,price );
            QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
            populateTableWidget(tableWidget, commoditieslist);

            ui->txtName->clear();
            ui->txtID->clear();
            ui->txtAmount->clear();
            ui->txtPrice->clear();
            saveCommoditiesToFile(fileName,commoditieslist);


            }
            else {

                ui->txtName->clear();
                ui->txtID->clear();
                ui->txtAmount->clear();
                ui->txtPrice->clear();

                QMessageBox::information(this, "ID in Commodities", "ERRON ExpDate ");

            }
        }

        else {

            QMessageBox::information(this, "ID in Commodities", "Invail date");

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

/*Sự kiện click vào bảng*/
void ManagerProduct::on_tableWidget_cellDoubleClicked(int row, int column)
{
    int cur_row = row;
    int day, month, year;
    int dayexp, monthexp, yearexp;
    ui->txtID->setText(ui->tableWidget->item(cur_row, 0)->text());
    ui->txtName->setText(ui->tableWidget->item(cur_row, 1)->text());
    ui->txtAmount->setText(ui->tableWidget->item(cur_row, 2)->text());
    ui->txtPrice->setText(ui->tableWidget->item(cur_row, 5)->text());
    parseDate(ui->tableWidget->item(cur_row, 3)->text(), day, month, year);
    parseDate(ui->tableWidget->item(cur_row, 4)->text(), dayexp, monthexp, yearexp);
    idedit = ui->txtID->text();
    ui->comboBox->setCurrentText(QString::number(month));
    ui->comboBox_2->setCurrentText(QString::number(day));
    ui->comboBox_3->setCurrentText(QString::number(year));

    ui->comboBox_7->setCurrentText(QString::number(monthexp));
    ui->comboBox_8->setCurrentText(QString::number(dayexp));
    ui->comboBox_9->setCurrentText(QString::number(yearexp));
    //--------------
    ui->Editcommodities->show();
    ui->txtID->setReadOnly(true);

}


void ManagerProduct::on_tableWidget_cellActivated(int row, int column)
{

}

/*Sắp xếp theo còn nhiều ngày gần hết hạn*/
void ManagerProduct::on_radioButton_3_clicked()
{
    sortmoreDates(commoditieslist);
    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
    populateTableWidget(tableWidget, commoditieslist);

}

/*Sắp xếp theo còn i ngày gần hết hạn*/
void ManagerProduct::on_radioButton_4_clicked()
{
    sortDates(commoditieslist);
    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
    populateTableWidget(tableWidget, commoditieslist);

}


void ManagerProduct::on_pushButton_4_clicked()
{
    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
    populateTableWidget(tableWidget, commoditieslist);
}


void ManagerProduct::on_exp_clicked()
{
    bool checkexpdate;
    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
    populateTableWidget_expdate(tableWidget, commoditieslist, checkexpdate);
    if(checkexpdate){
        populateTableWidget(tableWidget, commoditieslist);
    }


}


void ManagerProduct::on_pushButton_5_clicked()
{
    deteExpDate(commoditieslist);
    QTableWidget *tableWidget = ui->tableWidget;  // Đảm bảo rằng "ui->tableWidget" là hợp lệ
    populateTableWidget(tableWidget, commoditieslist);
    saveCommoditiesToFile(fileName,commoditieslist);

}

