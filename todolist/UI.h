#pragma once
#include <iostream>
using namespace std;

enum MainMenuOption {
    EXIT_APP    = 0,
    ADD_TASK    = 1,
    DELETE_TASK = 2,
    EDIT_TASK   = 3,
    SEARCH_TASK = 4,
    SHOW_TASKS  = 5,
    SORT_TASKS  = 6
};

enum SearchMenuOption {
    SEARCH_BACK        = 0,
    SEARCH_BY_NAME     = 1,
    SEARCH_BY_PRIORITY = 2,
    SEARCH_BY_DESC     = 3,
    SEARCH_BY_DATETIME = 4
};

enum ShowMenuOption {
    SHOW_BACK      = 0,
    SHOW_FOR_DAY   = 1,
    SHOW_FOR_WEEK  = 2,
    SHOW_FOR_MONTH = 3
};

enum SortMenuOption {
    SORT_BACK        = 0,
    SORT_BY_PRIORITY = 1,
    SORT_BY_DATETIME = 2
};

ushort calculateWeek(ushort day, ushort month, ushort year) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[2] = 29;
    int dayOfYear = day;
    for (int m = 1; m < month; m++)
        dayOfYear += daysInMonth[m];
    return static_cast<ushort>((dayOfYear - 1) / 7 + 1);
}

void printMainMenu() {
    printLine();
    cout << "            *** TO-DO LIST APPLICATION ***\n";
    printLine();
    cout << "  1. Add task\n";
    cout << "  2. Delete task\n";
    cout << "  3. Edit task\n";
    cout << "  4. Search tasks\n";
    cout << "  5. Show tasks (by day / week / month)\n";
    cout << "  6. Sort tasks\n";
    cout << "  0. Exit\n";
    printLine();
    cout << "  Your choice: ";
}

void printSearchMenu() {
    printLine();
    cout << "  SEARCH BY:\n";
    printLine();
    cout << "  1. Name\n";
    cout << "  2. Priority\n";
    cout << "  3. Description\n";
    cout << "  4. Date & Time\n";
    cout << "  0. Back to main menu\n";
    printLine();
    cout << "  Your choice: ";
}

void printShowMenu() {
    printLine();
    cout << "  SHOW TASKS FOR:\n";
    printLine();
    cout << "  1. Day\n";
    cout << "  2. Week\n";
    cout << "  3. Month\n";
    cout << "  0. Back to main menu\n";
    printLine();
    cout << "  Your choice: ";
}

void printSortMenu() {
    printLine();
    cout << "  SORT BY:\n";
    printLine();
    cout << "  1. Priority\n";
    cout << "  2. Date & Time\n";
    cout << "  0. Back to main menu\n";
    printLine();
    cout << "  Your choice: ";
}

void showWelcomeMenu(Task*& tasks, uint& size) {
    printLine();
    cout << "        Welcome to the To-Do List Application!\n";
    printLine();
    cout << "  How many tasks would you like to enter right now?\n";
    cout << "  (Enter 0 to skip and go directly to the main menu)\n";
    printLine();
    cout << "  Count: ";
    cin >> size;

    if (size == 0) {
        tasks = nullptr;
        cout << "\n  Skipped. You can add tasks from the main menu.\n";
        return;
    }

    tasks = new Task[size];
    for (uint i = 0; i < size; i++) {
        cout << "\n  --- Entering Task " << (i + 1) << " of " << size << " ---\n";
        tasks[i]      = createTask();
        tasks[i].week = calculateWeek(tasks[i].day, tasks[i].month, tasks[i].year);
    }
    cout << "\n  " << size << " task(s) added successfully!\n";
}
void handleSearchMenu(const Task* tasks, uint size) {
    uint choice;
    do {
        cout << "\n";
        printSearchMenu();
        cin >> choice;
        cout << "\n";
        switch (static_cast<SearchMenuOption>(choice)) {
            case SEARCH_BY_NAME: {
                char name[50];
                cout << "  Enter name to search: ";
                cin.ignore();
                cin.getline(name, 50);
                searchTaskByName(tasks, size, name);
                break;
            }
            case SEARCH_BY_PRIORITY: {
                ushort priority;
                cout << "  Enter priority to search: ";
                cin >> priority;
                searchTaskByPriority(tasks, size, priority);
                break;
            }
            case SEARCH_BY_DESC: {
                char desc[50];
                cout << "  Enter description to search: ";
                cin.ignore();
                cin.getline(desc, 50);
                searchTaskByDescription(tasks, size, desc);
                break;
            }
            case SEARCH_BY_DATETIME: {
                ushort day, month, year, time;
                cout << "  Enter day   : "; cin >> day;
                cout << "  Enter month : "; cin >> month;
                cout << "  Enter year  : "; cin >> year;
                cout << "  Enter time  : "; cin >> time;
                searchTaskByDateAndTime(tasks, size, day, month, year, time);
                break;
            }
            case SEARCH_BACK:
                cout << "  Returning to main menu...\n";
                break;
            default:
                cout << "  Invalid choice. Please try again.\n";
        }
    } while (static_cast<SearchMenuOption>(choice) != SEARCH_BACK);
}

