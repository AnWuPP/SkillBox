#pragma once

#include <QtWidgets/QWidget>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>

class ImageCircle : public QWidget {
	Q_OBJECT
public:
	ImageCircle() = default;
	ImageCircle(QWidget* parent);
	void paintEvent(QPaintEvent* e) override;
	QSize minimumSizeHint() const override;
public slots:
	void setRed();
	void setGreen();
	void setYellow();

private:
	QPixmap current;
	QPixmap red;
	QPixmap green;
	QPixmap yellow;
};

