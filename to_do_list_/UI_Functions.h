#pragma once
#include <iostream>
#include <iomanip>
#include "Characteristics.h"

using namespace std;

enum MenuOptions 
{
    EXIT = 0,
    ADD_TASK = 1,
    DELETE_TASK = 2,
    EDIT_TASK = 3,
    SHOW_ALL_TASKS = 4,
    SHOW_DAY = 5,
    SHOW_WEEK = 6,
    SHOW_MONTH = 7,
    SEARCH_NAME = 8,
    SEARCH_PRIORITY = 9,
    SEARCH_DESC = 10,
    SEARCH_DATE_TIME = 11
};

extern Task createTask();
extern void addTask(Task*& tasks, uint& size, const Task& newTask);
extern void deleteTask(Task*& tasks, uint& size, uint searchPriority);
extern void changeTask(Task* tasks, uint size);
extern void clearInput();

void showWelcomeMenu()
{
    cout << "=========================================================" << endl;
    cout << "||                                                     ||" << endl;
    cout << "||            ЛАСКАВО ПРОСИМО В «СПИСОК СПРАВ»         ||" << endl;
    cout << "||                                                     ||" << endl;
    cout << "=========================================================" << endl;
    cout << "  Iнструкiя: Спочатку введiть кiлькiсть стартових задач." << endl;
    cout << "  Якщо ви хочете одразу перейти в меню, просто введiть 0." << endl;
    cout << "=========================================================" << endl;
}

void showTask(const Task& stdTask)
{
    char displayName[16] = "";
    char displayDesc[21] = "";

    if (stdTask.name != nullptr) 
    {
        strncpy(displayName, stdTask.name, 15);
        if (strlen(stdTask.name) > 15) 
        {
            displayName[12] = '.'; displayName[13] = '.'; displayName[14] = '.';
        }
    }

    if (stdTask.description != nullptr) 
    {
        strncpy(displayDesc, stdTask.description, 20);
        if (strlen(stdTask.description) > 20) 
        {
            displayDesc[17] = '.'; displayDesc[18] = '.'; displayDesc[19] = '.';
        }
    }

    ushort hours = stdTask.time / 100;
    ushort minutes = stdTask.time % 100;

    cout << "| " << left << setw(15) << displayName
        << " | " << right << setw(8) << stdTask.numb 
        << " | " << left << setw(20) << displayDesc
        << " | " << right << setfill('0') << setw(2) << stdTask.day << "."
        << setw(2) << stdTask.month << "." << setfill(' ') << setw(4) << stdTask.year
        << " | " << setfill('0') << setw(2) << hours << ":"
        << setw(2) << minutes << setfill(' ') << " |" << endl;
}

void showAll(const Task* task, uint size)
{
    if (size == 0 || task == nullptr) 
    {
        cout << "\n>>> Список задач пустий! <<<\n" << endl;
        return;
    }

    cout << endl;
    cout << setfill('-') << setw(68) << "-" << setfill(' ') << endl;
    cout << "| " << left << setw(15) << "Назва"
        << " | " << setw(8) << "Приорiт."
        << " | " << setw(20) << "Опис"
        << " | " << setw(10) << "Дата"
        << " | " << setw(5) << "Час" << " |" << endl;
    cout << setfill('-') << setw(68) << "-" << setfill(' ') << endl;

    for (uint i = 0; i < size; i++)
    {
        showTask(task[i]);
    }
    cout << setfill('-') << setw(68) << "-" << setfill(' ') << endl;
}

void searchTaskByName(const Task* tasks, uint size)
{
    char searchStr[256];
    cout << "Введiть назву задачi для пошуку: ";
    cin.getline(searchStr, 256);

    uint foundCount = 0;
    for (uint i = 0; i < size; i++) 
    {
        if (tasks[i].name != nullptr && strstr(tasks[i].name, searchStr) != nullptr) {
            if (foundCount == 0) 
            {
                cout << "\n--- Результати пошуку по назвi \"" << searchStr << "\": ---" << endl;
            }
            showTask(tasks[i]);
            foundCount++;
        }
    }
    if (foundCount == 0) cout << "Задачi с такою назвою не знайдено." << endl;
}

void searchTaskByPriority(const Task* tasks, uint size)
{
    uint searchPriority;
    cout << "Введить приорiтет для пошуку: ";
    cin >> searchPriority;
    clearInput();

    uint foundCount = 0;
    for (uint i = 0; i < size; i++) 
    {
        if (tasks[i].numb == searchPriority) 
        {
            if (foundCount == 0) 
            {
                cout << "\n--- Результатм пошуку по приорiтету " << searchPriority << ": ---" << endl;
            }
            showTask(tasks[i]);
            foundCount++;
        }
    }
    if (foundCount == 0) cout << "Задачi с таким приорiтетом не знайдено." << endl;
}

void searchTaskByDescription(const Task* tasks, uint size)
{
    char searchStr[256];
    cout << "Введите текст з опису для пошуку: ";
    cin.getline(searchStr, 256);

    uint foundCount = 0;
    for (uint i = 0; i < size; i++) 
    {
        if (tasks[i].description != nullptr && strstr(tasks[i].description, searchStr) != nullptr) {
            if (foundCount == 0) 
            {
                cout << "\n--- Результати пошуку в описi: ---" << endl;
            }
            showTask(tasks[i]);
            foundCount++;
        }
    }
    if (foundCount == 0) cout << "Задачi с таким описом не знайдено." << endl;
}

