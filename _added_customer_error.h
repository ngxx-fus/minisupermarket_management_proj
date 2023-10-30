#ifndef _ADDED_CUSTOMER_ERROR_H
#define _ADDED_CUSTOMER_ERROR_H

#include "ui__added_customer_error.h"
#include <QDialog>

namespace Ui {
class _added_customer_error;
}

class _added_customer_error : public QDialog
{
    Q_OBJECT

public:
    explicit _added_customer_error(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::_added_customer_error)
    {
        ui->setupUi(this);
    }

    ~_added_customer_error()
    {
        delete ui;
    }


private:
    Ui::_added_customer_error *ui;
};

#endif // _ADDED_CUSTOMER_ERROR_H
