#include "myCustomer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myCustomer w;
    w.show();
    return a.exec();
}
