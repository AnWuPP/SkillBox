#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::string word;
	std::ifstream file;

	std::cout << "What is word your search? ";
	std::cin >> word;

	file.open("words.txt");

	if (!file.is_open()) {
		std::cout << "Error open file" << std::endl;
		return 1;
	}

	int count = 0;
	while (!file.eof()) {
		std::string r;
		file >> r;
		if (r == word) count++;
	}

	std::cout << "Your word finded " << count << " times." << std::endl;

	file.close();
}