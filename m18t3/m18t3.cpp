#include <iostream>

int countJump(int n, int s = 3) {
    int co = 0;
    for (int i = 1; i <= s; ++i) {
        if (i < n)
            co += countJump(n - i, s);
        else if (i == n)
            ++co;
    }
    return co;
}

int main()
{
    int n, s;
    std::cin >> n >> s;

    std::cout << countJump(n, s) << std::endl;
}