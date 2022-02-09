#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_m39t2.h"
#include <QRegularExpression>

class m39t2 : public QMainWindow
{
    Q_OBJECT

public:
    m39t2(QWidget *parent = Q_NULLPTR);

private:
    Ui::m39t2Class ui;
};
