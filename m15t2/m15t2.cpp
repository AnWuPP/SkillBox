#include <iostream>
#include <vector>

int main()
{
	std::vector<int> a = { 2, 7, 11, 15 };
	int find = 9;

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) {
			if (a[i] + a[j] == find) {
				std::cout << a[i] << " " << a[j] << std::endl;
				return 0;
			}
		}
	}
}