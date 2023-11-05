/********************************************************************************
** Form generated from reading UI file 'managerproduct.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERPRODUCT_H
#define UI_MANAGERPRODUCT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerProduct
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QLineEdit *txtID;
    QLabel *label_4;
    QLineEdit *txtName;
    QLabel *label_5;
    QLineEdit *txtAmount;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *txtPrice;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLabel *label_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_23;
    QComboBox *comboBox_8;
    QComboBox *comboBox_9;
    QLabel *label_21;
    QComboBox *comboBox_7;
    QLabel *label_22;
    QPushButton *Editcommodities;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QPushButton *btnSearch;
    QLineEdit *txtSearch;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_4;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *txtUpdateAmount;
    QLineEdit *txtSearchID;
    QPushButton *pushButton_3;

    void setupUi(QDialog *ManagerProduct)
    {
        if (ManagerProduct->objectName().isEmpty())
            ManagerProduct->setObjectName("ManagerProduct");
        ManagerProduct->resize(1000, 700);
        QFont font;
        font.setPointSize(10);
        ManagerProduct->setFont(font);
        ManagerProduct->setFocusPolicy(Qt::NoFocus);
        ManagerProduct->setContextMenuPolicy(Qt::NoContextMenu);
        ManagerProduct->setStyleSheet(QString::fromUtf8("QPushButton#pushButton {\n"
"                   background-color: #0078A8; \n"
"                    color: white;\n"
"                    border: 2px solid #0078A8; \n"
"                   border-radius: 5px; \n"
"                   padding: 5px 10px;\n"
"                   font-weight: bolder;\n"
"                   }\n"
"QPushButton#pushButton_3 {\n"
"                   background-color: #0078A8; \n"
"                    color: white;\n"
"                    border: 2px solid #0078A8; \n"
"                   border-radius: 5px; \n"
"                   padding: 5px 10px;\n"
"                  font-weight: bolder;\n"
"                   }\n"
"QPushButton#Editcommodities {\n"
"                   background-color: #0078A8; \n"
"                    color: white;\n"
"                    border: 2px solid #0078A8; \n"
"                   border-radius: 5px; \n"
"                   padding: 5px 10px;\n"
"                  font-weight: bolder;\n"
"                   }\n"
"QPushButton#pushButton_2{\n"
"               "
                        "    background-color: #0078A8; \n"
"                    color: white;\n"
"                    border: 2px solid #0078A8; \n"
"                   border-radius: 5px; \n"
"                   padding: 5px 10px;\n"
"font-weight: bolder;\n"
"                   }\n"
"QPushButton#pushButton_4{\n"
"                   background-color: #0078A8; \n"
"                    color: white;\n"
"                    border: 2px solid #0078A8; \n"
"                   border-radius: 5px; \n"
"                   padding: 5px 10px;\n"
"font-weight: bolder;\n"
"                   }\n"
"QPushButton#btnSearch{\n"
"                   background-color: #0078A8; \n"
"                    color: white;\n"
"                    border: 2px solid #0078A8; \n"
"                   border-radius: 5px; \n"
"                   padding: 5px 10px;\n"
"font-weight: bolder;\n"
"                   }\n"
"QPushButton#btnCloseSearch{\n"
"                   background-color: #0078A8; \n"
"                    color: white;\n"
"                    border: 2px"
                        " solid #0078A8; \n"
"                   border-radius: 5px; \n"
"                   padding: 5px 10px;\n"
"font-weight: bolder;\n"
"                   }\n"
"QLineEdit#txtSearchID{\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}\n"
"\n"
"QLineEdit#txtID{\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}                 \n"
"QLineEdit#txtName{\n"
"\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t "
                        "m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}      \n"
"QLineEdit#txtAmount{\n"
"\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"\n"
"}      \n"
"QLineEdit#txtPrice{\n"
"\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240"
                        "u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}    \n"
"QLineEdit#txtUpdateAmount{\n"
"\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}    \n"
"QLineEdit#txtSearch\n"
"{\n"
"\n"
"background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 5px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}   \n"
"QDialog#ManagerProduct\n"
"{\n"
"\n"
"   background-color: #87CEFA; /* \304\220\341\272\267t m\303\240u n\341\273\201n 8472FF l\303\240 tr\341\272\257ng"
                        " */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}  \n"
