#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <random>

struct OutOfRangeBoardException : std::exception {
    const char* what() const noexcept override {
        return "out of range board";
    }
};
struct NoFishException : std::exception {
    const char* what() const noexcept override {
        return "oh no! its not fish!";
    }
};

class Game {
    std::vector<std::vector<short>> board;
public:
    Game() : board(9, std::vector<short>(9, 0)) {
        std::random_device rd;
        std::uniform_int_distribution<int> uid(0, 8);
        board[uid(rd)][uid(rd)] = 1;
        for (int i = 0; i < 3; ++i) {
            int x = uid(rd), y = uid(rd);
            if (board[y][x] != 0)
            {
                --i;
                continue;
            }
            board[y][x] = 2;
        }
    }

    short move(int x, int y) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board.size())
            throw OutOfRangeBoardException();
        if (board[y][x] == 2)
            throw NoFishException();
        return board[y][x];
    }

    void process() {
        int res = 0;
        int x = -1, y = -1;
        do {
            std::cin >> x >> y;
            try {
               res = move(x, y);
            }
            catch (OutOfRangeBoardException& e) {
                std::cerr << e.what() << std::endl;
            }
            catch (NoFishException& e) {
                std::cerr << e.what() << std::endl;
            }
        } while (res != 1);
        std::cout << "You won game!" << std::endl;
    }

    void print() {
        for (auto& i : board) {
            for (auto& j : i) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    Game game;
    game.process();
    game.print();
}