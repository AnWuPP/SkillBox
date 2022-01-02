#include <iostream>
#include "ram.h"
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"

int main()
{
	std::string cmd;

	std::cout << "Enter command: input, sum, display, save, load, exit" << std::endl;
	while (cmd != "exit") {
		std::cin >> cmd;
		if (cmd == "input") {
			write(keyboard());
		}
		else if (cmd == "sum") {
			std::cout << "Sum: " << complute(read()) << std::endl;
		}
		else if (cmd == "display") {
			display(read());
		}
		else if (cmd == "save") {
			save(read());
		}
		else if (cmd == "load") {
			write(load());
		}
	}
}
