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
    return 0;
}
