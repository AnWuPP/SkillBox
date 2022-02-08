#include "MyButton.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyButton w;

    QObject::connect(&w, &MyButton::clicked, &w, &MyButton::down);
    w.setFixedSize(200, 200);
    w.move(900, 400);
    w.show();
    return a.exec();
}