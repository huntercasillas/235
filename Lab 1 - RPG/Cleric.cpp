#include "Cleric.h"

int Cleric::getDamage() {
    damage = magic;
    return damage;
}

void Cleric::reset() {
    Fighter::reset();
    currentMana = maxMana;
}

void Cleric::regenerate() {
    Fighter::regenerate();
    if ((magic / 5.0) < 1) {
        currentMana += 1;
    }
    else {
        currentMana += (magic / 5.0);
    }
    if (currentMana > maxMana) {
        currentMana = maxMana;
    }
}
	
bool Cleric::useAbility() {
    if (currentMana < CLERIC_ABILITY_COST) {
        return false;
    }
    else {
        if ((magic / 3.0) < 1) {
            currentHP += 1;
        }
        else {
            currentHP += (magic / 3.0);
        }
        if (currentHP > maxHP) {
            currentHP = maxHP;
        }
        currentMana -= CLERIC_ABILITY_COST;
        return true;
    }
}