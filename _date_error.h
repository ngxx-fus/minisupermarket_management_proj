#ifndef _DATE_ERROR_H
#define _DATE_ERROR_H

#include <QDialog>

namespace Ui {
class _date_error;
}

class _date_error : public QDialog
{
    Q_OBJECT

public:
    explicit _date_error(QWidget *parent = nullptr);
    ~_date_error();

private:
    Ui::_date_error *ui;
};

#endif // _DATE_ERROR_H
