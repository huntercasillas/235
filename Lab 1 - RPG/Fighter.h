#pragma once
#include "FighterInterface.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fighter: public FighterInterface {
    
protected:
	string name;
	int maxHP;
	int strength;
	int originalSpeed;
	int currentSpeed;
	int magic;
	int currentHP;
	int damage;
	
public:
    Fighter(string name, int maxHP, int strength, int originalSpeed, int magic) {
    	this->name = name;
    	this->maxHP = maxHP;
    	this->strength = strength;
    	this->originalSpeed = originalSpeed;
    	this->magic = magic;
    	currentHP = maxHP;
    	currentSpeed = originalSpeed;
    	damage = 0;
    }
	~Fighter() {}

	string getName() const;
	int getMaximumHP() const;
	int getCurrentHP() const;
	int getStrength() const;
	int getSpeed() const;
	int getMagic() const;
	virtual int getDamage() = 0;
	void takeDamage(int damage);
	virtual void reset();
	virtual void regenerate();
	virtual bool useAbility() = 0;
};