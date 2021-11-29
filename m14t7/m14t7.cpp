#include <iostream>


bool updatePopit(bool popit[][12], int pop[]) {
    int die = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (i >= pop[0] && j >= pop[1] && i <= pop[2] && j <= pop[3])
                popit[i][j] = false;
            if (!popit[i][j])
                die++;
            std::cout << (popit[i][j] ? 'o' : 'x') << " ";
        }
        std::cout << std::endl;
    }
    return die != 144;
}

int main()
{
    int pop[4] = { -1, -1, -1, -1 }; // Массив для вводимых данных зоны
    bool popit[12][12];
    
    // Инициализируем массив
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            popit[i][j] = true;
        }
    }

    updatePopit(popit, pop);

    bool alive = true; // Состояние упаковки
    bool skip = false; // Пропуск внешнего цикла
    while (alive) {
        // Ввод данных от пользователя в массив pop[4]
        std::cout << "Input pop-zone [x y z d]: ";
        for (int i = 0; i < 4; ++i) {
            std::cin >> pop[i];
            if (pop[i] < 0 || pop[i] > 11) {
                skip = true;
            }
        }
        if (skip) {
            skip = false;
            std::cout << "Error! Please try again.." << std::endl;
            continue;
        }
        
        alive = updatePopit(popit, pop);
    }
    std::cout << "Popit burst :(\nYou can start again.." << std::endl;
}