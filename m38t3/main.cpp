#include "ImageBlurer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageBlurer w;
    w.show();
    return a.exec();
}
