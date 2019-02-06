#include "Robot.h"

int Robot::getDamage() {
    damage = strength + addedDamage;
    addedDamage = 0;
    return damage;
}

void Robot::reset() {
    Fighter::reset();
    currentEnergy = maxEnergy;
    addedDamage = 0;
}

bool Robot::useAbility() {
    if (currentEnergy < ROBOT_ABILITY_COST) {
        addedDamage = 0;
        return false;
    }
    else {
        addedDamage = (strength * pow((double)currentEnergy/(double)maxEnergy, 4));
        currentEnergy = currentEnergy - ROBOT_ABILITY_COST;
        return true;
    }
}