#include <iostream>
#include "Hero.h"
#include "TaskManager.h"
#include "RPGEngine.h"

int main() {
    // DATA LAYER
    Hero player("Sir Codes-a-Lot");
    TaskManager taskManager;

    // BUSINESS LOGIC LAYER
    RPGEngine engine;

    // 1. Adding Tasks (Presentation Layer interacting with TaskManager)
    taskManager.addTask("Write Hero.h", "Define the data structure", 2, 1, "Today");
    taskManager.addTask("Fix Main logic", "Align with architecture diagram", 4, 5, "Now");

    std::cout << "--- Quest Log ---" << std::endl;
    taskManager.printAllTasks();

    // Display initial hero stats
    std::cout << "Initial Hero Stats: " << player.getName() << " | HP: " << player.getHP() << " | XP: " << player.getXP() << std::endl;

    // 2. Processing a Success
    int successfulId = 1;
    if (taskManager.completeTask(successfulId)) {
        Task* sucessfulTask = taskManager.findTaskById(successfulId);
        engine.processTaskSuccess(player, *sucessfulTask);
    }

    std::cout << std::endl << "Hero Stats after a successful task: " << player.getName() << " | HP: " << player.getHP() << " | XP: " << player.getXP() << std::endl;

    // 3. Processing a Failure
    int failedId = 2;
    if (taskManager.failTask(failedId)) {
        Task* failedTask = taskManager.findTaskById(failedId);
        engine.processTaskFailure(player, *failedTask);
    }

    std::cout << std::endl << "Hero Stats after a failed task: " << player.getName() << " | HP: " << player.getHP() << " | XP: " << player.getXP() << std::endl;

    return 0;
}