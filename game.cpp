#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

void newGame(){
    Player player;
    cout  << "Enter your name: ";
    cin >> player.name();
    cout << "Choose your weapon:\n(1) Sword\n(2) Weapon";
    cin >> player.weapon();
}

bool hit(float distBetween, int range){
    if (distBetween <= range){
        return true;
    } else {
        return false;
    }
}

void playerAttack(){

}

void enemyAttack(){
    
}

bool battle(Player *player, float weaponAtk, float enemyDist, Enemy *enemy){
    float dmg = enemy.atk;
    player.def = player.def - dmg;
    dmg = dmg - player.def;
    if (player.def < 0 && dmg > 0){
        player.hp = player.hp + player.def;
        player.hp = player.hp - dmg;
    }
    bool inBattle = true;
    while (inBattle){
        player.atk = player.atk + weaponAtk;
        bool hit_true = hit(enemyDist, player.range);
        if (hit_true){
            enemy.hp = enemy.hp - player.atk;
        }
        if (enemy.hp == 0){
            inBattle = false;
        }
    }
    return inBattle;
}

void generateScene(){
    
}

void loadGame(Player *player){
    ifstream inFile("savegame.txt");
    if (inFile.is_open()){
        string line;
        while(getline(inFile, line)){
            cout << line;
        }
        inFile.close();
    } else {
        cout << "error";
    }
}

void saveGame(Player *player){
    string fileName = "savegame.txt";
    ofstream outFile(fileName);
    // string name;
    // float atk, def, hp, range;
    // int weapon; // 1 = sword, 2 = bow
    if (outFile.is_open()){
        outFile << player.name << "\n" << player.atk << "\n" << player.def << "\n" << player.hp << "\n" << player.range << "\n" << player.weapon;
        cout << "succesful\n";
    } else {
        cout << "failed\n";
    }
}

void startMenu(){
    int userInput;
    cout << " _ _ _ _ _ _ __\n| MAIN MENU    |\n| 1: New Game  |\n| 2: Load Game |\n| 0: Exit      |\n|_ _ _ _ _ _ _ |\n";
    cin >> userInput;

    if (userInput == 1){
        newGame();
    } else if (userInput == 2){
        loadGame();
    } else{
        abort();
    }
}