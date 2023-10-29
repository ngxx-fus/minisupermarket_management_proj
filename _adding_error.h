#ifndef _ADDING_ERROR_H
#define _ADDING_ERROR_H

#include <QDialog>

namespace Ui {
class _adding_error;
}

class _adding_error : public QDialog
{
    Q_OBJECT

public:
    explicit _adding_error(QWidget *parent = nullptr);
    ~_adding_error();

private:
    Ui::_adding_error *ui;
};

#endif // _ADDING_ERROR_H
