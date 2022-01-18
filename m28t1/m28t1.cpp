#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <thread>

struct Swimmer {
	std::string name = "Unknown";
	double speed = 0;
	double dist = 0;
	std::time_t start, end;
};

int main()
{
	std::vector<Swimmer> swimmers(6);
	std::vector<Swimmer> result;

	std::cout << "Enter name and speed for swimmers [name speed]:" << std::endl;
	for (auto& e : swimmers) {
		std::cin >> e.name >> e.speed;
	}

	for (auto& e : swimmers) {
		e.start = std::time(nullptr);
	}

	while (result.size() < 6) {
		for (auto& e : swimmers) {
			if (e.dist >= 100.0)
				continue;
			e.dist += e.speed;
			if (e.dist > 100.0)
				e.dist = 100.0;
			std::cout << e.name << " distance " << e.dist << std::endl;
			if (e.dist >= 100.0) {
				e.end = std::time(nullptr);
				result.push_back(e);
			}
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	swimmers.clear();

	std::cout << "Result table:" << std::endl;
	int count = 0;
	for (auto& e : result) {
		count++;
		std::cout << "#" << count << " " << e.name << "\t" << e.end - e.start << "sec." << std::endl;
	}
}