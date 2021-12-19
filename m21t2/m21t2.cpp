#include <iostream>
#include <vector>

struct stRoom {
    int sqr = 0;
    int type = 0;
};

struct stPlot {
    int sqr = 0;

    struct {
        int floors = 1;
        std::vector<int> heightFloors;
        std::vector<stRoom> rooms;
        bool bake = false;
    } home;

    struct {
        bool inc = false;
        int sqr = 0;
    } garage;

    struct {
        bool inc = false;
        int sqr = 0;
    } barn;

    struct {
        bool inc = false;
        int sqr = 0;
        bool bake = false;
    } bath;
};

void getAns(bool& val) {
    std::string ans;
    std::cout << "Enter answer [Yes/No]: ";
    std::cin >> ans;
    if (ans == "Yes" || ans == "Y" || ans == "y") {
        val = true;
        return;
    }
    else if (ans == "No" || ans == "N" || ans == "n") {
        val = false;
        return;
    }
    getAns(val);
}

void cleanCin() {
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main()
{
    int dBuf;
    std::vector<stPlot> plots;

    std::cout << "Input the number of parcels: ";
    std::cin >> dBuf;

    int coPlots = dBuf;

    for (int i = 0; i < coPlots; ++i) {
        stPlot temp;
        do {
            cleanCin();
            std::cout << "Enter square plot: ";
            std::cin >> dBuf;
        } while (dBuf < 1);
        temp.sqr = dBuf;

        do {
            cleanCin();
            std::cout << "Enter floor count in home (1-3): ";
            std::cin >> dBuf;
        } while (dBuf < 1 || dBuf > 3);

        int floor = dBuf;
        for (int j = 0; j < floor; ++j) {
            do {
                cleanCin();
                std::cout << "Enter room count on " << j + 1 << " floor (2 - 4): ";
                std::cin >> dBuf;
            } while (dBuf < 2 || dBuf > 4);

            int room = dBuf;
            for (int k = 0; k < room; ++k) {
                stRoom tempRoom;
                std::cout << "Types: 1. bedroom, 2. kitchen, 3. bathroom, 4. nursery, 5. living room." << std::endl;
                do {
                    cleanCin();
                    std::cout << "Enter type room " << k + 1 << " (1-5): ";
                    std::cin >> dBuf;
                } while (dBuf < 1 || dBuf > 5);
                tempRoom.type = dBuf;
                do {
                    cleanCin();
                    std::cout << "Enter square room " << k + 1 << " (1-5): ";
                    std::cin >> dBuf;
                } while (dBuf < 1);
                tempRoom.sqr = dBuf;

                temp.home.rooms.push_back(tempRoom);
            }
        }

        std::cout << "Add bake to house? ";
        getAns(temp.home.bake);

        std::cout << "Build garage? ";
        getAns(temp.garage.inc);

        if (temp.garage.inc) {
            do {
                cleanCin();
                std::cout << "Enter square garage: ";
                std::cin >> dBuf;
            } while (dBuf < 1);
            temp.garage.sqr = dBuf;
        }

        std::cout << "Build barn? ";
        getAns(temp.barn.inc);

        if (temp.barn.inc) {
            do {
                cleanCin();
                std::cout << "Enter square barn: ";
                std::cin >> dBuf;
            } while (dBuf < 1);
            temp.barn.sqr = dBuf;
        }

        std::cout << "Build bath? ";
        getAns(temp.bath.inc);

        if (temp.bath.inc) {
            do {
                cleanCin();
                std::cout << "Enter square bath: ";
                std::cin >> dBuf;
            } while (dBuf < 1);
            temp.bath.sqr = dBuf;

            std::cout << "Add bake to bath? ";
            getAns(temp.bath.bake);
        }

        plots.push_back(temp);
    }
    
    std::cout << "Plots: " << plots.size() << std::endl;
}