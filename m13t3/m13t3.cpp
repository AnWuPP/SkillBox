#include <iostream>
#include <vector>

int main()
{
    std::vector<int> base(20);
    int buf = 0, next = 0, co = 0;
    std::cout << "Input number for add number to base.\nUse -1 for check list.\nUse -2 for exit app." << std::endl;
    while (buf != -2) {
        std::cin >> buf;
        if (buf == -1) {
            if (co == 0) {
                std::cout << "Base empty" << std::endl;
                continue;
            }
            for (int i = 0; i < 20; ++i) {
                if (i >= co)
                    break;
                std::cout << base[i] << " ";
            }
            std::cout << std::endl;
        }
        else {
            co++;
            base[next] = buf;
            next++;
            if (next >= 20)
                next = 0;
        }
    }
}