#include <iostream>

void initBoard(char board[][10][10])
{
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                board[i][j][k] = ' ';
            }
        }
    }
}

void showBoards(char board[][10][10])
{
    std::cout << "- - - - - - - - - -" << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << "Player #" << i + 1 << std::endl;
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                std::cout << board[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "- - - - - - - - - -" << std::endl;
    }
}

void showOneBoard(char board[][10][10], int player)
{
    for (int j = 0; j < 10; ++j) {
        for (int k = 0; k < 10; ++k) {
            std::cout << board[player][j][k] << " ";
        }
        std::cout << std::endl;
    }
}

bool validInput(int buf[]) {
    bool valid = true;
    for (int i = 0; i < 4; ++i) {
        int d = buf[i];
        if (d < 0 || d > 9) {
            valid = false;
            break;
        }
    }
    return valid;
}

void getInput(int buf[], int d) {
    for (int i = 0; i < d; ++i) {
        std::cin >> buf[i];
    }
}

void setShipsOnBoard(char board[][10][10], int player) {
    int buf[4] = { 0 };

    for (int i = 4; i > 0; --i) {
        int maxBuf = i == 4 ? 2 : 4;
        int ship = 5 - i;
        for (int j = 0; j < i; ++j) {
            std::cout << "Input for " << ship << " ship: ";
            getInput(buf, maxBuf);

            if (!validInput(buf)) {
                --j;
                std::cout << "Bad position, use range 0-9! Please try again..." << std::endl;
                continue;
            }

            if (maxBuf == 2) {
                if (board[player][buf[0]][buf[1]] != ' ') {
                    --j;
                    std::cout << "This position is not empty! Please try again..." << std::endl;
                    continue;
                }
                board[player][buf[0]][buf[1]] = '1';
            }
            else {
                if (buf[0] == buf[2] && buf[1] == buf[3]) {
                    --j;
                    std::cout << "Bad position! Please try again..." << std::endl;
                    continue;
                }
                bool vertical = buf[1] == buf[3];
                int start = vertical ? buf[0] : buf[1];
                int finish = vertical ? buf[2] : buf[3];
                if (finish - start != ship - 1) {
                    --j;
                    std::cout << "Bad size ship! Please try again..." << std::endl;
                    continue;
                }
                bool error = false;
                for (int k = start; k <= finish; ++k) {
                    int x = (vertical ? k : buf[0]);
                    int y = (vertical ? buf[1] : k);
                    if (board[player][x][y] != ' ') {
                        error = true;
                        break;
                    }
                    board[player][x][y] = '0' + ship;
                }
                if (error) {
                    --j;
                    std::cout << "This position is not empty! Please try again..." << std::endl;
                }
            }
        }
    }

}

int main()
{
    int p = 0; // Player
    int score[2] = { 0 }; // Max score 20

    char board[2][10][10];
    initBoard(board);
    std::cout << !0 << " " << !1 << std::endl;
    std::cout << "Player 1, set you ships to board:" << std::endl;
    setShipsOnBoard(board, 0);
    std::cout << "Player 1, you board:" << std::endl;
    showOneBoard(board, 0);
    std::cout << "Player 2, set you ships to board:" << std::endl;
    setShipsOnBoard(board, 1);
    std::cout << "Dear players, full board:" << std::endl;
    showBoards(board);

    std::cout << "Game started, first go player 1!" << std::endl;
    
    int buf[2];
    while (true) {
        std::cout << "Player " << p + 1 << " you turn: ";
        bool fail = false;
        for (int i = 0; i < 2; ++i) {
            std::cin >> buf[i];
            if (buf[i] < 0 || buf[i] > 9) {
                fail = true;
                std::cout << "Bad position! Please try again..." << std::endl;
                continue;
            }
        }
        if (fail)
            continue;
        if (board[!p][buf[0]][buf[1]] != ' ') {
            score[p]++;
            board[!p][buf[0]][buf[1]] = ' ';
            std::cout << "Hit!" << std::endl;
        }
        else {
            std::cout << "Miss!" << std::endl;
        }

        if (score[p] == 20) {
            std::cout << "Player" << p + 1 << " won the game!" << std::endl;
            showBoards(board);
            break;
        }
        p = !p;
    }
}
/*
* example:
0 0
1 0
2 0
3 0
4 0 5 0
7 0 8 0
9 1 9 2
9 3 9 5
9 7 9 9
5 9 8 9
*/