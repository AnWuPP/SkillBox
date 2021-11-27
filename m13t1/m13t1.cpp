#include <iostream>
#include <vector>

int main()
{
    int co, buf;
    std::cout << "Input the number of required numbers: ";
    std::cin >> co;
    while (co < 1) {
        std::cout << "Error, please try again: ";
        std::cin >> co;
    }

    std::vector<int> nums(co);
    std::cout << "Input " << co << " numbers:" << std::endl;
    for (int i = 0; i < co; ++i) {
        std::cin >> buf;
        nums[i] = buf;
    }
   
    std::vector<int> vec;
    std::cout << "Input the number you want to remove: ";
    std::cin >> buf;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != buf)
            vec.push_back(nums[i]);
    }
    std::cout << "Result:" << std::endl;
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << std::endl;
    }
}