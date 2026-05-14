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

    // 2. Processing a Success
    int successfulId = 1;
    if (taskManager.completeTask(successfulId)) {
        Task* sucessfulTask = taskManager.findTaskById(successfulId);
        engine.processTaskSuccess(player, *sucessfulTask);
    }

    // 3. Processing a Failure
    int failedId = 2;
    if (taskManager.failTask(failedId)) {
        Task* failedTask = taskManager.findTaskById(failedId);
        engine.processTaskFailure(player, *failedTask);
    }

    return 0;
}