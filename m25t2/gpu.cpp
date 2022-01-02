#include "gpu.h"

void display(std::vector<int>& data) {
	for (int i = 0; i < data.size(); ++i) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}