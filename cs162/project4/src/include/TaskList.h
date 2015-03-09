/*
 * =====================================================================================
 *
 *       Filename:  TaskList.h
 *
 *    Description:  Header file for tasklist class
 *
 *        Version:  1.0
 *        Created:  02/20/2015 01:52:27 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC CS162
 *
 * =====================================================================================
 */

#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"
const int LIST_CAPACITY = 101;
const int COURSE_COL_WIDTH = 10;
const int DES_COL_WIDTH = 40;
const int DUE_DATE_WIDTH= 12;
class TaskList
{
public:
    //constructors
    TaskList();
    TaskList(int initCapacity, const char fileName[]);

    //destructor
    ~TaskList();

    //access functions
    bool get(int index, Task& aTask) const;
    bool searchEntry(const char course[], TaskList& matches) const;
    int getSize() const;
    void printAll() const;
    void saveDB(const char fileName[]) const;

    //mutator functions
    void addTask(const Task& aTask);
    void loadTaskList(const char fileName[]);

private:
    Task * list;
    int    size;
    int    capacity;

    void expandList();
};

#endif
