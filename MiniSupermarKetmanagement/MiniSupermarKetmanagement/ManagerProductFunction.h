//#ifndef MANAGERPRODUCTFUNCTION_H
//#define MANAGERPRODUCTFUNCTION_H

//#include "commodities.h"

namespace ManagerProductFuntion
{

//void addcommodities(vector<Commodities>& addCommodities,QString defaultName, QString defaultID,
//                    unsigned int defaultAmountCommodities, QString defaultDateCommodities,
//                    QString defaultDateExpCommodities, double defaultPrice )
//{
//    Commodities newCommodities;
//    newCommodities.setName(defaultName);
//    newCommodities.setID(defaultID);
//    newCommodities.setAmountCommodities(defaultAmountCommodities);
//    newCommodities.setDateCommodities(defaultDateCommodities);
//    newCommodities.setDateExpCommodities(defaultDateExpCommodities);
//    newCommodities.setPrice(defaultPrice);
//    addCommodities.push_back(newCommodities);
//}

//int findCommodity(const vector<Commodities>& commoditieslist, const QString& searchName) {
//    for (int i = 0; i < commoditieslist.size(); i++) {
//        if (commoditieslist[i].getName() == searchName) {
//            return i; // Trả về chỉ số của sản phẩm nếu tên sản phẩm khớp
//        }
//    }
//    return -1; // Trả về -1 nếu không tìm thấy sản phẩm
//}

//void saveCommoditiesToFile(const QString& filename, const vector<Commodities>& commoditiesList) {
//    QFile file(filename);

//    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//        QTextStream out(&file);

//        for (const Commodities& commodity : commoditiesList) {
//            out << "Name: " << commodity.getName() << " | ";
//            out << "ID: " << commodity.getID() << " | ";
//            out << "Amount: " << commodity.getAmountCommodities() << " | ";
//            out << "Purchase Date: " << commodity.getDateCommodities() << " | ";
//            out << "Expiration Date: " << commodity.getDateExpCommodities() << " | ";
//            out << "Price: " << commodity.getPrice() << "\n";
//        }

//        file.close();
//    } else {
//        // Xử lý lỗi mở tệp
//    }
//}



//void readCommoditiesFromFile(const QString& filename, vector<Commodities>& commoditiesList) {
//    QFile file(filename);

//    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        QTextStream in(&file);

//        while (!in.atEnd()) {
//            QString line = in.readLine();
//            QStringList tokens = line.split(" | ");
//            if (tokens.size() == 6) {
//                QString name = tokens[0].section("Name: ", 1, 1);
//                QString id = tokens[1].section("ID: ", 1, 1);
//                unsigned int amount = tokens[2].section("Amount: ", 1, 1).toUInt();
//                QString date = tokens[3].section("Purchase Date: ", 1, 1);
//                QString dateExp = tokens[4].section("Expiration Date: ", 1, 1);
//                double price = tokens[5].section("Price: ", 1, 1).toDouble();

//                // Tạo một đối tượng Commodities và thêm vào danh sách
//                Commodities newCommodities;
//                newCommodities.setName(name);
//                newCommodities.setID(id);
//                newCommodities.setAmountCommodities(amount);
//                newCommodities.setDateCommodities(date);
//                newCommodities.setDateExpCommodities(dateExp);
//                newCommodities.setPrice(price);
//                commoditiesList.push_back(newCommodities);
//            }
//        }

//        file.close();
//    } else {
//        // Xử lý lỗi mở tệp
//    }
//}

//void searchcommodities(vector<Commodities>& addCommodities, const QString& id, const Commodities& updatedCommodity) {

//    // Nếu không tìm thấy sản phẩm với ID tương ứng, bạn có thể xử lý hoặc báo lỗi ở đây.
//}

}

//#endif // MANAGERPRODUCTFUNCTION_H
