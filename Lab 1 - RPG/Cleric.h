#pragma once
#include "Fighter.h"

using namespace std;

class Cleric:public Fighter {

public:
    Cleric(string name, int maxHP, int strength, int originalSpeed, int magic):Fighter(name, maxHP, strength, originalSpeed, magic){
        maxMana = (5 * magic);
        currentMana = maxMana;
    };
    ~Cleric(){};
    
    int getDamage();
    void reset();
    void regenerate();
    bool useAbility();

private:
    int maxMana;
    int currentMana;
};