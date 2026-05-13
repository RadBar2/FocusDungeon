#ifndef RPGENGINE_H_INCLUDED
#define RPGENGINE_H_INCLUDED

#include "Hero.cpp"
#include "Task.h"

class RPGEngine {
    private:
        int xpRequired;
        void checkLevelUp(Hero &hero);

    public:
        RPGEngine() : xpRequired(100) {}

        // Setters/getters
        int getXPRequired() const;

        // Method, used to process a successful task
        void processTaskSuccess(Hero &hero, const Task &task);

        // Method, used to process a failed task
        void processTaskFailure(Hero &hero, const Task &task);
};



#endif // RPGENGINE_H_INCLUDED
