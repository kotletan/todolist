#include <iostream>
using namespace std;
#include "Characteristics.h"
#include "Functions.h"
using namespace std;
int main() {
    uint size;
       cout<<"Enter quantity of Tasks: ";
       cin>>size;
       Task* task=new Task[size];
       for(uint i=0;i<size;i++)
       {
           task[i]=createTask();
       }
       for(uint i=0;i<size;i++)
       {
           showTask(task[i]);
       }
    showAll(task,size);
    Task newTask = createTask();
    addTask(task,size,newTask);
    int p;
    cout<<"Enter priority of the task, that you want to delete: ";
    cin>>p;
    deleteTask(task,size,p);
    showAll(task,size);
    changeTask(task,size);
    showAll(task,size);
    return 0;
}
