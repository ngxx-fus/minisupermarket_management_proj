#include "my_customer.h"
#include "ui_my_customer.h"
#include <QString>
#include <QTextStream>
#include <QFile>
#include <iostream>
#include <fstream>
#include <QMessageBox>


my_customer::my_customer(QDialog::QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::my_customer)
{
    auto_save = true;//set-up trong file
    ui->setupUi(this);
    ui->progressBar_FIND->hide();
    load_customers();
    ui->pushButton_RM_MOD->hide();
    ui->pushButtonUpdateInfo->hide();
    refresh_customers_list();
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

void my_customer::refresh_search_result_list(){

    int const   max_column = 6,
        max_row = qv_search_result.size();

    set_layout_list_view(max_row, max_column);

    for(int r = 0, ind = 0; r < max_row; r++, ind++)
    {
        auto cus = qv_search_result.at(r);
        ui->tableWidget->setItem(ind,0, new QTableWidgetItem(cus->getName()));
        ui->tableWidget->setItem(ind,1, new QTableWidgetItem(cus->getDOB()));
        ui->tableWidget->setItem(ind,2, new QTableWidgetItem(cus->getPhoneNumber()));
        ui->tableWidget->setItem(ind,3, new QTableWidgetItem(_time().int_to_QString(cus->getPoint())));
        ui->tableWidget->setItem(ind,4, new QTableWidgetItem(cus->getLatestModification().get_date()));
        ui->tableWidget->setItem(ind,5, new QTableWidgetItem(cus->getID()));
    }
}

void my_customer::refresh_customers_list(){

    int const   max_column = 6,
        max_row = (qv_cus.size()<20)?qv_cus.size():20;

    //ui->tableWidget->clear();
    set_layout_list_view(max_row, max_column);

    for(int r = qv_cus.size() - 1, ind = 0; r >= (qv_cus.size()<max_row?0:qv_cus.size()-max_row); r--, ind++)
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
    if(!key_ID.size())return  qv_cus.end();
    QVector<_customers>::iterator it;
    bool found_it = false;
    ui->progressBar_FIND->show();
    ui->progressBar_FIND->setRange(0, 100);
    int count_ = 0, all_ = qv_cus.size();
    for( it = qv_cus.begin(); it != qv_cus.end(); it++){
        ui->progressBar_FIND->setValue(++count_*100/all_);
        std::this_thread::sleep_for( std::chrono::milliseconds(10) );
        if(it->getID() ==key_ID) {
            found_it = true;
            break;
        }
    }
    ui->progressBar_FIND->setValue(100);
    ui->progressBar_FIND->hide();
    return found_it ? it : qv_cus.end();
}

QVector<_customers>::iterator my_customer::find_by_PhoneNumber(QString key_PhoneNumber){
    if(!key_PhoneNumber.size())return  qv_cus.end();
    QVector<_customers>::iterator it;
    bool found_it = false;
    ui->progressBar_FIND->show();
    ui->progressBar_FIND->setRange(0, 100);
    int count_ = 0, all_ = qv_cus.size();
    for( it = qv_cus.begin(); it != qv_cus.end(); it++){
        ui->progressBar_FIND->setValue(++count_*100/all_);
        std::this_thread::sleep_for( std::chrono::milliseconds(10) );
        if(it->getPhoneNumber() == key_PhoneNumber) {
            found_it = true;
            break;
        }
    }
    ui->progressBar_FIND->setValue(100);
    ui->progressBar_FIND->hide();
    return found_it ? it : qv_cus.end();
}

QVector< QVector<_customers>::iterator > my_customer::find_by_name(QString key_Name)
{
    QVector<_customers>::iterator it;
//    key_Name = string_standardizing(key_Name);
      key_Name = key_Name;

    QVector< QVector<_customers>::iterator > qv_it;
    if(!key_Name.size())return qv_it;
    ui->progressBar_FIND->show();
    ui->progressBar_FIND->setRange(0, 100);
    int count_ = 0, all_ = qv_cus.size();
    for( it = qv_cus.begin(); it != qv_cus.end(); it++){
        ui->progressBar_FIND->setValue(++count_*100/all_);
        std::this_thread::sleep_for( std::chrono::milliseconds(10) );
        if(it->getName() == key_Name) {
            qv_it.push_back(it);
        }
    }
    ui->progressBar_FIND->setValue(100);
    ui->progressBar_FIND->hide();
    return qv_it;
}

void my_customer::add_customer(QString cus_name, QString cus_DOB, QString cus_phoneNumber, int cus_point){
    qv_cus.push_back(_customers(cus_name, cus_DOB, cus_phoneNumber, cus_point));
    ui->progressBar_FIND->hide();
}

void my_customer::remove_by_phoneNumber(QString cus_phoneNumer){
    auto it = find_by_PhoneNumber(cus_phoneNumer);
    if(it == qv_cus.end())return;
    auto const const_it = it;
    qv_cus.erase(const_it);
}

void my_customer::load_customers()
{
    QFile file("CustomerManagament_DATA");
    int current_row = 0;

    ui->progressBar_FIND->setRange(0,100);
    ui->progressBar_FIND->show();
    ui->progressBar_FIND->setValue( 0 );

    if (file.open(QIODevice::ReadOnly  | QIODevice::Text))
    {
        QTextStream in(&file);

        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList tokens = line.split(" | ");
            if (tokens.size() == 6)
            {
                ui->progressBar_FIND->setValue( (++current_row)<80?current_row:80  );
                QString name = tokens[0].section("Name: ", 1, 1);
                QString dob = tokens[1].section("DOB: ", 1, 1);
                QString phone_number = tokens[2].section("Phone: ", 1, 1);
                unsigned int point = tokens[3].section("Point: ", 1, 1).toUInt();
                QString date = tokens[4].section("Date: ", 1, 1);
                QString id = tokens[5].section("ID: ", 1, 1);

                qv_cus.push_back(_customers(point, phone_number, dob, name, date, id));
                refresh_customers_list();
            }
        }
    }
    ui->progressBar_FIND->setValue( 100 );
    ui->progressBar_FIND->hide();
    file.close();
}

