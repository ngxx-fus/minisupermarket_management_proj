#ifndef INVOICEMANAGEMENT_H
#define INVOICEMANAGEMENT_H

#include <QDialog>
#include "invoice.h"
#include "_customers.h"
#include <QCloseEvent>

namespace Ui {
class InvoiceManagement;
}

class InvoiceManagement : public QDialog
{
    Q_OBJECT

public:
    explicit InvoiceManagement(QWidget *parent = nullptr);
    ~InvoiceManagement();

    void closeEvent (QCloseEvent *event);

    void clearWhenPressAddItemButton();
    void clearWhenPressPrintButton();
    void updateStorageAfterRemove(int);

private slots:
    void on_Btn_AddItem_clicked();
    void on_Btn_Print_clicked();
    void on_TxtBox_ProductID_textChanged(const QString &arg1);

    void on_tableWidgetItem_cellClicked(int row, int column);

    void on_tableWidgetItem_cellDoubleClicked(int row, int column);

    void on_TxtBox_ProductName_editingFinished();

    void on_Btn_Refresh_clicked();

    void on_TxtBox_ProductID_editingFinished();

    void on_comboBox_Customer_activated(int index);

    void on_TxtBox_PhoneNumber_editingFinished();

private:
    Ui::InvoiceManagement *ui;
    Invoice NewInvoice;
    vector <_customers> CustomerList;
    void load_config();

};

#endif // INVOICEMANAGEMENT_H
