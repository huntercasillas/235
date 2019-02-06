#include "Arena.h"

using namespace std;

bool Arena::addFighter(string info) {
    string name;
    string type;
    int maxHP;
    int strength;
    int originalSpeed;
    int magic;

    stringstream ss(info);
    
    ss >> name >> type >> maxHP >> strength >> originalSpeed >> magic;

    if (maxHP <= 0 || strength <= 0 || originalSpeed <= 0 || magic <= 0) {
        return false;
    }
    
    if (ss.fail() || !ss.eof()) {
        return false;
    }

    for (int i = 0; i < fighterVec.size(); i++) {
        if (fighterVec.at(i)->getName() == name) {
            return false;
        }
    }

    
    if (type == "A") {
        fighterVec.push_back(new Archer(name, maxHP, strength, originalSpeed, magic));
        return true;
    }
    else if (type == "R") {
        fighterVec.push_back(new Robot(name, maxHP, strength, originalSpeed, magic));
        return true;
    }
    else if (type == "C") {
        fighterVec.push_back(new Cleric(name, maxHP, strength, originalSpeed, magic));
        return true;
    }
    
    return false;
}

bool Arena::removeFighter(string name) {
    for (int i = 0; i < fighterVec.size(); i++) {
        if (fighterVec.at(i)->getName() == name) {
            delete fighterVec.at(i);
            fighterVec.erase(fighterVec.begin() + i);
            return true;
        }
    }
    return false;
}

FighterInterface* Arena::getFighter(string name) {
    for (int i = 0; i < fighterVec.size(); i++) {
        if (fighterVec.at(i)->getName() == name) {
            return fighterVec.at(i);
        }
    }
    return NULL;
}

int Arena::getSize() const {
    return fighterVec.size();
}
