#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
public slots:
    void volume();
    void chanal();

private:
    int chanel = 0;
    int vol = 100;
    Ui::MainWindowClass ui;
};
