#pragma once

#include "Task.h"

#include <vector>
#include <string>

class TaskManager {
private:
    // List of all tasks
    std::vector<Task> tasks;

    // ID for the next created task
    int nextId;

public:
    // Creates an empty TaskManager
    TaskManager();

    // Adds a new task
    Task& addTask(const std::string& title,
                  const std::string& description,
                  int difficulty,
                  int urgency,
                  const std::string& deadline);

    // Edits an existing task
    bool editTask(int id,
                  const std::string& newTitle,
                  const std::string& newDescription,
                  int newDifficulty,
                  int newUrgency,
                  const std::string& newDeadline);

    // Finds a task by ID
    Task* findTaskById(int id) const;

    // Basic task actions
    bool deleteTask(int id);
    bool completeTask(int id);
    bool failTask(int id);

    // Returns task lists
    const std::vector<Task>& getAllTasks() const;
    std::vector<Task> getPendingTasks() const;
    std::vector<Task> getCompletedTasks() const;
    std::vector<Task> getFailedTasks() const;

    // Returns task statistics
    int getTaskCount() const;
    int getCompletedTaskCount() const;
    int getFailedTaskCount() const;

    // Prints all tasks
    void printAllTasks() const;
};