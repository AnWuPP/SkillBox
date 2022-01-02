#include "ram.h"

std::vector<int> ram(8, 0);

std::vector<int> read() {
	return ram;
}

void write(std::vector<int> data) {
	ram = data;
}