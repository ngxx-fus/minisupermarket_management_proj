/********************************************************************************
** Form generated from reading UI file 'minisupermarketmanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINISUPERMARKETMANAGEMENT_H
#define UI_MINISUPERMARKETMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MiniSupermarKetmanagement
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MiniSupermarKetmanagement)
    {
        if (MiniSupermarKetmanagement->objectName().isEmpty())
            MiniSupermarKetmanagement->setObjectName("MiniSupermarKetmanagement");
        MiniSupermarKetmanagement->resize(600, 600);
        centralwidget = new QWidget(MiniSupermarKetmanagement);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(200, 190, 191, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(200, 260, 191, 41));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(200, 330, 191, 41));
        MiniSupermarKetmanagement->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MiniSupermarKetmanagement);
        statusbar->setObjectName("statusbar");
        MiniSupermarKetmanagement->setStatusBar(statusbar);

        retranslateUi(MiniSupermarKetmanagement);

        QMetaObject::connectSlotsByName(MiniSupermarKetmanagement);
    } // setupUi

    void retranslateUi(QMainWindow *MiniSupermarKetmanagement)
    {
        MiniSupermarKetmanagement->setWindowTitle(QCoreApplication::translate("MiniSupermarKetmanagement", "MiniSupermarKetmanagement", nullptr));
        pushButton->setText(QCoreApplication::translate("MiniSupermarKetmanagement", "Manager Commodites", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MiniSupermarKetmanagement", "Manager Custormer", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MiniSupermarKetmanagement", "Bill", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MiniSupermarKetmanagement: public Ui_MiniSupermarKetmanagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINISUPERMARKETMANAGEMENT_H
