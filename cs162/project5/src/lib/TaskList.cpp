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
#include "../include/TaskList.h"
using namespace std;

//Default constructor initializer make an empty list
TaskList::TaskList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

//Initialize from database
TaskList::TaskList(const char fileName[])
{
    head = NULL;
    tail = NULL;
    size = 0;
    loadTaskList(fileName);
}

//Destructor to release dynamically allocated mem
TaskList::~TaskList()
{
    Node * curr;
    while(head != NULL)
    {

        curr = head;
        head = head->next;
        delete curr;
    }
    tail = NULL;
    size = 0;
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
    Node * curr = head;
    for(int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    //Traverse the linked list
    curr->info.getCourse(course);
    curr->info.getDes(des);
    curr->info.getDueDate(dueDate);
    aTask.setCourse(course);
    aTask.setDes(des);
    aTask.setDueDate(dueDate);
    return true;
}

//Search list for an entry with in parm: course, return match with out parm: match
bool TaskList::searchEntry(const char course[], TaskList &matches) const
{
    Task aTask;
    Node * curr;
    char currentCourse[MAX_CHAR];
    char currentDes[MAX_CHAR];
    char currentDueDate[MAX_CHAR];
    bool found = 0;
    for(curr = head; curr != NULL; curr = curr->next)
    {
        curr->info.getCourse(currentCourse);
        curr->info.getDes(currentDes);
        curr->info.getDueDate(currentDueDate);
        
        if(strcmp(course, currentCourse) == 0)
        {
            aTask.setCourse(currentCourse);
            aTask.setDes(currentDes);
            aTask.setDueDate(currentDueDate);
            matches.addTask(aTask);
            found = 1;
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
    Node * curr;
    char course[MAX_CHAR];
    char des[MAX_CHAR];
    char dueDate[MAX_CHAR];
    cout << setw(COURSE_COL_WIDTH) << "Course";
    cout << setw(DES_COL_WIDTH) << "Description";
    cout << setw(DUE_DATE_WIDTH) << "Due Date" << endl;
    for(curr = head; curr != NULL; curr = curr->next)
    {
        curr->info.getCourse(course);
        curr->info.getDes(des);
        curr->info.getDueDate(dueDate);
        cout << setw(COURSE_COL_WIDTH) << course;
        cout << setw(DES_COL_WIDTH) << des;
        cout << setw(DUE_DATE_WIDTH) << dueDate << endl;
    }
}

//Write database file
void TaskList::saveDB(const char fileName[]) const
{
    Node * curr;
    ofstream out;
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
    for(curr = head; curr != NULL; curr = curr->next)
    {
        curr->info.getCourse(course);
        curr->info.getDes(des);
        curr->info.getDueDate(dueDate);

        out << course << ';' << des << ';' <<  dueDate << '\n';
    }
    out.close();
}

//Adds an entry to the task list 
void TaskList::addTask(const Task &aTask)
{
    bool found;
    Node * current;
    Node * trailCurrent;
    Node * newNode;
    char currentDes[MAX_CHAR];
    char checkDes[MAX_CHAR];
    newNode = new Node(aTask);
    newNode->next = NULL;

    //Case 1
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        size++;
    }
    else
    {
        current = head;
        found = false;
        
        while (current != NULL && !found)
        {
            newNode->info.getDes(checkDes);
            current->info.getDes(currentDes);
            if(strcmp(currentDes, checkDes) == 0)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->next;
            }
        }

        //Case 2
        if(current == head)
        {
            newNode->next = head;
            head = newNode;
            size++;
        }
        else
        {
            trailCurrent->next = newNode;
            newNode->next = current;

            if(current == NULL)
                tail = newNode;

            size++;
        }
    }
}
