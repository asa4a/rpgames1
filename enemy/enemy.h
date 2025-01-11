#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

class Enemy{
    private:
        string name;
        float hp, atk;
    public:
        Enemy(float eHp, float eAtk, const string &eName) : hp(eHp), atk(eAtk), name(eName){}
        // getter
        string getName() const { return name; }
        float getHp() const { return hp; }
        float getAtk() const { return atk; }
        // setter
        void setName(const string &newName){name = newName;}
        void setHp(float &newHp){hp = newHp;}
        void setAtk(float &newAtk){atk = newAtk;}
};

class parentEnemy : public Enemy {
    private:
        float def;
    public:
        parentEnemy(float eHp, float eAtk, const string &eName, float eDef) : Enemy(eHp, eAtk, eName), def(eDef){}
        // getter
        float getDef() const { return def; }
        // setter
        void setDef(float newDef) { def = newDef; }
};

Enemy* enemyLevel(bool isParent){
    // akses file level
    ifstream fileLevel("enemyLevel.txt");
    string name;

    if (fileLevel.is_open()){
        string line;
        while (getline(fileLevel, line)){
            cout << line;
        }
        fileLevel.close();
    } else {
        name = "lalala";
    }

    if (!isParent){
        // generate random
        // float hp = random
        float hp = rand() % 51 + 50;
        float atk = 0.25 * hp;
        return new Enemy(hp,atk,name);
    } else {
        float hp = 200;
        float def = rand() % 26 + 25;
        float atk = 0.25 * hp;
        string name = "boss";
        return new parentEnemy(hp,atk,name,def);
    }
}