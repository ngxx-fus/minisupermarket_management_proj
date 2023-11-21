#ifndef COMMODITIES_H
#define COMMODITIES_H
#include <QTextStream>
#include <QFile>

#include <QTableWidgetItem>
#include <QString>
#include "template_class.h"
#include <iostream>
#include <fstream>
#include<QMessageBox>
#include <QDate>
void addcommodities();
class Commodities : public templateClass, public QTableWidgetItem , public QTableWidget{
private:
    unsigned int amountCommodities;
    QString dateCommodities;        // Change to QString
    QString dateExpCommodities;     // Change to QString
    double price;

public:
    Commodities() {}

    Commodities(const QString& name, const QString& ID, const QString& dateCom, int amount, const QString& dateExp, double price)
        : templateClass(name, ID, "none"), dateCommodities(dateCom), amountCommodities(amount), dateExpCommodities(dateExp), price(price) {}
    Commodities(const Commodities& other)
        : templateClass(other),
        dateCommodities(other.dateCommodities),
        amountCommodities(other.amountCommodities),
        dateExpCommodities(other.dateExpCommodities),
        price(other.price)
    {
        // Nếu có các thành phần không thể sao chép như con trỏ hoặc tham chiếu, bạn cần xác định sao chép chúng ở đây.
    }
    Commodities& operator=(const Commodities& other)
    {
        if (this == &other)
            return *this; // Tránh gán cho chính nó

        templateClass::operator=(other);
        dateCommodities = other.dateCommodities;
        amountCommodities = other.amountCommodities;
        dateExpCommodities = other.dateExpCommodities;
        price = other.price;

        return *this;
    }
    ~Commodities() {}


    void setAmountCommodities(unsigned int newAmountCommodities) {
        this->amountCommodities = newAmountCommodities;
    }

    unsigned int getAmountCommodities() const {
        return this->amountCommodities;
    }

    void setDateCommodities(QString newDateCommodities) {    // Change to QString
        this->dateCommodities = newDateCommodities;
    }

    QString getDateCommodities()const  {                           // Change to QString
        return this->dateCommodities;
    }

    void setDateExpCommodities(QString newDateExpCommodities) {  // Change to QString
        this->dateExpCommodities = newDateExpCommodities;
    }

    QString getDateExpCommodities() const {                         // Change to QString
        return this->dateExpCommodities;
    }

    void setPrice(double newPrice) {
        this->price = newPrice;
    }

    double getPrice()const  {
        return this->price;
    }

};
extern vector<Commodities> commoditieslist;
int findCommodity(const vector<Commodities>& commoditieslist, const QString& searchID);
void addcommodities(vector<Commodities>& addCommodities, QString defaultName, QString defaultID, unsigned int defaultAmountCommodities, QString defaultDateCommodities, QString defaultDateExpCommodities, double defaultPrice);
void SortIncrease(vector<Commodities>& commoditiesList);
void SortDecrease(vector<Commodities>& commoditiesList);
void Delete(vector<Commodities>& commoditiesList, QString defaultID);
void saveCommoditiesToFile(const QString& filename, const vector<Commodities>& commoditiesList);
void readCommoditiesFromFile(const QString& filename, vector<Commodities>& commoditiesList);
void updateCommodities(vector<Commodities>& commoditieslist, const QString& searchID, int newAmount);
bool Checkbox(vector<Commodities>& commoditieslist, QString defaultName, QString defaultID, unsigned int defaultAmountCommodities, double defaultPrice);
bool Checkbox1(vector<Commodities>& commoditieslist, QString defaultName, QString defaultID, unsigned int defaultAmountCommodities, double defaultPrice);
bool  CheckboxAmount(vector<Commodities>& commoditieslist, unsigned int defaultAmountCommodities);
bool  CheckboxName(vector<Commodities>& commoditieslist,QString defaultName  );
bool  CheckboxID(vector<Commodities>& commoditieslist, QString defaultID );
bool  CheckboxPrice(vector<Commodities>& commoditieslist, double defaultPrice  );
void populateTableWidget(QTableWidget* tableWidget, const vector<Commodities>& commoditieslist);
bool LeapYears(int year);
bool DateAnalysis(int day, int month, int year, int expday, int expmonth, int expyear ) ;
void parseDate(QString dateString, int &day, int &month, int &year);
void EditCommodities(vector<Commodities>& addCommodities, QString newID, QString newName, unsigned int newAmount, QString newDate, QString newDateExp, double newPrice);
bool CompareDate(int day ,int month, int year,int expday, int expmonth, int expyear);
void sortmoreDates(vector<Commodities>& commoditiesList);
void sortDates(vector<Commodities>& commoditiesList);
void populateTableWidget_expdate(QTableWidget* tableWidget, const vector<Commodities>& commoditieslist, bool &checkexpdate);
void deteExpDate(std::vector<Commodities>& commoditiesList);
#endif // COMMODITIES_H
