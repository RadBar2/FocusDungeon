#include "RPGEngine.h"

#include <iostream>

void RPGEngine::checkLevelUp(Hero &hero) {
    if (hero.getXP() >= xpRequired) {
        int newLevel = hero.getLevel() + 1;
        hero.setLevel(newLevel);

        // Restore HP after level up
        hero.setHP(100);

        // Remove used XP
        hero.addXP(-xpRequired);

        // Increase required XP for the next level
        xpRequired += 50;

        std::cout << "[EVENT] Level up! Your level is now " << newLevel << "! Your HP has been fully restored!\n";
        std::cout << "XP required for the next level: " << xpRequired << std::endl;
    }
}

int RPGEngine::getXPRequired() const {
    return xpRequired;
}

void RPGEngine::processTaskSuccess(Hero &hero, const Task &task) {
    int gainedXP = task.getDifficulty() * 20;
    std::cout << "\n[EVENT] Task '" << task.getTitle() << "' completed!" << std::endl;
    std::cout << "[REWARD] " << hero.getName() << " has received " << gainedXP << " XP!\n";

    hero.addXP(gainedXP);
    checkLevelUp(hero);
}

void RPGEngine::processTaskFailure(Hero &hero, const Task &task) {
    int damage = task.getUrgency() * 10;
    int currentHP = hero.getHP();

    // Prevent HP from dropping to 0
    int newHP = (currentHP - damage < 0) ? 0 : currentHP - damage;
    hero.setHP(newHP);

    std::cout << "[EVENT] Task '" << task.getTitle() << "' failed!" << std::endl;
    std::cout << "[DAMAGE] " << hero.getName() << " took " << damage << " damage!" << std::endl;

    if (hero.getHP() <= 0) {
        std::cout << "[GAME OVER] " << hero.getName() << " has been defeated by procrastination..." << std::endl;
    }
}
