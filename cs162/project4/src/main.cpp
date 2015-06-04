/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: user file for tasklist
 *
 *        Version:  1.0
 *        Created:  02/20/2015 12:38:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC CS162
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <iostream>
#include <cctype>

#include "Task.h"
#include "TaskList.h"
#include "UserInput.h"

using namespace std;

//UI function prototypes
void printMenu();
char readCommand();
void runCommand(char command, TaskList& list);
void readTask(Task& aTask);
void readCourse(char course[]);

int main()
{
    char command;
    char fileName[] = "tasks.txt";
    TaskList list(1, fileName);

    printMenu();
    command = readCommand();
   
    while(command != 'q')
    {
        runCommand(command, list);
        printMenu();
        command = readCommand();
    }
    list.saveDB(fileName);
    return 0;
}

void printMenu()
{
    cout << '\n' << "Welcome to you task list!\n\n";
    cout << "\ta: add a new task\n";
    cout << "\tl: show a list of your tasks\n";
    cout << "\ts: search a task by course name\n";
    cout << "\tq: exit the program\n";
}

char readCommand()
{
    char cmd;
    cmd = getChar("Please enter your choice(a,l.s,or q):");
    return tolower(cmd);
}

void runCommand(char command, TaskList& list)
{
    TaskList matches;
    Task aTask;
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];
    switch(command)
    {
    case 'a': readTask(aTask);
              list.addTask(aTask);
              break;
    case 'l': list.printAll();
              break;
    case 's': readCourse(course);
              if(list.searchEntry(course, matches))
              {
                  matches.printAll();   
              }
              else 
                  cout << "Sorry no results for " << course;
              break;
    default: cout << "\nIllegal command\n";
             break;
    }
}

void readTask(Task& aTask)
{
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];
    //get course and dscription
    getString("Please input course name:", course, MAX_CHAR);
    getString("Please input description:", des, MAX_CHAR);
    getString("Please input Due Date:", dueDate, MAX_CHAR);
    //set new task
    aTask.setCourse(course);
    aTask.setDes(des);
    aTask.setDueDate(dueDate);
}

void readCourse(char course[])
{
    getString("Please enter course name to search:", course, MAX_CHAR);
}
