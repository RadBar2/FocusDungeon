#pragma once

#include <string>

enum class TaskStatus {
    Pending,
    Completed,
    Failed
};

class Task {
private:
    int id;
    std::string title;
    std::string description;
    int difficulty;
    int urgency;
    std::string deadline;
    TaskStatus status;

public:
    Task(int id,
         const std::string& title,
         const std::string& description,
         int difficulty,
         int urgency,
         const std::string& deadline);

    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    int getDifficulty() const;
    int getUrgency() const;
    std::string getDeadline() const;
    TaskStatus getStatus() const;

    void setTitle(const std::string& title);
    void setDescription(const std::string& description);
    void setDifficulty(int difficulty);
    void setUrgency(int urgency);
    void setDeadline(const std::string& deadline);

    void markCompleted();
    void markFailed();

    std::string statusToString() const;

    void print() const;
};
