/*
=====================================================================================================================
file  : Task_4.cpp
brief : simple console-based to-do list manager that allows users to add, view, and delete tasks
author: hana maged mohamed
date  : September 23, 2023
=====================================================================================================================
*/
#include <iostream>
#include <string>

using namespace std;
/*creating the TO-DO List by using doubly linked lists*/
class to_do_list
{
private:
    int task_total;
    struct todo
    {
        int idx;
        string note;
        todo *next;
        todo *previous;
    };
    todo *first;
    todo *current;

public:
    to_do_list();
    void add_tasks();
    void view_tasks();
    void mark_pendingtasks();
    void mark_donetasks();
    void delete_tasks();
};
/*constructor function for initialization*/
to_do_list ::to_do_list()
{
    first = NULL;
    current = NULL;
    task_total = 0;
}
/*function to add tasks*/
void to_do_list ::add_tasks()
{
    string task;
    cout << "\t\t\t\t Enter the task: ";
    cin.ignore();
    getline(cin, task);
    todo *add = new todo;
    if (first == NULL)
    {
        first = add;
        current = add;
        add->previous = 0;
        add->next = 0;
        add->note = task;
    }
    else
    {
        current = first;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = add;
        add->next = 0;
        add->previous = current;
        add->note = task;
    }
    ++task_total;
}
/*function to view tasks*/
void to_do_list ::view_tasks()
{
    if (task_total == 0)
    {
        cout << "\t\t\t\t Empty to-do list! \n\n";
    }
    else
    {
        current = first;
        cout << "\t\t ============================================================================\n\n";
        cout << "\t\t Today's TO-DO List\n";
        cout << "\t\t ------------------\n\n";
        for (int i = 0; i < task_total; ++i)
        {
            cout << "\t\t" << i + 1 << ". " << current->note << "\n\n";
            current = current->next;
        }
        cout << "\t\t ============================================================================\n\n";
        cout << "\n\n";
    }
}
/*function to mark a task as pending*/
void to_do_list ::mark_pendingtasks()
{
    int task_idx;
    cout << "\t\t\t\t Enter the task index to mark as pending: ";
    cin >> task_idx;
    task_idx--;
    current = first;
    for (int i = 0; i < task_idx; ++i)
    {
        current = current->next;
    }
    current->note += " (Pending)";
}
/*function to mark a task as done*/
void to_do_list ::mark_donetasks()
{
    int task_idx;
    cout << "\t\t\t\t Enter the task index to mark as done: ";
    cin >> task_idx;
    task_idx--;
    current = first;
    for (int i = 0; i < task_idx; ++i)
    {
        current = current->next;
    }
    current->note += " (Done)";
}
/*function to delete tasks*/
void to_do_list::delete_tasks()
{
    int task_idx;
    cout << "\t\t\t\t Enter the task index to be deleted: ";
    cin >> task_idx;
    task_idx--;

    if (task_total == 0)
    {
        cout << "\t\t\t\t No tasks to be deleted!\n";
    }
    else if (task_idx == 0)
    {
        first = first->next;
        if (first != NULL)
        {
            first->previous = NULL;
        }
        --task_total;
    }
    else if (task_idx >= task_total)
    {
        cout << "\t\t\t\t Invalid task index!\n";
    }
    else
    {
        current = first;
        for (int i = 0; i < task_idx; ++i)
        {
            current = current->next;
        }
        current->previous->next = current->next;
        if (current->next != NULL)
        {
            current->next->previous = current->previous;
        }
        delete current;
        --task_total;
    }
}
int main()
{
    to_do_list my_list /*creating the TO-DO List object*/;
    int option;
    bool exit = false;
    cout << "\n\n";
    cout << "\t\t\t\t ******************************** \n\n";
    cout << "\t\t\t\t     TO-DO LIST Application \n\n";
    cout << "\t\t\t\t ******************************** \n\n";
    cout << "\t\t\t\t Welcome to your TO-DO List! \n\n";
    cout << "\t\t\t\t Here's the TO-DO list options: \n";
    while (1)
    {
        cout << "\t\t\t\t 1] Add a task.\n";
        cout << "\t\t\t\t 2] View your tasks. \n";
        cout << "\t\t\t\t 3] Mark a task as pending. \n";
        cout << "\t\t\t\t 4] Mark a task as done. \n";
        cout << "\t\t\t\t 5] Delete a task. \n";
        cout << "\t\t\t\t 6] Exit TO-DO List. \n\n";
        cout << "\t\t\t\t Press an option: ";
        cin >> option;
        cout << "\n\n";
        switch (option)
        {
        case 1:
            my_list.add_tasks();
            break;
        case 2:
            my_list.view_tasks();
            break;
        case 3:
            my_list.mark_pendingtasks();
            break;
        case 4:
            my_list.mark_donetasks();
            break;
        case 5:
            my_list.delete_tasks();
            break;
        case 6:
            exit = true;
            break;
        default:
            cout << "\t\t\t\t INVALID OPTION! \n";
        }
        if (exit == true)
        {
            cout << "\t\t\t\t Thank you for using our TO-DO List application, feel free to return whenever you have new tasks! \n";
            break;
        }
    }

    return 0;
}