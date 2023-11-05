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
void EditCommodities(vector<Commodities>& addCommodities, QString newID, QString newName, unsigned int newAmount, QString newDate, QString newDateExp, double newPrice) {
    int i = findCommodity(commoditieslist, newID);
    // Tìm thấy đối tượng cần chỉnh sửa dựa trên ID

    // Thực hiện các thay đổi
    addCommodities[i].setName(newName);
    addCommodities[i].setAmountCommodities(newAmount);
    addCommodities[i].setDateCommodities(newDate);
    addCommodities[i].setDateExpCommodities(newDateExp);
    addCommodities[i].setPrice(newPrice);


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
bool CompareDate(int day ,int month, int year,int expday, int expmonth, int expyear){
    QDate currentDate(year, month, day);
    QDate expDate(expyear, expmonth, expday);

    if (currentDate <= expDate){

        return true;
    }
    else {
        return false;

    }

}

bool  Checkbox(vector<Commodities>& commoditieslist,QString defaultName, QString defaultID, unsigned int defaultAmountCommodities, double defaultPrice  ){
    if(defaultName.isEmpty() || defaultID.isEmpty() ||  defaultAmountCommodities == 0 || defaultPrice == 0.0 )
    {
        return false;

    }
    else
        return true;
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
        if (commoditieslist[i].getAmountCommodities() == 0) {
            QBrush redBrush(QColor(255, 0, 0));  // Red color
            amountItem->setForeground(redBrush);
        }
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


bool LeapYears(int year)
{
    if (year % 400 == 0)
        return true;
    else
        if ((year % 4 == 0) && (year % 100 != 0))
            return true;
        else
            return false;
}
bool DateAnalysis(int day, int month, int year, int expday, int expmonth, int expyear ) {

    if (((month == 1) || (month == 3) || (month == 5) || (month == 7) ||
         (month == 8) || (month == 10) || (month == 12)) &&( (expmonth == 1) || (expmonth == 3) || (expmonth == 5) || (expmonth == 7) ||
            (expmonth == 8) || (expmonth == 10) || (expmonth == 12)))
    {
        if ((day > 31) || (expday > 31))

        return false;
        else
            return true;
    }
    else
    {
        if ( ((month == 2) && (LeapYears(year) == true)) ){
            if (day > 29)
                return false;
            else
                return true;

        }
        if ( ((expmonth == 2) && (LeapYears(expyear) == true)) ){
            if  (expday > 29)
                return false;
            else
                return true;
        }

        if (month == 2) {
            if (day > 28 )
                return false;
            else
                return true;
        }
        if (expmonth == 2) {
            if ( expday > 28)
                return false;
            else
                return true;
        }

        else{
            if (day > 30 || expday > 30)
                return false;
            else
                return true;
        }

    }
}


void parseDate(QString dateString, int &day, int &month, int &year) {
    int firstSlashPos = dateString.indexOf("/");
    int secondSlashPos = dateString.indexOf("/", firstSlashPos + 1);
    if (firstSlashPos != -1 && secondSlashPos != -1) {
        day = dateString.left(firstSlashPos).toInt();
        month = dateString.mid(firstSlashPos + 1, secondSlashPos - firstSlashPos - 1).toInt();
        year = dateString.mid(secondSlashPos + 1).toInt();
    }
}

bool isDateNearCurrentDate(const QString& date, const int daysThreshold) {
    int day, month, year;
    parseDate(date, day, month, year);

    QDate currentDate = QDate::currentDate();
    QDate givenDate(year, month, day);

    return currentDate.daysTo(givenDate) <= daysThreshold;
}

//void  sortDates(vector<Commodities>& commoditiesList, int daysThreshold) {
//    QDate currentDate = QDate::currentDate();

//   sort(commoditiesList.begin(), commoditiesList.end(), [daysThreshold](const Commodities& a, const Commodities& b) {
//        return isDateNearCurrentDate(a.getDateExpCommodities(), daysThreshold) >= isDateNearCurrentDate(b.getDateExpCommodities(), daysThreshold);
//    });

//    // Sau khi sắp xếp, bạn có thể in danh sách commoditiesList ở đây.
//}
//void  sortmoreDates(vector<Commodities>& commoditiesList, int daysThreshold) {
//   QDate currentDate = QDate::currentDate();

//   sort(commoditiesList.begin(), commoditiesList.end(), [daysThreshold](const Commodities& a, const Commodities& b) {
//       return isDateNearCurrentDate(a.getDateExpCommodities(), daysThreshold) < isDateNearCurrentDate(b.getDateExpCommodities(), daysThreshold);
//   });

//}
bool compareDates(const QString& date1, const QString& date2) {
    int day1, month1, year1;
    int day2, month2, year2;

    parseDate(date1, day1, month1, year1);
    parseDate(date2, day2, month2, year2);

    if (year1 < year2 || (year1 == year2 && month1 < month2) || (year1 == year2 && month1 == month2 && day1 < day2)) {
        return false; // Ngày 1 đứng trước ngày 2
    }

    return true; // Ngày 2 đứng trước ngày 1 hoặc cùng một ngày
}

void sortDates(vector<Commodities>& commoditiesList) {
    sort(commoditiesList.begin(), commoditiesList.end(), [](const Commodities& a, const Commodities& b) {
        return compareDates(a.getDateExpCommodities(), b.getDateExpCommodities());
    });
}
//bool compareDates1(const QString& date1, const QString& date2) {
//    int day1, month1, year1;
//    int day2, month2, year2;

//    parseDate(date1, day1, month1, year1);
//    parseDate(date2, day2, month2, year2);

//    if (year1 < year2 || (year1 == year2 && month1 < month2) || (year1 == year2 && month1 == month2 && day1 < day2)) {
//        return true; // Ngày 1 đứng trước ngày 2
//    }

//    return false; // Ngày 2 đứng trước ngày 1 hoặc cùng một ngày
//}
void sortmoreDates(vector<Commodities>& commoditiesList) {
   sort(commoditiesList.begin(), commoditiesList.end(), [](const Commodities& a, const Commodities& b) {
        return !compareDates(a.getDateExpCommodities(), b.getDateExpCommodities());
    });
}
