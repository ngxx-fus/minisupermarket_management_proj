#ifndef _ADDING_ERROR_H
#define _ADDING_ERROR_H

#include "ui__adding_error.h"
#include <QDialog>

namespace Ui {
class _adding_error;
}

class _adding_error : public QDialog
{
    Q_OBJECT

public:
    explicit _adding_error(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::_adding_error)
    {
        ui->setupUi(this);
    }
    ~_adding_error()
    {
        delete ui;
    }


private:
    Ui::_adding_error *ui;
};

#endif // _ADDING_ERROR_H
