#include "InvoiceManagement.h"
#include "ui_InvoiceManagement.h"
#include "QString"
#include "invoice.h"
#include "_customers.h"
#include "commodities.h"
#include <vector>
#include <iostream>
#include <cctype>
#include <QDebug>

QString FileListOfProducts = "ManagerCommodities.txt";
InvoiceManagement::InvoiceManagement(QWidget *parent) : QDialog(parent),
                                                        ui(new Ui::InvoiceManagement)
{
    ui->setupUi(this);
    ui->tableWidgetItem->setColumnWidth(0, 256);
    ui->tableWidgetItem->setColumnWidth(1, 256);
    ui->tableWidgetItem->setColumnWidth(2, 256);
    ui->tableWidgetItem->setColumnWidth(3, 256);

    QFile file("CustomerManagament_DATA");
    if (file.open(QIODevice::ReadOnly  | QIODevice::Text))
    {
        QTextStream in(&file);

        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList tokens = line.split(" | ");
            if (tokens.size() == 6)
            {
                QString name = tokens[0].section("Name: ", 1, 1);
                QString dob = tokens[1].section("DOB: ", 1, 1);
                QString phone_number = tokens[2].section("Phone: ", 1, 1);
                unsigned int point = tokens[3].section("Point: ", 1, 1).toUInt();
                QString date = tokens[4].section("Date: ", 1, 1);
                QString id = tokens[5].section("ID: ", 1, 1);

                CustomerList.push_back(_customers(point, phone_number, dob, name, date, id));

            }
        }
    }
    file.close();
}

InvoiceManagement::~InvoiceManagement()
{
    delete ui;
}

void InvoiceManagement::closeEvent(QCloseEvent *event)
{
    for (size_t indexOfInvoice = 0; indexOfInvoice < NewInvoice.getItems().size(); ++indexOfInvoice)
    {
        for (size_t indexOfStorage = 0; indexOfStorage < commoditieslist.size(); ++indexOfStorage)
        {
            if (NewInvoice.getItems()[indexOfInvoice].commodities.getID() == commoditieslist[indexOfStorage].getID())
            {
                unsigned int ItemInStorage = commoditieslist[indexOfStorage].getAmountCommodities();
                ItemInStorage += NewInvoice.getItems()[indexOfInvoice].amount;
                commoditieslist[indexOfStorage].setAmountCommodities(ItemInStorage);
                break;
            }
        }
    }
    // commoditieslist.clear();
}

