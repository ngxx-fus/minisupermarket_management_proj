#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class customers; }
QT_END_NAMESPACE

class customers : public QMainWindow
{
    Q_OBJECT

public:
    customers(QWidget *parent = nullptr);
    ~customers();

private:
    Ui::customers *ui;
};
#endif // CUSTOMERS_H
