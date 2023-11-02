#include "InvoiceManagement.h"
#include "ui_InvoiceManagement.h"
#include "QString"
#include "invoice.h"
#include "commodities.h"
#include <vector>
#include <iostream>
#include <cctype>
#include<QDebug>


QString FileListOfProducts = "ManagerCommodities.txt";

InvoiceManagement::InvoiceManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InvoiceManagement)
{
    ui->setupUi(this);
    ui->tableWidgetItem->setColumnWidth(0, 256);
    ui->tableWidgetItem->setColumnWidth(1, 256);
    ui->tableWidgetItem->setColumnWidth(2, 256);
    ui->tableWidgetItem->setColumnWidth(3, 256);
}

InvoiceManagement::~InvoiceManagement()
{
    delete ui;
}

void InvoiceManagement::on_Btn_AddItem_clicked()
{
    QString ProductID = "";
    ProductID += ui->TxtBox_ProductID->text();
    //Commodities *TempTypeOfProduct;

    for (char c : ui->TxtBox_Amount->text().toStdString()) {
        if (!std::isdigit(c)) {
            ui->TxtBox_Amount->setText("Invalid");
            return;
        }
    }

    unsigned int Amount = (ui->TxtBox_Amount->text()).toUInt();
    qInfo() << Amount;
    for (size_t counter = 0; counter < commoditieslist.size() ; ++counter) {
        if ( ProductID == commoditieslist[counter].getID() )
        {

            //TempTypeOfProduct = &ListOfProducts[counter];
            //ProductName += ui->TxtBox_ProductName->text();
            if (NewInvoice.addToCart( commoditieslist[counter], Amount))
            {

                ui->tableWidgetItem->setRowCount(0);
                QTableWidgetItem *newProductID;
                QTableWidgetItem *newProductName;
                QTableWidgetItem *newAmount;
                QTableWidgetItem *newPrice;

                for (size_t j = 0; j < NewInvoice.getItems().size() ; ++j)
                {
                    ui->tableWidgetItem->insertRow(ui->tableWidgetItem->rowCount());
                    newProductID = new QTableWidgetItem(NewInvoice.getItems()[j].commodities.getID());
                    newProductName = new QTableWidgetItem(NewInvoice.getItems()[j].commodities.getName());
                    newAmount = new QTableWidgetItem(QString::number(NewInvoice.getItems()[j].amount));
                    newPrice = new QTableWidgetItem( QString::number(NewInvoice.getItems()[j].commodities.getPrice() * NewInvoice.getItems()[j].amount) );

                    ui->tableWidgetItem->setItem( (ui->tableWidgetItem->rowCount()  - 1), 0, newProductID);
                    ui->tableWidgetItem->setItem( (ui->tableWidgetItem->rowCount()  - 1), 1, newProductName);
                    ui->tableWidgetItem->setItem( (ui->tableWidgetItem->rowCount()  - 1), 2, newAmount);
                    ui->tableWidgetItem->setItem( (ui->tableWidgetItem->rowCount()  - 1), 3, newPrice);
                }

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
    ui->TxtBox_Total->setText( QString::number(NewInvoice.getTotalPrice()) );
    //delete TempTypeOfProduct;
}


void InvoiceManagement::on_Btn_Print_clicked()
{
    if (ui->TxtBox_CustomerID->text().isEmpty()
        || ui->TxtBox_CustomerName->text().isEmpty()
        || ui->TxtBox_PhoneNumber ->text().isEmpty())
    {
        return;
    }

    NewInvoice.setCustomerID(ui->TxtBox_CustomerID->text());
    NewInvoice.setCustomerName(ui->TxtBox_CustomerName->text());
    NewInvoice.setCustomerPhoneNumber(ui->TxtBox_PhoneNumber->text());

    NewInvoice.printInvoice();
    saveCommoditiesToFile(FileListOfProducts, commoditieslist);


    NewInvoice.getItems().clear();
    ui->TxtBox_CustomerID->clear();
    ui->TxtBox_CustomerName->clear();
    ui->TxtBox_PhoneNumber->clear();
    ui->TxtBox_ProductName->clear();
    ui->TxtBox_ProductID->clear();
    ui->TxtBox_Amount->clear();
    NewInvoice.setTotalPrice(0.0);
    ui->TxtBox_Total->setText( QString::number(NewInvoice.getTotalPrice()));
    ui->tableWidgetItem->setRowCount(0);
    //NewInvoice.~Invoice();
}



void InvoiceManagement::on_TxtBox_ProductID_textChanged(const QString &arg1)
{
    QString ProductID = "";
    ProductID += ui->TxtBox_ProductID->text();
    Commodities TempTypeOfProduct;
    for (int counter = 0; counter < commoditieslist.size() ; ++counter) {
        if ( ProductID == commoditieslist[counter].getID() )
        {
            TempTypeOfProduct = commoditieslist[counter];
            ui->TxtBox_ProductName->setText(TempTypeOfProduct.getName());
            ui->TxtBox_Amount->setText(QString::number(TempTypeOfProduct.getAmountCommodities()));
            break;
        }
        else
            ui->TxtBox_ProductName->setText("Not found Product");
    }
}

