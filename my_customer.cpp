#include "my_customer.h"
#include "ui_my_customer.h"
#include <QString>



my_customer::my_customer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::my_customer)
{
    ui->setupUi(this);
    add_customer("Nguyen Thanh Phu", "10/08/2002", "0845939722", 100);
    add_customer("Nguyen Hong Son", "10/08/2002", "0845234622", 190);
    add_customer("Nguyen Minh Tuan", "10/08/2002", "0845235672", 200);
    add_customer("Hoang Xuan Bach", "10/08/2002", "0376235672", 200);
    refresh_list_view();
}

void my_customer::refresh_list_view(){

    int const max_column = 6,
        max_row = (qv_cus.size()<=100 ? qv_cus.size() : 100);

    ui->tableWidget->setRowCount(max_row);
    ui->tableWidget->setColumnCount(max_column);

    //setup column 0
    ui->tableWidget->setColumnWidth(0,150);

    //setup column 1
    ui->tableWidget->setColumnWidth(1,130);

    //setup column 2
    ui->tableWidget->setColumnWidth(2,130);

    //setup column 3
    ui->tableWidget->setColumnWidth(3,150);

    //setup column 4
    ui->tableWidget->setColumnWidth(4,200);

    //setup column 5
    ui->tableWidget->setColumnWidth(5,250);

//    for(int r = 0; r < max_row; r++){
    for(int r = max_row - 1; r >= 0; r--)
    {
        _customers cus = qv_cus.at(r);
        ui->tableWidget->setItem((max_row - 1)- r,0, new QTableWidgetItem(cus.getName()));
        ui->tableWidget->setItem((max_row - 1)- r,1, new QTableWidgetItem(cus.getDOB()));
        ui->tableWidget->setItem((max_row - 1)- r,2, new QTableWidgetItem(cus.getPhoneNumber()));
        ui->tableWidget->setItem((max_row - 1)- r,3, new QTableWidgetItem(_time().int_to_QString(cus.getPoint())));
        ui->tableWidget->setItem((max_row - 1)- r,4, new QTableWidgetItem(cus.getLatestModification().get_date()));
        ui->tableWidget->setItem((max_row - 1)- r,5, new QTableWidgetItem(cus.getID()));

    }
}

void my_customer::add_customer(QString cus_name, QString cus_dob, QString cus_phoneNumber, int cus_point){
    qv_cus.push_back(_customers(cus_name, cus_dob, cus_phoneNumber, cus_point));
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

void my_customer::on_pushButtonExportFile_clicked()
{
    QString text;
    int current_row = ui->tableWidget->rowCount();
    QFile file("E:/demo_qt_write_file.txt");
    //    if (!file.open(QFile::WriteOnly | QFile::Text))
    //    {
    //        QMessageBox::warning(this, "Message", "File can not open!!!");
    //    }
    if (file.open(QIODevice::WriteOnly | QIODevice::ReadWrite))
    {
        QTextStream out(&file);

        for (int i = 0; i < current_row; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                text = ui->tableWidget->item(i, j)->text();
                out << text;
                out << "  ";
                file.flush();
            }
            out << "\n";
        }
    }
    file.close();
}

void my_customer::on_pushButtonADD_clicked()
{
//    int current_row = ui->tableWidget->rowCount();
//    ui->tableWidget->insertRow(current_row);

    add_customer(ui->textEditName->toPlainText(), ui->textEditDOB->toPlainText(),
                 ui->textEditPhoneNumber->toPlainText(), ui->textEditPoint->toPlainText().toInt());
    check_customer();
    refresh_list_view();

    //    _customers cus = qv_cus.at(current_row);
//    ui->tableWidget->setItem(current_row,0, new QTableWidgetItem(cus.getName()));
//    ui->tableWidget->setItem(current_row,1, new QTableWidgetItem(cus.getPhoneNumber()));
//    ui->tableWidget->setItem(current_row,2, new QTableWidgetItem(_time().int_to_QString(cus.getPoint())));
//    ui->tableWidget->setItem(current_row,3, new QTableWidgetItem(cus.getLatestModification().get_date()));
//    ui->tableWidget->setItem(current_row,4, new QTableWidgetItem(cus.getID()));

}

void my_customer::on_pushButtonDelete_clicked()
{
    remove_by_phoneNumber(ui->textEditPhoneNumberDelete->toPlainText());
    refresh_list_view();

//    int indexPhoneNumber;

//    int current_row = ui->tableWidget->rowCount();

//    for (int i = 0; i < current_row; i++)
//    {
//        QString text = ui->tableWidget->item(i, 1)->text();
//        if(text == ui->textEditPhoneNumberDelete->toPlainText())
//        {
//            indexPhoneNumber = i;
//            break;
//        }
//    }

//    ui->tableWidget->removeRow(indexPhoneNumber);
}

void my_customer::check_customer()
{
    int max_row = (qv_cus.size()<=100 ? qv_cus.size() : 100);
    _customers temp_cus = qv_cus.at(max_row - 1);
    for(int i = 0; i < (max_row - 1); i++)
    {
        _customers cus = qv_cus.at(i);
        if((temp_cus.getName() == cus.getName()) && (temp_cus.getPhoneNumber() == cus.getPhoneNumber()))
        {
            remove_by_phoneNumber(cus.getPhoneNumber());
                break;
        }
        else if((temp_cus.getPhoneNumber() == cus.getPhoneNumber()) || temp_cus.getName() == "")
        {
            qv_cus.pop_back();
            break;
        }
    }
}


void my_customer::on_tableWidget_cellClicked(int row, int column)
{
    refresh_list_view();
}


void my_customer::on_tableWidget_itemClicked(QTableWidgetItem *item)
{

}




