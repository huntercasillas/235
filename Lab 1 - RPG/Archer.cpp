#include "Archer.h"

using namespace std;

int Archer::getDamage() {
    damage = currentSpeed;
    return damage;
}

void Archer::reset() {
    Fighter::reset();
    currentSpeed = originalSpeed;
}

bool Archer::useAbility() {
    currentSpeed += 1;
    return true;
}