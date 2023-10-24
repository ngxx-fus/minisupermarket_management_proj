#include "myCustomer.h"

#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myCustomer w;
    w.addCustomer(QString("Nguyễn Thanh Phú"), "22119211", "03/02/2004", "08459396532", 0);
    w.addCustomer(QString("Hoàng Bách"), "22119212", "05/06/2004", "0845943522", 0);
    w.addCustomer(QString("Nguyễn Hoàng Nam"), "22119213", "18/02/2004", "08459397356", 0);

    w.show();
    return a.exec();
}
