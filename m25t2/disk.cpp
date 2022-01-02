#include "disk.h"
#include <iostream>

void save(std::vector<int>& data) {
	std::ofstream file(DATABSE);
	if (file.is_open()) {
		for (int v : data) {
			file << v << std::endl;
		}
		file.close();
	}
}

std::vector<int> load() {
	std::vector<int> data(8, 0);
	std::ifstream file(DATABSE);
	if (file.is_open()) {
		for (int& v : data) {
			if (!file.eof())
				file >> v;
		}
		file.close();
	}
	return data;
}