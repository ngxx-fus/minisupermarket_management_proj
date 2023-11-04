/********************************************************************************
** Form generated from reading UI file 'my_customer.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_CUSTOMER_H
#define UI_MY_CUSTOMER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_my_customer
{
public:
    QAction *actionAdd;
    QAction *actionSave_as;
    QAction *actionExport;
    QAction *actionImport_season;
    QAction *actionExport_season;
    QAction *actionContact_us_now;
    QAction *actionOpen_guidebook;
    QAction *factory_rest;
    QAction *actionFactory_reset;
    QAction *actionSet_path;
    QAction *actionAuto_save;
    QWidget *centralwidget;
    QGroupBox *groupBox_ADD_CUS;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButtonADD;
    QPushButton *pushButtonCancel;
    QLabel *label_5;
    QLineEdit *lineEdit_NAME_ADD;
    QLineEdit *lineEdit_NUMPHONE_ADD;
    QLineEdit *lineEdit_POINT_ADD;
    QSpinBox *spinBox_DAY_ADD;
    QSpinBox *spinBox_MONTH_ADD;
    QSpinBox *spinBox_YEAR_ADD;
    QGroupBox *groupBox_FIND_CUS;
    QLabel *label_4;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton_FIND;
    QLineEdit *lineEdit_NAME_FIND;
    QLineEdit *lineEdit_NUMPHONE_FIND;
    QLineEdit *lineEdit_DOB_FIND;
    QComboBox *comboBox;
    QPushButton *pushButton_CLOSE_SEARCH_RES;
    QProgressBar *progressBar_FIND;
    QLabel *label_12;
    QLineEdit *lineEdit_POINT_FIND;
    QLabel *label_13;
    QLineEdit *lineEdit_ID_FIND;
    QGroupBox *groupBox_VIEWTABLE;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_SORT;
    QComboBox *comboBox_OPTION_SORT;
    QComboBox *comboBox_KEY__SORT;
    QPushButton *pushButton__SORT;
    QPushButton *pushButton_RM_MOD;
    QPushButton *pushButtonUpdateInfo;
    QPushButton *pushButton_PURCHASE_MOD;
    QMenuBar *menubar;
    QMenu *menuRefrence;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QDialog *my_customer)
    {
        if (my_customer->objectName().isEmpty())
            my_customer->setObjectName("my_customer");
        my_customer->resize(1286, 676);
        actionAdd = new QAction(my_customer);
        actionAdd->setObjectName("actionAdd");
        actionSave_as = new QAction(my_customer);
        actionSave_as->setObjectName("actionSave_as");
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("applications-science");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave_as->setIcon(icon);
        actionExport = new QAction(my_customer);
        actionExport->setObjectName("actionExport");
        actionImport_season = new QAction(my_customer);
        actionImport_season->setObjectName("actionImport_season");
        actionExport_season = new QAction(my_customer);
        actionExport_season->setObjectName("actionExport_season");
        actionContact_us_now = new QAction(my_customer);
        actionContact_us_now->setObjectName("actionContact_us_now");
        actionOpen_guidebook = new QAction(my_customer);
        actionOpen_guidebook->setObjectName("actionOpen_guidebook");
        factory_rest = new QAction(my_customer);
        factory_rest->setObjectName("factory_rest");
        factory_rest->setCheckable(false);
        actionFactory_reset = new QAction(my_customer);
        actionFactory_reset->setObjectName("actionFactory_reset");
        actionFactory_reset->setEnabled(true);
        actionSet_path = new QAction(my_customer);
        actionSet_path->setObjectName("actionSet_path");
        actionAuto_save = new QAction(my_customer);
        actionAuto_save->setObjectName("actionAuto_save");
        actionAuto_save->setCheckable(true);
        centralwidget = new QWidget(my_customer);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 1231, 811));
        groupBox_ADD_CUS = new QGroupBox(centralwidget);
        groupBox_ADD_CUS->setObjectName("groupBox_ADD_CUS");
        groupBox_ADD_CUS->setGeometry(QRect(20, 20, 411, 311));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(true);
        groupBox_ADD_CUS->setFont(font);
        groupBox_ADD_CUS->setFlat(false);
        groupBox_ADD_CUS->setCheckable(false);
        label = new QLabel(groupBox_ADD_CUS);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 119, 16));
        label->setFont(font);
        label->setScaledContents(false);
        label->setWordWrap(false);
        label_2 = new QLabel(groupBox_ADD_CUS);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 90, 94, 16));
        label_2->setFont(font);
        label_3 = new QLabel(groupBox_ADD_CUS);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 150, 181, 16));
        label_3->setFont(font);
        pushButtonADD = new QPushButton(groupBox_ADD_CUS);
        pushButtonADD->setObjectName("pushButtonADD");
        pushButtonADD->setGeometry(QRect(310, 50, 81, 24));
        pushButtonADD->setFont(font);
        pushButtonCancel = new QPushButton(groupBox_ADD_CUS);
        pushButtonCancel->setObjectName("pushButtonCancel");
        pushButtonCancel->setGeometry(QRect(310, 90, 81, 24));
        pushButtonCancel->setFont(font);
        label_5 = new QLabel(groupBox_ADD_CUS);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 210, 131, 16));
        label_5->setFont(font);
        lineEdit_NAME_ADD = new QLineEdit(groupBox_ADD_CUS);
        lineEdit_NAME_ADD->setObjectName("lineEdit_NAME_ADD");
        lineEdit_NAME_ADD->setGeometry(QRect(40, 50, 251, 31));
        lineEdit_NUMPHONE_ADD = new QLineEdit(groupBox_ADD_CUS);
        lineEdit_NUMPHONE_ADD->setObjectName("lineEdit_NUMPHONE_ADD");
        lineEdit_NUMPHONE_ADD->setGeometry(QRect(40, 110, 251, 31));
        lineEdit_POINT_ADD = new QLineEdit(groupBox_ADD_CUS);
        lineEdit_POINT_ADD->setObjectName("lineEdit_POINT_ADD");
        lineEdit_POINT_ADD->setGeometry(QRect(40, 230, 251, 31));
        spinBox_DAY_ADD = new QSpinBox(groupBox_ADD_CUS);
        spinBox_DAY_ADD->setObjectName("spinBox_DAY_ADD");
        spinBox_DAY_ADD->setGeometry(QRect(40, 180, 61, 25));
        spinBox_DAY_ADD->setMinimum(1);
        spinBox_DAY_ADD->setMaximum(31);
        spinBox_MONTH_ADD = new QSpinBox(groupBox_ADD_CUS);
        spinBox_MONTH_ADD->setObjectName("spinBox_MONTH_ADD");
        spinBox_MONTH_ADD->setGeometry(QRect(110, 180, 61, 25));
        spinBox_MONTH_ADD->setMinimum(1);
        spinBox_MONTH_ADD->setMaximum(12);
        spinBox_YEAR_ADD = new QSpinBox(groupBox_ADD_CUS);
        spinBox_YEAR_ADD->setObjectName("spinBox_YEAR_ADD");
        spinBox_YEAR_ADD->setGeometry(QRect(180, 180, 111, 25));
        spinBox_YEAR_ADD->setMinimum(1901);
        spinBox_YEAR_ADD->setMaximum(2101);
        label->raise();
        label_2->raise();
        label_3->raise();
        pushButtonADD->raise();
        label_5->raise();
        lineEdit_NAME_ADD->raise();
        lineEdit_NUMPHONE_ADD->raise();
        lineEdit_POINT_ADD->raise();
        spinBox_DAY_ADD->raise();
        spinBox_MONTH_ADD->raise();
        spinBox_YEAR_ADD->raise();
        pushButtonCancel->raise();
        groupBox_FIND_CUS = new QGroupBox(centralwidget);
        groupBox_FIND_CUS->setObjectName("groupBox_FIND_CUS");
        groupBox_FIND_CUS->setGeometry(QRect(470, 20, 471, 311));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setUnderline(false);
        groupBox_FIND_CUS->setFont(font1);
        label_4 = new QLabel(groupBox_FIND_CUS);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 70, 201, 16));
        label_4->setFont(font1);
        label_10 = new QLabel(groupBox_FIND_CUS);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 20, 201, 16));
        label_10->setFont(font1);
        label_11 = new QLabel(groupBox_FIND_CUS);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(40, 120, 131, 16));
        label_11->setFont(font);
        pushButton_FIND = new QPushButton(groupBox_FIND_CUS);
        pushButton_FIND->setObjectName("pushButton_FIND");
        pushButton_FIND->setGeometry(QRect(310, 80, 151, 24));
        pushButton_FIND->setFont(font1);
        lineEdit_NAME_FIND = new QLineEdit(groupBox_FIND_CUS);
        lineEdit_NAME_FIND->setObjectName("lineEdit_NAME_FIND");
        lineEdit_NAME_FIND->setGeometry(QRect(40, 40, 251, 31));
        lineEdit_NUMPHONE_FIND = new QLineEdit(groupBox_FIND_CUS);
        lineEdit_NUMPHONE_FIND->setObjectName("lineEdit_NUMPHONE_FIND");
        lineEdit_NUMPHONE_FIND->setGeometry(QRect(40, 90, 251, 31));
        lineEdit_DOB_FIND = new QLineEdit(groupBox_FIND_CUS);
        lineEdit_DOB_FIND->setObjectName("lineEdit_DOB_FIND");
        lineEdit_DOB_FIND->setGeometry(QRect(40, 140, 251, 31));
        comboBox = new QComboBox(groupBox_FIND_CUS);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(310, 50, 151, 24));
        pushButton_CLOSE_SEARCH_RES = new QPushButton(groupBox_FIND_CUS);
        pushButton_CLOSE_SEARCH_RES->setObjectName("pushButton_CLOSE_SEARCH_RES");
        pushButton_CLOSE_SEARCH_RES->setGeometry(QRect(310, 110, 151, 24));
        pushButton_CLOSE_SEARCH_RES->setFont(font1);
        progressBar_FIND = new QProgressBar(groupBox_FIND_CUS);
        progressBar_FIND->setObjectName("progressBar_FIND");
        progressBar_FIND->setGeometry(QRect(40, 281, 411, 20));
        progressBar_FIND->setValue(24);
        label_12 = new QLabel(groupBox_FIND_CUS);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 170, 131, 16));
        label_12->setFont(font);
        lineEdit_POINT_FIND = new QLineEdit(groupBox_FIND_CUS);
        lineEdit_POINT_FIND->setObjectName("lineEdit_POINT_FIND");
        lineEdit_POINT_FIND->setGeometry(QRect(40, 190, 251, 31));
        label_13 = new QLabel(groupBox_FIND_CUS);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(40, 220, 131, 16));
        label_13->setFont(font);
        lineEdit_ID_FIND = new QLineEdit(groupBox_FIND_CUS);
        lineEdit_ID_FIND->setObjectName("lineEdit_ID_FIND");
        lineEdit_ID_FIND->setGeometry(QRect(40, 240, 251, 31));
        groupBox_VIEWTABLE = new QGroupBox(centralwidget);
        groupBox_VIEWTABLE->setObjectName("groupBox_VIEWTABLE");
        groupBox_VIEWTABLE->setGeometry(QRect(20, 340, 1191, 451));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setUnderline(false);
        font2.setKerning(false);
        groupBox_VIEWTABLE->setFont(font2);
        groupBox_VIEWTABLE->setMouseTracking(false);
        groupBox_VIEWTABLE->setTabletTracking(true);
        groupBox_VIEWTABLE->setAutoFillBackground(false);
        tableWidget = new QTableWidget(groupBox_VIEWTABLE);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(40, 30, 1141, 311));
        tableWidget->setFont(font2);
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSortingEnabled(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        groupBox_SORT = new QGroupBox(centralwidget);
        groupBox_SORT->setObjectName("groupBox_SORT");
        groupBox_SORT->setGeometry(QRect(950, 20, 191, 311));
        comboBox_OPTION_SORT = new QComboBox(groupBox_SORT);
        comboBox_OPTION_SORT->addItem(QString());
        comboBox_OPTION_SORT->addItem(QString());
        comboBox_OPTION_SORT->setObjectName("comboBox_OPTION_SORT");
        comboBox_OPTION_SORT->setGeometry(QRect(20, 80, 151, 24));
        comboBox_KEY__SORT = new QComboBox(groupBox_SORT);
        comboBox_KEY__SORT->addItem(QString());
        comboBox_KEY__SORT->addItem(QString());
        comboBox_KEY__SORT->addItem(QString());
        comboBox_KEY__SORT->setObjectName("comboBox_KEY__SORT");
        comboBox_KEY__SORT->setGeometry(QRect(20, 40, 151, 24));
        pushButton__SORT = new QPushButton(groupBox_SORT);
        pushButton__SORT->setObjectName("pushButton__SORT");
        pushButton__SORT->setGeometry(QRect(20, 120, 151, 24));
        pushButton_RM_MOD = new QPushButton(groupBox_SORT);
        pushButton_RM_MOD->setObjectName("pushButton_RM_MOD");
        pushButton_RM_MOD->setGeometry(QRect(20, 200, 151, 24));
        pushButtonUpdateInfo = new QPushButton(groupBox_SORT);
        pushButtonUpdateInfo->setObjectName("pushButtonUpdateInfo");
        pushButtonUpdateInfo->setGeometry(QRect(20, 240, 151, 24));
        pushButton_PURCHASE_MOD = new QPushButton(groupBox_SORT);
        pushButton_PURCHASE_MOD->setObjectName("pushButton_PURCHASE_MOD");
        pushButton_PURCHASE_MOD->setGeometry(QRect(20, 160, 151, 24));
        groupBox_VIEWTABLE->raise();
        groupBox_FIND_CUS->raise();
        groupBox_ADD_CUS->raise();
        groupBox_SORT->raise();
        menubar = new QMenuBar(my_customer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1286, 21));
        menuRefrence = new QMenu(menubar);
        menuRefrence->setObjectName("menuRefrence");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        statusbar = new QStatusBar(my_customer);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 22));

        menubar->addAction(menuRefrence->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuRefrence->addAction(actionImport_season);
        menuRefrence->addAction(actionExport_season);
        menuRefrence->addAction(actionSet_path);
        menuRefrence->addAction(actionAuto_save);
        menuHelp->addAction(actionContact_us_now);
        menuHelp->addAction(actionOpen_guidebook);
        menuHelp->addAction(actionFactory_reset);

        retranslateUi(my_customer);

        QMetaObject::connectSlotsByName(my_customer);
    } // setupUi

    void retranslateUi(QDialog *my_customer)
    {
        my_customer->setWindowTitle(QCoreApplication::translate("my_customer", "Customer Management", nullptr));
        actionAdd->setText(QCoreApplication::translate("my_customer", "Save season", nullptr));
        actionSave_as->setText(QCoreApplication::translate("my_customer", "Save as", nullptr));
        actionExport->setText(QCoreApplication::translate("my_customer", "Export", nullptr));
        actionImport_season->setText(QCoreApplication::translate("my_customer", "Import season", nullptr));
        actionExport_season->setText(QCoreApplication::translate("my_customer", "Export season", nullptr));
        actionContact_us_now->setText(QCoreApplication::translate("my_customer", "Contact us now!", nullptr));
        actionOpen_guidebook->setText(QCoreApplication::translate("my_customer", "Open guidebook.", nullptr));
        factory_rest->setText(QCoreApplication::translate("my_customer", "Factory reset.", nullptr));
        actionFactory_reset->setText(QCoreApplication::translate("my_customer", "Factory reset.", nullptr));
        actionSet_path->setText(QCoreApplication::translate("my_customer", "Set path.", nullptr));
        actionAuto_save->setText(QCoreApplication::translate("my_customer", "Auto save.", nullptr));
        groupBox_ADD_CUS->setTitle(QCoreApplication::translate("my_customer", "Add customer:", nullptr));
        label->setText(QCoreApplication::translate("my_customer", "Name of customer:", nullptr));
        label_2->setText(QCoreApplication::translate("my_customer", "Phone number:", nullptr));
        label_3->setText(QCoreApplication::translate("my_customer", "Date of Birth (DD:MM:YYYY):", nullptr));
        pushButtonADD->setText(QCoreApplication::translate("my_customer", "Add", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("my_customer", "Clear all", nullptr));
        label_5->setText(QCoreApplication::translate("my_customer", "Accumuation Point:", nullptr));
        groupBox_FIND_CUS->setTitle(QCoreApplication::translate("my_customer", "Find customer:", nullptr));
        label_4->setText(QCoreApplication::translate("my_customer", "Phone Number:", nullptr));
        label_10->setText(QCoreApplication::translate("my_customer", "Name of customer:", nullptr));
        label_11->setText(QCoreApplication::translate("my_customer", "Date of Birth:", nullptr));
        pushButton_FIND->setText(QCoreApplication::translate("my_customer", "Find now!", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("my_customer", "by Customer's Name.", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("my_customer", "by Phone Number.", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("my_customer", "by Accumulations Point.", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("my_customer", "by Date modificacion.", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("my_customer", "by Month of birth.", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("my_customer", "by Day of birth.", nullptr));

        pushButton_CLOSE_SEARCH_RES->setText(QCoreApplication::translate("my_customer", "Close search result", nullptr));
        label_12->setText(QCoreApplication::translate("my_customer", "Points", nullptr));
        label_13->setText(QCoreApplication::translate("my_customer", "ID", nullptr));
        groupBox_VIEWTABLE->setTitle(QCoreApplication::translate("my_customer", "List of customers:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("my_customer", "Customer's name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("my_customer", "Birth day", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("my_customer", "Phone number", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("my_customer", "Accumulation point", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("my_customer", "Modification", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("my_customer", "ID", nullptr));
        groupBox_SORT->setTitle(QCoreApplication::translate("my_customer", "Table properties:", nullptr));
        comboBox_OPTION_SORT->setItemText(0, QCoreApplication::translate("my_customer", "Ascending", nullptr));
        comboBox_OPTION_SORT->setItemText(1, QCoreApplication::translate("my_customer", "Descending", nullptr));

        comboBox_KEY__SORT->setItemText(0, QCoreApplication::translate("my_customer", "by Name", nullptr));
        comboBox_KEY__SORT->setItemText(1, QCoreApplication::translate("my_customer", "by Accumulation Point", nullptr));
        comboBox_KEY__SORT->setItemText(2, QCoreApplication::translate("my_customer", "Month of Birth", nullptr));

        pushButton__SORT->setText(QCoreApplication::translate("my_customer", "Sort now!", nullptr));
        pushButton_RM_MOD->setText(QCoreApplication::translate("my_customer", "Remove customer.", nullptr));
        pushButtonUpdateInfo->setText(QCoreApplication::translate("my_customer", "Update info", nullptr));
        pushButton_PURCHASE_MOD->setText(QCoreApplication::translate("my_customer", "Load purchase history.", nullptr));
        menuRefrence->setTitle(QCoreApplication::translate("my_customer", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("my_customer", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class my_customer: public Ui_my_customer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_CUSTOMER_H
