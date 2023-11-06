/********************************************************************************
** Form generated from reading UI file 'InvoiceManagement.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVOICEMANAGEMENT_H
#define UI_INVOICEMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_InvoiceManagement
{
public:
    QPushButton *Btn_Print;
    QGroupBox *GrpBoxCustomer;
    QLineEdit *TxtBox_PhoneNumber;
    QLabel *Label_PhoneNumber;
    QLineEdit *TxtBox_CustomerName;
    QLabel *Label_CustomerName;
    QLabel *Label_CustomerID;
    QLineEdit *TxtBox_CustomerID;
    QComboBox *comboBox_Customer;
    QGroupBox *GrpBoxProduct;
    QLineEdit *TxtBox_ProductID;
    QLabel *Label_ProductID;
    QLineEdit *TxtBox_ProductName;
    QLabel *Label_ProdectName;
    QLabel *Label_Amount;
    QLineEdit *TxtBox_Amount;
    QPushButton *Btn_AddItem;
    QPushButton *Btn_Refresh;
    QTableWidget *tableWidgetItem;
    QLabel *Label_Total;
    QLineEdit *TxtBox_Total;
    QLabel *label;

    void setupUi(QDialog *InvoiceManagement)
    {
        if (InvoiceManagement->objectName().isEmpty())
            InvoiceManagement->setObjectName("InvoiceManagement");
        InvoiceManagement->resize(1000, 700);
        InvoiceManagement->setStyleSheet(QString::fromUtf8("QPushButton#Btn_Chose_Customer{\n"
"                   background-color: #0078A8; \n"
"                    color: white;\n"
"                    border: 2px solid #0078A8; \n"
"                   border-radius: 5px; \n"
"                   padding: 5px 10px;\n"
"                   font-weight: bolder;\n"
"                   }\n"
"QPushButton#Btn_AddItem{\n"
"                   background-color: #0078A8; \n"
"                    color: white;\n"
"                    border: 2px solid #0078A8; \n"
"                   border-radius: 5px; \n"
"                   padding: 5px 10px;\n"
"                   font-weight: bolder;\n"
"                   }\n"
"QPushButton#Btn_Print{\n"
"                   background-color: #0078A8; \n"
"                    color: white;\n"
"                    border: 2px solid #0078A8; \n"
"                   border-radius: 5px; \n"
"                   padding: 5px 10px;\n"
"                   font-weight: bolder;\n"
"                   }\n"
"QPushButton#Btn_Refresh{\n"
"                "
                        "   background-color: #0078A8; \n"
"                    color: white;\n"
"                    border: 2px solid #0078A8; \n"
"                   border-radius: 5px; \n"
"                   padding: 5px 10px;\n"
"                   font-weight: bolder;\n"
"                   }\n"
"QLineEdit#TxtBox_PhoneNumber{\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}\n"
"QLineEdit#TxtBox_CustomerID{\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303"
                        "\240 m\303\240u \304\221en */\n"
"}\n"
"QLineEdit#TxtBox_CustomerName{\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}\n"
"QLineEdit#TxtBox_ProductID{\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}\n"
"QLineEdit#TxtBox_ProductName{\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    pa"
                        "dding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}\n"
"QLineEdit#TxtBox_Amount{\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}\n"
"QLineEdit#TxtBox_Total{\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}\n"
"QDialog#InvoiceManagement\n"
"{\n"
"\n"
"   background-co"
                        "lor: #87CEFA; /* \304\220\341\272\267t m\303\240u n\341\273\201n 8472FF l\303\240 tr\341\272\257ng */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}  \n"
