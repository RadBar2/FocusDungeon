# Focus Dungeon

Focus Dungeon is a gamified productivity application where players complete real-life tasks to
progress in a dungeon-like environment. Each task is assigned importance and urgency levels,
which determine the experience points (EXP) gained upon completion. Failure to complete
tasks on time results in a loss of health points (HP), encouraging consistent productivity
and time managemen

## UML Class Diagram

```mermaid
classDiagram
    class Hero {
        - name : string
        - hp : int
        - maxHP : int
        - xp : int
        - level : int
        + Hero(heroName : string)
        + getName() string
        + getHP() int
        + getMaxHP() int
        + getXP() int
        + getLevel() int
        + setHP(newHP : int)
        + setMaxHP(newMax : int)
        + setXP(newXP : int)
        + setLevel(newLevel : int)
        + addXP(amount : int)
    }

    class Task {
        - id : int
        - title : string
        - description : string
        - difficulty : int
        - urgency : int
        - deadline : string
        - status : TaskStatus
        + Task(id, title, description, difficulty, urgency, deadline)
        + getId() int
        + getTitle() string
        + getDescription() string
        + getDifficulty() int
        + getUrgency() int
        + getDeadline() string
        + getStatus() TaskStatus
        + setTitle(title : string)
        + setDescription(desc : string)
        + setDifficulty(diff : int)
        + setUrgency(urg : int)
        + setDeadline(dl : string)
        + markCompleted()
        + markFailed()
        + statusToString() string
        + print()
    }

    class TaskManager {
        - tasks : vector~Task~
        - nextId : int
        + TaskManager()
        + addTask(...) Task&
        + editTask(...) bool
        + findTaskById(id : int) Task*
        + deleteTask(id : int) bool
        + completeTask(id : int) bool
        + failTask(id : int) bool
        + getAllTasks() vector~Task~
        + getPendingTasks() vector~Task~
        + getTaskCount() int
        + printAllTasks()
    }

    class RPGEngine {
        - xpRequired : int
        - checkLevelUp(hero : Hero&)
        + RPGEngine()
        + getXPRequired() int
        + processTaskSuccess(hero : Hero&, task : Task&)
        + processTaskFailure(hero : Hero&, task : Task&)
    }

    class TaskStatus {
        <<enumeration>>
        Pending
        Completed
        Failed
    }

    %% Relationships
    TaskManager "1" *-- "*" Task : contains
    Task --> TaskStatus : uses
    RPGEngine ..> Hero : manages/modifies
    RPGEngine ..> Task : processes
```
