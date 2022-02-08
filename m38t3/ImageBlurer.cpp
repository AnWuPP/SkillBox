#include "ImageBlurer.h"

ImageBlurer::ImageBlurer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QObject::connect(ui.openFile, &QPushButton::clicked, [this]() {
        QString file = QFileDialog::getOpenFileName(nullptr, "open jpg", "", "jpg (*.jpg, *.JPG)");
        image = QImage(file);
        updateImage(ui.radius->value());
        });
    QObject::connect(ui.radius, &QSlider::valueChanged, [this](int newValue) {
        updateImage(newValue);
        });
}
void ImageBlurer::updateImage(int newValue) {
    ui.imageView->setPixmap(QPixmap::fromImage(blurImage(image, newValue).scaled(
            ui.imageView->width(),
            ui.imageView->height(),
            Qt::KeepAspectRatio)
    ));
}
QImage ImageBlurer::blurImage(QImage source, int blurRadius) {
    if (source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));
    auto* blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));
    return result;
}
