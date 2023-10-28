#ifndef MY_CUSTOMER_H
#define MY_CUSTOMER_H

#include "_customers.h"
#include <QMainWindow>
#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui { class my_customer; }
QT_END_NAMESPACE

class my_customer : public QMainWindow
{
    Q_OBJECT
    QVector<_customers> qv_cus;

public:
    my_customer(QWidget *parent = nullptr);

    void refresh_list_view();
    void remove_by_phoneNumber(QString cus_phoneNumber);
    void add_customer(QString cus_name, QString cus_phoneNumber, int cus_point);

    ~my_customer();



private slots:
    void on_pushButtonExportFile_clicked();


    void on_pushButtonADD_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_pushButtonDelete_clicked();

private:
    Ui::my_customer *ui;

};
#endif // MY_CUSTOMER_H
