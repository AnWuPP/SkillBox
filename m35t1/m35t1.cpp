#include <iostream>
#include <array>

int main()
{
	std::array<int, 5> a{ 1, 2, 3, 4, 5 };
	for (auto& i : a)
		std::cout << i << std::endl;
}