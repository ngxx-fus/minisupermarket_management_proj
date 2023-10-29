#ifndef _ADD_CUSTOMER_H
#define _ADD_CUSTOMER_H

#include <QWidget>
#include "_customers.h"

namespace Ui {
    class _add_customer;
}

class _add_customer : public QWidget
{
    Q_OBJECT

public:
    explicit _add_customer(QWidget *parent = nullptr);
    ~_add_customer();

private:
    Ui::_add_customer *ui;
};

#endif // _ADD_CUSTOMER_H
