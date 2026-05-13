#include "TaskManager.h"

#include <iostream>
#include <cstddef>

using namespace std;

TaskManager::TaskManager()
    : nextId(1)
{
}

Task* TaskManager::findTaskById(int id) {
    for (Task& task : tasks) {
        if (task.getId() == id) {
            return &task;
        }
    }

    return nullptr;
}

Task& TaskManager::addTask(const string& title,
                           const string& description,
                           int difficulty,
                           int urgency,
                           const string& deadline) {
    tasks.emplace_back(nextId, title, description, difficulty, urgency, deadline);
    nextId++;

    return tasks.back();
}

bool TaskManager::editTask(int id,
                           const string& newTitle,
                           const string& newDescription,
                           int newDifficulty,
                           int newUrgency,
                           const string& newDeadline) {
    Task* task = findTaskById(id);

    if (task == nullptr) {
        return false;
    }

    task->setTitle(newTitle);
    task->setDescription(newDescription);
    task->setDifficulty(newDifficulty);
    task->setUrgency(newUrgency);
    task->setDeadline(newDeadline);

    return true;
}

bool TaskManager::deleteTask(int id) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].getId() == id) {
            tasks.erase(tasks.begin() + i);
            return true;
        }
    }

    return false;
}

bool TaskManager::completeTask(int id) {
    Task* task = findTaskById(id);

    if (task == nullptr) {
        return false;
    }

    if (task->getStatus() != TaskStatus::Pending) {
        return false;
    }

    task->markCompleted();
    return true;
}

bool TaskManager::failTask(int id) {
    Task* task = findTaskById(id);

    if (task == nullptr) {
        return false;
    }

    if (task->getStatus() != TaskStatus::Pending) {
        return false;
    }

    task->markFailed();
    return true;
}

const vector<Task>& TaskManager::getAllTasks() const {
    return tasks;
}

vector<Task> TaskManager::getPendingTasks() const {
    vector<Task> result;

    for (const Task& task : tasks) {
        if (task.getStatus() == TaskStatus::Pending) {
            result.push_back(task);
        }
    }

    return result;
}

vector<Task> TaskManager::getCompletedTasks() const {
    vector<Task> result;

    for (const Task& task : tasks) {
        if (task.getStatus() == TaskStatus::Completed) {
            result.push_back(task);
        }
    }

    return result;
}

vector<Task> TaskManager::getFailedTasks() const {
    vector<Task> result;

    for (const Task& task : tasks) {
        if (task.getStatus() == TaskStatus::Failed) {
            result.push_back(task);
        }
    }

    return result;
}

int TaskManager::getTaskCount() const {
    return static_cast<int>(tasks.size());
}

int TaskManager::getCompletedTaskCount() const {
    int count = 0;

    for (const Task& task : tasks) {
        if (task.getStatus() == TaskStatus::Completed) {
            count++;
        }
    }

    return count;
}

int TaskManager::getFailedTaskCount() const {
    int count = 0;

    for (const Task& task : tasks) {
        if (task.getStatus() == TaskStatus::Failed) {
            count++;
        }
    }

    return count;
}

void TaskManager::printAllTasks() const {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    for (const Task& task : tasks) {
        cout << "-------------------------\n";
        task.print();
    }

    cout << "-------------------------\n";
}
