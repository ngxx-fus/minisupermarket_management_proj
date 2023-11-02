#ifndef INVOICE_H
#define INVOICE_H

#include <fstream>
#include <string>
#include <ctime>
#include "template_class.h"
#include "commodities.h"
#include <vector>
#include <QDateTime>
#include <QString>
#include <iostream>
#include <string>

using namespace std;

struct itemInCart
{
    Commodities commodities;
    unsigned int amount;
};

class Invoice : public templateClass
{
private:
    QString customerName;
    QString customerID;
    QString customerPhoneNumber;
    QString dayBuy;
    double TotalPrice;
    vector <itemInCart> ItemsInCart;

public:

    Invoice();

    ~Invoice();

    vector<itemInCart> getItems(){ return ItemsInCart;}

    void setCustomerName(QString );

    void setCustomerID(QString );

    void setCustomerPhoneNumber(QString );

    void setDayBuy(QString dayBuy);

    QString getCustomerName();

    QString getCustomerID();

    QString getCustomerPhoneNumber();

    QString getDayBuy();

    void setTotalPrice(double TotalPrice);

    double getTotalPrice();

    bool addToCart(Commodities &commodities, unsigned int amounInCart);

    double sumOfInvoice();

    QString generateInvoiceID();

    void printInvoice();

};


#endif // INVOICE_H
