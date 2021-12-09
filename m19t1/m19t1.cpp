#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::string word;
	std::vector<std::string> words;
	std::ifstream file;

	std::cout << "What is word your search? ";
	std::cin >> word;

	file.open("words.txt");

	while (!file.eof()) {
		std::string r;
		file >> r;
		words.push_back(r);
	}

	int count = 0;
	for (int i = 0; i < words.size(); ++i) {
		if (words[i] == word) count++;
	}

	std::cout << "Your word finded " << count << " times." << std::endl;

	file.close();
}