/*
 * =====================================================================================
 *
 *       Filename:  TaskList.cpp
 *
 *    Description:Implementation file for tasklist class  
 *
 *        Version:  1.0
 *        Created:  02/20/2015 02:18:39 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC CS162
 *
 * =====================================================================================
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "TaskList.h"
using namespace std;

//Default constructor initializer make an empty list
TaskList::TaskList()
{
    capacity = LIST_CAPACITY;
    list = new Task[capacity];
    size = 0;
}

//Initialize from database
TaskList::TaskList(int initCapacity, const char fileName[])
{
    capacity = initCapacity;
    list = new Task[capacity];
    size = 0;
    loadTaskList(fileName);
}

//Destructor to release dynamically allocated mem
TaskList::~TaskList()
{
    if(list != NULL)
        delete [] list;
}

//Read files fom given file into tasklist
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
        cerr << "\n" << "Failed to open " << fileName << " for input" << "\n\n";
        return;
    }

    in.get(course, MAX_CHAR, ';');
    while(!in.eof())
    {
        in.get();
        in.get(des, MAX_CHAR, ';');
        in.ignore(100, ';');
        in.get(dueDate,MAX_CHAR,'\n');
        in.ignore(100,'\n');
        
        aTask.setCourse(course);
        aTask.setDes(des);
        aTask.setDueDate(dueDate);
        addTask(aTask);
        
        in.get(course, MAX_CHAR, ';');
    }
    in.close();
}

//Return List list
int TaskList::getSize() const
{
    return size;
}

//Returns entry at position within in parm: index, returns out: atask
bool TaskList::get(int index, Task& aTask) const
{
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];

    if(index < 0 || index >size)
        return false;

    list[index].getCourse(course);
    list[index].getDes(des);
    list[index].getDueDate(dueDate);
    aTask.setCourse(course);
    aTask.setDes(des);
    aTask.setDueDate(dueDate);
    return true;
}

//Search list for an entry with in parm: course, return match with out parm: match
bool TaskList::searchEntry(const char course[], TaskList &matches) const
{
    int index;
    Task aTask;
    bool found = 0;
    char currentCourse[MAX_CHAR];
    char currentDes[MAX_CHAR];
    char currentDueDate[MAX_CHAR];
   
    for(index = 0; index < size; index++)
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
    
    if(!found)
        return false;
    else
        return true;
}

//Prints all tasks in list to standard out
void TaskList::printAll() const
{
    int index;
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];
    cout << setw(COURSE_COL_WIDTH) << "Course";
    cout << setw(DES_COL_WIDTH) << "Description";
    cout << setw(DUE_DATE_WIDTH) << "Due Date" << endl;
    for(index = 0; index < size; index++)
    {
        list[index].getCourse(course);
        list[index].getDes(des);
        list[index].getDueDate(dueDate);
        cout << setw(COURSE_COL_WIDTH) << course;
        cout << setw(DES_COL_WIDTH) << des;
        cout << setw(DUE_DATE_WIDTH) << dueDate << endl;
    }
}

//Write database file
void TaskList::saveDB(const char fileName[]) const
{
    ofstream out;
    int index;
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];
    out.open(fileName);
    if(!out)
    {
        out.clear();
        cerr << "Failed to open" << fileName;
        return;
    } 
    for(index = 0; index < size; index++)
    {
        list[index].getCourse(course);
        list[index].getDes(des);
        list[index].getDueDate(dueDate);

        out << course << ';' << des << ';' <<  dueDate << '\n';
    }
    out.close();
}

//Adds an entry to the task list 
void TaskList::addTask(const Task &aTask)
{
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];

    if (size == capacity)
    {
        expandList();
    }
    aTask.getCourse(course);
    aTask.getDes(des);
    aTask.getDueDate(dueDate);
    list[size].setCourse(course);
    list[size].setDes(des);
    list[size].setDueDate(dueDate);
    size++;
}

//creates a new, larger array and copies contents ofsmall to it
void TaskList::expandList()
{
    Task * tempList;
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];
    int index;

    //new array
    capacity *= 2;
    tempList = new Task[capacity];

    for(index = 0; index < size; index++)
    {
        list[index].getCourse(course);
        list[index].getDes(des);
        list[index].getDueDate(dueDate);
        tempList[index].setCourse(course);
        tempList[index].setDes(des);
        tempList[index].setDueDate(dueDate);
    }

    delete [] list;

    //Make pointer to new array!
    list = tempList;
    tempList = NULL;
}


