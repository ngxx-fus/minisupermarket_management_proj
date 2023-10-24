/********************************************************************************
** Form generated from reading UI file 'myCustomer.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCUSTOMER_H
#define UI_MYCUSTOMER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myCustomer
{
public:
    QAction *actionSearch_by_customer_s_nam;
    QAction *actionSearch_by_ID;
    QAction *actionSearch_by_phone_number;
    QAction *actionSearch_by_Birth_of_Date;
    QAction *actionSave_season;
    QAction *actionExport_season;
    QAction *actionImport_season;
    QAction *actionContact_information;
    QWidget *centralwidget;
    QPushButton *addCustomer;
    QPushButton *removeCustomer;
    QPushButton *editInformation;
    QTableWidget *tableWidget;
    QPushButton *addPoint_3;
    QPushButton *addPoint_4;
    QPushButton *addPoint_5;
    QPushButton *addCustomer_2;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuCusManager;
    QMenu *menuSeach;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *myCustomer)
    {
        if (myCustomer->objectName().isEmpty())
            myCustomer->setObjectName("myCustomer");
        myCustomer->resize(750, 600);
        actionSearch_by_customer_s_nam = new QAction(myCustomer);
        actionSearch_by_customer_s_nam->setObjectName("actionSearch_by_customer_s_nam");
        actionSearch_by_ID = new QAction(myCustomer);
        actionSearch_by_ID->setObjectName("actionSearch_by_ID");
        actionSearch_by_phone_number = new QAction(myCustomer);
        actionSearch_by_phone_number->setObjectName("actionSearch_by_phone_number");
        actionSearch_by_Birth_of_Date = new QAction(myCustomer);
        actionSearch_by_Birth_of_Date->setObjectName("actionSearch_by_Birth_of_Date");
        actionSave_season = new QAction(myCustomer);
        actionSave_season->setObjectName("actionSave_season");
        actionExport_season = new QAction(myCustomer);
        actionExport_season->setObjectName("actionExport_season");
        actionImport_season = new QAction(myCustomer);
        actionImport_season->setObjectName("actionImport_season");
        actionContact_information = new QAction(myCustomer);
        actionContact_information->setObjectName("actionContact_information");
        centralwidget = new QWidget(myCustomer);
        centralwidget->setObjectName("centralwidget");
        addCustomer = new QPushButton(centralwidget);
        addCustomer->setObjectName("addCustomer");
        addCustomer->setGeometry(QRect(590, 50, 111, 24));
        removeCustomer = new QPushButton(centralwidget);
        removeCustomer->setObjectName("removeCustomer");
        removeCustomer->setGeometry(QRect(590, 110, 111, 24));
        editInformation = new QPushButton(centralwidget);
        editInformation->setObjectName("editInformation");
        editInformation->setGeometry(QRect(590, 80, 111, 24));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tableWidget->rowCount() < 10)
            tableWidget->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem14);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 50, 541, 291));
        tableWidget->setMinimumSize(QSize(541, 0));
        addPoint_3 = new QPushButton(centralwidget);
        addPoint_3->setObjectName("addPoint_3");
        addPoint_3->setGeometry(QRect(590, 170, 111, 24));
        addPoint_4 = new QPushButton(centralwidget);
        addPoint_4->setObjectName("addPoint_4");
        addPoint_4->setGeometry(QRect(590, 200, 111, 24));
        addPoint_5 = new QPushButton(centralwidget);
        addPoint_5->setObjectName("addPoint_5");
        addPoint_5->setGeometry(QRect(590, 140, 111, 24));
        addCustomer_2 = new QPushButton(centralwidget);
        addCustomer_2->setObjectName("addCustomer_2");
        addCustomer_2->setGeometry(QRect(20, 10, 111, 24));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(140, 10, 241, 31));
        myCustomer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(myCustomer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 750, 21));
        menuCusManager = new QMenu(menubar);
        menuCusManager->setObjectName("menuCusManager");
        menuSeach = new QMenu(menubar);
        menuSeach->setObjectName("menuSeach");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        myCustomer->setMenuBar(menubar);
        statusbar = new QStatusBar(myCustomer);
        statusbar->setObjectName("statusbar");
        myCustomer->setStatusBar(statusbar);

        menubar->addAction(menuCusManager->menuAction());
        menubar->addAction(menuSeach->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuCusManager->addAction(actionSave_season);
        menuCusManager->addAction(actionExport_season);
        menuCusManager->addAction(actionImport_season);
        menuSeach->addSeparator();
        menuSeach->addAction(actionSearch_by_customer_s_nam);
        menuSeach->addAction(actionSearch_by_phone_number);
        menuSeach->addAction(actionSearch_by_ID);
        menuSeach->addAction(actionSearch_by_Birth_of_Date);
        menuHelp->addAction(actionContact_information);

        retranslateUi(myCustomer);

        QMetaObject::connectSlotsByName(myCustomer);
    } // setupUi

    void retranslateUi(QMainWindow *myCustomer)
    {
        myCustomer->setWindowTitle(QCoreApplication::translate("myCustomer", "Customers Management", nullptr));
        actionSearch_by_customer_s_nam->setText(QCoreApplication::translate("myCustomer", "Search by customer's name", nullptr));
        actionSearch_by_ID->setText(QCoreApplication::translate("myCustomer", "Search by ID", nullptr));
        actionSearch_by_phone_number->setText(QCoreApplication::translate("myCustomer", "Search by phone number", nullptr));
        actionSearch_by_Birth_of_Date->setText(QCoreApplication::translate("myCustomer", "Search by Birth of Date", nullptr));
        actionSave_season->setText(QCoreApplication::translate("myCustomer", "Save season", nullptr));
        actionExport_season->setText(QCoreApplication::translate("myCustomer", "Export season", nullptr));
        actionImport_season->setText(QCoreApplication::translate("myCustomer", "Import season", nullptr));
        actionContact_information->setText(QCoreApplication::translate("myCustomer", "Contact information", nullptr));
        addCustomer->setText(QCoreApplication::translate("myCustomer", "Add customer", nullptr));
        removeCustomer->setText(QCoreApplication::translate("myCustomer", "Remove customer", nullptr));
        editInformation->setText(QCoreApplication::translate("myCustomer", "Edit Infomation", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("myCustomer", "Customer's name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("myCustomer", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("myCustomer", "Birth of date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("myCustomer", "Phone number", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("myCustomer", "Accumulation point", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("myCustomer", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("myCustomer", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("myCustomer", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("myCustomer", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("myCustomer", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("myCustomer", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("myCustomer", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("myCustomer", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("myCustomer", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("myCustomer", "10", nullptr));
        addPoint_3->setText(QCoreApplication::translate("myCustomer", "Latest commodity", nullptr));
        addPoint_4->setText(QCoreApplication::translate("myCustomer", "Purchase history", nullptr));
        addPoint_5->setText(QCoreApplication::translate("myCustomer", "New commodity", nullptr));
        addCustomer_2->setText(QCoreApplication::translate("myCustomer", "Search by name", nullptr));
        menuCusManager->setTitle(QCoreApplication::translate("myCustomer", "File", nullptr));
        menuSeach->setTitle(QCoreApplication::translate("myCustomer", "Seach", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("myCustomer", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myCustomer: public Ui_myCustomer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCUSTOMER_H
