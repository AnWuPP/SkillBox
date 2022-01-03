#include "kbd.h"

std::vector<int> keyboard() {
	std::vector<int> data(8, 0);
	for (int i = 0; i < 8; ++i) {
		std::cin >> data[i];
	}
	return data;
}