void my_customer::save_customers()
{
    ui->progressBar_FIND->setRange(0, 100);
    ui->progressBar_FIND->show();
    ui->progressBar_FIND->setValue(0);
    QString text;
    int current_row = ui->tableWidget->rowCount();
    QFile file("CustomerManagament_DATA");
    if (file.open(QIODevice::WriteOnly | QIODevice::ReadWrite))
    {
        QTextStream out(&file);

        for (int i = 0; i < current_row; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                ui->progressBar_FIND->setValue(int( i*100/(current_row*6)) );
                std::this_thread::sleep_for( std::chrono::milliseconds(10) );
                if(j == 0)
                {
                    text = ui->tableWidget->item(i, j)->text();
                    out << "Name: " << text << " | ";
                }
                else if (j == 1)
                {
                    text = ui->tableWidget->item(i, j)->text();
                    out << "DOB: " << text << " | ";
                }
                else if (j == 2)
                {
                    text = ui->tableWidget->item(i, j)->text();
                    out << "Phone: " << text << " | ";
                }
                else if (j == 3)
                {
                    text = ui->tableWidget->item(i, j)->text();
                    out << "Point: " << text << " | ";
                }
                else if (j == 4)
                {
                    text = ui->tableWidget->item(i, j)->text();
                    out << "Date: " << text << " | ";
                }
                else if (j == 5)
                {
                    text = ui->tableWidget->item(i, j)->text();
                    out << "ID: " << text <<"\n";
                }
            }
            out << "\n";
        }
    }
    ui->progressBar_FIND->setValue(100);
    ui->progressBar_FIND->hide();
    file.close();
}




my_customer::~my_customer()
{
    delete ui;
}

//---------------------------------------- declaration of private slot ----------------------------------------------

void my_customer::on_pushButtonADD_clicked()
{

    int const dd = ui->spinBox_DAY_ADD->value();
    int const mm = ui->spinBox_MONTH_ADD->value();
    int const yyyy = ui->spinBox_YEAR_ADD->value();
#define cus_numphone ui->lineEdit_NUMPHONE_ADD->text()
#define cus_name     ui->lineEdit_NAME_ADD->text()
#define cus_point    ui->lineEdit_POINT_ADD->text().toInt()

    _time DOB;
    if(DOB.set_DDMMYYYY(dd, mm, yyyy) == false){
        QMessageBox::information(this, "Date error!", "Plese enter the correct of DATE!");
        return;
    }

    if( !cus_numphone.size() )
    {
        QMessageBox::information(this, "Error!", "\"Name\" is empty! ");
        return;
    }

    if( !cus_name.size() )
    {
        QMessageBox::information(this, "Error!", "\"Phone number\" is empty! ");
        return;
    }

#define cus_DOB     DOB.get_date()

    if( this->find_by_PhoneNumber( cus_numphone ) == qv_cus.end() )
    {
        qv_cus.push_back( _customers(cus_name, cus_DOB, cus_numphone, cus_point) );
        refresh_customers_list();
        clear_all_text_in_add_box();
    }else{
        QMessageBox::information(this, "Error!", "The phone number has been added!");
    }
    save_customers();
}

