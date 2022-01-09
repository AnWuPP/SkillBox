#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>

enum class Color {
	NONE,
	GREEN,
	RED,
	BLUE
};

struct Rect {
	double x = 0, y = 0;
	Rect(double _x, double _y) : x(_x), y(_y) {}
};

class Figure {
public:
	double x = 0, y = 0;
	Figure(double _x, double _y) : x(_x), y(_y) {}
	Color color = Color::NONE;
	virtual double square() = 0;
	virtual Rect rect() = 0;
	virtual ~Figure() = 0;
};

class Circle : public Figure {
public:
	double r = 0;

	Circle(double _x, double _y, double _r) : Figure(_x, _y), r(_r) {}

	double square() override {
		return M_PI * std::pow(r, 2);
	}

	Rect rect() override {
		return Rect(r, r);
	}

	void dump() {
		Rect rt = rect();
		std::printf("X: %f Y: %f, Radius: %f, Rect: %f %f", x, y, r, rt.x, rt.y);
	}
};

class Triangle : public Figure {
public:
	double a = 0;

	Triangle(double _x, double _y, double _a) : Figure(_x, _y), a(_a) {}

	double square() override {
		return (a * height()) / 2;
	}

	Rect rect() override {
		return Rect(a, height());
	}

	void dump() {
		Rect rt = rect();
		std::printf("X: %f Y: %f, Edge: %f, Rect: %f %f", x, y, a, rt.x, rt.y);
	}

private:
	double height() {
		return a * std::sin(M_PI / 3);
	}
};

class Quad : public Figure {
public:
	double a = 0;

	Quad(double _x, double _y, double _a) : Figure(_x, _y), a(_a) {}

	double square() override {
		return std::pow(a, 2);
	}

	Rect rect() override {
		return Rect(a, a);
	}

	void dump() {
		Rect rt = rect();
		std::printf("X: %f Y: %f, Edge: %f, Rect: %f %f", x, y, a, rt.x, rt.y);
	}
};


class Rectangle : public Figure {
public:
	double a = 0, b = 0;

	Rectangle(double _x, double _y, double _a, double _b) : Figure(_x, _y), a(_a), b(_b) {}

	double square() override {
		return a * b;
	}

	Rect rect() override {
		return Rect(a, b);
	}

	void dump() {
		Rect rt = rect();
		std::printf("X: %f Y: %f, W: %f H: %f, Rect: %f %f", x, y, a, b, rt.x, rt.y);
	}
};

int main()
{
	std::string buf;

	std::cout << "Enter command: circle [x y r], triangle [x y a], square [x y a], rectangle [x y w h]" << std::endl;
	while (buf != "exit") {
		std::cin >> buf;
		if (buf == "circle") {
			double x, y, r;
			std::cin >> x >> y >> r;
			Circle c(x, y, r);
			c.dump();
		}
		else if (buf == "triangle") {
			double x, y, a;
			std::cin >> x >> y >> a;
			Triangle t(x, y, a);
			t.dump();
		}
		else if (buf == "square") {
			double x, y, a;
			std::cin >> x >> y >> a;
			Quad q(x, y, a);
			q.dump();
		}
		else if (buf == "rectangle") {
			double x, y, a, b;
			std::cin >> x >> y >> a >> b;
			Rectangle r(x, y, a, b);
			r.dump();
		}
	}
}