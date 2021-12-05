#include <iostream>

void evendigits(long long int i, int& c) {
	if (i == 0) return;
	int p = i % 10;
	if (p % 2 == 0) c++;
	evendigits(i / 10, c);
}

int main()
{
	int ans = 0;

	evendigits(9223372036854775806, ans);

	std::cout << ans << std::endl;
}