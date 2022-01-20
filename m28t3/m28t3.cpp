#include <iostream>
#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <random>

int genRandom(int min, int max) {
	static thread_local std::random_device rd;
	std::uniform_int_distribution<int> uid(min, max);
	return uid(rd);
}

class Kitchen {
	std::queue<int> orders;
	std::queue<int> cooked;
	std::mutex work;
	bool cooking = false;
	int count = 0;

public:

	std::string getNameEat(int i) {
		switch (i) {
		case 0:
			return "Pizza";
		case 1:
			return "Soup";
		case 2:
			return "Stake";
		case 3:
			return "Salat";
		case 4:
			return "Sushi";
		default:
			return "unk";
		}
	}

	void getOrder() {
		std::this_thread::sleep_for(std::chrono::seconds(genRandom(5, 10)));
		std::lock_guard<std::mutex> lock{ work };
		int eat = genRandom(0, 4);
		std::cout << "The waiter took the order " << getNameEat(eat) << std::endl;
		orders.push(eat);
	}

	void cookOrder() {
		if (orders.size() == 0 || cooking)
			return;
		cooking = true;
		std::this_thread::sleep_for(std::chrono::seconds(genRandom(5, 15)));
		std::lock_guard<std::mutex> lock{ work };
		auto first = orders.front();
		std::cout << "The cook has prepared " << getNameEat(first) << std::endl;
		cooked.push(first);
		orders.pop();
		cooking = false;
	}

	void takeOrder() {
		if (cooked.size() == 0)
			return;
		std::this_thread::sleep_for(std::chrono::seconds(30));
		std::lock_guard<std::mutex> lock{ work };
		auto first = cooked.front();
		std::cout << "Courier picked up " << getNameEat(first) << std::endl;
		cooked.pop();
		count++;
	}

	void proccess() {
		while (count < 10) {
			std::thread get(&Kitchen::getOrder, this);
			std::thread cook(&Kitchen::cookOrder, this);
			std::thread take(&Kitchen::takeOrder, this);
			get.join();
			cook.join();
			take.join();
		}
		std::cout << "Mission complite, ten order finished" << std::endl;
	}
};

int main() {
	Kitchen kitchen;
	kitchen.proccess();
}