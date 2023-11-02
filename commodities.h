#ifndef COMMODITIES_H
#define COMMODITIES_H
#include <QTextStream>
#include <QFile>

#include <QTableWidgetItem>
#include <QString>
#include "template_class.h"
#include <iostream>
#include <fstream>
class Commodities : public templateClass, public QTableWidgetItem , public QTableWidget{
private:
    unsigned int amountCommodities;
    QString dateCommodities;        // Change to QString
    QString dateExpCommodities;     // Change to QString
    double price;

public:
    Commodities() {}

    /*Lỗi xuất hiện do bạn gặp vấn đề về việc sao chép đối tượng Commodities trong hàm addcommodities.
     *  Lớp Commodities chứa các thành phần có thể không được sao chép một cách đơn giản bởi hàm sao chép mặc định.
     *  Mặc định, C++ sẽ tạo một hàm sao chép (Commodities::Commodities(const Commodities&)) nhưng có thể bị xóa (deleted)
     *   nếu Commodities chứa các thành phần không thể sao chép, ví dụ như con trỏ hoặc tham chiếu.
    Cách để giải quyết vấn đề này là phải xác định một hàm sao chép tùy chỉnh cho lớp Commodities nếu nó chứa các thành phần không thể sao chép.
 Dưới đây là cách bạn có thể thực hiện điều đó:*/
    Commodities(const QString& name, const QString& ID, const QString& dateCom, int amount, const QString& dateExp, double price)
        : templateClass(name, ID), dateCommodities(dateCom),amountCommodities(amount), dateExpCommodities(dateExp), price(price) {}

    // Copy constructor for Commodities
    Commodities(const Commodities& other)
        : templateClass(other), dateCommodities(other.dateCommodities),amountCommodities(other.amountCommodities), dateExpCommodities(other.dateExpCommodities), price(other.price) {
        // If there are complex components or pointers, make sure to copy them correctly.
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

void addcommodities(vector<Commodities>& addCommodities,QString defaultName, QString defaultID, unsigned int defaultAmountCommodities, QString defaultDateCommodities, QString defaultDateExpCommodities, double defaultPrice ) {
    Commodities newCommodities;
    newCommodities.setName(defaultName);
    newCommodities.setID(defaultID);
    newCommodities.setAmountCommodities(defaultAmountCommodities);
    newCommodities.setDateCommodities(defaultDateCommodities);
    newCommodities.setDateExpCommodities(defaultDateExpCommodities);
    newCommodities.setPrice(defaultPrice);
    addCommodities.push_back(newCommodities);

}

int findCommodity(const vector<Commodities>& commoditieslist, const QString& searchName) {
    for (int i = 0; i < commoditieslist.size(); i++) {
        if (commoditieslist[i].getName() == searchName) {
            return i; // Trả về chỉ số của sản phẩm nếu tên sản phẩm khớp
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy sản phẩm
}

void saveCommoditiesToFile(const QString& filename, const vector<Commodities>& commoditiesList) {
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        for (const Commodities& commodity : commoditiesList) {
            out << "Name: " << commodity.getName() << " | ";
            out << "ID: " << commodity.getID() << " | ";
            out << "Amount: " << commodity.getAmountCommodities() << " | ";
            out << "Purchase Date: " << commodity.getDateCommodities() << " | ";
            out << "Expiration Date: " << commodity.getDateExpCommodities() << " | ";
            out << "Price: " << commodity.getPrice() << "\n";
        }

        file.close();
    } else {
        // Xử lý lỗi mở tệp
    }
}

void readCommoditiesFromFile(const QString& filename, vector<Commodities>& commoditiesList) {
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList tokens = line.split(" | ");
            if (tokens.size() == 6) {
                QString name = tokens[0].section("Name: ", 1, 1);
                QString id = tokens[1].section("ID: ", 1, 1);
                unsigned int amount = tokens[2].section("Amount: ", 1, 1).toUInt();
                QString date = tokens[3].section("Purchase Date: ", 1, 1);
                QString dateExp = tokens[4].section("Expiration Date: ", 1, 1);
                double price = tokens[5].section("Price: ", 1, 1).toDouble();

                // Tạo một đối tượng Commodities và thêm vào danh sách
                Commodities newCommodities;
                newCommodities.setName(name);
                newCommodities.setID(id);
                newCommodities.setAmountCommodities(amount);
                newCommodities.setDateCommodities(date);
                newCommodities.setDateExpCommodities(dateExp);
                newCommodities.setPrice(price);
                commoditiesList.push_back(newCommodities);
            }
        }

        file.close();
    } else {
        // Xử lý lỗi mở tệp
    }
}


void searchcommodities(vector<Commodities>& addCommodities, const QString& id, const Commodities& updatedCommodity) {

    // Nếu không tìm thấy sản phẩm với ID tương ứng, bạn có thể xử lý hoặc báo lỗi ở đây.
}



#endif // COMMODITIES_H
