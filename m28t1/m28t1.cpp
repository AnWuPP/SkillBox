#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <thread>

struct Swimmer {
	int id = 0;
	std::string name = "Unknown";
	double speed = 0;
	double dist = 0;
	std::time_t start = 0, end = 0;
	std::thread th;
};

class Swimmers {
	std::vector<Swimmer> swimmers;
	std::vector<int> result;
	unsigned int countEnd = 0;
	std::mutex lock;
public:
	void init(int co) {
		swimmers.resize(co);
		for (int i = 0; i < co; ++i) {
			swimmers[i].id = i;
		}
	}
	int countSwimmers() {
		return static_cast<int>(swimmers.size());
	}
	void setName(int index, std::string name) {
		swimmers[index].name = name;
	}
	void setSpeed(int index, double speed) {
		swimmers[index].speed = speed;
	}
	void move(Swimmer* sw) {
		sw->start = std::time(nullptr);
		while (sw->dist < 100.0) {
			sw->dist += sw->speed;
			if (sw->dist > 100.0)
				sw->dist = 100.0;
			std::cout << sw->name << " distance " << sw->dist << std::endl;
			if (sw->dist >= 100.0) {
				std::lock_guard<std::mutex> l{ lock };
				sw->end = std::time(nullptr);
				++countEnd;
				result.push_back(sw->id);
			}
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}

	void go() {
		for (auto& s : swimmers) {
			s.th = std::thread(&Swimmers::move, this, &s);
		}
	}

	void end() {
		for (auto& s : swimmers) {
			s.th.join();
		}
	}

	bool allFinished() {
		return countEnd == swimmers.size();
	}

	void getRsult() {
		std::cout << "Result table:" << std::endl;
		int count = 0;
		for (auto& e : result) {
			count++;
			std::cout << "#" << count << " " << swimmers[e].name << "\t" << swimmers[e].end - swimmers[e].start << "sec." << std::endl;
		}
	}
};

int main()
{
	Swimmers pool;
	pool.init(6);

	std::string buf;
	double dBuf;

	std::cout << "Enter name and speed for swimmers [name speed]:" << std::endl;
	for (int i = 0, ie = pool.countSwimmers(); i != ie; ++i) {
		std::cin >> buf >> dBuf;
		pool.setName(i, buf);
		pool.setSpeed(i, dBuf);
	}

	pool.go();
	while (!pool.allFinished()) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	pool.end();

	pool.getRsult();
}