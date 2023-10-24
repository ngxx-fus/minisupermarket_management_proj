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
    QVector<customers*> m_customer;

public:

    myCustomer(QWidget *parent = nullptr);
    ~myCustomer();

    void handleItemClicked(QListWidgetItem* item) {
        qDebug() << "item clicked";
    }

    void addCustomer(customers* cus);//cus : customer
    void addCustomer(QString cus_name);
    void addCustomer(QString cus_name,
                    QString cus_ID,
                    QString cus_DOB,
                    QString cus_phoneNumber,
                    int cus_accumulationPoint);
    void removeCustomer(customers* cus);
    //this function return an position that stores *cus*
    unsigned int findByPtr(customers* cus){
        for(int i = 0; i < m_customer.size(); i++){
            if( m_customer[i] == cus ) return i;
        }
        return 0;
    }

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);
};
#endif // MYCUSTOMER_H
