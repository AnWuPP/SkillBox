#include <iostream>
#include <string>
#include <map>

bool isAnagram(std::string& one, std::string& two) {
	bool fail = one == two || one.length() != two.length();

	std::map<char, int> coOne, coTwo;

	for (int i = 0; i < one.length(); ++i) {
		std::map<char, int>::iterator itOne = coOne.find(one[i]), itTwo = coTwo.find(two[i]);
		if (itOne != coOne.end())
			itOne->second++;
		else
			coOne.insert(std::pair<char, int>(one[i], 1));
		if (itTwo != coTwo.end())
			itTwo->second++;
		else
			coTwo.insert(std::pair<char, int>(two[i], 1));
	}
	fail = fail || coOne.size() != coTwo.size();
	for (std::map<char, int>::iterator it = coOne.begin(), jt = coTwo.begin(); it != coOne.end() && jt != coTwo.end() && !fail; ++it, ++jt) {
		fail = it->first != jt->first || it->second != jt->second;
	}

	return !fail;
}

int main()
{
	std::string first, second;

	while (first != "!q" && second != "!q") {
		std::cout << "Input pair word: ";
		std::cin >> first >> second;

		if (isAnagram(first, second))
			std::cout << "Yea, its anagram [" << first << " " << second << "]" << std::endl;
		else
			std::cout << second << " is not anagram " << first << std::endl;
	}
}