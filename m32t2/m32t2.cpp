#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main()
{
	std::ifstream file("cinema_base.json");
	if (!file.is_open()) {
		std::cout << "File not found" << std::endl;
		return 1;
	}
	json data;
	file >> data;
	file.close();

	std::cout << "Enter actor name or subname" << std::endl;
	std::string findBuf;
	std::cin >> findBuf;
	std::vector<std::string> cinema;
	std::cout << "Searching.." << std::endl;
	for (json::iterator it = data.begin(); it != data.end(); ++it) {
		json c = (*it)["actors"];
		for (auto& e : c) {
			if (e["name"].get<std::string>().find(findBuf) != std::string::npos)
				cinema.push_back(it.key());
		}
	}
	if (cinema.empty())
		std::cout << "Actor not found" << std::endl;
	else {
		std::cout << "Films:" << std::endl;
		for (auto& e : cinema) {
			std::cout << e << std::endl;
		}
	}
}