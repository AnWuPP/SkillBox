#include <iostream>
#include <string>
#include <map>

bool isAnagram(std::string& first, std::string& second) {
	bool fail = first == second || first.length() != second.length();

	for (int i = 0; i < first.length() && !fail; ++i) {
		fail = second.find(first[i]) == std::string::npos;
	}

	return !fail;
}

int main()
{
	std::map<std::string, std::string> anagrams;
	std::string first, second;

	while (first != "!q" && second != "!q") {
		std::cout << "Input pair word: ";
		std::cin >> first >> second;

		if (isAnagram(first, second)) {
			anagrams.insert(std::pair<std::string, std::string>(first, second));
			std::cout << "Added pair words [" << first << " " << second << "]" << std::endl;
		}
		else
			std::cout << second << " is not anagram " << first << std::endl;
	}

	std::cout << "Anagrams:" << std::endl;
	for (auto& pair : anagrams) {
		std::cout << pair.first << " <- " << pair.second << std::endl;
	}
}