void my_customer::clear_all_text_in_add_box(){
    ui->lineEdit_NAME_ADD->clear();
    ui->spinBox_DAY_ADD->clear();
    ui->spinBox_MONTH_ADD->clear();
    ui->spinBox_YEAR_ADD->clear();
    ui->lineEdit_NUMPHONE_ADD->clear();
    ui->lineEdit_POINT_ADD->clear();

    ui->progressBar_FIND->setValue(0);
    ui->progressBar_FIND->hide();
}

void my_customer::clear_all_text_in_find_box(){
    ui->lineEdit_DOB_FIND->clear();
    ui->lineEdit_NAME_FIND->clear();
    ui->lineEdit_NUMPHONE_FIND->clear();
    ui->lineEdit_ID_FIND->clear();
    ui->lineEdit_POINT_FIND->clear();

    ui->progressBar_FIND->setValue(0);
    ui->progressBar_FIND->hide();
}


void my_customer::on_tableWidget_cellClicked(int row, int column)
{
    //refresh_customers_list();
}

void my_customer::on_pushButtonCancel_clicked()
{
    clear_all_text_in_add_box();
}


void my_customer::on_pushButton_CLOSE_SEARCH_RES_clicked()
{
    qv_search_result.clear();
    clear_all_text_in_find_box();
    ui->pushButton_RM_MOD->hide();
    ui->pushButtonUpdateInfo->hide();
    refresh_customers_list();
}


void my_customer::on_pushButton_FIND_clicked()
{
    int opt = ui->comboBox->currentIndex();
    qv_search_result.clear();
    switch( opt )
    {
    case 0:
        qv_search_result = find_by_name( ui->lineEdit_NAME_FIND->text() );
        refresh_search_result_list();
        break;
    case 1:
        auto it = find_by_PhoneNumber( ui->lineEdit_NUMPHONE_FIND->text() );
        if( it == qv_cus.end() ) break;
        qv_search_result.push_back( it );
        refresh_search_result_list();
    };
}

void my_customer::on_pushButton_RM_MOD_clicked()
{
    remove_by_phoneNumber(ui->lineEdit_NUMPHONE_FIND->text());
    ui->pushButton_RM_MOD->hide();
    ui->pushButtonUpdateInfo->hide();
    refresh_customers_list();
    clear_all_text_in_find_box();
}

void my_customer::on_tableWidget_cellDoubleClicked(int row, int column)
{
    int cur_row = row;
    QString day, month, year;
    ui->lineEdit_NAME_FIND->setText(ui->tableWidget->item(cur_row, 0)->text());
    ui->lineEdit_NUMPHONE_FIND->setText(ui->tableWidget->item(cur_row, 2)->text());
    ui->lineEdit_DOB_FIND->setText(ui->tableWidget->item(cur_row, 1)->text());
    ui->lineEdit_POINT_FIND->setText(ui->tableWidget->item(cur_row, 3)->text());
    ui->lineEdit_ID_FIND->setText(ui->tableWidget->item(cur_row, 5)->text());

    //------------------------------
    ui->pushButton_RM_MOD->show();
    ui->pushButtonUpdateInfo->show();
}


void my_customer::on_pushButtonUpdateInfo_clicked()
{
    QString name = ui->lineEdit_NAME_FIND->text();
    QString dob = ui->lineEdit_DOB_FIND->text();
    QString phone_number = ui->lineEdit_NUMPHONE_FIND->text();
    int point = ui->lineEdit_POINT_FIND->text().toInt();
    QString id = ui->lineEdit_ID_FIND->text();
    //ui->tableWidget->item()

    QVector<_customers>::iterator it = qv_cus.begin();
    for(it = qv_cus.begin(); it != qv_cus.end(); it++)
    {
        if(it->getID() == id)
        {
            it->setName(name);
            it->setDOB(dob);
            it->setPhoneNumber(phone_number);
            it->setPoint(point);
            break;
        }
    }
    refresh_customers_list();
    if(auto_save) save_customers();
    ui->pushButton_RM_MOD->hide();
    ui->pushButtonUpdateInfo->hide();
    clear_all_text_in_find_box();
}

void my_customer::on_actionFactory_reset_triggered()
{
    qv_cus.clear();
    refresh_customers_list();
}


void my_customer::on_actionExport_season_triggered()
{
    save_customers();
}


void my_customer::on_pushButton__SORT_clicked()
{
//    switch( ui->comboBox_KEY__SORT->currentIndex() ){
//    case 0:
//        sort_by_name( ui->comboBox_OPTION_SORT->currentIndex() );
//        break;
//    case 1:
//        sort_by_accumulationPoint( ui->comboBox_OPTION_SORT->currentIndex() );
//        break;
//    };
//    refresh_customers_list();
}

