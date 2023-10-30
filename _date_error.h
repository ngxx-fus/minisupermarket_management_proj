#ifndef _DATE_ERROR_H
#define _DATE_ERROR_H

#include "ui__date_error.h"
#include <QDialog>

namespace Ui {
class _date_error;
}

class _date_error : public QDialog
{
    Q_OBJECT

public:
    explicit  _date_error(QWidget *parent  = nullptr) :
            QDialog(parent),
            ui(new Ui::_date_error)
    {
        ui->setupUi(this);
    }

    ~_date_error(){
        delete ui;
    }

private:
    Ui::_date_error *ui;
};

#endif // _DATE_ERROR_H
