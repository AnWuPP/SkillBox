#include "imagecircle.h"
#include <QtWidgets/QApplication>
#include <QSlider>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QWidget window;
	auto* layout = new QVBoxLayout(&window);

	ImageCircle* circle = new ImageCircle(&window);
	circle->setFixedSize(139, 139);

	QSlider* slider = new QSlider(Qt::Orientation::Horizontal, &window);
	slider->setFixedSize(139, 20);
	slider->setMaximum(0);
	slider->setMaximum(100);

	layout->addWidget(circle);
	layout->addWidget(slider);

	QObject::connect(slider, &QSlider::valueChanged, [&slider, &circle](int newValue) {
		if (newValue > 66)
			circle->setRed();
		else if (newValue > 33)
			circle->setYellow();
		else
			circle->setGreen();
		});

	window.resize(160, 170);
	window.move(1000, 400);
	window.show();
    return a.exec();
}
