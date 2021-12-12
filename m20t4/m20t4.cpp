#include <iostream>
#include <fstream>
#include <vector>

bool getBase(std::string& path, int vec[]) {
	std::ifstream file(path, std::ios::binary);

	if (!file.is_open()) {
		return false;
	}

	int count = 0;
	while (count < 6) {
		int buf;
		file.read((char*)&buf, sizeof(buf));
		vec[count++] = buf;
	}

	file.close();

	return true;
}

void saveBase(std::string& path, int vec[]) {
	std::ofstream file(path, std::ios::binary);

	for (int i = 0; i < 6; ++i) {
		file.write((char*)&vec[i], sizeof(vec[i]));
	}

	file.close();
}

int countMoney(int vec[], int t = -1) {
	int count = 0;
	if (t == -1) {
		for (int i = 0; i < 6; ++i) {
			count += vec[i];
		}
	}
	else {
		count = vec[t];
	}
	return count;
}

int main()
{
	int mtype[] = { 100, 200, 500, 1000, 2000, 5000 };
	int money[6] = { 0 };
	char act;
	std::string path = "bank.bin";
	
	if (!getBase(path, money))
		saveBase(path, money);

	std::cout << "Hello! Input action [+ / -]: ";
	std::cin >> act;

	if (act == '+') {
		int c = countMoney(money);
		if (c != 1000) {
			for (int i = 0; i < 1000 - c; ++i) {
				money[std::rand() % 6]++;
			}
			std::cout << "Bank replenished!" << std::endl;
			saveBase(path, money);
		}
		else {
			std::cout << "Error, bank is full!" << std::endl;
			return 0;
		}
	}
	else if (act == '-') {
		int buf;
		std::cout << "Input sum for get: ";
		std::cin >> buf;

		if (buf < 100) {
			std::cout << "Error! Input more 100.." << std::endl;
			return 0;
		}
		else if (buf % 100 != 0) {
			std::cout << "Error! Invalid integer.." << std::endl;
			return 0;
		}

		int take = buf;
		int taked = 0;
		for (int i = 5; i >= 0; --i) {
			int d = take / mtype[i];
			if (d > 0 && d < money[i]) {
				money[i] -= d;
				taked++;
				take %= mtype[i];
				std::cout << "Take " << mtype[i] << " x" << d << std::endl;
			}
		}
		if (taked == 0) {
			std::cout << "There is no required amount in the ATM." << std::endl;
		}
		else
			saveBase(path, money);
	}
	else {
		std::cout << "Wrong action! Please try again..." << std::endl;
	}
}