#include "HtmlEditor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HtmlEditor w;
    w.show();
    return a.exec();
}
