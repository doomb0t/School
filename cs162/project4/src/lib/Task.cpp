/*
 * =====================================================================================
 *
 *       Filename:  Task.cpp
 *
 *    Description:  Implementation file for Task class
 *
 *        Version:  1.0
 *        Created:  02/20/2015 02:16:52 AM
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
#include <cstring>
#include "Task.h"
using namespace std;

//Default const.
Task::Task()
{
    course = new char[strlen("empty") + 1];
    strcpy(course, "empty");
    des = new char[strlen("empty") + 1];
    strcpy(des, "empty");
    dueDate = new char[strlen("empty") + 1];
    strcpy(dueDate, "empty");
}

//Constructor to intialize based on parameters
Task::Task(const char course[], const char des[], const char dueDate[])
{
    this -> course = new char[strlen(course) + 1];
    strcpy(this->course, course);
    this -> des = new char[strlen(des) + 1];
    strcpy(this->des, des);
    this -> dueDate = new char [strlen(dueDate) + 1];
    strcpy(this->dueDate, dueDate);
}

//Destructor to release dynamic memory allocated
Task::~Task()
{
    if(course!=NULL)
        delete [] course;
    if(des!=NULL)
        delete [] des;
    if(dueDate!=NULL)
        delete [] dueDate;
}

//Return the course name through parm out: course
void Task::getCourse(char course[]) const
{
    strcpy(course, this->course);
}

//Return description through parm out:des
void Task::getDes(char des[]) const
{
    strcpy(des,this->des);
}

void Task::getDueDate(char dueDate[]) const
{
    strcpy(dueDate, this->dueDate);
}

//Print out the task
void Task::print() const
{
    cout << course << ":\n" << des << "\n\n";
}

//Set course name to input parm: course
void Task::setCourse(const char course[])
{
    if (this->course != NULL)
        delete [] this -> course;
    this -> course = new char[strlen(course)+1];
    strcpy(this->course,course);
}

//Set description with in parm: des
void Task::setDes(const char des[])
{
    if(this->des != NULL)
        delete [] this->des;
    this->des = new char[strlen(des)+1];
    strcpy(this->des,des);
}

void Task::setDueDate(const char dueDate[])
{
    if(this->dueDate != NULL)
        delete [] this->dueDate;
    this->dueDate = new char[strlen(dueDate) + 1];
    strcpy(this->dueDate,dueDate);
}
