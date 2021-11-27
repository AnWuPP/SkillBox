#include <iostream>
#include <string>

int main()
{
    std::string surnames[10];
    int apr;

    std::cout << "Input subnames:" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "Surname for apartament #" << i + 1 << ": ";
        std::cin >> surnames[i];
    }

    std::cout << "What apartments are you interested in?" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cin >> apr;
        if (apr < 1 || apr > 10) {
            std::cout << "Error! Please try again" << std::endl;
            i--;
            continue;
        }
        std::cout << "Surname for apartament #" << apr << ": " << surnames[apr - 1] << std::endl;
    }
}