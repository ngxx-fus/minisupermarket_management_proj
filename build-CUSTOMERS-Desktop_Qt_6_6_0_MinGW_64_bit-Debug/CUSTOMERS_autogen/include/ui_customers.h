/********************************************************************************
** Form generated from reading UI file 'customers.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERS_H
#define UI_CUSTOMERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customers
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *customers)
    {
        if (customers->objectName().isEmpty())
            customers->setObjectName("customers");
        customers->resize(800, 600);
        centralwidget = new QWidget(customers);
        centralwidget->setObjectName("centralwidget");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(30, 40, 256, 192));
        customers->setCentralWidget(centralwidget);
        menubar = new QMenuBar(customers);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        customers->setMenuBar(menubar);
        statusbar = new QStatusBar(customers);
        statusbar->setObjectName("statusbar");
        customers->setStatusBar(statusbar);

        retranslateUi(customers);

        QMetaObject::connectSlotsByName(customers);
    } // setupUi

    void retranslateUi(QMainWindow *customers)
    {
        customers->setWindowTitle(QCoreApplication::translate("customers", "customers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customers: public Ui_customers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERS_H
