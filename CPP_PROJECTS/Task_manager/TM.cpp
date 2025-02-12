// Project: Task manager (CLI based)
// Starting date: 10/02/2025
// Deadline: 17/02/2025

#include<iostream>
#include<vector>
#include<string>
#include<limits>
#include<algorithm>
#include<fstream>
#include<sstream>

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
        int nextid = 1;
    public:
        void add_task();
        void view_task();
        void delete_task(int id);
        void task_done();
        void save();
        void load();


};
void task_manager :: add_task()
{   
    string title, dd;
    int priority;
    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter due-date: ";
    getline(cin, dd);

    cout << "Enter priority (high = 1, medium = 2, low = 3): ";
    while (!(cin >> priority) || priority < 1 || priority > 3)
    {
        cout << "Invalid input! enter the value between 1 and 3" << endl;
        cin.ignore();
    }
    cin.ignore();
    task newT(nextid++, title, dd, priority);
    tasks.push_back(newT);
    cout << "Task added successfully!" << endl;

}
void task_manager :: view_task()
{
    if (tasks.empty())
    {
        cout << "You have no task in the list!" << endl;
        return;
    }
    sort(tasks.begin(), tasks.end(), [](const task &a, const task &b){ return a.priority < b.priority; });
    cout << "\n************ Tasks ************" << endl;
    for(const auto &t : tasks)
    {
        cout << "ID: " << t.id << " | Title: " << t.title << " | Due-Date: " << t.due_date << " | Priority: ";
        switch(t.priority)
        {
            case 1: cout << "High"; break;
            case 2: cout << "Medium"; break;
            case 3: cout << "Low"; break;
        }
        cout << " | status: " << (t.completed ? "Completed" : "Pending") << endl;
    }
}
void task_manager :: task_done()
{
    int id;
    bool found;
    cout << "Enter id: ";
    cin >> id;

    for(task &t : tasks)
    {
        if (t.id == id)
        {
            if (t.completed)
            {
                cout << "Task is already completed!" << endl;
                break;
            }
            else
            {
                t.completed = true;
                cout << "Task is successfully marked as completed!" << endl;
            }
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Task of ID " << id << " is not found!" << endl;
    }
    
}
void task_manager :: delete_task(int id)
{
    auto it = remove_if(tasks.begin(), tasks.end(), [id](const task &t){return t.id == id;});
    if ( it != tasks.end())
    {
        tasks.erase(it, tasks.end());
        cout << "Tasks deleted successfully!" << endl;
    }
    else
    {
        cout << "Task with Id " << id << "is not found in the list" << endl;
    }
    
}
void task_manager :: save()
{
    ofstream file("tasks.txt");
    if (!file)
    {
        cout << "Error occured while opening the file!" << endl;
        return;
    }
    for(const task &t : tasks)
    {
        file << t.id << " | "
        << t.title << " | "
        << t.due_date << " | "
        << t.priority << " | "
        << t.completed << "\n";
    }
    file.close();
    cout << "Tasks saved on file successfully! " << endl;
}
void task_manager :: load()
{
    ifstream file("tasks.txt");
    if (!file)
    {
        cout << "No save tasks on file!" << endl;
        return;
    }
    tasks.clear();
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string idstr, title, dd, prioritystr, complestr;

        getline(ss, idstr, '|');
        getline(ss, title, '|');
        getline(ss, dd, '|');
        getline(ss, prioritystr, '|');
        getline(ss, complestr, '|');

        int id = stoi(idstr);
        int priority = stoi(prioritystr);
        bool completed = (complestr == "1");

        task loaded_task(id, title, dd, priority);
        loaded_task.completed = completed;
        tasks.push_back(loaded_task);

        if (id >= nextid)
        {
            nextid = id + 1;
        }
    }
    cout << "Task loaded successfully!" << endl;
}
int main()
{   
    task_manager me;
    me.load();
    me.view_task();

    return 0;
}