#pragma once
#include <iostream>
#include <cstring>
using namespace std;
//Aisha's Work
void printLine() {
    cout << "=============================================================\n";
}

void printDivider() {
    cout << "-------------------------------------------------------------\n";
}

void showTask(const Task& task) {
    printDivider();
    cout << "  Priority    : " << task.numb        << "\n";
    cout << "  Name        : " << task.name        << "\n";
    cout << "  Description : " << task.description << "\n";
    cout << "  Date        : " << task.day << "/" << task.month << "/" << task.year << "\n";
    cout << "  Time        : " << task.time << ":00\n";
    cout << "  Week #      : " << task.week        << "\n";
    printDivider();
}

void showAll(const Task* tasks, uint size) {
    printLine();
    if (size == 0) {
        cout << "  [No tasks available]\n";
        printLine();
        return;
    }
    cout << "  TASK LIST   -   Total: " << size << " task(s)\n";
    printLine();
    for (uint i = 0; i < size; i++) {
        cout << "  Task #" << (i + 1) << "\n";
        showTask(tasks[i]);
    }
}

//Nika's work

Task createTask() {
    cin.ignore();
    Task std{};
    const int N1 = 20;
    char n1[N1];
    cout << "Enter name: ";
    cin.getline(n1, N1);
    std.name = new char[strlen(n1) + 1];
    strcpy(std.name, n1);
    cout << "Enter priority: ";
    cin >> std.numb;
    cin.ignore();
    const int N2 = 20;
    char n2[N2];
    cout << "Enter description: ";
    cin.getline(n2, N2);
    std.description = new char[strlen(n2) + 1];
    strcpy(std.description, n2);
    cout << "Enter Date (day month year): ";
    cin >> std.day >> std.month >> std.year;
    cout << "Enter time (hour): ";
    cin >> std.time;
    return std;
}

void addTask(Task*& tasks, uint& size, const Task& newTask) {
    Task* temp = new Task[size + 1];
    for (uint i = 0; i < size; i++)
        temp[i] = tasks[i];
    temp[size] = newTask;
    delete[] tasks;
    tasks = temp;
    size++;
}

void freeTaskMemory(Task& task) {
    delete[] task.name;
    delete[] task.description;
}

void deleteTask(Task*& tasks, uint& size, uint searchPriority) {
    bool isFound = false;
    uint priorityDelete = 0;
    for (uint i = 0; i < size; i++) {
        if (tasks[i].numb == searchPriority) {
            priorityDelete = i;
            isFound = true;
            break;
        }
    }
    if (!isFound) {
        cout << "Task with priority: " << searchPriority << " not found!\n";
        return;
    }
    if (size == 1) {
        freeTaskMemory(tasks[0]);
        delete[] tasks;
        tasks = nullptr;
        size = 0;
        return;
    }
    Task* temp = new Task[size - 1];
    for (uint i = 0, j = 0; i < size; i++) {
        if (i != priorityDelete)
            temp[j++] = tasks[i];
        else
            freeTaskMemory(tasks[i]);
    }
    delete[] tasks;
    tasks = temp;
    size--;
}

void changeTask(Task* tasks, uint size) {
    uint numberTask;
    cout << "Enter priority of task to change: ";
    cin >> numberTask;
    int index = -1;
    for (uint i = 0; i < size; i++) {
        if (tasks[i].numb == numberTask) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Task not found!\n";
        return;
    }
    uint change = (uint)-1;
    while (change != 0) {
        cout << "Choose what to change: 1-name  2-priority  3-description  4-date  5-time  0-exit : ";
        cin >> change;
        if (change == 0) { cout << "Exit...\n"; break; }
        if (change == 1) {
            cin.ignore();
            const int N1 = 20;
            char n1[N1];
            cout << "Enter name: ";
            cin.getline(n1, N1);
            delete[] tasks[index].name;
            tasks[index].name = new char[strlen(n1) + 1];
            strcpy(tasks[index].name, n1);
            cout << "Name changed!\n";
        } else if (change == 2) {
            cout << "Enter priority: ";
            cin >> tasks[index].numb;
            cout << "Priority changed!\n";
        } else if (change == 3) {
            cin.ignore();
            const int N2 = 20;
            char n2[N2];
            cout << "Enter description: ";
            cin.getline(n2, N2);
            delete[] tasks[index].description;
            tasks[index].description = new char[strlen(n2) + 1];
            strcpy(tasks[index].description, n2);
            cout << "Description changed!\n";
        } else if (change == 4) {
            cout << "Enter date (day month year): ";
            cin >> tasks[index].day >> tasks[index].month >> tasks[index].year;
            cout << "Date changed!\n";
        } else if (change == 5) {
            cout << "Enter time (hour): ";
            cin >> tasks[index].time;
            cout << "Time changed!\n";
        } else {
            cout << "Invalid option, try again!\n";
        }
    }
}

