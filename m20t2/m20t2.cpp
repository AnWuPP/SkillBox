#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::ofstream file("pic.txt", std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Cant open file." << std::endl;
		return 0;
	}

	int w, h;
	std::cout << "Input weight and height: ";
	std::cin >> w >> h;

	std::srand(std::time(nullptr));
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < h; ++j) {
			char s = '0' + std::rand() % 2;
			file.write(&s, sizeof(char));
		}
		char s = '\n';
		file.write(&s, sizeof(char));
	}

	file.close();
}