#include "Fighter.h"

using namespace std;

string Fighter::getName() const {
    return name;
}

int Fighter::getMaximumHP() const {
    return maxHP;
}

int Fighter::getCurrentHP() const {
    return currentHP;
}

int Fighter::getStrength() const {
    return strength;
}

int Fighter::getSpeed() const {
    return currentSpeed;
}

int Fighter::getMagic() const {
    return magic;
}

void Fighter::takeDamage(int damage) {
    if ((damage - (currentSpeed / 4)) < 1) {
        currentHP -= 1;
    }
    else {
        currentHP = currentHP - (damage - (currentSpeed / 4));
    }
}

void Fighter::reset() {
    currentHP = maxHP;
}

void Fighter::regenerate() {
    if ((strength / 6) < 1) {
        currentHP += 1;
    }
    else {
        currentHP += (strength / 6);
    }
    if (currentHP > maxHP) {
        currentHP = maxHP;
    }
}