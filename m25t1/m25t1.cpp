#include "m25t1.h"

int main()
{
	std::string cmd;
	bool started = false;
	Point x, y;
	std::cout << "Enter command: scalpel, hemostat, tweezers, suture" << std::endl;
	while (cmd != "exit") {
		std::cin >> cmd;

		if (cmd == "scalpel") {
			if (started) {
				std::cout << "Finished last operation and try again" << std::endl;
				continue;
			}
			started = true;
			scalpel(x, y);
		}
		else if (cmd == "hemostat") {
			if (!started) {
				std::cout << "Start new operation for this action" << std::endl;
				continue;
			}
			hemostat();
		}
		else if (cmd == "tweezers") {
			if (!started) {
				std::cout << "Start new operation for this action" << std::endl;
				continue;
			}
			tweezers();
		}
		else if (cmd == "suture") {
			if (!started) {
				std::cout << "Start new operation for this action" << std::endl;
				continue;
			}
			suture(x, y);
			started = false;
		}
	}
}
