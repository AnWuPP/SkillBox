#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void MainWindow::volume() {
    QObject* sender = QObject::sender();
    QPushButton* btn = qobject_cast<QPushButton*>(sender);
    vol = (btn->text() == "+" ? vol + 10 : vol - 10);
    if (vol <= 0)
        vol = 0;
    else if (vol >= 100)
        vol = 100;
    ui.volumeVal->setText(QString::number(vol) + "%");
}

void MainWindow::chanal() {
    QObject* sender = QObject::sender();
    QPushButton* btn = qobject_cast<QPushButton*>(sender);
    if (btn->text() == "<") {
        --chanel;
        if (chanel < 0)
            chanel = 0;
    }
    else if (btn->text() == ">") {
        ++chanel;
        if (chanel > 9)
            chanel = 9;
    }
    else {
        ui.chanelVal->setText(btn->text());
        return;
    }
    ui.chanelVal->setText(QString::number(chanel));
}