void searchTaskByDateAndTime(const Task* tasks, uint size)
{
    ushort d, m, y, t;
    cout << "Введiть дату (День Мiсяць Рiк через пробiл): ";
    cin >> d >> m >> y;
    cout << "Введiть час (наприклад, 1530): ";
    cin >> t;
    clearInput();

    uint foundCount = 0;
    for (uint i = 0; i < size; i++) 
    {
        if (tasks[i].day == d && tasks[i].month == m && tasks[i].year == y && tasks[i].time == t) {
            if (foundCount == 0) 
            {
                cout << "\n--- Результати точного пошуку по датi/часу: ---" << endl;
            }
            showTask(tasks[i]);
            foundCount++;
        }
    }
    if (foundCount == 0) cout << "Задачi на цей час не знайдено." << endl;
}

void showTaskForDay(const Task* tasks, uint size)
{
    ushort d, m, y;
    cout << "Введiть дату яка вас цiкавить (День Мiсяць Рiк через пробiл): ";
    cin >> d >> m >> y;
    clearInput();

    uint foundCount = 0;
    for (uint i = 0; i < size; i++) 
    {
        if (tasks[i].day == d && tasks[i].month == m && tasks[i].year == y) 
        {
            if (foundCount == 0) cout << "\n=== Задачi на день " << d << "." << m << "." << y << " ===" << endl;
            showTask(tasks[i]);
            foundCount++;
        }
    }
    if (foundCount == 0) cout << "На цей день задач немає." << endl;
}

void showTaskForWeek(const Task* tasks, uint size)
{
    ushort weekNum;
    cout << "Введить номер недiлi в роцi (1-53): ";
    cin >> weekNum;
    clearInput();

    uint foundCount = 0;
    for (uint i = 0; i < size; i++) 
    {
        if (tasks[i].week == weekNum) 
        {
            if (foundCount == 0) cout << "\n=== Задачi на недiлю № " << weekNum << " ===" << endl;
            showTask(tasks[i]);
            foundCount++;
        }
    }
    if (foundCount == 0) cout << "На цю недiлю задач немає." << endl;
}

void showTaskForMonth(const Task* tasks, uint size)
{
    ushort m, y;
    cout << "Введiть мiсяць та рiк (Мiсяць Рiк): ";
    cin >> m >> y;
    clearInput();

    uint foundCount = 0;
    for (uint i = 0; i < size; i++) 
    {
        if (tasks[i].month == m && tasks[i].year == y) 
        {
            if (foundCount == 0) cout << "\n=== Задачi на місяць " << m << "." << y << " ===" << endl;
            showTask(tasks[i]);
            foundCount++;
        }
    }
    if (foundCount == 0) cout << "На цей мiсяць задач немає." << endl;
}

void callFunction(Task*& tasks, uint& size)
{
    int choice = -1;
    while (choice != EXIT)
    {
        cout << "\n==================== ГОЛОВНЕ МЕНЮ ====================" << endl;
        cout << " 1. Додати нову задачу" << endl;
        cout << " 2. Видалити задачу (по прiоритету)" << endl;
        cout << " 3. Редагувати задачу" << endl;
        cout << " 4. Показати усi задачi" << endl;
        cout << " 5. Показати задачi на ДЕНЬ" << endl;
        cout << " 6. Показати задачi на НЕДIЛЮ" << endl;
        cout << " 7. Показати задачi на МIСЯЦЬ" << endl;
        cout << " 8. Пошук по НАЗВI" << endl;
        cout << " 9. Пошук по ПРІОРИТЕТУ" << endl;
        cout << "10. Пошук по ОПИСУ" << endl;
        cout << "11. Пошук по ДАТI ТА ЧАСУ" << endl;
        cout << " 0. Вийти з программи" << endl;
        cout << "======================================================" << endl;
        cout << "Оберіть дію: ";

        if (!(cin >> choice)) 
        {
            cout << "Помилка: введить корректное число!" << endl;
            clearInput();
            continue;
        }
        clearInput();

        switch (choice)
        {
        case ADD_TASK: {
            Task newTask = createTask();
            addTask(tasks, size, newTask);
            cout << "\n[Успішно]: Задачу додано!" << endl;
            break;
        }
        case DELETE_TASK: {
            if (size == 0) {
                cout << "Список пустий , нiчого видаляти!" << endl;
                break;
            }
            uint priorityToDelete;
            cout << "Введiть прiоритет задачi для видалення: ";
            cin >> priorityToDelete;
            clearInput();
            deleteTask(tasks, size, priorityToDelete);
            break;
        }
        case EDIT_TASK:
            changeTask(tasks, size);
            break;
        case SHOW_ALL_TASKS:
            showAll(tasks, size);
            break;
        case SHOW_DAY:
            showTaskForDay(tasks, size);
            break;
        case SHOW_WEEK:
            showTaskForWeek(tasks, size);
            break;
        case SHOW_MONTH:
            showTaskForMonth(tasks, size);
            break;
        case SEARCH_NAME:
            searchTaskByName(tasks, size);
            break;
        case SEARCH_PRIORITY:
            searchTaskByPriority(tasks, size);
            break;
        case SEARCH_DESC:
            searchTaskByDescription(tasks, size);
            break;
        case SEARCH_DATE_TIME:
            searchTaskByDateAndTime(tasks, size);
            break;
        case EXIT:
            cout << "\nЗавершення программи. Гарного дня!" << endl;
            break;
        default:
            cout << "Невiрный пункт меню! Спробуйте знову." << endl;
            break;
        }
    }
}
