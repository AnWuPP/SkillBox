#pragma once

#include <iostream>
#include <string>

struct Point {
	double x = -1, y = -1;
};

void scalpel(Point& x, Point& y) {
	std::cout << "Enter start and finish position: ";
	std::cin >> x.x >> x.y >> y.x >> y.y;
	
	std::cout << "The incision is made " << x.x << " " << x.y << " - " << y.x << " " << y.y << std::endl;
}

void hemostat() {
	std::cout << "Enter position for clamp: ";
	Point p;
	std::cin >> p.x >> p.y;
	std::cout << "Clamp installed " << p.x << " " << p.y << std::endl;
}

void tweezers() {
	std::cout << "Enter position for tweezers: ";
	Point p;
	std::cin >> p.x >> p.y;
	std::cout << "Tweezers set to " << p.x << " " << p.y << std::endl;
}

void suture(Point& x, Point& y) {
	std::cout << "Suture set to " << x.x << " " << x.y << " - " << y.x << " " << y.y << std::endl;
}
