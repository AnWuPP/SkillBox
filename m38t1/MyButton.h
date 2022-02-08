#pragma once

#include <QtWidgets/QWidget>
#include "ui_MyButton.h"

#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QPushButton>
#include <QUrl>
#include <QMediaPlayer>
#include <QMediaContent>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(QWidget *parent = Q_NULLPTR);
    void paintEvent(QPaintEvent* e) override;
    QSize sizeHint() const override;
public slots:
    void down();
    void up();

private:
    Ui::MyButtonClass ui;
    QPixmap btnImage;
    QPixmap btnClickedImage;
    QPixmap current;
    QMediaPlayer player;
};
