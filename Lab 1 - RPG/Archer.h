#pragma once
#include "Fighter.h"

using namespace std;

class Archer:public Fighter {

public:
    Archer(string name, int maxHP, int strength, int originalSpeed, int magic):Fighter(name, maxHP, strength, originalSpeed, magic){};
    ~Archer(){};
    
    int getDamage();
        
    void reset();
    
    bool useAbility();
    
};