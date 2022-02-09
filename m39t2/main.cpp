#include "m39t2.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    m39t2 w;
    w.show();
    return a.exec();
}