void handleShowMenu(const Task* tasks, uint size) {
    uint choice;
    do {
        cout << "\n";
        printShowMenu();
        cin >> choice;
        cout << "\n";
        switch (static_cast<ShowMenuOption>(choice)) {
            case SHOW_FOR_DAY: {
                ushort day;
                cout << "  Enter day   : "; cin >> day;
                showTaskForDay(tasks, size, day);
                break;
            }
            case SHOW_FOR_WEEK: {
                ushort week;
                cout << "  Enter week  : "; cin >> week;
                showTaskForWeek(tasks, size, week);
                break;
            }
            case SHOW_FOR_MONTH: {
                ushort month;
                cout << "  Enter month : "; cin >> month;
                showTaskForMonth(tasks, size, month);
                break;
            }
            case SHOW_BACK:
                cout << "  Returning to main menu...\n";
                break;
            default:
                cout << "  Invalid choice. Please try again.\n";
        }
    } while (static_cast<ShowMenuOption>(choice) != SHOW_BACK);
}
void handleSortMenu(Task* tasks, uint size) {
    uint choice;
    do {
        cout << "\n";
        printSortMenu();
        cin >> choice;
        cout << "\n";
        switch (static_cast<SortMenuOption>(choice)) {
            case SORT_BY_PRIORITY:
                sortingTaskByPriority(tasks, size);
                cout << "  Tasks sorted by priority.\n";
                showAll(tasks, size);
                break;
            case SORT_BY_DATETIME:
                sortingTaskByDateAndTime(tasks, size);
                cout << "  Tasks sorted by date & time.\n";
                showAll(tasks, size);
                break;
            case SORT_BACK:
                cout << "  Returning to main menu...\n";
                break;
            default:
                cout << "  Invalid choice. Please try again.\n";
        }
    } while (static_cast<SortMenuOption>(choice) != SORT_BACK);
}

void callFunction(Task*& tasks, uint& size) {
    uint choice;
    do {
        cout << "\n";
        showAll(tasks, size);
        printMainMenu();
        cin >> choice;
        cout << "\n";

        switch (static_cast<MainMenuOption>(choice)) {

            case ADD_TASK: {
                cout << "  --- Add New Task ---\n";
                Task newTask      = createTask();
                newTask.week      = calculateWeek(newTask.day, newTask.month, newTask.year);
                addTask(tasks, size, newTask);
                cout << "  Task added successfully!\n";
                break;
            }
            case DELETE_TASK: {
                if (size == 0) { cout << "  No tasks to delete.\n"; break; }
                uint p;
                cout << "  Enter priority of task to delete: ";
                cin >> p;
                deleteTask(tasks, size, p);
                break;
            }
            case EDIT_TASK: {
                if (size == 0) { cout << "  No tasks to edit.\n"; break; }
                changeTask(tasks, size);
                break;
            }
            case SEARCH_TASK: {
                if (size == 0) { cout << "  No tasks to search.\n"; break; }
                handleSearchMenu(tasks, size);
                break;
            }
            case SHOW_TASKS: {
                if (size == 0) { cout << "  No tasks to display.\n"; break; }
                handleShowMenu(tasks, size);
                break;
            }
            case SORT_TASKS: {
                if (size == 0) { cout << "  No tasks to sort.\n"; break; }
                handleSortMenu(tasks, size);
                break;
            }
            case EXIT_APP:
                printLine();
                cout << "  Goodbye! Thank you for using To-Do List App.\n";
                printLine();
                break;
            default:
                cout << "  Invalid choice. Please try again.\n";
        }

    } while (static_cast<MainMenuOption>(choice) != EXIT_APP);
}
void runApp() {
    Task* tasks = nullptr;
    uint  size  = 0;
    showWelcomeMenu(tasks, size);
    callFunction(tasks, size);
    clearTask(tasks, size);
}

