#include <iostream>
#include <fstream>

int main()
{
	std::string fish;
	std::string buf;

	std::ifstream river("river.txt");
	if (!river.is_open()) {
		std::cout << "Failed open file." << std::endl;
		return 1;
	}

	std::ofstream basket("basket.txt", std::ios::app);

	std::cout << "Input fish: ";
	std::cin >> fish;

	while (!river.eof()) {
		river >> buf;

		if (buf == fish)
			basket << buf << std::endl;
	}

	basket.close();
	river.close();
}