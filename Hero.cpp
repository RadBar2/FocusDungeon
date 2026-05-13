#include "Hero.h"

// Constructor implementation
Hero::Hero(const std::string& heroName) 
    : name(heroName), hp(100), maxHP(100), xp(0), level(1) {}

// Getters 
std::string Hero::getName() const  {
     return name; 
}

int Hero::getHP() const {
     return hp; 
}

int Hero::getMaxHP() const {
    return maxHP; 
}

int Hero::getXP() const {
    return xp; 
}

int Hero::getLevel() const {
    return level;
}

// Setters
void Hero::setHP(int newHP) {
    hp = newHP;
}

void Hero::setMaxHP(int newMax)   {
    maxHP = newMax;
}
void Hero::setXP(int newXP) {
    xp = newXP; 
}

void Hero::setLevel(int newLevel) {
    level = newLevel;
}

void Hero::addXP(int amount) {
    xp += amount;
}