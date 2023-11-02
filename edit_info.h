#ifndef EDIT_INFO_H
#define EDIT_INFO_H

#include <QDialog>

namespace Ui {
class edit_info;
}

class edit_info : public QDialog
{
    Q_OBJECT

public:
    explicit edit_info(QWidget *parent = nullptr);
    ~edit_info();

private:
    Ui::edit_info *ui;
};

#endif // EDIT_INFO_H
