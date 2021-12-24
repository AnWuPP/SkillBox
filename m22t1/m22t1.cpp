#include <iostream>
#include <string>
#include <map>
#include <vector>

bool verifyPhone(std::string& phone) {
	bool fail = phone.length() != 8;
	if (!fail) {
		char sig[8] = { 'N', 'N', '-', 'N', 'N', '-', 'N', 'N' };
		for (int i = 0; i < 8 && !fail; ++i) {
			if (sig[i] == 'N') {
				fail = (phone[i] < '0' || phone[i] > '9');
			}
			else
				fail = phone[i] != sig[i];
		}
	}
	return !fail;
}

bool parseSurnameAndPhone(std::string& input, std::string& surname, std::string& phone) {
	size_t dep = input.find(' ');
	bool fail = dep == std::string::npos;
	if (!fail) {
		phone = input.substr(0, dep);
		surname = input.substr(dep + 1);
		fail = !verifyPhone(phone);
	}
	return !fail;
}

int main()
{
	std::map<std::string, std::string> surnameByPhone;
	std::map<std::string, std::vector<std::string>> phonesBySurname;
	std::string input = "", surname = "", phone = "";

	std::cout << "Enter !q for exit" << std::endl;
	while (input != "!q") {
		std::cout << "Enter surname or phone or phone and surname:" << std::endl;
		std::getline(std::cin, input);

		if (parseSurnameAndPhone(input, surname, phone)) {
			surnameByPhone.insert(std::pair<std::string, std::string>(phone, surname));
			phonesBySurname[surname].push_back(phone);
			std::cout << "Added " << surname << "[" << phone << "]" << std::endl;
		}
		else if (verifyPhone(input)) {
			std::map<std::string, std::string>::iterator it = surnameByPhone.find(input);
			if (it == surnameByPhone.end()) {
				std::cout << "Phone not found" << std::endl;
				continue;
			}
			std::cout << "This phone have " << it->second << std::endl;
		}
		else {
			std::map<std::string, std::vector<std::string>>::iterator it = phonesBySurname.find(input);
			if (it == phonesBySurname.end()) {
				std::cout << "Surname not found" << std::endl;
				continue;
			}
			std::cout << it->first << " phones:" << std::endl;
			for (auto& ph : it->second)
				std::cout << ph << std::endl;
		}
	}
}