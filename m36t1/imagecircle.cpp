#include "imagecircle.h"

ImageCircle::ImageCircle(QWidget* parent) {
	setParent(parent);
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	red = QPixmap("img/red.png");
	green = QPixmap("img/green.png");
	yellow = QPixmap("img/yellow.png");
	current = green;
	setGeometry(current.rect());
}
void ImageCircle::paintEvent(QPaintEvent* e) {
	QPainter p(this);
	p.drawPixmap(e->rect(), current);
}
QSize ImageCircle::minimumSizeHint() const {
	return QSize(100, 100);
}
void ImageCircle::setRed() {
	current = red;
	update();
}
void ImageCircle::setGreen() {
	current = green;
	update();
}
void ImageCircle::setYellow() {
	current = yellow;
	update();
}
