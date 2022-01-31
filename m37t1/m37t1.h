#pragma once

#include <QtWidgets/QMainWindow>
#include <QLineEdit>
#include "ui_m37t1.h"

class m37t1 : public QMainWindow
{
    Q_OBJECT
public:
    m37t1(QWidget *parent = Q_NULLPTR);
public slots:
    void add();
    void div();
    void min();
    void umn();

private:
    Ui::MainWindow ui;
    QLineEdit* oneNum = nullptr;
    QLineEdit* twoNum = nullptr;
    QLineEdit* result = nullptr;
};
