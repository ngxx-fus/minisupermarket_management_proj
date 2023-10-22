#include "customers.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    customers w;
    w.show();
    return a.exec();
}
