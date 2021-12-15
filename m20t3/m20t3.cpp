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
	if (!basket.is_open()) {
		std::cout << "Failed open file." << std::endl;
		return 1;
	}

	std::cout << "Input fish: ";
	std::cin >> fish;

	int count = 0;

	while (!river.eof()) {
		river >> buf;

		if (buf == fish) {
			count++;
			basket << buf << std::endl;
		}
	}

	std::cout << "Result: " << count << std::endl;

	basket.close();
	river.close();
}