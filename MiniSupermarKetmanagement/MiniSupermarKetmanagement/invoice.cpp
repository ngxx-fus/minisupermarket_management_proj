#include "invoice.h"
#include <iomanip>
Invoice::Invoice() : templateClass()
{
    setTotalPrice(0.0);
}

Invoice::~Invoice() {}

void Invoice::setCustomerName(QString customerName)
{
    this->customerName = customerName;
}

void Invoice::setCustomerID(QString customerID)
{
    this->customerID = customerID;
}

void Invoice::setCustomerPhoneNumber(QString customerPhoneNumber)
{
    this->customerPhoneNumber = customerPhoneNumber ;
}

QString Invoice::getCustomerName()
{
    return this->customerName;
}

QString Invoice::getCustomerID()
{
    return this->customerID;
}

QString Invoice::getCustomerPhoneNumber()
{
    return this->customerPhoneNumber;
}

//void setItems( size_t index)
//{
//    ItemsInCart[index] =;
//}

vector<itemInCart> Invoice::getItems()
{
    return this->ItemsInCart;
}
//
void Invoice::setDayBuy(QString dayBuy)
{
    this->dayBuy = dayBuy;
}
QString Invoice::getDayBuy()
{
    return this->dayBuy;
}
//
void Invoice::setTotalPrice(double TotalPrice)
{
    this->TotalPrice = TotalPrice;
}
//
double Invoice::getTotalPrice()
{
    return this->TotalPrice;
}

QString Invoice::generateInvoiceID() {
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yyyyMMdd-hhmmss");
    return dateTimeString;
}

bool Invoice::printInvoice()
{
    if (ItemsInCart.size() <= 0)
    {
        return false;
    }

    QDateTime currentDateTime = QDateTime::currentDateTime();
    setDayBuy(currentDateTime.toString("hh:mm:ss dd.MM.yyyy"));
    //QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
    std::string duongdanfile = ("D:\\" + currentDateTime.toString("yyyyMMddhhmmss") + ".txt").toStdString();
    ofstream File(duongdanfile, ios::out);
    File << "Invoice ID:\t" << generateInvoiceID().toStdString() << endl;
    File << "Purchase on:\t" <<  getDayBuy().toStdString() << endl;
    File << "Customer Name: " << getCustomerName().toStdString() << endl;
    File << "Customer ID: " << getCustomerID().toStdString() << endl;
    File << "Customer Phone Number: " << getCustomerPhoneNumber().toStdString() << endl << endl;

    for (size_t i = 0; i < ItemsInCart.size(); i++)
    {
        File << ItemsInCart[i].commodities.getName().toStdString() << "\t"
             << ItemsInCart[i].amount << "\t"
             << (ItemsInCart[i].commodities.getPrice() * ItemsInCart[i].amount) << endl;
    }
    File << "========================" << endl;
    File << "SUM PRICE: " << std::setw(9) << sumOfInvoice();
    File.close();
    return true;

}

bool Invoice::addToCart(Commodities &CommoditiesPtr, unsigned int amounInCart)
{
    bool trave = false;

    if ( CommoditiesPtr.getAmountCommodities() == 0)
        goto EndOfCode;
    //
    for (size_t i = 0; i < ItemsInCart.size(); i++)
    {
        if ( CommoditiesPtr.getID() == ItemsInCart[i].commodities.getID())
        {
            if (  (amounInCart <= CommoditiesPtr.getAmountCommodities()))
            {
                ItemsInCart[i].amount += amounInCart;

                unsigned int amountInStorage2 = CommoditiesPtr.getAmountCommodities();
                amountInStorage2 -= amounInCart;
                CommoditiesPtr.setAmountCommodities(amountInStorage2);
                trave = true;

                goto EndOfCode;
            }
        }
    }
    //
    if (amounInCart <= CommoditiesPtr.getAmountCommodities())
    {
        trave = true;

        unsigned int amountInStorage = CommoditiesPtr.getAmountCommodities();
        amountInStorage -= amounInCart;
        CommoditiesPtr.setAmountCommodities(amountInStorage);

        struct itemInCart NewItemsToCart;
        NewItemsToCart.amount = amounInCart;
        NewItemsToCart.commodities = CommoditiesPtr;
        ItemsInCart.push_back(NewItemsToCart);
    }

EndOfCode:
    return trave;
}

double Invoice::sumOfInvoice()
{
    double totalprice = 0;
    for (size_t counter = 0; counter < ItemsInCart.size(); counter++)
    {
        totalprice += ((ItemsInCart[counter].commodities.getPrice()) * (ItemsInCart[counter].amount));
    }
    return totalprice;
}

void Invoice::clear()
{
    setCustomerName("");
    setCustomerID("");
    setCustomerPhoneNumber("");
    setDayBuy("");
    setTotalPrice(0.0);
    //getItems().clear();
    ItemsInCart.clear();
}
