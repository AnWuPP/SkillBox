#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

enum class PlayerState {
    PLAY,
    PAUSE,
    STOP
};

struct Track {
    std::string name = "Unknown";
    std::tm createdAt{ 0 };
    int duration = 0;
};

class Player {
    PlayerState state = PlayerState::STOP;
    Track* track;
    std::vector<Track> list;

public:
    void play(std::string trackname) {
        if (state != PlayerState::STOP) {
            std::cout << "Please pause or stop current track" << std::endl;
            return;
        }
        bool found = false;
        for (auto& tr : list) {
            if (trackname == tr.name) {
                track = &tr;
                found = true;
            }
        }
        if (found) {
            state = PlayerState::PLAY;
            std::cout << "Now play " << track->name << "!" << std::endl;
        }
        else
            std::cout << "Track not found" << std::endl;
    }

    void stop() {
        if (state == PlayerState::STOP) {
            std::cout << "No one track now play" << std::endl;
            return;
        }
        std::cout << track->name << " stoped" << std::endl;
        state = PlayerState::STOP;
    }

    void pause() {
        if (state == PlayerState::STOP) {
            std::cout << "No one track now play" << std::endl;
            return;
        }
        if (state == PlayerState::PAUSE) {
            std::cout << "Resume track " << track->name << "!" << std::endl;
            state = PlayerState::PLAY;
        }
        else {
            std::cout << "Pause track " << track->name << "!" << std::endl;
            state = PlayerState::PAUSE;
        }
    }

    void next() {
        if (list.empty()) {
            std::cout << "Track list empty :/" << std::endl;
            return;
        }
        track = &list[(std::rand() % list.size())];
        state = PlayerState::PLAY;
        std::cout << "Play " << track->name << std::endl;
    }

    void addTrack(std::string name, int duration) {
        std::time_t t = std::time(nullptr);
        std::tm created = *std::localtime(&t);
        list.push_back({ name, created, duration });
    }
};

int main()
{
    std::string cmd;
    Player player;
    player.addTrack("test.mp3", 280);
    player.addTrack("test2.mp3", 80);
    player.addTrack("test55.mp3", 180);
    player.addTrack("test444.mp3", 120);

    std::cout << "Welcome to relax, enter command: play, stop, pause, next, exit: ";
    while (cmd != "exit") {
        std::cin >> cmd;
        if (cmd == "play") {
            std::string trname;
            std::cout << "Enter track name: ";
            std::cin >> trname;

            player.play(trname);
        }
        else if (cmd == "stop")
            player.stop();
        else if (cmd == "pause")
            player.pause();
        else if (cmd == "next")
            player.next();
    }
}