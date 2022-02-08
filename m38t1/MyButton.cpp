#include "MyButton.h"

MyButton::MyButton(QWidget *parent) {
	setParent(parent);
    ui.setupUi(this);

	player.setMedia(QUrl::fromLocalFile("media/clicked.mp3"));
	player.setVolume(100);

	btnImage = QPixmap("img\\btn.png");
	btnClickedImage = QPixmap("img\\btn_clicked.png");
	current = btnImage;
	setGeometry(current.rect());
}
void MyButton::paintEvent(QPaintEvent* e) {
	QPainter p(this);
	p.drawPixmap(e->rect(), current);
}
void MyButton::down() {
	player.play();
	current = btnClickedImage;
	update();
	QTimer::singleShot(200, this, &MyButton::up);
}
void MyButton::up() {
	current = btnImage;
	update();
}
QSize MyButton::sizeHint() const {
	return QSize(200, 200);
}
