#include <iostream>
#include <fstream>

int main()
{
    std::string path;
    std::ifstream file;

    while (path != "/q") {

        std::cout << "Input file path: ";
        std::cin >> path;

        std::string ex = path.substr(path.length() - 3, path.length());

        if (ex != "png" && ex != "PNG")
        {
            std::cout << "File is not PNG." << std::endl;
            continue;
        }

        file.open(path, std::ios::binary);

        if (!file.is_open()) {
            std::cout << "Failed open file of path. Please try again..." << std::endl;
            continue;
        }
        
        char signature[4] = { -119, 'P', 'N', 'G' };
        char byte[4];
        file.read(byte, sizeof(byte));

        bool error = false;
        for (int i = 0; i < 4 && !error; ++i) {
            error = byte[i] != signature[i];
        }

        std::cout << (error ? "File is not PNG." : "File is PNG.") << std::endl;

        file.close();
    }
}