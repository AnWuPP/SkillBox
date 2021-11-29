#include <iostream>

int main()
{
    int one[4][4], two[4][4];

    std::cout << "Input two matrix" << std::endl;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> one[i][j];
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> two[i][j];
        }
    }

    bool equal = true;

    for (int i = 0; i < 4 && equal; ++i) {
        for (int j = 0; j < 4 && equal; ++j) {
            equal = one[i][j] == two[i][j];
        }
    }

    std::cout << (equal ? "Equal" : "Not equal") << std::endl;
}


/*
Example matrix:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/