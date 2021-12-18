#include <iostream>
#include <fstream>
#include <string>

struct record {
	std::string name = "unknown";
	std::string date = "01.01.1975";
	int pay = 0;
};

int main()
{
	std::string act;
	std::string path = "records.bin";
	
	while (act != "exit") {
		std::cout << "Input action [list / add]: ";
		std::cin >> act;

		if (act == "list") {
			std::ifstream file(path, std::ios::binary);
			if (!file.is_open()) {
				std::cout << "Cant open file." << std::endl;
				continue;
			}

			while (!file.eof()) {
				record data;
				int len = 0;
				file.read((char*)&len, sizeof(len));
				if (len > 0) {
					data.name.resize(len);
					file.read((char*)data.name.c_str(), len);
					file.read((char*)&len, sizeof(len));
					data.date.resize(len);
					file.read((char*)data.date.c_str(), len);
					file.read((char*)&data.pay, sizeof(data.pay));
					std::cout << data.name << " " << data.date << " " << data.pay << std::endl;
				}
			}

			file.close();
		}
		else if (act == "add") {
			std::string name, surname, date;
			int pay;
			std::cin >> name >> surname >> date >> pay;

			std::ofstream file(path, std::ios::binary | std::ios::app);
			if (!file.is_open()) {
				std::cout << "Cant open file." << std::endl;
				continue;
			}
			std::string fname = name + " " + surname;
			int len = fname.length();
			file.write((char*)&len, sizeof(len));
			file.write(fname.c_str(), len);
			len = date.length();
			file.write((char*)&len, sizeof(len));
			file.write(date.c_str(), len);
			file.write((char*)&pay, sizeof(pay));

			std::cout << "Added " << fname << std::endl;

			file.close();
		}
		else {
			std::cout << "Unknown command." << std::endl;
		}
	}
}