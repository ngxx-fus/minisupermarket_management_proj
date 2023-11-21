#ifndef MY_CUSTOMER_H
#define MY_CUSTOMER_H

#include <QDialog>
#include "_customers.h"
#include <unistd.h>
#include <chrono>
#include <thread>
//#include <QMainWindow>
#include <algorithm>
#include <QtWidgets/qtwidgetsglobal.h>
#include <QtWidgets/qwidget.h>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <iostream>
#include <fstream>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class my_customer; }
QT_END_NAMESPACE

class my_customer : public QDialog
{
    Q_OBJECT
    QVector<_customers> qv_cus;
    QVector< QVector<_customers>::iterator > qv_search_result;
    bool auto_save;//
    int def_row;
public:
    my_customer(QWidget *parent = nullptr);

    void computeLPSArray(QString& pat, int M, QVector<int>& lps);
    bool KMPSearch(QString pat, QString txt);

    //if *inp* is empty, inp = "unknown" (for DOB)
    inline QString add_UKNOWN(QString inp){return (inp.size()==0 ? "unknown" : inp);}
    //return a QVector<_customers>::iterator to element that PhoneNumber = key_PhoneNumber
    QVector<_customers>::iterator find_by_PhoneNumber(QString key_PhoneNumber);
    //return a QVector<_customers>::iterator to element that ID = key_ID
    QVector<_customers>::iterator find_by_ID(QString key_ID);
    //return a vector of QVector<_customers>::iterator consist of all elements that have name = key_Name
    QVector< QVector<_customers>::iterator > find_by_name(QString key_Name);

    //set up layout of list of customers
    void set_layout_list_view(int const max_row, int const max_column);
    //refresh list of customers
    void refresh_customers_list(int default_row);
    void refresh_search_result_list();
    void clear_all_text_in_add_box();
    void clear_all_text_in_find_box();

    //add a customer
    void add_customer(QString cus_name, QString cus_DOB, QString cus_phoneNumber, int cus_point);

    //_mode = 0 for ascending, _mode = 1 for descending
    void sort_by_name(bool _mode );

    //_mode = 0 for ascending, _mode = 1 for descending
    void sort_by_accumulationPoint(bool _mode );

    //_mode = 0 for ascending, _mode = 1 for descending
    void sort_by_ModificationTime(bool _mode );

    void notice_auto_save(bool enable = false){
        if(enable == true)
            QMessageBox::information(this,"Auto-save is enable!","Becarefully, Every action cann't undo!");
        else
            QMessageBox::information(this,"Auto-save is disable!","Attention, Every action cann't be auto saved, you have to save manualy!");
    }

    void save_config();
    void load_config();
    void save_customers();
    void load_customers();

    ~my_customer();

private slots:

    void on_pushButtonADD_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButtonCancel_clicked();

    void on_pushButton_CLOSE_SEARCH_RES_clicked();

    void on_pushButton_FIND_clicked();

    void on_pushButton_RM_MOD_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_pushButtonUpdateInfo_clicked();

    void on_actionFactory_reset_triggered();

    void on_actionExport_season_triggered();

    void on_pushButton__SORT_clicked();

    void on_actionAuto_save_triggered();

    void on_pushButton__LOAD_MORE_clicked();

    void on_pushButton__LOAD_LESS_clicked();

private:
    Ui::my_customer *ui;

};

#endif // MY_CUSTOMER_H
