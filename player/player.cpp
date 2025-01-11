#include <iostream>
using namespace std;

class Player {
    private:
        string name;
        float atk, def, hp, range;
        int weapon; // 1 = sword, 2 = bow
    public:
        Player(float eAtk, float eHp, float eDef, int eWeapon, const string &eName) : atk(eAtk), def(eDef), hp(eHp), name(eName), weapon(eWeapon){}
        // getter
        string getName() const { return name; }
        int getWP() const { return weapon; }
        float getHp() const { return hp; }
        float getAtk() const { return atk; }
        float getDef() const { return def; }
        float getRange() const { return range; }
        // setter
        void setName(const string &newName){name = newName;}
        void setWP(int &newWP){weapon = newWP;}
        void setHp(float &newHp){hp = newHp;}
        void setAtk(float &newAtk){atk = newAtk;}
        void setDef(float &newDef){def = newDef;}
        void setRange(float &newRange){range = newRange;}
};