#include <iostream>

int main()
{
    int numbers[15] = { 114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118 };

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (j != i && numbers[i] == numbers[j]) {
                std::cout << "Duplicate number: " << numbers[i] << std::endl;
                return 0;
            }
        }
    }
}