void InvoiceManagement::on_Btn_AddItem_clicked()
{
    QString ProductID = "";
    ProductID += ui->TxtBox_ProductID->text();
    // Commodities *TempTypeOfProduct;

    for (char c : ui->TxtBox_Amount->text().toStdString())
    {
        if (!std::isdigit(c))
        {
            ui->TxtBox_Amount->setText("Invalid");
            return;
        }
    }

    unsigned int Amount = (ui->TxtBox_Amount->text()).toUInt();

    if (Amount <= 0)
    {
        ui->TxtBox_Amount->setText("Invalid");
        return;
    }

    // qInfo() << "txtbox" <<Amount;
    for (size_t counter = 0; counter < commoditieslist.size(); ++counter)
    {
        if (ProductID == commoditieslist[counter].getID())
        {
            // TempTypeOfProduct = &ListOfProducts[counter];
            // ProductName += ui->TxtBox_ProductName->text();
            if (NewInvoice.addToCart(commoditieslist[counter], Amount))
            {
                ui->tableWidgetItem->setRowCount(0);
                QTableWidgetItem *newProductID;
                QTableWidgetItem *newProductName;
                QTableWidgetItem *newAmount;
                QTableWidgetItem *newPrice;

                for (size_t j = 0; j < NewInvoice.getItems().size(); ++j)
                {
                    ui->tableWidgetItem->insertRow(ui->tableWidgetItem->rowCount());
                    newProductID = new QTableWidgetItem(NewInvoice.getItems()[j].commodities.getID());
                    newProductName = new QTableWidgetItem(NewInvoice.getItems()[j].commodities.getName());
                    newAmount = new QTableWidgetItem(QString::number(NewInvoice.getItems()[j].amount));

                    // qInfo() << NewInvoice.getItems()[j].amount << Amount;

                    newPrice = new QTableWidgetItem(QString::number(NewInvoice.getItems()[j].commodities.getPrice() * NewInvoice.getItems()[j].amount));

                    ui->tableWidgetItem->setItem((ui->tableWidgetItem->rowCount() - 1), 0, newProductID);
                    ui->tableWidgetItem->setItem((ui->tableWidgetItem->rowCount() - 1), 1, newProductName);
                    ui->tableWidgetItem->setItem((ui->tableWidgetItem->rowCount() - 1), 2, newAmount);
                    ui->tableWidgetItem->setItem((ui->tableWidgetItem->rowCount() - 1), 3, newPrice);
                }
                clearWhenPressAddItemButton();
                //                break;
            }
            else
            {
                ui->TxtBox_Amount->setText("Not enough in stroge");
            }
            break;
        }
    }

    double TotalPriceOfCart = NewInvoice.sumOfInvoice();
    NewInvoice.setTotalPrice(TotalPriceOfCart);
    ui->TxtBox_Total->setText(QString::number(NewInvoice.getTotalPrice()));
    // delete TempTypeOfProduct;
}

void InvoiceManagement::on_Btn_Print_clicked()
{
    if (ui->comboBox_Customer->currentIndex() == 0)
    {
        if (ui->TxtBox_CustomerID->text().isEmpty() || ui->TxtBox_CustomerName->text().isEmpty() || ui->TxtBox_PhoneNumber->text().isEmpty())
        {
            QMessageBox::information(this,"Message",
                                     "Please fill in all customer information",
                                     QMessageBox::Ok);
            return;
        }

        for ( _customers &customer : CustomerList)
        {
            //_customers CustomerNeedToFind("", "", "");
            if (customer.getID() == ui->TxtBox_CustomerID->text())
            {
                //CustomerNeedToFind = customer;
                NewInvoice.setCustomerID(customer.getID());
                NewInvoice.setCustomerName(customer.getName());
                NewInvoice.setCustomerPhoneNumber(customer.getPhoneNumber());
                break;
            }
            QMessageBox::information(this,"Message",
                                     "Not already a member!",
                                     QMessageBox::Ok);
            return;
        }
        clearWhenPressPrintButton();

    }
    else if (ui->comboBox_Customer->currentIndex() == 1)
    {
        if (ui->TxtBox_CustomerName->text().isEmpty() || ui->TxtBox_PhoneNumber->text().isEmpty())
        {
            QMessageBox::information(this,"Message",
                                     "Please fill in customer information",
                                     QMessageBox::Ok);
            return;
        }
        QString NewCustomerName = ui->TxtBox_CustomerName->text();
        QString NewCustomerPhoneNumber = ui->TxtBox_PhoneNumber->text();
        for ( _customers &customer : CustomerList)
        {
            if (customer.getPhoneNumber() == ui->TxtBox_PhoneNumber->text())
            {
                QMessageBox::information(this,"Message",
                                         "Already a member!",
                                         QMessageBox::Ok);
                return;
            }
        }
        _customers NewCustomer(NewCustomerName,"none", NewCustomerPhoneNumber, 0);
        CustomerList.push_back(NewCustomer);


        //
        QFile file("CustomerManagament_DATA");

        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);

            for ( _customers &customer : CustomerList)
            {
                out << "Name: " << customer.getName() << " | ";
                out << "DOB: " << customer.getDOB() << " | ";
                out << "Phone: " << customer.getPhoneNumber() << " | ";
                out << "Point: " << customer.getPoint() << " | ";
                out << "Date: "  << " | ";
                out << "ID: " << customer.getID() << "\n\n";
                qInfo() << customer.getID() << customer.getName() << customer.getPhoneNumber() ;
                if (customer.getPhoneNumber() == NewCustomerPhoneNumber)
                {
                    NewCustomer = customer;
                }
            }

            file.close();
        }
        else
        {
            // Xử lý lỗi mở tệp
        }
        //

        NewInvoice.setCustomerID(NewCustomer.getID());
        NewInvoice.setCustomerName(NewCustomer.getName());
        NewInvoice.setCustomerPhoneNumber(NewCustomer.getPhoneNumber());
        clearWhenPressPrintButton();

    }
    // NewInvoice.~Invoice();
}

