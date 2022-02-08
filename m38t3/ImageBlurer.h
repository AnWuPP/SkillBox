#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsBlurEffect>
#include <QPainter>
#include <QPushButton>
#include <QFileDialog>
#include "ui_ImageBlurer.h"

class ImageBlurer : public QMainWindow
{
    Q_OBJECT

public:
    ImageBlurer(QWidget *parent = Q_NULLPTR);
    QImage blurImage(QImage source, int blur_radius);
    void updateImage(int newValue);

private:
    Ui::ImageBlurerClass ui;
    QImage image;
};
