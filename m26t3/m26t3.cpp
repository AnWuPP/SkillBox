#include <iostream>
#include <string>

struct Vec {
    int x = 0, y = 0;
};

class Window {
    const Vec maxSize{ 50, 80 };
    Vec pos;
    Vec size;

public:
    void move(Vec v) {
        if (v.x < 0 || v.y < 0 || v.x + size.x >= maxSize.x || v.y + size.y >= maxSize.y) {
            std::cout << "Resize window or enter other position" << std::endl;
            return;
        }
        pos = v;
        std::cout << "Window move to " << pos.x << " " << pos.y << std::endl;
    }
    void resize(Vec v) {
        if (v.x < 0 || v.y < 0 || pos.x + v.x >= maxSize.x || pos.y + v.y >= maxSize.y) {
            std::cout << "Move window or enter other size" << std::endl;
            return;
        }
        size = v;
        std::cout << "Window resize to " << size.x << " " << size.y << std::endl;
    }
    void display() {
        for (int i = 0, ie = maxSize.x; i != ie; ++i) {
            for (int j = 0, je = maxSize.y; j != je; ++j) {
                std::cout << (i >= pos.x && i < pos.x + size.x && j >= pos.y && j < pos.y + size.y ? '1' : '0');
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    Window window;
    std::string cmd;
    std::cout << "Enter command: move, resize, display, exit" << std::endl;
    while (cmd != "exit") {
        std::cin >> cmd;
        if (cmd == "move") {
            Vec v;
            std::cin >> v.x >> v.y;
            window.move(v);
        }
        else if (cmd == "resize") {
            Vec v;
            std::cin >> v.x >> v.y;
            window.resize(v);
        }
        else if (cmd == "display")
            window.display();
    }
}