#include <iostream>

bool compare(float val, float ref, float ep) {
    return (val >= ref - ep && val <= ref + ep);
}

int main()
{
    float speed = 0;
    float delta;
    std::cout << "Hi, input delta-speed: ";
    std::cin >> delta;

    speed += delta;

    while (!compare(speed, 0.0, 0.01)) {
        std::cout << "Current speed: " << speed << " km/h, input next delta-speed: ";
        std::cin >> delta;

        speed += delta;

        if (speed > 150.f)
            speed = 150.f;
        else if (speed < 0.f)
            speed = 0.f;
    }

    std::cout << "Car stoped!" << std::endl;
}