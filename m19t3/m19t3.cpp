#include <iostream>
#include <fstream>

int main()
{
	std::ifstream file;

	file.open("base.txt");

	if (!file.is_open()) {
		std::cout << "Error open file" << std::endl;
		return 1;
	}

	int max = 0;
	std::string peaple = "";

	while (!file.eof()) {
		std::string name, surname, date;
		int pay;
		file >> name >> surname >> pay >> date;

		if (max < pay) {
			max = pay;
			peaple = name + " " + surname;
		}
	}

	std::cout << peaple << " pay: " << max << std::endl;

	file.close();
}