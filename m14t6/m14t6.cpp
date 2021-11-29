#include <iostream>
#include <vector>

int main()
{
    std::vector<float> v(4);
    std::vector<float> r(4);
    float m[4][4];
    std::cout << "Input vector: ";
    for (int i = 0; i < 4; ++i) {
        std::cin >> v[i];
    }
    std::cout << "Input matrix:" << std::endl;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> m[i][j];
        }
    }

    for (int i = 0; i < 4; ++i) {
        float sum = 0;
        for (int j = 0; j < 4; ++j) {
            sum += v[i] * m[i][j];
        }
        r[i] = sum;
    }

    std::cout << "Result:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << r[i] << " ";
    }
    std::cout << std::endl;
}
/*
Example vector:
1 2 -1 1
Example matrix:
2 4 -1 1
6 3 -2 0
0 5 -4 1
3 8 9 0
Result:
6 14 -2 20
*/