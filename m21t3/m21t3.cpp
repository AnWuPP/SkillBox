#include <iostream>
#include <string>
#include <cmath>

struct vec {
	double x = 0, y = 0;
};

vec add(vec& a, vec& b) {
	return { a.x + b.x, a.y + b.y };
}

vec subtract(vec& a, vec& b) {
	return { a.x - b.x, a.y - b.y };
}

vec scale(vec& a, double sc) {
	return { a.x * sc, a.y * sc };
}

double lenght(vec& a) {
	return std::fabs(std::sqrt(a.x * a.x + a.y * a.y));
}

vec normalize(vec& a) {
	double len = lenght(a);
	return { a.x * len, a.y * len };
}

int main()
{
	vec a, b;
	std::string act;

	std::cout << "Enter action: ";
	std::cin >> act;

	if (act == "add") {
		std::cout << "Enter A B and C D for vector 1 and 2" << std::endl;
		std::cin >> a.x >> a.y >> b.x >> b.y;

		vec c = add(a, b);
		std::cout << "Result: " << c.x << " " << c.y << std::endl;
	}
	else if (act == "subtract") {
		std::cout << "Enter A B and C D for vector 1 and 2" << std::endl;
		std::cin >> a.x >> a.y >> b.x >> b.y;

		vec c = subtract(a, b);
		std::cout << "Result: " << c.x << " " << c.y << std::endl;
	}
	else if (act == "scale") {
		std::cout << "Enter A B for vector 1 and scale number" << std::endl;
		std::cin >> a.x >> a.y >> b.x;

		vec c = scale(a, b.x);
		std::cout << "Result: " << c.x << " " << c.y << std::endl;
	}
	else if (act == "length") {
		std::cout << "Enter A B for vector 1" << std::endl;
		std::cin >> a.x >> a.y;

		double result = lenght(a);
		std::cout << "Result: " << result << std::endl;
	}
	else if (act == "normalize") {
		std::cout << "Enter A B for vector 1" << std::endl;
		std::cin >> a.x >> a.y;
		
		vec c = normalize(a);
		std::cout << "Result: " << c.x << " " << c.y << std::endl;
	}
}