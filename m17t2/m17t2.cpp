#include <iostream>

void reverse(int* a) {
    for (int i = 0; i < 5; ++i) {
        std::swap(a[i], a[9 - i]);
    }
}

int main()
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    reverse(a);

    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}