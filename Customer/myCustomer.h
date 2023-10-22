#ifndef MYCUSTOMER_H
#define MYCUSTOMER_H

#include "customers.h"


QT_BEGIN_NAMESPACE
namespace Ui { class myCustomer; }
QT_END_NAMESPACE

class myCustomer : public QMainWindow
{
private:
    Q_OBJECT
    Ui::myCustomer *ui;

public:
    myCustomer(QWidget *parent = nullptr);
    ~myCustomer();


private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
};
#endif // MYCUSTOMER_H
