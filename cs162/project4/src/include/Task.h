/*
 * =====================================================================================
 *
 *       Filename:  Task.h
 *
 *    Description:  Header file for task class
 *
 *        Version:  1.0
 *        Created:  02/20/2015 01:45:27 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC CS162
 *
 * =====================================================================================
 */
#ifndef TASK_H
#define TASK_H

const int MAX_CHAR = 100;
class Task
{
public:
    //constructors
    Task();
    Task(const char course[], const char des[], const char dueDate[]);

    //destructor
    ~Task();

    //access functions
    void getCourse(char course[]) const;
    void getDes(char des[]) const;
    void getDueDate(char dueDate[]) const;
    void print() const;

    //mutator functions
    void setCourse(const char course[]);
    void setDes(const char des[]);
    void setDueDate(const char dueDate[]);

private:
    char* course;
    char* des;
    char* dueDate;
};
#endif
