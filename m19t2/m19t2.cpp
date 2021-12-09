#include <iostream>
#include <fstream>

int main()
{
    std::string path;
    std::ifstream file;

    while (path != "/q") {
        std::string content = "";
        char buffer[512];
        
        std::cout << "Input file path: ";
        std::cin >> path;

        file.open(path, std::ios::binary);

        if (!file.is_open()) {
            std::cout << "Failed open file of path. Please try again..." << std::endl;
            continue;
        }

        while (!file.eof()) {
            file.read(buffer, sizeof(buffer) - 1);
            buffer[file.gcount()] = 0;
            content += buffer;
        }

        std::cout << "Content in file:" << std::endl;
        std::cout << content << std::endl;

        file.close();
    }
}