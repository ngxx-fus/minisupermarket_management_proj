#ifndef INVOICEMANAGEMENT_H
#define INVOICEMANAGEMENT_H

#include <QDialog>
#include "invoice.h"

namespace Ui {
class InvoiceManagement;
}

class InvoiceManagement : public QDialog
{
    Q_OBJECT

public:
    explicit InvoiceManagement(QWidget *parent = nullptr);
    ~InvoiceManagement();

private slots:
    void on_Btn_AddItem_clicked();
    void on_Btn_Print_clicked();
    void on_TxtBox_ProductID_textChanged(const QString &arg1);

private:
    Ui::InvoiceManagement *ui;
    Invoice NewInvoice;
};

#endif // INVOICEMANAGEMENT_H
