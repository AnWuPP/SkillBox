#include <iostream>

void showWorld(bool world[][5][10], int height) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << (world[i][j][height] ? 1 : 0) << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int buf;
    bool world[5][5][10];
    std::cout << "Input stand height:" << std::endl;
    std::cout << "Use range 0-9 and -1 for a missing column." << std::endl;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << "for x: " << i << ", y: " << j << ": ";
            std::cin >> buf;
            if (buf < -1 || buf > 9) {
                --j;
                std::cout << "Error! Please try again..." << std::endl;
                continue;
            }
            for (int k = 0; k < 10; ++k) {
                world[i][j][k] = k <= buf && buf != -1;
            }
        }
    }

    std::cout << "Input height for show world, use -1 for exit:" << std::endl;
    while (buf != -1) {
        std::cin >> buf;
        if (buf < 0 || buf > 9) {
            std::cout << "Error! User 0-9 range or -1 for exit.." << std::endl;
            continue;
        }

        showWorld(world, buf);
    }
}
/*
5
4
3
6
7
8
9
1
1
3
9
8
0
9
9
1
-1
2
5
6
7
8
9
-1
9
*/