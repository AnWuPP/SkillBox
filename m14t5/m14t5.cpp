#include <iostream>

int main()
{
    int m[4][4];

    std::cout << "Input matrix" << std::endl;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> m[i][j];
            if (i != j)
                m[i][j] = 0;
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
/*
Example matrix:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/