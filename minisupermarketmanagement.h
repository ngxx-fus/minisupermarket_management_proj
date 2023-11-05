#ifndef MINISUPERMARKETMANAGEMENT_H
#define MINISUPERMARKETMANAGEMENT_H
#include "managerproduct.h"
#include <QListWidgetItem>
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MiniSupermarKetmanagement; }
QT_END_NAMESPACE

class MiniSupermarKetmanagement : public QMainWindow
{
    Q_OBJECT

public:
    MiniSupermarKetmanagement(QWidget *parent = nullptr);
    ~MiniSupermarKetmanagement();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:

    Ui::MiniSupermarKetmanagement *ui;
    ManagerProduct* fromtestA;

};

#endif // MINISUPERMARKETMANAGEMENT_H
