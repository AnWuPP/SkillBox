#include <iostream>

int countJump(int n) {
    int co = 0;
    for (int i = 1; i <= 3; ++i) {
        if (i < n)
            co += countJump(n - i);
        else if (i == n)
            ++co;
    }
    return co;
}

int main()
{
    int n;
    std::cin >> n;

    std::cout << countJump(n) << std::endl;
}