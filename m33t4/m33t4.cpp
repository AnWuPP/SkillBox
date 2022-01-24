#include <iostream>
#include <string>
#include <vector>

template<typename T>
class Container {
	std::vector<T> data;
public:
	void add(T val) {
		data.push_back(val);
	}
	T calculate() {
		T sum = 0;
		for (auto& e : data) {
			sum += e;
		}
		return sum / static_cast<T>(data.size());
	}
};

int main()
{
	Container<int> arr;
	std::string cmd;
	int a = 0;

	while (cmd != "exit") {
		std::cin >> cmd;
		if (cmd == "add") {
			std::cin >> a;
			arr.add(a);
		}
		else if (cmd == "calc") {
			std::cout << arr.calculate() << std::endl;
		}
	}
}