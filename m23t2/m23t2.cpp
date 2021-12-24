#include <iostream>
#include <map>
#include <vector>

#define RET(fnc) fnc

void fill(std::vector<int>& pass) {
    int buf = 0;
    for (int i = 0; i < pass.size(); ++i) {
        std::cout << "Enter count passager for " << i << ": ";
        std::cin >> buf;
        if (buf < 1) {
            std::cout << "Wrong number" << std::endl;
            --i;
            continue;
        }
        pass[i] = buf;
    }
}

void analize(std::vector<int>& pass) {
    std::map<int, int> more;
    std::map<int, int> less;
    for (int i = 0; i < pass.size(); ++i) {
        if (pass[i] > 20)
            more.insert(std::pair<int, int>(i, pass[i] - 20));
        else if (pass[i] < 20)
            less.insert(std::pair<int, int>(i, 20 - pass[i]));
    }

    if (!more.empty()) {
        std::cout << "More passager:" << std::endl;
        for (auto& v : more)
            std::cout << "Coach #" << v.first << ". Passager: " << v.second << std::endl;
    }

    if (!less.empty()) {
        std::cout << "Less passager:" << std::endl;
        for (auto& v : less)
            std::cout << "Coach #" << v.first << ". Passager: " << v.second << std::endl;
    }
}

int main()
{
    std::vector<int> pass(10, 0);
    RET(fill)(pass);
    RET(analize)(pass);
}