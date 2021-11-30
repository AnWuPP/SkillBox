#include <iostream>
#include <vector>

int main()
{
	std::vector<int> a;
	int buf = 0;

	while (buf != -2) {
		std::cin >> buf;
		if (buf == -1) {
			for (int i = 0; i < a.size(); ++i) {
				for (int j = 0; j < a.size(); ++j) {
					if (a[i] < a[j])
						std::swap(a[i], a[j]);
				}
			}
			if (a.size() > 4)
				std::cout << a[4] << std::endl;
			else
				std::cout << "Error! Add more integer" << std::endl;
		}
		else
			a.push_back(buf);
	}
}