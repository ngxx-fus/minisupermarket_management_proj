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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myCustomer
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QLabel *customer_name;
    QLabel *customer_numberphone;
    QLabel *customer_ID;
    QLabel *customer_point;
    QLabel *customer_BOD;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QMenu *menuCusManager;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *myCustomer)
    {
        if (myCustomer->objectName().isEmpty())
            myCustomer->setObjectName("myCustomer");
        myCustomer->resize(750, 600);
        centralwidget = new QWidget(myCustomer);
        centralwidget->setObjectName("centralwidget");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(31, 40, 591, 291));
        customer_name = new QLabel(centralwidget);
        customer_name->setObjectName("customer_name");
        customer_name->setGeometry(QRect(111, 20, 151, 20));
        customer_numberphone = new QLabel(centralwidget);
        customer_numberphone->setObjectName("customer_numberphone");
        customer_numberphone->setGeometry(QRect(351, 20, 91, 20));
        customer_ID = new QLabel(centralwidget);
        customer_ID->setObjectName("customer_ID");
        customer_ID->setGeometry(QRect(51, 20, 51, 20));
        customer_point = new QLabel(centralwidget);
        customer_point->setObjectName("customer_point");
        customer_point->setGeometry(QRect(471, 20, 121, 16));
        customer_BOD = new QLabel(centralwidget);
        customer_BOD->setObjectName("customer_BOD");
        customer_BOD->setGeometry(QRect(251, 20, 91, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(71, 350, 80, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(240, 350, 101, 24));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(460, 350, 101, 24));
        myCustomer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(myCustomer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 750, 21));
        menuCusManager = new QMenu(menubar);
        menuCusManager->setObjectName("menuCusManager");
        myCustomer->setMenuBar(menubar);
        statusbar = new QStatusBar(myCustomer);
        statusbar->setObjectName("statusbar");
        myCustomer->setStatusBar(statusbar);

        menubar->addAction(menuCusManager->menuAction());

        retranslateUi(myCustomer);

        QMetaObject::connectSlotsByName(myCustomer);
    } // setupUi

    void retranslateUi(QMainWindow *myCustomer)
    {
        myCustomer->setWindowTitle(QCoreApplication::translate("myCustomer", "Customers Management", nullptr));
        customer_name->setText(QCoreApplication::translate("myCustomer", "Customer's name", nullptr));
        customer_numberphone->setText(QCoreApplication::translate("myCustomer", "Phone number", nullptr));
        customer_ID->setText(QCoreApplication::translate("myCustomer", "ID", nullptr));
        customer_point->setText(QCoreApplication::translate("myCustomer", "Accumulation point", nullptr));
        customer_BOD->setText(QCoreApplication::translate("myCustomer", "Birth", nullptr));
        pushButton->setText(QCoreApplication::translate("myCustomer", "Add customer", nullptr));
        pushButton_2->setText(QCoreApplication::translate("myCustomer", "Delete customer", nullptr));
        pushButton_3->setText(QCoreApplication::translate("myCustomer", "Edit Infomation", nullptr));
        menuCusManager->setTitle(QCoreApplication::translate("myCustomer", "Customer Manager", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myCustomer: public Ui_myCustomer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCUSTOMER_H
