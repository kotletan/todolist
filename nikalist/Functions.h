#pragma once
Task createTask()
{
    cin.ignore();
    Task std{};
//    static uint numb=1;
//    std.numb=numb++;
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
void addTask(Task*& tasks, uint& size)
{
    
}
void resizeArray (Task*& tasks, uint& size)
{
    
}
void deleteTask(Task*& tasks, uint& size )
{
    
}
void freeTaskMemory(Task& task) {
    delete[] task.name;
    delete[] task.description;
}
void changeTask(int )
{
    
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
    
}
void callFunction(Task*& tasks, uint& size)
{
    
}
