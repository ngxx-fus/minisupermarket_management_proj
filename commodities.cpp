#include "commodities.h"

int findCommodity(const vector<Commodities>& commoditieslist, const QString& searchID) {
    for (int i = 0; i < commoditieslist.size(); i++) {
        if (commoditieslist[i].getID() == searchID) {
            return i; // Trả về chỉ số của sản phẩm nếu tên sản phẩm khớp
        }
    }
    return -1 ; // Trả về -1 nếu không tìm thấy sản phẩm
}

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
void SortIncrease(vector<Commodities>& commoditiesList) {
    sort(commoditiesList.begin(), commoditiesList.end(), [](const Commodities& amount1, const Commodities& amount2) {
        return amount1.getAmountCommodities() < amount2.getAmountCommodities();
    });
}

void SortDecrease(vector<Commodities>& commoditiesList) {
    sort(commoditiesList.begin(), commoditiesList.end(), [](const Commodities& amount1, const Commodities& amount2) {
        return amount1.getAmountCommodities() > amount2.getAmountCommodities();

    });
}

void Delete(vector<Commodities>& commoditiesList, QString defaultID) {
    int indexToDelete= findCommodity(commoditiesList, defaultID);
    commoditiesList.erase(commoditiesList.begin() + indexToDelete);

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
void updateCommodities(vector<Commodities>& commoditieslist, const QString& searchID, int newAmount) {
    int k = findCommodity(commoditieslist, searchID);
    if (k != -1) {
        commoditieslist[k].setAmountCommodities(commoditieslist[k].getAmountCommodities() + newAmount);
    }
    else {
        // Hiển thị thông báo bằng QMessageBox
        QMessageBox messageBox;
        messageBox.critical(0, "ERROR", "Don't ID: " + searchID + " in CommoditiesList");
        messageBox.setFixedSize(500, 200); // Tuỳ chỉnh kích thước của MessageBox
     //   messageBox.exec();
    }
}
void CompareDate(vector<Commodities>& commoditieslist, int day ,int month, int year,int expday, int expmonth, int expyear,
                 QString defaultName, QString defaultID, unsigned int defaultAmountCommodities, QString defaultDateCommodities, QString defaultDateExpCommodities, double defaultPrice  ){


    if (year < 2023 || expyear < 2023 ||
        day < 1 || day > 31 ||
        expday < 1 || expday > 31||
        expmonth < 1 || expmonth > 12||
        month < 1 || month > 12 ) {

        QMessageBox messageBox;
        messageBox.critical(0, "ERROR", " Vui lòng nhập lại ");
        messageBox.setFixedSize(500, 200); // Tuỳ chỉnh kích thước của MessageBox
     //   messageBox.exec();
    }
    else{
        QDate currentDate(year, month, day);
        QDate expDate(expyear, expmonth, expday);

        if (currentDate <= expDate){

            addcommodities( commoditieslist,defaultName, defaultID, defaultAmountCommodities, defaultDateCommodities,defaultDateExpCommodities,defaultPrice );
        }
        else {
            QMessageBox messageBox;
            messageBox.critical(0, "ERROR", "nhập sai hạn sử dụng");
            messageBox.setFixedSize(500, 200); // Tuỳ chỉnh kích thước của MessageBox
          //  messageBox.exec();
        }


    }

}
int  Checkbox(vector<Commodities>& commoditieslist,QString defaultName, QString defaultID, unsigned int defaultAmountCommodities, double defaultPrice  ){
    if(defaultName.isEmpty() || defaultID.isEmpty() ||  defaultAmountCommodities == 0 || defaultPrice == 0.0 )
    {
        return 1;

    }
    else
        return -1;
}



void populateTableWidget(QTableWidget* tableWidget, const vector<Commodities>& commoditieslist) {
    tableWidget->setRowCount(commoditieslist.size());
    tableWidget->setColumnCount(6);
    tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
    tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Amount"));
    tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Purchase Date"));
    tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Expiration Date"));
    tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Price"));

    int columnWidth = 160;
    for (int col = 0; col < tableWidget->columnCount(); ++col) {
        tableWidget->setColumnWidth(col, columnWidth);
    }

    for (int i = 0; i < commoditieslist.size(); i++) {
        QTableWidgetItem* idItem = new QTableWidgetItem(commoditieslist[i].getID());
        QTableWidgetItem* nameItem = new QTableWidgetItem(commoditieslist[i].getName());
        QTableWidgetItem* amountItem = new QTableWidgetItem(QString::number(commoditieslist[i].getAmountCommodities()));
        QTableWidgetItem* dateItem = new QTableWidgetItem(commoditieslist[i].getDateCommodities());
        QTableWidgetItem* dateexpItem = new QTableWidgetItem(commoditieslist[i].getDateExpCommodities());
        QTableWidgetItem* priceItem = new QTableWidgetItem(QString::number(commoditieslist[i].getPrice()));

        tableWidget->setItem(i, 0, idItem);
        tableWidget->setItem(i, 1, nameItem);
        tableWidget->setItem(i, 2, amountItem);
        tableWidget->setItem(i, 3, dateItem);
        tableWidget->setItem(i, 4, dateexpItem);
        tableWidget->setItem(i, 5, priceItem);
    }
}

int nhuan(int a)
{
    if (a % 400 == 0)
        return 1;
    else
        if ((a % 4 == 0) && (a % 100 != 0))
            return 1;
        else
            return 0;
}
