#ifndef _ADDED_CUSTOMER_ERROR_H
#define _ADDED_CUSTOMER_ERROR_H

#include <QDialog>

namespace Ui {
class _added_customer_error;
}

class _added_customer_error : public QDialog
{
    Q_OBJECT

public:
    explicit _added_customer_error(QWidget *parent = nullptr);
    ~_added_customer_error();

private:
    Ui::_added_customer_error *ui;
};

#endif // _ADDED_CUSTOMER_ERROR_H
