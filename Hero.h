#ifndef HERO_H
#define HERO_H

#include <string>

class Hero {
private:
    std::string name;
    int hp;
    int maxHP;
    int xp;
    int level;

public:
    Hero(const std::string& heroName);

    std::string getName() const;
    int getHP() const;
    int getMaxHP() const;
    int getXP() const;
    int getLevel() const;

    void setHP(int newHP);
    void setMaxHP(int newMax);
    void setXP(int newXP);
    void setLevel(int newLevel);
    
    void addXP(int amount);
};

#endif