#ifndef MANAGERPRODUCT_H
#define MANAGERPRODUCT_H

#include "qlistwidget.h"
#include <QDialog>
#include <ui_managerproduct.h>

namespace Ui {
class ManagerProduct;
}

class ManagerProduct : public QDialog
{
    Q_OBJECT

public:
     ManagerProduct(QWidget *parent, bool& hasReadFileFlag);
    ~ManagerProduct();


private slots:

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_btnrepair_clicked();



    void on_btnSearch_clicked();

private:
    Ui::ManagerProduct *ui;
};

#endif // MANAGERPRODUCT_H
