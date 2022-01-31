#include "m37t1.h"

m37t1::m37t1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    oneNum = ui.numOne;
    twoNum = ui.numTwo;
    result = ui.result;
}

void m37t1::add() {
    auto one = oneNum->text().toStdString();
    auto two = twoNum->text().toStdString();
    if (one.empty() || two.empty()) {
        result->setText("ERROR");
        return;
    }
    double a = std::stod(one);
    double b = std::stod(two);
    double r = a + b;
    result->setText(QString::number(r));
}
void m37t1::div() {
    auto one = oneNum->text().toStdString();
    auto two = twoNum->text().toStdString();
    if (one.empty() || two.empty()) {
        result->setText("ERROR");
        return;
    }
    double a = std::stod(one);
    double b = std::stod(two);
    if (b == 0.0) {
        result->setText("ERROR");
        return;
    }
    double r = a / b;
    result->setText(QString::number(r));
}
void m37t1::min() {
    auto one = oneNum->text().toStdString();
    auto two = twoNum->text().toStdString();
    if (one.empty() || two.empty()) {
        result->setText("ERROR");
        return;
    }
    double a = std::stod(one);
    double b = std::stod(two);
    double r = a - b;
    result->setText(QString::number(r));
}
void m37t1::umn() {
    auto one = oneNum->text().toStdString();
    auto two = twoNum->text().toStdString();
    if (one.empty() || two.empty()) {
        result->setText("ERROR");
        return;
    }
    double a = std::stod(one);
    double b = std::stod(two);
    double r = a * b;
    result->setText(QString::number(r));
}
