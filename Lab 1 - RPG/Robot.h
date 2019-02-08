#pragma once
#include "Fighter.h"
#include <cmath>

using namespace std;

class Robot:public Fighter {
    
public:
    Robot(string name, int maxHP, int strength, int originalSpeed, int magic):Fighter(name, maxHP, strength, originalSpeed, magic){
        maxEnergy = magic * 2;
        currentEnergy = maxEnergy;
        addedDamage = 0;
    };
    ~Robot(){}
    
    int getDamage();
    void reset();
    bool useAbility();
    
private:
    int maxEnergy;
    int currentEnergy;
    int addedDamage;
};