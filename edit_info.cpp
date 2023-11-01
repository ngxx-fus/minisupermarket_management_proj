#include "edit_info.h"
#include "ui_edit_info.h"

edit_info::edit_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_info)
{
    ui->setupUi(this);
}

edit_info::~edit_info()
{
    delete ui;
}
