#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Characteristics.h"

using namespace std;

void clearInput() 
{
    cin.clear();
    while (cin.get() != '\n');
}

void freeTaskMemory(Task& task) 
{
    delete[] task.name;
    delete[] task.description;
    task.name = nullptr;
    task.description = nullptr;
}

Task createTask()
{
    Task stdTask{};
    const int MAX_LEN = 256;
    char buffer[MAX_LEN];

    cout << "\n--- Створення нової справи ---" << endl;
    cout << "Введiть назву: ";
    cin.getline(buffer, MAX_LEN);
    stdTask.name = new char[strlen(buffer) + 1];
    strcpy(stdTask.name, buffer);

    cout << "Введiть прiоритет (число): ";
    while (!(cin >> stdTask.numb)) 
    {
        cout << "Некоректний прiоритет! Спробуйте ще раз: ";
        clearInput();
    }
    clearInput();

    cout << "Введiть опис: ";
    cin.getline(buffer, MAX_LEN);
    stdTask.description = new char[strlen(buffer) + 1];
    strcpy(stdTask.description, buffer);

    cout << "Введiть Дату (День Мiсяць Рiк через пробiл): ";
    while (!(cin >> stdTask.day >> stdTask.month >> stdTask.year)) 
    {
        cout << "Некоректна дата! Спробуйте ще раз: ";
        clearInput();
    }

    cout << "Введiть час виконання (наприклад, 1530 для 15:30): ";
    while (!(cin >> stdTask.time)) 
    {
        cout << "Некоректний час! Спробуйте ще раз: ";
        clearInput();
    }
    clearInput();

    return stdTask;
}

void addTask(Task*& tasks, uint& size, const Task& newTask)
{
    Task* temp = new Task[size + 1];
    for (uint i = 0; i < size; i++)
    {
        temp[i] = tasks[i];
    }
    temp[size] = newTask;
    delete[] tasks;
    tasks = temp;
    size++;
}

void deleteTask(Task*& tasks, uint& size, uint searchPriority)
{
    bool isFound = false;
    uint indexToDelete = -1;
    for (uint i = 0; i < size; i++)
    {
        if (tasks[i].numb == searchPriority)
        {
            indexToDelete = i;
            isFound = true;
            break;
        }
    }

    if (!isFound)
    {
        cout << "Справу з прiоритетом " << searchPriority << " не знайдено!" << endl;
        return;
    }

    freeTaskMemory(tasks[indexToDelete]);

    if (size == 1)
    {
        delete[] tasks;
        tasks = nullptr;
        size = 0;
        return;
    }

    Task* temp = new Task[size - 1];
    for (uint i = 0, j = 0; i < size; i++)
    {
        if (i != indexToDelete)
        {
            temp[j++] = tasks[i];
        }
    }
    delete[] tasks;
    tasks = temp;
    size--;
    cout << "Справу з прiоритетом " << searchPriority << " успiшно видалено!" << endl;
}

void changeTask(Task* tasks, uint size)
{
    if (size == 0 || tasks == nullptr) 
    {
        cout << "Список порожнiй!" << endl;
        return;
    }

    uint numberTask;
    cout << "Введiть прiоритет (число) справи, яку хочете змiнити: ";
    cin >> numberTask;

    int index = -1;
    for (uint i = 0; i < size; i++)
    {
        if (tasks[i].numb == numberTask)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Справу не знайдено!" << endl;
        return;
    }

    uint change = -1;
    const int MAX_LEN = 256;
    char buffer[MAX_LEN];

    while (change != 0)
    {
        cout << "\nЩо ви бажаєте змiнити у справi \"" << tasks[index].name << "\"?" << endl;
        cout << "1 - Назву, 2 - Прiоритет, 3 - Опис, 4 - Дату, 5 - Час, 0 - Вихiд: ";
        cin >> change;
        clearInput();

        if (change == 0)
        {
            cout << "Вихiд з редагування..." << endl;
            break;
        }
        if (change == 1) 
        {
            cout << "Введiть нову назву: ";
            cin.getline(buffer, MAX_LEN);
            delete[] tasks[index].name;
            tasks[index].name = new char[strlen(buffer) + 1];
            strcpy(tasks[index].name, buffer);
            cout << "Назву змiнено!" << endl;
        }
        else if (change == 2)
        {
            cout << "Введiть новий прiоритет: ";
            cin >> tasks[index].numb;
            cout << "Прiоритет змiнено!" << endl;
        }
        else if (change == 3)
        {
            cout << "Введiть новий опис: ";
            cin.getline(buffer, MAX_LEN);
            delete[] tasks[index].description;
            tasks[index].description = new char[strlen(buffer) + 1];
            strcpy(tasks[index].description, buffer);
            cout << "Опис змiнено!" << endl;
        }
        else if (change == 4)
        {
            cout << "Введiть нову Дату (День Місяць Рiк): ";
            cin >> tasks[index].day >> tasks[index].month >> tasks[index].year;
            cout << "Дату змiнено!" << endl;
        }
        else if (change == 5)
        {
            cout << "Введiть новий час (наприклад, 1430): ";
            cin >> tasks[index].time;
            cout << "Час змiнено!" << endl;
        }
        else
        {
            cout << "Некоректний вибiр! Спробуйте ще раз." << endl;
        }
    }
}

void clearTask(Task*& tasks, uint& size)
{
    if (tasks != nullptr) 
    {
        for (uint i = 0; i < size; i++)
        {
            freeTaskMemory(tasks[i]);
        }
        delete[] tasks;
        tasks = nullptr;
    }
    size = 0;
}
