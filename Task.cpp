#include "Task.h"

#include <iostream>
#include <stdexcept>

using namespace std;

Task::Task(int id,
           const string& title,
           const string& description,
           int difficulty,
           int urgency,
           const string& deadline)
    : id(id),
      title(title),
      description(description),
      difficulty(difficulty),
      urgency(urgency),
      deadline(deadline),
      status(TaskStatus::Pending)
{
    if (difficulty < 1 || difficulty > 5) {
        throw invalid_argument("Difficulty must be between 1 and 5.");
    }

    if (urgency < 1 || urgency > 5) {
        throw invalid_argument("Urgency must be between 1 and 5.");
    }

    if (title.empty()) {
        throw invalid_argument("Title cannot be empty.");
    }
}

int Task::getId() const {
    return id;
}

string Task::getTitle() const {
    return title;
}

string Task::getDescription() const {
    return description;
}

int Task::getDifficulty() const {
    return difficulty;
}

int Task::getUrgency() const {
    return urgency;
}

string Task::getDeadline() const {
    return deadline;
}

TaskStatus Task::getStatus() const {
    return status;
}

void Task::setTitle(const string& newTitle) {
    if (newTitle.empty()) {
        throw invalid_argument("Title cannot be empty.");
    }

    title = newTitle;
}

void Task::setDescription(const string& newDescription) {
    description = newDescription;
}

void Task::setDifficulty(int newDifficulty) {
    if (newDifficulty < 1 || newDifficulty > 5) {
        throw invalid_argument("Difficulty must be between 1 and 5.");
    }

    difficulty = newDifficulty;
}

void Task::setUrgency(int newUrgency) {
    if (newUrgency < 1 || newUrgency > 5) {
        throw invalid_argument("Urgency must be between 1 and 5.");
    }

    urgency = newUrgency;
}

void Task::setDeadline(const string& newDeadline) {
    deadline = newDeadline;
}

void Task::markCompleted() {
    status = TaskStatus::Completed;
}

void Task::markFailed() {
    status = TaskStatus::Failed;
}

string Task::statusToString() const {
    switch (status) {
        case TaskStatus::Pending:
            return "Pending";

        case TaskStatus::Completed:
            return "Completed";

        case TaskStatus::Failed:
            return "Failed";

        default:
            return "Unknown";
    }
}

void Task::print() const {
    cout << "Task ID: " << id << "\n";
    cout << "Title: " << title << "\n";
    cout << "Description: " << description << "\n";
    cout << "Difficulty: " << difficulty << "\n";
    cout << "Urgency: " << urgency << "\n";
    cout << "Deadline: " << deadline << "\n";
    cout << "Status: " << statusToString() << "\n";
}