void clearTask(Task*& tasks, uint& size) {
    for (uint i = 0; i < size; i++)
        freeTaskMemory(tasks[i]);
    delete[] tasks;
    tasks = nullptr;
    size = 0;
}

//Nastya's work

void searchTaskByName(const Task* tasks, uint size, const char* searchName) {
    bool found = false;
    for (uint i = 0; i < size; i++) {
        bool equal = true;
        for (int j = 0; tasks[i].name[j] != '\0' || searchName[j] != '\0'; j++) {
            if (tasks[i].name[j] != searchName[j]) {
                equal = false;
                break;
            }
        }
        if (equal) {
            showTask(tasks[i]);
            found = true;
        }
    }
    if (!found)
        cout << "No tasks found with name: " << searchName << "\n";
}

void searchTaskByPriority(const Task* tasks, uint size, ushort priority) {
    bool found = false;
    for (uint i = 0; i < size; i++) {
        if (tasks[i].numb == priority) {
            showTask(tasks[i]);
            found = true;
        }
    }
    if (!found)
        cout << "No tasks found with priority: " << priority << "\n";
}

void searchTaskByDescription(const Task* tasks, uint size, const char* searchDesc) {
    bool found = false;
    for (uint i = 0; i < size; i++) {
        bool equal = true;
        for (int j = 0; tasks[i].description[j] != '\0' || searchDesc[j] != '\0'; j++) {
            if (tasks[i].description[j] != searchDesc[j]) {
                equal = false;
                break;
            }
        }
        if (equal) {
            showTask(tasks[i]);
            found = true;
        }
    }
    if (!found)
        cout << "No tasks found with description: " << searchDesc << "\n";
}

void searchTaskByDateAndTime(const Task* tasks, uint size,
                             ushort day, ushort month, ushort year, ushort time) {
    bool found = false;
    for (uint i = 0; i < size; i++) {
        if (tasks[i].day  == day   && tasks[i].month == month &&
            tasks[i].year == year  && tasks[i].time  == time) {
            showTask(tasks[i]);
            found = true;
        }
    }
    if (!found)
        cout << "No tasks found at specified date and time.\n";
}

void showTaskForDay(const Task* tasks, uint size, ushort day) {
    bool found = false;
    for (uint i = 0; i < size; i++) {
        if (tasks[i].day == day) {
            showTask(tasks[i]);
            found = true;
        }
    }
    if (!found)
        cout << "No tasks for this day.\n";
}

void showTaskForWeek(const Task* tasks, uint size, ushort week) {
    bool found = false;
    for (uint i = 0; i < size; i++) {
        if (tasks[i].week == week) {
            showTask(tasks[i]);
            found = true;
        }
    }
    if (!found)
        cout << "No tasks for this week.\n";
}

void showTaskForMonth(const Task* tasks, uint size, ushort month) {
    bool found = false;
    for (uint i = 0; i < size; i++) {
        if (tasks[i].month == month) {
            showTask(tasks[i]);
            found = true;
        }
    }
    if (!found)
        cout << "No tasks for this month.\n";
}

bool isEarlier(const Task& a, const Task& b) {
    if (a.year  != b.year)  return a.year  < b.year;
    if (a.month != b.month) return a.month < b.month;
    if (a.day   != b.day)   return a.day   < b.day;
    return a.time < b.time;
}

void sortingTaskByPriority(Task* tasks, uint size) {
    for (uint i = 0; i < size - 1; i++)
        for (uint j = 0; j < size - 1 - i; j++)
            if (tasks[j].numb > tasks[j + 1].numb) {
                Task temp    = tasks[j];
                tasks[j]     = tasks[j + 1];
                tasks[j + 1] = temp;
            }
}

void sortingTaskByDateAndTime(Task* tasks, uint size) {
    for (uint i = 0; i < size - 1; i++)
        for (uint j = 0; j < size - 1 - i; j++)
            if (!isEarlier(tasks[j], tasks[j + 1])) {
                Task temp    = tasks[j];
                tasks[j]     = tasks[j + 1];
                tasks[j + 1] = temp;
            }
}

