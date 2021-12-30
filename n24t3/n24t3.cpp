#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

int main()
{
	std::time_t now = std::time(nullptr);
	std::tm start = *std::localtime(&now);
	std::cin >> std::get_time(&start, "%M:%S");
	std::time_t finish = std::time(nullptr) + (start.tm_min * 60) + start.tm_sec - 1;
	std::time_t after = now - 1;
	while (finish > std::time(nullptr)) {
		if (after != std::time(nullptr)) {
			after = std::time(nullptr);
			std::cout << "Tick-Tack" << std::endl;
		}
	}
	std::cout << "DING DING DING!!!!!!" << std::endl;
}