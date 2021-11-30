#include <iostream>
#include <vector>

int main()
{
	std::vector<int> a = { -100,-50, -5, 1, 10, 15 };

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a.size() - i - 1; ++j) {
			if (std::abs(a[j]) > std::abs(a[j + 1]))
				std::swap(a[j], a[j + 1]);
		}
	}

	for (int i = 0; i < a.size(); ++i) {
		std::cout << a[i] << " ";
	}
}