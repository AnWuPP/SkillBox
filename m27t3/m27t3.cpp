#include <iostream>
#include <vector>

enum class JobType {
	NONE,
	A,
	B,
	C
};

class Worker {
	JobType job = JobType::NONE;
public:
	void setJob(int jobid) {
		switch (jobid) {
		case 0:
			job = JobType::A;
			break;
		case 1:
			job = JobType::B;
			break;
		case 2:
			job = JobType::C;
			break;
		}
	}

	char getJob() {
		switch (job) {
		case JobType::A:
			return 'A';
		case JobType::B:
			return 'B';
		case JobType::C:
			return 'C';
		default:
			return 'N';
		}
	}
};

class Manager {
	int id = -1;
	int maxWorkers = 0;
	std::vector<Worker> workers;
public:
	void printWork() {
		for (auto& w : workers) {
			std::cout << w.getJob() << " ";
		}
		std::cout << std::endl;
	}
	void setWorkers(int mWorkers) {
		if (maxWorkers != 0)
			return;
		maxWorkers = mWorkers;
	}
	int getId() {
		return id;
	}
	void setId(int inId) {
		if (id != -1)
			return;
		id = inId;
	}
	bool isAllWorkerBusy() {
		return maxWorkers <= workers.size();
	}
	void addWorker(int seed) {
		if (isAllWorkerBusy() || id == -1)
			return;
		std::srand(seed + id);
		Worker worker;
		worker.setJob(std::rand() % 3);
		workers.push_back(worker);
	}
};

class Director {
public:
	std::vector<Manager> managers;
	void addManager(Manager& m) {
		m.setId(managers.size() + 1);
		managers.push_back(m);
	}
};

int main()
{
	Director director;
	int work = 0;

	std::cout << "Enter count of managers: ";
	std::cin >> work;

	for (int i = 0, ie = work; i != ie; ++i) {
		std::cout << "Enter worker for team " << i << ": ";
		std::cin >> work;
		Manager manager;
		manager.setWorkers(work);
		director.addManager(manager);
	}
	std::cout << "Okay, next step." << std::endl;
	for (auto& m : director.managers) {
		while (!m.isAllWorkerBusy()) {
			std::cout << "Enter work number: ";
			std::cin >> work;
			m.addWorker(work);
		}
	}
	std::cout << "All workers job. Result:" << std::endl;
	for (auto& m : director.managers) {
		std::cout << "Team #" << m.getId() << std::endl;
		m.printWork();
	}
}