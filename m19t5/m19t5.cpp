#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// rading file on path
std::string readFile(std::string path) {
    std::ifstream file;
    std::string content = "";
    char buffer[512];

    file.open(path, std::ios::binary);

    if (!file.is_open()) {
        return "";
    }

    while (!file.eof()) {
        file.read(buffer, sizeof(buffer) - 1);
        buffer[file.gcount()] = 0;
        content += buffer;
    }

    file.close();

    return content;
}

int getWinner(int score[], int& maxScore, int& winner) {
    for (int i = 0; i < 3 && winner == -1; ++i) {
        if (score[i] == maxScore)
            winner = i;
    }

    return winner;
}

void nextStroke(int& stroke, int& teams) {
    stroke = stroke + 1 > teams ? 1 : stroke + 1;
}

int calcNextSector(int& sector, int& msector, std::vector<bool>& closeSector, int sectorOffset) {
    sectorOffset -= (sectorOffset / msector) * msector;
    int diff = msector - sector;
    int newSector = (sector + sectorOffset > msector ? sectorOffset - diff : sector + sectorOffset);
    return closeSector[newSector] ? calcNextSector(sector, msector, closeSector, 1) : newSector;
}

int main()
{
    int sector = 1; // current sector
    int msector = 13; // max sector in game
    int stroke = 0; // Current team for questions, Team 1 default
    std::vector<bool> closeSector(msector, false);

    int teamSpec = 0; // Team spectators
    int teamOne = 1; // Team 1
    int teamTwo = 2; // Team 2
    int teams = 2; // +1 = Teams in game
    std::string teamName[3] = {
                                "Spectators",
                                "Russian",
                                "USA"
                              };
    int score[3] = { 0 }; // Team score
    int maxScore = 6; // Score for win
    int winner = -1; // id winner

    int sectorOffset = 0; // Input offset sector
    std::string ians = ""; // Input ask

    std::string pathToQuestion = "questions\\";
    std::string pathToAns = "ans\\";

    while (getWinner(score, maxScore, winner) == -1) {
        std::cout << teamName[stroke] << ", input offset for sector: ";
        std::cin >> sectorOffset;

        int nextSector = calcNextSector(sector, msector, closeSector, sectorOffset);

        std::string question = readFile(pathToQuestion + std::to_string(nextSector) + ".txt");
        std::string ans = readFile(pathToAns + std::to_string(nextSector) + ".txt");

        if (question.empty() || ans.empty()) {
            std::cout << "Error load file pair. Please try again.." << std::endl;
            continue;
        }

        std::cout << "Question:" << std::endl;
        std::cout << question << std::endl;
        std::cout << "Input ask for question (one word):" << std::endl;
        std::cin >> ians;

        if (ians == ans) {
            std::cout << "Yes! All right! Next stroke..." << std::endl;
            score[stroke]++;
        }
        else {
            std::cout << "Not! Not true! The point goes to the audience.." << std::endl;
            score[0]++;
        }
        std::cout << "- - - - - - - - - - - - - -" << std::endl;
        closeSector[nextSector] = true;
        sector = nextSector;
        nextStroke(stroke, teams);
    }

    std::cout << teamName[winner] << " won the game!" << std::endl;

}