"QTableWidget#tableWidgetItem{\n"
"\n"
"   background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 10px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}  "));
        Btn_Print = new QPushButton(InvoiceManagement);
        Btn_Print->setObjectName("Btn_Print");
        Btn_Print->setGeometry(QRect(870, 640, 101, 41));
        GrpBoxCustomer = new QGroupBox(InvoiceManagement);
        GrpBoxCustomer->setObjectName("GrpBoxCustomer");
        GrpBoxCustomer->setGeometry(QRect(20, 60, 471, 231));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setStrikeOut(false);
        GrpBoxCustomer->setFont(font);
        TxtBox_PhoneNumber = new QLineEdit(GrpBoxCustomer);
        TxtBox_PhoneNumber->setObjectName("TxtBox_PhoneNumber");
        TxtBox_PhoneNumber->setGeometry(QRect(200, 140, 250, 31));
        Label_PhoneNumber = new QLabel(GrpBoxCustomer);
        Label_PhoneNumber->setObjectName("Label_PhoneNumber");
        Label_PhoneNumber->setGeometry(QRect(10, 145, 181, 21));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setStrikeOut(false);
        Label_PhoneNumber->setFont(font1);
        TxtBox_CustomerName = new QLineEdit(GrpBoxCustomer);
        TxtBox_CustomerName->setObjectName("TxtBox_CustomerName");
        TxtBox_CustomerName->setGeometry(QRect(200, 90, 250, 31));
        Label_CustomerName = new QLabel(GrpBoxCustomer);
        Label_CustomerName->setObjectName("Label_CustomerName");
        Label_CustomerName->setGeometry(QRect(10, 95, 151, 21));
        Label_CustomerName->setFont(font1);
        Label_CustomerID = new QLabel(GrpBoxCustomer);
        Label_CustomerID->setObjectName("Label_CustomerID");
        Label_CustomerID->setGeometry(QRect(10, 45, 121, 21));
        Label_CustomerID->setFont(font1);
        TxtBox_CustomerID = new QLineEdit(GrpBoxCustomer);
        TxtBox_CustomerID->setObjectName("TxtBox_CustomerID");
        TxtBox_CustomerID->setGeometry(QRect(200, 40, 250, 31));
        comboBox_Customer = new QComboBox(GrpBoxCustomer);
        comboBox_Customer->addItem(QString());
        comboBox_Customer->addItem(QString());
        comboBox_Customer->setObjectName("comboBox_Customer");
        comboBox_Customer->setGeometry(QRect(310, 180, 141, 31));
        comboBox_Customer->setAutoFillBackground(false);
        GrpBoxProduct = new QGroupBox(InvoiceManagement);
        GrpBoxProduct->setObjectName("GrpBoxProduct");
        GrpBoxProduct->setGeometry(QRect(540, 60, 441, 231));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        GrpBoxProduct->setFont(font2);
        TxtBox_ProductID = new QLineEdit(GrpBoxProduct);
        TxtBox_ProductID->setObjectName("TxtBox_ProductID");
        TxtBox_ProductID->setGeometry(QRect(180, 40, 250, 31));
        Label_ProductID = new QLabel(GrpBoxProduct);
        Label_ProductID->setObjectName("Label_ProductID");
        Label_ProductID->setGeometry(QRect(10, 50, 121, 21));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        Label_ProductID->setFont(font3);
        TxtBox_ProductName = new QLineEdit(GrpBoxProduct);
        TxtBox_ProductName->setObjectName("TxtBox_ProductName");
        TxtBox_ProductName->setGeometry(QRect(180, 90, 250, 31));
        TxtBox_ProductName->setReadOnly(false);
        Label_ProdectName = new QLabel(GrpBoxProduct);
        Label_ProdectName->setObjectName("Label_ProdectName");
        Label_ProdectName->setGeometry(QRect(10, 95, 151, 21));
        Label_ProdectName->setFont(font3);
        Label_Amount = new QLabel(GrpBoxProduct);
        Label_Amount->setObjectName("Label_Amount");
        Label_Amount->setGeometry(QRect(10, 145, 161, 21));
        Label_Amount->setFont(font3);
        TxtBox_Amount = new QLineEdit(GrpBoxProduct);
        TxtBox_Amount->setObjectName("TxtBox_Amount");
        TxtBox_Amount->setGeometry(QRect(180, 140, 250, 31));
        Btn_AddItem = new QPushButton(GrpBoxProduct);
        Btn_AddItem->setObjectName("Btn_AddItem");
        Btn_AddItem->setGeometry(QRect(340, 180, 81, 31));
        Btn_Refresh = new QPushButton(GrpBoxProduct);
        Btn_Refresh->setObjectName("Btn_Refresh");
        Btn_Refresh->setGeometry(QRect(240, 180, 81, 31));
        tableWidgetItem = new QTableWidget(InvoiceManagement);
        if (tableWidgetItem->columnCount() < 4)
            tableWidgetItem->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetItem->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetItem->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetItem->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetItem->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetItem->setObjectName("tableWidgetItem");
        tableWidgetItem->setGeometry(QRect(20, 310, 961, 311));
        tableWidgetItem->setMaximumSize(QSize(16777215, 16777215));
        QFont font4;
        font4.setBold(false);
        tableWidgetItem->setFont(font4);
        tableWidgetItem->setShowGrid(true);
        tableWidgetItem->setSortingEnabled(true);
        Label_Total = new QLabel(InvoiceManagement);
        Label_Total->setObjectName("Label_Total");
        Label_Total->setGeometry(QRect(650, 650, 41, 31));
        QFont font5;
        font5.setPointSize(13);
        font5.setBold(true);
        Label_Total->setFont(font5);
        TxtBox_Total = new QLineEdit(InvoiceManagement);
        TxtBox_Total->setObjectName("TxtBox_Total");
        TxtBox_Total->setGeometry(QRect(710, 640, 141, 41));
        TxtBox_Total->setLayoutDirection(Qt::LeftToRight);
        TxtBox_Total->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TxtBox_Total->setReadOnly(false);
        label = new QLabel(InvoiceManagement);
        label->setObjectName("label");
        label->setGeometry(QRect(440, -10, 221, 71));
        label->setSizeIncrement(QSize(0, 0));
        QFont font6;
        font6.setPointSize(20);
        font6.setBold(true);
        label->setFont(font6);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(-6);
        label->setTextFormat(Qt::PlainText);

        retranslateUi(InvoiceManagement);

        QMetaObject::connectSlotsByName(InvoiceManagement);
    } // setupUi

    void retranslateUi(QDialog *InvoiceManagement)
    {
        InvoiceManagement->setWindowTitle(QCoreApplication::translate("InvoiceManagement", "Invoices", nullptr));
        Btn_Print->setText(QCoreApplication::translate("InvoiceManagement", "Print Invoice", nullptr));
        GrpBoxCustomer->setTitle(QCoreApplication::translate("InvoiceManagement", "Customer Information", nullptr));
        Label_PhoneNumber->setText(QCoreApplication::translate("InvoiceManagement", "Customer of Phone Number:", nullptr));
        Label_CustomerName->setText(QCoreApplication::translate("InvoiceManagement", "Customer of Name:", nullptr));
        Label_CustomerID->setText(QCoreApplication::translate("InvoiceManagement", "Customer of ID:", nullptr));
        comboBox_Customer->setItemText(0, QCoreApplication::translate("InvoiceManagement", "Member Customer", nullptr));
        comboBox_Customer->setItemText(1, QCoreApplication::translate("InvoiceManagement", "New Customer", nullptr));

        GrpBoxProduct->setTitle(QCoreApplication::translate("InvoiceManagement", "Product", nullptr));
        Label_ProductID->setText(QCoreApplication::translate("InvoiceManagement", "ID of Commodities:", nullptr));
        Label_ProdectName->setText(QCoreApplication::translate("InvoiceManagement", "Name of Commodities:", nullptr));
        Label_Amount->setText(QCoreApplication::translate("InvoiceManagement", "Amount of Commodities:", nullptr));
        Btn_AddItem->setText(QCoreApplication::translate("InvoiceManagement", "Add", nullptr));
        Btn_Refresh->setText(QCoreApplication::translate("InvoiceManagement", "Refresh", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetItem->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("InvoiceManagement", "Product ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetItem->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("InvoiceManagement", "Product Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetItem->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("InvoiceManagement", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetItem->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("InvoiceManagement", "Price", nullptr));
        Label_Total->setText(QCoreApplication::translate("InvoiceManagement", "Total", nullptr));
        TxtBox_Total->setText(QCoreApplication::translate("InvoiceManagement", "0", nullptr));
        label->setText(QCoreApplication::translate("InvoiceManagement", "Manager Invoice", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InvoiceManagement: public Ui_InvoiceManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVOICEMANAGEMENT_H
