#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <limits>

struct Task {
	std::string name = "";
	std::time_t start = 0;
	std::time_t end = 0;
};

void endTask(std::vector<Task>& tasks) {
	if (tasks.size() > 0) {
		std::vector<Task>::iterator it = --tasks.end();
		if (it->end == 0) {
			it->end = std::time(nullptr);
			std::cout << "Ended task \"" << it->name << "\"" << std::endl;
		}
	}
}

void showTask(std::vector<Task>::iterator task) {
	std::time_t diff = (std::time_t)std::difftime(task->end != 0 ? task->end : std::time(nullptr), task->start);
	std::cout << "Task: " << task->name << std::endl;
	std::printf("%s: %02d:%02d\n", (task->end != 0 ? "Time to end" : "Time from start"), diff / 60, diff % 60);
	std::cout << "-----=========-----" << std::endl;
}

int main()
{
	std::string cmd;
	std::vector<Task> tasks;

	std::cout << "Enter commands: begin, end, status or exit" << std::endl;
	while (cmd != "exit") {
		std::cin >> cmd;
		if (cmd == "begin") {
			endTask(tasks);
			Task task;
			std::cout << "Enter name for new task: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, task.name);
			task.start = std::time(nullptr);

			tasks.push_back(task);
			std::cout << task.name << " started" << std::endl;
		}
		else if (cmd == "end") {
			endTask(tasks);
		}
		else if (cmd == "status") {
			if (tasks.size() > 0) {
				for (auto it = tasks.begin(); it != --tasks.end(); ++it) {
					if (it->end != 0) {
						std::cout << "-----=========-----" << std::endl;
						showTask(it);
					}
				}
			}
			if (tasks.size() == 0 || (--tasks.end())->end != 0) {
				std::cout << "No current task" << std::endl;
			}
			else {
				std::cout << "-----=========-----" << std::endl;
				std::cout << "Current task:" << std::endl;
				showTask(--tasks.end());
			}
		}

	}

}