#include <iostream>
#include <vector>

enum class RoomType {
    BEDROOM,
    KITCHEN,
    BATHROOM,
    NURSERY,
    LIVING_ROOM
};

enum class BuildType {
    HOUSE,
    GARAGE,
    BARN,
    BATH
};

struct Room {
    int square = 0;
    RoomType type = RoomType::BEDROOM;
};
struct Floor {
    int height = 0;
    std::vector<Room> rooms;
};
struct Build {
    BuildType type = BuildType::HOUSE;
    int square = 0;
    std::vector<Floor> floors;
    bool bake = false;
};
struct Plot {
    int square = 0;
    std::vector<Build> build;
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

Build buildHouse() {
    int coFloor = 0;
    Build build;
    
    std::cout << "Add bake to house? ";
    getAns(build.bake);

    do {
        std::cout << "Enter floor count (1-3): ";
        std::cin >> coFloor;
    } while (coFloor < 1 || coFloor > 3);

    for (int i = 0; i < coFloor; ++i) {
        Floor floor;
        int coRoom = 0;
        
        do {
            std::cout << "Enter height floor: ";
            std::cin >> floor.height;
        } while (floor.height < 1);
        
        do {
            std::cout << "Enter room count (2-4) for " << i + 1 << " floor: ";
            std::cin >> coRoom;
        } while (coRoom < 2 || coRoom > 4);

        for (int j = 0; j < coRoom; ++j) {
            Room room;
            int type = 0;
            
            do {
                std::cout << "Enter room square: ";
                std::cin >> room.square;
            } while (room.square < 1);

            do {
                std::cout << "Enter room type: ";
                std::cin >> type;
            } while (type < 0 || type > 4);

            room.type = static_cast<RoomType>(type);

            floor.rooms.push_back(room);
        }

        build.floors.push_back(floor);
    }

    return build;
}

Build buildGarage() {
    Build build;
    build.type = BuildType::GARAGE;

    do {
        std::cout << "Enter square garage: ";
        std::cin >> build.square;
    } while (build.square < 1);

    return build;
}

Build buildBarn() {
    Build build;
    build.type = BuildType::BARN;

    do {
        std::cout << "Enter square barn: ";
        std::cin >> build.square;
    } while (build.square < 1);

    return build;
}

Build buildBath() {
    Build build;
    build.type = BuildType::BATH;

    do {
        std::cout << "Enter square bath: ";
        std::cin >> build.square;
    } while (build.square < 1);

    std::cout << "Add bake to bath? ";
    getAns(build.bake);

    return build;
}

Plot fillPlot() {
    Plot plot;
    int co = 0;

    // Houses
    do {
        std::cout << "How many build house? ";
        std::cin >> co;
    } while (co < 1);

    for (int i = 0; i < co; ++i) {
        plot.build.push_back(buildHouse());
    }

    // Garages
    do {
        std::cout << "How many build garage? ";
        std::cin >> co;
    } while (co < 0);

    for (int i = 0; i < co; ++i) {
        plot.build.push_back(buildGarage());
    }

    // Barns
    do {
        std::cout << "How many build barn? ";
        std::cin >> co;
    } while (co < 0);

    for (int i = 0; i < co; ++i) {
        plot.build.push_back(buildBarn());
    }

    // Bath
    do {
        std::cout << "How many build bath? ";
        std::cin >> co;
    } while (co < 0);

    for (int i = 0; i < co; ++i) {
        plot.build.push_back(buildBath());
    }
    
    return plot;
}

int main()
{
    int coPlots = 0;
    std::vector<Plot> plots;

    do {
        std::cout << "Enter count of plots: ";
        std::cin >> coPlots;
    } while (coPlots < 1);

    for (int i = 0; i < coPlots; ++i) {
        plots.push_back(fillPlot());
    }
    
    std::cout << "Plots: " << plots.size() << std::endl;
}