#include <string>

class Hero {
private:
    std::string name;
    int hp;
    int xp;
    int level;

public:
    // Constructor to initialize a new hero
    Hero(std::string heroName) 
        : name(heroName), hp(100), xp(0), level(1) {}

    // Getters
    std::string getName() const { return name; }
    int getHP() const { return hp; }
    int getXP() const { return xp; }
    int getLevel() const { return level; }

    // Setters
    void setHP(int newHP) { hp = newHP; }
    
    void addXP(int amount) { 
        xp += amount; 
    }

    void setLevel(int newLevel) { 
        level = newLevel; 
    }
};