#include <iostream>

struct vec {
	double x = 0, y = 0;
};

int main()
{
	vec a, b;
	std::string act;

	std::cout << "Enter action: ";
	std::cin >> act;

	if (act == "add") {
		std::cout << "Enter A B and C D for vector 1 and 2" << std::endl;
		std::cin >> a.x >> a.y >> b.x >> b.y;

		vec c{ a.x + b.x, a.y + b.y };
		std::cout << "Result: " << c.x << " " << c.y << std::endl;
	}
	else if (act == "subtract") {
		std::cout << "Enter A B and C D for vector 1 and 2" << std::endl;
		std::cin >> a.x >> a.y >> b.x >> b.y;

		vec c{ a.x - b.x, a.y - b.y };
		std::cout << "Result: " << c.x << " " << c.y << std::endl;
	}
	else if (act == "scale") {
		std::cout << "Enter A B and C D for vector 1 and 2" << std::endl;
		std::cin >> a.x >> a.y >> b.x >> b.y;

		double result = a.x * b.x + a.y * b.y;
		std::cout << "Result: " << result << std::endl;
	}
	else if (act == "length") {
		std::cout << "Enter A B for vector 1" << std::endl;
		std::cin >> a.x >> a.y;

		double result = std::fabs(std::sqrtf(a.x * a.x + a.y * a.y));
		std::cout << "Result: " << result << std::endl;
	}
	else if (act == "normalize") {
		std::cout << "Enter A B for vector 1" << std::endl;
		std::cin >> a.x >> a.y;

		double result = std::fabs(std::sqrtf(a.x * a.x + a.y * a.y));
		vec c{ a.x * result, a.y * result };
		std::cout << "Result: " << c.x << " " << c.y << std::endl;
	}
}