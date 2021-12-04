#include <iostream>
#include <string>

int main()
{
    std::string first, second;
    std::cout << "Input first and second block: ";
    std::cin >> first >> second;

    double result = std::stod(first + "." + second);

    std::cout << "Result: " << result << std::endl;
}