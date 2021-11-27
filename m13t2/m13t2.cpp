#include <iostream>
#include <vector>

int main()
{
    std::vector<float> price = { 2.5, 4.25, 3.0, 10.0 };
    std::vector<int> basket = { 1, 1, 0, 3 };
    float sum = .0f;
    for (int i = 0; i < basket.size(); ++i) {
        sum += price[basket[i]];
    }
    std::cout << "Result: " << sum << std::endl;

}