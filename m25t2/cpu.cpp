#include "cpu.h"

int complute(std::vector<int>& data) {
	int sum = 0;
	for (int i = 0; i < data.size(); ++i) {
		sum += data[i];
	}
	return sum;
}