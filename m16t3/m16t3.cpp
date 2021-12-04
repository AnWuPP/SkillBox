#include <iostream>
#include <sstream>

int main()
{
    while (true) {
        double first = 0, second = 0;
        char act = ' ';
        std::string buf;

        std::cout << "Caluclate: ";
        std::getline(std::cin, buf);

        std::stringstream str(buf);
        str >> first >> act >> second;

        double result;
        if (act == '+')
            result = first + second;
        else if (act == '-')
            result = first - second;
        else if (act == '/')
            result = first / second;
        else if (act == '*')
            result = first * second;
        else {
            std::cout << "Wrong action!" << std::endl;
            continue;
        }

        std::cout << buf << " = " << result << std::endl;
    }
}