void InvoiceManagement::on_TxtBox_ProductID_textChanged(const QString &arg1)
{
}

void InvoiceManagement::clearWhenPressAddItemButton()
{
    ui->TxtBox_ProductName->clear();
    ui->TxtBox_ProductID->clear();
    ui->TxtBox_Amount->clear();
}

void InvoiceManagement::clearWhenPressPrintButton()
{
    if (NewInvoice.printInvoice())
    {
        saveCommoditiesToFile(FileListOfProducts, commoditieslist);
        ui->TxtBox_CustomerID->clear();
        ui->TxtBox_CustomerName->clear();
        ui->TxtBox_PhoneNumber->clear();
        ui->TxtBox_ProductName->clear();
        ui->TxtBox_ProductID->clear();
        ui->TxtBox_Amount->clear();
        NewInvoice.setTotalPrice(0.0);
        ui->TxtBox_Total->setText(QString::number(NewInvoice.getTotalPrice()));
        ui->tableWidgetItem->setRowCount(0);
        NewInvoice.clear();
        QMessageBox::information(this,"Message",
                                 "Invoices has been printed",
                                 QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this,"Message",
                                 "No Items In Cart!",
                                 QMessageBox::Ok);
    }

}

void InvoiceManagement::on_tableWidgetItem_cellClicked(int row, int column)
{
}

void InvoiceManagement::on_tableWidgetItem_cellDoubleClicked(int row, int column)
{
    QString text = ui->tableWidgetItem->itemAt(row, column)->text();
    // ui->TxtBox_ProductID->setText(text);
    for (size_t counter = 0; counter < NewInvoice.getItems().size(); ++counter)
    {
        if (text == NewInvoice.getItems()[counter].commodities.getID())
        {
            //
            for (size_t indexOfStorage = 0; indexOfStorage < commoditieslist.size(); ++indexOfStorage)
            {
                if (text == commoditieslist[indexOfStorage].getID())
                {
                    unsigned int ItemInStorage = commoditieslist[indexOfStorage].getAmountCommodities();
                    ItemInStorage += NewInvoice.getItems()[counter].amount;
                    commoditieslist[indexOfStorage].setAmountCommodities(ItemInStorage);
                    break;
                }
            }
            //
            NewInvoice.removeAnItemInCart(counter);
            //
            ui->tableWidgetItem->setRowCount(0);
            QTableWidgetItem *newProductID;
            QTableWidgetItem *newProductName;
            QTableWidgetItem *newAmount;
            QTableWidgetItem *newPrice;

            for (size_t j = 0; j < NewInvoice.getItems().size(); ++j)
            {
                ui->tableWidgetItem->insertRow(ui->tableWidgetItem->rowCount());
                newProductID = new QTableWidgetItem(NewInvoice.getItems()[j].commodities.getID());
                newProductName = new QTableWidgetItem(NewInvoice.getItems()[j].commodities.getName());
                newAmount = new QTableWidgetItem(QString::number(NewInvoice.getItems()[j].amount));
                newPrice = new QTableWidgetItem(QString::number(NewInvoice.getItems()[j].commodities.getPrice() * NewInvoice.getItems()[j].amount));

                ui->tableWidgetItem->setItem((ui->tableWidgetItem->rowCount() - 1), 0, newProductID);
                ui->tableWidgetItem->setItem((ui->tableWidgetItem->rowCount() - 1), 1, newProductName);
                ui->tableWidgetItem->setItem((ui->tableWidgetItem->rowCount() - 1), 2, newAmount);
                ui->tableWidgetItem->setItem((ui->tableWidgetItem->rowCount() - 1), 3, newPrice);
            }

            double TotalPriceOfCart = NewInvoice.sumOfInvoice();
            NewInvoice.setTotalPrice(TotalPriceOfCart);
            ui->TxtBox_Total->setText(QString::number(NewInvoice.getTotalPrice()));
            //
            break;
        }
    }
}

