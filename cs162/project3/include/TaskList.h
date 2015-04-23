/*
 * =====================================================================================
 *
 *       Filename:  TaskList.h
 *
 *    Description:  header file for TaskList class
 *
 *        Version:  1.0
 *        Created:  02/06/2015 08:44:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC
 *
 * =====================================================================================
 */
#ifndef TASK_LIST_H
#define TASK_LIST_H

#include "Task.h"

using namespace std;

const int MAX_TASK = 100;

class TaskList
{
public:
    //constructers
    TaskList();
    TaskList(const char fileName[]);

    //accessor
    bool get(int index, Task &aTask) const;
    bool searchCourse(const char course[], TaskList &matches) const;
    int getSize() const;
    void printAll() const;
    void saveList(const char fileName[]) const;

    //mutator
    void addTask(Task &toAdd);
    void removeTask(char course[], char des[], char dueDate);
    void loadTaskList(const char fileName[]);

private:
    Task list[MAX_TASK];
    int size;
};

#endif

