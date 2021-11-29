#include <iostream>

int main()
{
	int num = 0;
	int t[5][5];

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			t[i][(i % 2 == 0 ? j : 4 - j)] = num;
			num++;
		}
	}


	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			std::cout << t[i][j] << " ";
		}
		std::cout << std::endl;
	}
}