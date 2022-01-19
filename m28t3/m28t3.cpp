#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <random>

int genRandom(int min, int max) {
	static thread_local std::random_device rd;
	std::uniform_int_distribution<int> uid(min, max);
	return uid(rd);
}

class Kitchen {
	std::vector<int> orders;
	std::vector<int> cooked;
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

	static void getOrder(Kitchen* kitchen) {
		std::this_thread::sleep_for(std::chrono::seconds(genRandom(5, 10)));
		std::lock_guard<std::mutex> lock{ kitchen->work };
		int eat = genRandom(0, 4);
		std::cout << "The waiter took the order " << kitchen->getNameEat(eat) << std::endl;
		kitchen->orders.push_back(eat);
	}

	static void cookOrder(Kitchen* kitchen) {
		if (kitchen->orders.size() == 0 || kitchen->cooking)
			return;
		kitchen->cooking = true;
		std::this_thread::sleep_for(std::chrono::seconds(genRandom(5, 15)));
		std::lock_guard<std::mutex> lock{ kitchen->work };
		auto first = kitchen->orders.begin();
		std::cout << "The cook has prepared " << kitchen->getNameEat(*first) << std::endl;
		kitchen->cooked.push_back(*first);
		kitchen->orders.erase(first);
		kitchen->cooking = false;
	}

	static void takeOrder(Kitchen* kitchen) {
		if (kitchen->cooked.size() == 0)
			return;
		std::this_thread::sleep_for(std::chrono::seconds(30));
		std::lock_guard<std::mutex> lock{ kitchen->work };
		auto first = kitchen->cooked.begin();
		std::cout << "Courier picked up " << kitchen->getNameEat(*first) << std::endl;
		kitchen->cooked.erase(first);
		kitchen->count++;
	}

	static void proccess(Kitchen* kitchen) {
		if (kitchen == nullptr)
			return;
		while (kitchen->count < 10) {
			std::thread get(Kitchen::getOrder, kitchen);
			std::thread cook(Kitchen::cookOrder, kitchen);
			std::thread take(Kitchen::takeOrder, kitchen);
			get.join();
			cook.join();
			take.join();
		}
		std::cout << "Mission complite, ten order finished" << std::endl;
	}
};

int main() {
	Kitchen kitchen;
	Kitchen::proccess(&kitchen);
}