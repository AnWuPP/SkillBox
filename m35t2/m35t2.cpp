#include <iostream>
#include <vector>
#include <unordered_set>

auto sort_vec = [](std::vector<int>& vec) {
	std::vector<int> unique;
	std::unordered_set<int> res;
	for (auto& e : vec) {
		res.insert(e);
	}
	for (auto& e : res) {
		unique.push_back(e);
	}
	return std::make_unique<std::vector<int>>(unique);
};

int main()
{
	std::vector<int> a{ 1, 2, 3, 4, 5, 5, 1, 2 };
	auto t = sort_vec(a);
	std::cout << "Before:" << std::endl;
	for (auto& e : a) {
		std::cout << e << std::endl;
	}
	std::cout << "After:" << std::endl;
	for (auto& e : *t) {
		std::cout << e << std::endl;
	}
}