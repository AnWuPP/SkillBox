#include <iostream>
#include <vector>

enum note {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LYA = 32,
    SI = 64
};

int main()
{
    std::vector<std::string> combo(12);

    std::cout << "Input 12 combo-note:" << std::endl;
    for (int i = 0; i < combo.size(); i++) {
        std::cin >> combo[i];
        bool error = false;
        for (int j = 0; j < combo[i].length() && !error; j++) {
            error = combo[i][j] < '1' || combo[i][j] > '7';
        }
        if (error) {
            std::cout << "Wrong combo! Please try again and use note 1-7" << std::endl;
            --i;
            continue;
        }
    }

    std::cout << "Song:" << std::endl;
    for (int i = 0; i < combo.size(); i++) {
        for (int j = 0; j < combo[i].length(); j++) {
            int nt = (1 << (combo[i][j] - '1'));
            if (nt == DO) {
                std::cout << "do ";
            }
            else if (nt == RE) {
                std::cout << "re ";
            }
            else if (nt == MI) {
                std::cout << "mi ";
            }
            else if (nt == FA) {
                std::cout << "fa ";
            }
            else if (nt == SOL) {
                std::cout << "sol ";
            }
            else if (nt == LYA) {
                std::cout << "lya ";
            }
            else if (nt == SI) {
                std::cout << "si ";
            }
        }
        std::cout << std::endl;
    }
}