#include <iostream>

bool substr(const char* a, const char* b) {
	int i = 0;
	bool found = false;
	while ((*(a + i) != '\0') && !found) {
		int j = 0;
		bool fail = false;
		while ((*(b + j) != '\0') && !found) {
			fail = *(a + i +j) == '\0' || *(a + i + j) != *(b + j);
			++j;
		}
		found = !fail;
		++i;
	}
	return found;
}

int main()
{
	const char* a = "Hello world";
	const char* b = "wor";
	const char* c = "banana";
	std::cout << substr(a, b) << " " << substr(a, c);
}