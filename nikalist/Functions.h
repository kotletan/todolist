#pragma once
Task createTask()
{
    cin.ignore();
    Task std{};
    const int N1=20;
    char n1[N1];
    cout<<"Enter name: ";
    cin.getline(n1,N1);
    std.name=new char[strlen(n1)+1];
    strcpy(std.name,n1);
    cout<<"Enter priority: ";
    cin>>std.numb;
    cin.ignore();
    const int N2=20;
    char n2[N2];
    cout<<"Enter description: ";
    cin.getline(n2,N2);
    std.description=new char[strlen(n2)+1];
    strcpy(std.description,n2);
    cout<<"Enter Date(day, month, year): ";
    cin>>std.day;
    cin>>std.month;
    cin>>std.year;
    cout<<"Enter posted time: ";
    cin>>std.time;
    return std;
};
void showWelcomeMenu()
{
    
}
void showTask(const Task& std )
{
    cout<<std.name<<'\t'<<std.numb<<'\t'<<std.description<<'\t'<<std.day<<'\t'<<std.month<<'\t'<<std.year<<endl;
}
void showAll(const Task* task,uint size)
{
    for(uint i=0;i<size;i++)
    {
        showTask(task[i]);
    }
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
void deleteTask(Task*& tasks, uint& size,  uint searchPriority)
{
    bool isFound=false;
        uint PriorityDelete=-1;
        for(uint i=0;i<size;i++)
        {
            if(tasks[i].numb==searchPriority)
            {
                PriorityDelete = i;
                isFound = true;
                break;
            }
        }
        if(!isFound)
        {
            cout<<"Student with ID: "<<searchPriority<<" not found!"<<endl;
        }
  if(size==1)
  {
      delete[] tasks[0].name;
      delete[] tasks;
      tasks=nullptr;
      size=0;
      return;
      }
      Task* temp=new Task[size - 1];
  for(uint i=0, j = 0;i<size;i++)
  {
      if (i != PriorityDelete)
      {
          temp[j++] = tasks[i];
      }
      else
      {
          delete[] tasks[i].name;
      }
      }
  delete[] tasks;
  tasks=temp;
  size--;
}
void freeTaskMemory(Task& task) {
    delete[] task.name;
    delete[] task.description;
}
void changeTask(Task* tasks, uint size)
{
    uint numberTask;
    cout<<"What task u want to change?";
    cin>>numberTask;
    int index=-1;
    for(uint i=0;i<size;i++)
    {
        if(tasks[i].numb==numberTask)
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        cout<<"Task not found!"<<endl;
        return;
    }
    uint change=-1;
    while(change!=0)
    {
        cout<<"Choose what u want to change: 1-name, 2-priority, 3-description, 4-Date, 5-time, 0-exit : ";
        cin>>change;
        if(change==0)
        {
            cout<<"Exit......"<<endl;
            break;
        }
        if (change==1) {
            cin.ignore();
            const int N1=20;
            char n1[N1];
            cout<<"Enter name: ";
            cin.getline(n1,N1);
            delete[] tasks[index].name;
            tasks[index].name=new char[strlen(n1)+1];
            strcpy(tasks[index].name,n1);
            cout<<"Name changed!"<<endl;
        }
        else if(change ==2)
        {
            cout<<"Enter priority: ";
            cin>>tasks[index].numb;
        }
        else if(change ==3)
        {
            cin.ignore();
            const int N2=20;
            char n2[N2];
            cout<<"Enter description: ";
            cin.getline(n2,N2);
            delete[] tasks[index].description;
            tasks[index].description=new char[strlen(n2)+1];
            strcpy(tasks[index].description,n2);
            cout<<"New description!"<<endl;
        }
        else if(change ==4)
        {
            cout<<"Enter Date(day, month, year): ";
            cin>>tasks[index].day;
            cin>>tasks[index].month;
            cin>>tasks[index].year;
            cout<<"New date!"<<endl;
        }
        else if(change ==5)
        {
            cout<<"Enter posted time: ";
            cin>>tasks[index].time;
            cout<<"New time posted!"<<endl;
        }
        else
        {
            cout<<"Invalid number, try again!"<<endl;
        }
    }
}
void searchTaskByName(const Task* tasks, uint size )
{
    
}
void searchTaskByPriority(const Task* tasks, uint size )
{
    
}
void searchTaskByDescription(const Task* tasks, uint size )
{
    
}
void searchTaskByDateAndTime(const Task* tasks, uint size)
{
    
}
void showTaskForDay(const Task& std )
{
    
}
void showTaskForWeek(const Task& std )
{
    
}
void showTaskForMonth(const Task& std )
{
    
}
void sortingTaskByPriority(int )
{
    
}
void sortingTaskByDateAndTime(int )
{
    
}
void clearTask(Task*& tasks, uint& size )
{
    for(uint i=0;i<size;i++)
    {
        freeTaskMemory(tasks[i]);
    }
    delete[] tasks;
}
void callFunction(Task*& tasks, uint& size)
{
    
}
