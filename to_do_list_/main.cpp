#include <iostream>
#include "Characteristics.h"
#include "UI_Functions.h"

using namespace std;

extern void clearTask(Task*& tasks, uint& size);

int main() 
{
    setlocale(LC_ALL, "Russian");

    uint size = 0;
    Task* tasks = nullptr;

    showWelcomeMenu();

    uint initialSize = 0;
    while (true) 
    {
        if (cin >> initialSize) 
        {
            break;
        }
        else {
            cout << "Будь ласка, введiть коректне число: ";
            cin.clear();
            while (cin.get() != '\n');
        }
    }

    cin.clear();
    while (cin.get() != '\n');

    if (initialSize > 0) 
    {
        tasks = new Task[initialSize];
        size = initialSize;
        for (uint i = 0; i < size; i++) 
        {
            cout << "\n--- Створення задачi №" << i + 1 << " з " << size << " ---" << endl;
            tasks[i] = createTask();
        }
    }

    callFunction(tasks, size);

    clearTask(tasks, size);

    return 0;
}