// Project: Task manager (CLI based)
// Starting date: 10/02/2025
// Deadline: 17/02/2025

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class task
{
    public:
    int id;
    int priority;
    string due_date;
    string title;
    bool completed;

    void display();

    task(int taskid, string tasktitle, string taskduedate, int taskpriority) : id(taskid), title(tasktitle), due_date(taskduedate),priority(taskpriority), completed(false){};
};
class task_manager
{
    private:
        vector<task> tasks;
        int nextid = 0;
    public:
        void add_task();
        void view_task();
        void delete_task();
        void task_done();
        void save();
        void load();


};
void task_manager :: add_task()
{
    string title, dd;
    int priority;
    cin.ignore();
    cout << "Enter task title: ";
    getline(cin, title);
    cout << "Enter due-date (dd-mm-yyyy): ";
    getline(cin, dd);
    cout << "Enter task priority (high = 1, medium = 2, low = 3): ";
    cin >> priority;
    while (priority < 1 || priority > 3)
    {
        cout << "Invalid input! please enter the value between 1 and 3: ";
        cin >> priority;
    }
    cin.ignore();
    task newT(nextid++, title, dd, priority);
    tasks.push_back(newT);
}

int main()
{   

    return 0;
}