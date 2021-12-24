#include <iostream>
#include <string>
#include <map>

int main()
{
	std::map<std::string, int> queue;
	std::string buf;

	std::cout << "Use !q for exit" << std::endl;
	while (buf != "!q") {
		std::cin >> buf;
		if (buf == "next") {
			if (queue.empty()) {
				std::cout << "Queue is empty" << std::endl;
				continue;
			}
			std::map<std::string, int>::iterator it = queue.begin();
			std::cout << it->first << std::endl;
			it->second--;
			if (it->second <= 0)
				queue.erase(it);
		}
		else {
			std::map<std::string, int>::iterator it = queue.find(buf);
			if (it == queue.end())
				queue.insert(std::pair<std::string, int>(buf, 1));
			else
				it->second++;
		}
	}
}