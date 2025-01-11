#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

struct Scene{
    string description;
    vector<string> possibleEnemy;
};

class Chapter {
private:
    vector<Scene> scene;
    int currentScene;
    string chapterBoss = "Demon Lord";
    string bossDesc = "The source of all evil, a powerful demon lord wielding dark magic and a cursed blade.";

public:
    Chapter() : currentScene(0) {
        scene = {
            {
                "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
                {"Slime", "Wild Dog", "Goblin"},
            },
            {
                "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
                {"Wolf", "Dark Elf", "Forest Troll"},
            },
            {
                "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
                {"Rock Golem", "Harpy", "Mountain Orc"},
            },
            {
                "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
                {"Skeleton Warrior", "Ghost", "Cursed Knight"},
            }
        };
    }

    const Scene& getCurrentScene() const {
        return scene[currentScene];
    }

    bool nextScene() {
        currentScene++;
        return currentScene < scene.size();
    }

    bool isLastChapter() const {
        return currentScene == scene.size() - 1;
    }
};