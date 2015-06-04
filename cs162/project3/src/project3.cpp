/*
 * =====================================================================================
 *
 *       Filename:  project3.cpp
 *
 *    Description:  user file for project3 task tracker
 *
 *        Version:  1.0
 *        Created:  02/06/2015 11:57:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: Jonathon Sonesen
 *   Organization:  PCC CS162
 *
 * =====================================================================================
 */
#include <iostream>
#include <cctype>

#include "Task.h"
#include "TaskList.h"
#include "UserInput.h"

using namespace std;

//UI Functions
void menuOut();
char userIn();
void runUserIn(char userIn, TaskList& list);
void getNewTask(Task& aTask);
void inCourse(char course[]);

int main()
{   
    //variables for user input and class
    char choice;
    char fileName[] = "tasks.txt";  
    TaskList list(fileName);

    //dipsplay menu, execute choices
    menuOut();
    choice = userIn();
    while(choice != 'q')
    {
        runUserIn(choice, list);
        menuOut();
        choice = userIn();
    }
    //save database
    list.saveList(fileName);
    return 0;

}

//Displays the main menu
void menuOut()
{  
    cout << "Welcome to the Task Manager!\n";
    cout << "\t(A):add entry\n";
    cout << "\t(L):list of tasks\n";
    cout << "\t(S):search by course\n";
    cout << "\t(Q):exit program\n";
}

//reads user input
char userIn()
{
    char in;
    in = getChar("Please enter your choice:");
 
    return in;
}

//actually  runs the command
void runUserIn(char userIn, TaskList& list)
{       
    Task entry;
    TaskList matches;    
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];

    //control list for executing user input
    switch (userIn)
    {
    case 'a':
    getNewTask(entry);
    list.addTask(entry);
    break;
    case 'l':
        list.printAll();
        break;
    case 's':
        inCourse(course);

        if(list.searchCourse(course, matches))
        {
            matches.printAll();
        }else
        {
            cout << "No tasks match that course\n";
        }
        break;
    default:
        cout << "Illegal option!\n";
        break; 
    }
}

//this will read int the user manipulated task entry
void getNewTask(Task& aTask)
{
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];
    
    getString("Please enter the course:", course, MAX_CHAR);
    getString("Please enter the Description:", des, MAX_CHAR);
    getString("Please enter the Due Date:", dueDate, MAX_CHAR);

    aTask.setCourse(course);
    aTask.setDes(des);
    aTask.setDueDate(dueDate);
}

//gets the course name for searching
void inCourse(char course[])
{
    getString("Please enter the course to searc by: ", course, MAX_CHAR);
}