"QTableWidget#tableWidget\n"
"{\n"
"\n"
"   background-color: #FFFFFF; /* \304\220\341\272\267t m\303\240u n\341\273\201n l\303\240 tr\341\272\257ng */\n"
"    border-radius: 10px; /* Bo g\303\263c */\n"
"    padding: 5px; /* \304\220\341\272\267t \304\221\341\273\207m */\n"
"    color: #000000; /* \304\220\341\272\267t m\303\240u v\304\203n b\341\272\243n l\303\240 m\303\240u \304\221en */\n"
"}  "));
        tableWidget = new QTableWidget(ManagerProduct);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 430, 961, 241));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        label = new QLabel(ManagerProduct);
        label->setObjectName("label");
        label->setGeometry(QRect(350, -20, 301, 81));
        label->setSizeIncrement(QSize(0, 0));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label->setFont(font1);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(-6);
        label->setTextFormat(Qt::PlainText);
        groupBox = new QGroupBox(ManagerProduct);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 40, 531, 381));
        groupBox->setContextMenuPolicy(Qt::PreventContextMenu);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(440, 340, 81, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Users/hagia/Downloads/qtc++/add-folder.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        txtID = new QLineEdit(groupBox);
        txtID->setObjectName("txtID");
        txtID->setGeometry(QRect(200, 40, 321, 31));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 40, 141, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        label_4->setFont(font2);
        txtName = new QLineEdit(groupBox);
        txtName->setObjectName("txtName");
        txtName->setGeometry(QRect(200, 90, 321, 31));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 90, 141, 31));
        label_5->setFont(font2);
        txtAmount = new QLineEdit(groupBox);
        txtAmount->setObjectName("txtAmount");
        txtAmount->setGeometry(QRect(200, 140, 321, 31));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 140, 161, 31));
        label_6->setFont(font2);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 190, 141, 31));
        label_7->setFont(font2);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 240, 181, 31));
        label_8->setFont(font2);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 290, 141, 31));
        label_9->setFont(font2);
        txtPrice = new QLineEdit(groupBox);
        txtPrice->setObjectName("txtPrice");
        txtPrice->setGeometry(QRect(200, 290, 321, 31));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(360, 190, 51, 21));
        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(240, 190, 51, 21));
        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(470, 190, 51, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 190, 31, 21));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(310, 190, 41, 21));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(440, 190, 31, 21));
        label_23 = new QLabel(groupBox);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(440, 250, 31, 21));
        comboBox_8 = new QComboBox(groupBox);
        comboBox_8->setObjectName("comboBox_8");
        comboBox_8->setGeometry(QRect(240, 250, 51, 21));
        comboBox_9 = new QComboBox(groupBox);
        comboBox_9->setObjectName("comboBox_9");
        comboBox_9->setGeometry(QRect(470, 250, 51, 21));
        label_21 = new QLabel(groupBox);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(310, 250, 41, 21));
        comboBox_7 = new QComboBox(groupBox);
        comboBox_7->setObjectName("comboBox_7");
        comboBox_7->setGeometry(QRect(360, 250, 51, 21));
        label_22 = new QLabel(groupBox);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(200, 250, 31, 21));
        Editcommodities = new QPushButton(groupBox);
        Editcommodities->setObjectName("Editcommodities");
        Editcommodities->setGeometry(QRect(310, 340, 91, 31));
        Editcommodities->setIcon(icon);
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(200, 340, 81, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Users/hagia/Downloads/qtc++/bin.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        groupBox_2 = new QGroupBox(ManagerProduct);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(570, 290, 411, 131));
        groupBox_2->setFont(font);
        btnSearch = new QPushButton(groupBox_2);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setGeometry(QRect(300, 90, 101, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../Users/hagia/Downloads/qtc++/loupe.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSearch->setIcon(icon2);
        txtSearch = new QLineEdit(groupBox_2);
        txtSearch->setObjectName("txtSearch");
        txtSearch->setGeometry(QRect(160, 40, 241, 31));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 40, 141, 31));
        label_2->setFont(font2);
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(160, 90, 111, 31));
        pushButton_4->raise();
        btnSearch->raise();
        txtSearch->raise();
        label_2->raise();
        groupBox_3 = new QGroupBox(ManagerProduct);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(570, 180, 411, 101));
        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(20, 30, 151, 22));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        radioButton->setFont(font3);
        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(20, 60, 141, 22));
        radioButton_2->setFont(font3);
        radioButton_3 = new QRadioButton(groupBox_3);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(240, 30, 121, 22));
        radioButton_3->setFont(font3);
        radioButton_4 = new QRadioButton(groupBox_3);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(240, 60, 121, 22));
        radioButton_4->setFont(font3);
        groupBox_4 = new QGroupBox(ManagerProduct);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(570, 40, 411, 131));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 30, 141, 31));
        label_12->setFont(font2);
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 90, 161, 31));
        label_13->setFont(font2);
        txtUpdateAmount = new QLineEdit(groupBox_4);
        txtUpdateAmount->setObjectName("txtUpdateAmount");
        txtUpdateAmount->setGeometry(QRect(170, 30, 211, 31));
        txtSearchID = new QLineEdit(groupBox_4);
        txtSearchID->setObjectName("txtSearchID");
        txtSearchID->setGeometry(QRect(171, 90, 121, 31));
        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(300, 90, 81, 31));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../Users/hagia/Downloads/qtc++/check-mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);

        retranslateUi(ManagerProduct);

        QMetaObject::connectSlotsByName(ManagerProduct);
    } // setupUi

    void retranslateUi(QDialog *ManagerProduct)
    {
        ManagerProduct->setWindowTitle(QCoreApplication::translate("ManagerProduct", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ManagerProduct", "Manager Commodities", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ManagerProduct", "Add Commodities", nullptr));
        pushButton->setText(QCoreApplication::translate("ManagerProduct", "Add", nullptr));
        label_4->setText(QCoreApplication::translate("ManagerProduct", "ID of Commodities:", nullptr));
        label_5->setText(QCoreApplication::translate("ManagerProduct", "Name of Commodities:", nullptr));
        label_6->setText(QCoreApplication::translate("ManagerProduct", "Amount of Commodities:", nullptr));
        label_7->setText(QCoreApplication::translate("ManagerProduct", "Date of Commodities:", nullptr));
        label_8->setText(QCoreApplication::translate("ManagerProduct", "Date Expried of Commodities:", nullptr));
        label_9->setText(QCoreApplication::translate("ManagerProduct", "Price of Commodities:", nullptr));
        label_3->setText(QCoreApplication::translate("ManagerProduct", "Date:", nullptr));
        label_10->setText(QCoreApplication::translate("ManagerProduct", "Month:", nullptr));
        label_11->setText(QCoreApplication::translate("ManagerProduct", "Year:", nullptr));
        label_23->setText(QCoreApplication::translate("ManagerProduct", "Year:", nullptr));
        label_21->setText(QCoreApplication::translate("ManagerProduct", "Month:", nullptr));
        label_22->setText(QCoreApplication::translate("ManagerProduct", "Date:", nullptr));
        Editcommodities->setText(QCoreApplication::translate("ManagerProduct", "Edit ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ManagerProduct", "Delete", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ManagerProduct", "Delete and Search", nullptr));
        btnSearch->setText(QCoreApplication::translate("ManagerProduct", "Search", nullptr));
        label_2->setText(QCoreApplication::translate("ManagerProduct", "ID of Commodities", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ManagerProduct", "Close Search", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("ManagerProduct", "Sort by quantity", nullptr));
        radioButton->setText(QCoreApplication::translate("ManagerProduct", "Increasing Amounts", nullptr));
        radioButton_2->setText(QCoreApplication::translate("ManagerProduct", "Decreasing Amounts", nullptr));
        radioButton_3->setText(QCoreApplication::translate("ManagerProduct", "More ExpDate", nullptr));
        radioButton_4->setText(QCoreApplication::translate("ManagerProduct", "Little ExpDate", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("ManagerProduct", "Update Commodities", nullptr));
        label_12->setText(QCoreApplication::translate("ManagerProduct", "ID of Commodities:", nullptr));
        label_13->setText(QCoreApplication::translate("ManagerProduct", "Amount of Commodities:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ManagerProduct", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagerProduct: public Ui_ManagerProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERPRODUCT_H
