#include "my_customer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    my_customer w;
    w.show();
    return a.exec();
}
