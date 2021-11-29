#include <iostream>

int main()
{
    char board[3][3] = {
                         { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' }
                       };
    int co = 0;
    char winner = ' ';
    int x, y;
    std::cout << "Crosses go first:" << std::endl;
    while (co != 9 && winner == ' ') {
        std::cin >> x >> y;
        
        if (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != ' ') {
            std::cout << "Wrong move! Please try again.." << std::endl;
            continue;
        }

        char sym = co % 2 == 0 ? 'X' : 'O';
        std::string wonCombo = co % 2 == 0 ? "XXX" : "OOO";
        board[x][y] = sym;
        co++;

        std::string bufLine = "", bufColumn = "";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j] << " ";
                bufLine += board[i][j];
                bufColumn += board[j][i];
            }
            std::cout << std::endl;
            if ((bufLine == wonCombo || bufColumn == wonCombo) && winner == ' ') {
                winner = sym;
            }
            bufLine = "";
            bufColumn = "";
        }
    }
    if (winner == 'X')
        std::cout << "Crosses won" << std::endl;
    else if (winner == 'O')
        std::cout << "Zeroes won" << std::endl;
    else if (winner == ' ')
        std::cout << "Nobody!" << std::endl;
}