/*
 * =====================================================================================
 *
 *       Filename:  TaskList.cpp
 *
 *    Description:  implementation file for TaskList
 *
 *        Version:  1.0
 *        Created:  02/06/2015 09:21:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iomanip>
#include <fstream>
#include "TaskList.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


TaskList::TaskList()
{
    size = 0;
}

TaskList::TaskList(const char fileName[])
{       
    size = 0;
    loadTaskList(fileName);
}

void TaskList::loadTaskList(const char fileName[])
{
    ifstream in;
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];
    Task aTask;
    in.open(fileName);

    if(!in)
    {
        in.clear();
        cout << "\nFailed to open" << fileName << endl;
        return;
    }

    in.get(course, MAX_CHAR, ';');
    while(!in.eof())
    {
        in.get();       //remove field seperator
        in.get(des, MAX_CHAR, ';');
        in.ignore(100, ';'); //ignore field sep

        in.get(dueDate, MAX_CHAR, '\n');
        in.ignore(100, '\n');
      
        aTask.setCourse(course);
        aTask.setDes(des);
        aTask.setDueDate(dueDate);

        addTask(aTask);

        //start next recrd
        in.get(course, MAX_CHAR, ';');
    }
    in.close();
}

//this function returns list size
int TaskList::getSize() const
{
    return size;
}
//return a task from the specific location index
//in: index
//out: aTask
bool TaskList::get(int index, Task &aTask) const
{
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];

    if (index < 0 || index >= size)
        return false;


    list[index].getCourse(course);
    list[index].getDes(des);
    list[index].getDueDate(dueDate);
    return true;
}

//returns a list of entries that match the input course name
bool TaskList::searchCourse(const char course[], TaskList &matches) const
{
    //int matchNum = 0;
    int index;
    Task aTask;
    char currentCourse[MAX_CHAR];
    char currentDes[MAX_CHAR];
    char currentDueDate[MAX_CHAR];
    bool found = 0; 
    
    for (index = 0; index < size; index++)
    {
        list[index].getCourse(currentCourse);
        list[index].getDes(currentDes);
        list[index].getDueDate(currentDueDate);
        
        if(strcmp(course, currentCourse) == 0)
        {
            aTask.setCourse(currentCourse);
            aTask.setDes(currentDes);
            aTask.setDueDate(currentDueDate);
            matches.addTask(aTask);
            found = true;
        }
    }
    if (!found)
        return false;
    else
        return true;
}

//prints all the entries to stdout
void TaskList::printAll() const
{
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];
    
    for (int i = 0; i < size; i++)
    {
        cout << " " << "Course: ";
        list[i].getCourse(course);
        cout << course << '\n';
        cout << "\tDue Date: ";
        list[i].getDueDate(dueDate);
        cout << dueDate << "\n\tDescription: ";
        list[i].getDes(des);
        cout << des << "\n";
    }
}

//write the DB file
void TaskList::saveList(const char fileName[]) const
{
    ofstream out;
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];

    out.open(fileName);
    if(!out)
    {
        out.clear();
        cout << "Error opening output";
        return;
    }

    for(int i = 0; i < size; i++)
    {
        list[i].getCourse(course);
        list[i].getDes(des);
        list[i].getDueDate(dueDate);
        out << course << ";";
        out << des << ";";
        out << dueDate << "\n";
    }
    out.close();
}

//this adds enteries and it is cool
void TaskList::addTask(Task &toAdd)
{
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];
    
    toAdd.getCourse(course);
    toAdd.getDes(des);
    toAdd.getDueDate(dueDate);
    list[size].setCourse(course);
    list[size].setDes(des);
    list[size].setDueDate(dueDate);
    
    size++;
}
