#include <iostream>

int main()
{
    float num[15];
    std::cout << "Input 15 float numbers for sorting:\n";

    for (int i = 0; i < 15; i++) {
        std::cin >> num[i];
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (num[i] < num[j])
            {
                float last = num[j];
                num[j] = num[i];
                num[i] = last;
            }
        }
    }
    std::cout << "Sorted numbers:\n";
    for (int i = 0; i < 15; i++) {
        std::cout << num[i] << " ";
    }
    std::cout << std::endl;
}