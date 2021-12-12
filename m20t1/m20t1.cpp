#include <iostream>
#include <string>
#include <fstream>

bool validateString(std::string str) {
	bool fail = str.length() == 0;
	for (int i = 0; i < str.length() && !fail; i++) {
		char l = tolower(str[i]);
		fail = l < 'a' || l > 'z';
	}
	return !fail;
}

bool validateNumber(std::string str) {
	bool fail = str.length() == 0;
	for (int i = 0; i < str.length() && !fail; i++) {
		fail = str[i] < '0' || str[i] > '9';
	}
	return !fail;
}

bool validateDate(std::string str) {
	bool fail = str.length() == 0;
	int point = 0;
	int last = 0;
	int next = 0;
	while (next != std::string::npos && !fail) {
		next = str.find('.', last);
		std::string sub = str.substr(last, next != std::string::npos ? next - last : -1);
		if (point < 2)
			fail = sub.length() != 2;
		else if (point == 2)
			fail = sub.length() != 4;
		if (!fail)
			fail = !validateNumber(sub);
		last = next + 1;
		point++;
	}
	return !fail && point == 3;
}

bool validateData(std::string& data) {
	bool fail = data.length() == 0;
	int count = 0;
	int lastPos = 0;
	int newPos = 0;
	while (newPos != std::string::npos && !fail) {
		newPos = data.find(' ', lastPos);
		if (count < 2)
			fail = !validateString(data.substr(lastPos, newPos - lastPos));
		else if (count == 2)
			fail = !validateNumber(data.substr(lastPos, newPos - lastPos));
		else if (count == 3)
			fail = !validateDate(data.substr(lastPos));
		lastPos = newPos + 1;
		count++;
	}
	return !fail && count == 4;
}

int main()
{
	std::string buffer;
	std::ofstream file("pay.txt", std::ios::app);

	std::cout << "Input new note by format: Name Surname Pay Date. Use \"end\" for exit." << std::endl;
	while (true) {
		std::getline(std::cin, buffer);
		if (buffer == "end")
			break;

		if (!validateData(buffer)) {
			std::cout << "Error! Please use valid format.." << std::endl;
			continue;
		}

		file << buffer << std::endl;
	}

	file.close();
}