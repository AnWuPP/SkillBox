#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

std::mutex state;

class Train {
    char id = 'N';
    int roadTime = 0;
public:
    Train(char id_) : id(id_) {}
    char getId() {
        return id;
    }
    int getTime() {
        return roadTime;
    }
    void setTime(int time) {
        if (time < 0)
            return;
        roadTime = time;
    }

    static void move(Train*);
};

void Train::move(Train* t) {
    std::this_thread::sleep_for(std::chrono::seconds(t->roadTime));
    std::cout << t->getId() << " arrived" << std::endl;
    std::lock_guard<std::mutex> m{ state };
    std::string cmd = "";
    std::cout << "Wait for you command for deport train " << t->getId() << std::endl;
    while (cmd != "deport") {
        std::cin >> cmd;
    }
}

int main()
{
    std::vector<Train> trains;
    trains.push_back(Train('A'));
    trains.push_back(Train('B'));
    trains.push_back(Train('C'));

    int buf;

    for (auto& t : trains) {
        std::cout << "Enter road time for " << t.getId() << " train: ";
        std::cin >> buf;
        t.setTime(buf);
    }

    std::vector<std::thread> road(trains.size());

    for (int i = 0, ie = road.size(); i != ie; ++i) {
        road[i] = std::thread(Train::move, &trains[i]);
    }

    for (auto& t : road) {
        t.join();
    }
}