void InvoiceManagement::on_TxtBox_ProductName_editingFinished()
{
    QString Name = "";
    Name += ui->TxtBox_ProductName->text();
    Commodities TempTypeOfProduct;
    for (int counter = 0; counter < commoditieslist.size(); ++counter)
    {
        if (Name == commoditieslist[counter].getName())
        {
            TempTypeOfProduct = commoditieslist[counter];
            ui->TxtBox_ProductID->setText(TempTypeOfProduct.getID());
            ui->TxtBox_Amount->setText(QString::number(TempTypeOfProduct.getAmountCommodities()));
            break;
        }
        else
        {
            ui->TxtBox_ProductID->setText("Not found Product");
            ui->TxtBox_Amount->setText("Not found Product");
        }
    }
}

void InvoiceManagement::on_Btn_Refresh_clicked()
{
    ui->TxtBox_ProductID->clear();
    ui->TxtBox_ProductName->clear();
    ui->TxtBox_Amount->clear();
}

void InvoiceManagement::on_TxtBox_ProductID_editingFinished()
{
    QString ProductID = "";
    ProductID += ui->TxtBox_ProductID->text();
    Commodities TempTypeOfProduct;
    for (int counter = 0; counter < commoditieslist.size(); ++counter)
    {
        if (ProductID == commoditieslist[counter].getID())
        {
            TempTypeOfProduct = commoditieslist[counter];
            ui->TxtBox_ProductName->setText(TempTypeOfProduct.getName());
            ui->TxtBox_Amount->setText(QString::number(TempTypeOfProduct.getAmountCommodities()));
            break;
        }
        else
        {
            ui->TxtBox_ProductName->setText("Not found Product");
            ui->TxtBox_Amount->setText("Not found Product");
        }
    }
}

void InvoiceManagement::on_comboBox_Customer_activated(int index)
{
    switch (index)
    {
    case 0:
        if ( ui->TxtBox_CustomerID->text() == "ID will be auto generate!")
        {
            ui->TxtBox_CustomerID->clear();
        }
        ui->TxtBox_CustomerID->setReadOnly(false);
        break;
    case 1:
        ui->TxtBox_CustomerID->clear();
        ui->TxtBox_CustomerID->setReadOnly(true);
        ui->TxtBox_CustomerID->setText("ID will be auto generate!");
        break;
        /*defaut:
            ui->TxtBox_CustomerID->isModified()*/
        ;
    }
    //    if ( index == 0)
    //        ui->TxtBox_CustomerID->isModified();
    //    else
    //        ui->TxtBox_CustomerID->isReadOnly();
}

void InvoiceManagement::on_TxtBox_PhoneNumber_editingFinished()
{
    if (ui->comboBox_Customer->currentIndex() == 0)
    {
        for ( _customers &customer : CustomerList)
        {
            if (customer.getPhoneNumber() == ui->TxtBox_PhoneNumber->text())
            {
                ui->TxtBox_CustomerName->setText(customer.getName());
                ui->TxtBox_CustomerID->setText(customer.getID());
                break;
            }
        }
    }
}

