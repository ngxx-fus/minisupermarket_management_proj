#include "my_customer.h"
#include "ui_my_customer.h"
#include <QString>



my_customer::my_customer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::my_customer)
{
    ui->setupUi(this);
    refresh_list_view();
}

void my_customer::set_layout_list_view(int const max_row, int const max_column){
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
    ui->tableWidget->setColumnWidth(4,130);
    //setup column 5
    ui->tableWidget->setColumnWidth(5,150);
}

void my_customer::refresh_list_view(){

    int const   max_column = 6,
                max_row = (qv_cus.size()<=20 ? qv_cus.size() : 20);

    set_layout_list_view(max_row, max_column);

    for(int r = max_row - 1, ind = 0; r >= (max_row<20?0:max_row-20); r--, ind++)
    {
        _customers cus = qv_cus.at(r);
        ui->tableWidget->setItem(ind,0, new QTableWidgetItem(cus.getName()));
        ui->tableWidget->setItem(ind,1, new QTableWidgetItem(cus.getDOB()));
        ui->tableWidget->setItem(ind,2, new QTableWidgetItem(cus.getPhoneNumber()));
        ui->tableWidget->setItem(ind,3, new QTableWidgetItem(_time().int_to_QString(cus.getPoint())));
        ui->tableWidget->setItem(ind,4, new QTableWidgetItem(cus.getLatestModification().get_date()));
        ui->tableWidget->setItem(ind,5, new QTableWidgetItem(cus.getID()));
    }
}

QVector<_customers>::iterator my_customer::find_by_ID(QString key_ID){
    QVector<_customers>::iterator it;
    bool found_it = false;
    for( it = qv_cus.begin(); it != qv_cus.end(); it++){
        if(it->getID() ==key_ID) {
            found_it = true;
            break;
        }
    }
    return found_it ? it : qv_cus.end();
}

QVector<_customers>::iterator my_customer::find_by_PhoneNumber(QString key_PhoneNumber){
    QVector<_customers>::iterator it;
    bool found_it = false;
    for( it = qv_cus.begin(); it != qv_cus.end(); it++){
        if(it->getPhoneNumber() == key_PhoneNumber) {
            found_it = true;
            break;
        }
    }
    return found_it ? it : qv_cus.end();
}

QVector< QVector<_customers>::iterator > my_customer::find_by_name(QString key_Name)
{
    QVector<_customers>::iterator it;
    QVector< QVector<_customers>::iterator > qv_it;
    bool found_it = false;
    for( it = qv_cus.begin(); it != qv_cus.end(); it++){
        if(it->getName() == key_Name) {
            qv_it.push_back(it);
        }
    }
    return qv_it;
}

void my_customer::add_customer(QString cus_name, QString cus_DOB, QString cus_phoneNumber, int cus_point){
    qv_cus.push_back(_customers(cus_name, cus_DOB, cus_phoneNumber, cus_point));
}

void my_customer::remove_by_phoneNumber(QString cus_phoneNumer){
    QVector<_customers>::iterator it = qv_cus.begin();
    //linear searching
    for(it = qv_cus.begin(); it != qv_cus.end(); it++){
        if(it->getPhoneNumber() == cus_phoneNumer) {
            break;
        }
    }
    QVector<_customers>::const_iterator const const_it = it;
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
    QFile file("demo_qt_write_file.txt");
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
    #define cus_numphone ui->lineEdit_NUMPHONE_ADD->text()
    #define cus_dob      ui->lineEdit_DOB_ADD->text()
    #define cus_name     ui->lineEdit_NAME_ADD->text()
    #define cus_point    ui->lineEdit_POINT_ADD->text().toInt()
    if( !cus_numphone.size() || !cus_name.size() )
    {
        _adding_error noti(this);
        noti.setModal(true);
        noti.exec();
        return;
    }

    if( this->find_by_PhoneNumber( cus_numphone ) == qv_cus.end() )
    {
        qv_cus.push_back( _customers(cus_name, cus_dob, cus_numphone, cus_point) );
        refresh_list_view();
        clear_all_text_in_add_box();
    }else{
        _added_customer_error err(this);
        err.setModal(true);
        err.exec();
    }

}

void my_customer::clear_all_text_in_add_box(){
    ui->lineEdit_NAME_ADD->clear();
    ui->lineEdit_DOB_ADD->clear();
    ui->lineEdit_NUMPHONE_ADD->clear();
    ui->lineEdit_POINT_ADD->clear();
}

void my_customer::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    clear_all_text_in_add_box();
}

void my_customer::on_pushButtonDelete_clicked()
{
    remove_by_phoneNumber(ui->lineEdit_NUMPHONE_ADD->text());
    refresh_list_view();
}

void my_customer::on_tableWidget_cellClicked(int row, int column)
{
    refresh_list_view();
}

void my_customer::on_pushButtonCancel_clicked()
{

}

