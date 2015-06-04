/*
 * =====================================================================================
 *
 *       Filename:  Task.cpp
 *
 *    Description:  implementation for Task.h
 *
 *        Version:  1.0
 *        Created:  02/06/2015 11:03:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC
 *
 * =====================================================================================
 */
#include "Task.h"
#include <iostream>
#include <cstring>
using namespace std;

//Default constructor
Task::Task()
{
   strcpy(course, "no course");
   strcpy(des, "no des");
   strcpy(dueDate, "no duedate");
}

//initialize from given data
Task::Task(const char course[], const char des[], const char dueDate[])
{

   strcpy(this->course,course);
   strcpy(this->des, des);
   strcpy(this->dueDate,dueDate);
}

//call course data
void Task::getCourse(char course[]) const
{
    strcpy(course, this->course);
}

//call description to input parameter
void Task::getDes(char des[]) const
{

   strcpy(des,this->des);
}

//call due date to input cstring
void Task::getDueDate(char dueDate[]) const
{ 
   strcpy(dueDate,this->dueDate);
}

//print out task data
void Task::print() const
{
    cout << course << " " << des << " " << dueDate << "\n";
}

//set the course name to that of the passed parameter
void Task::setCourse(const char course[])
{
    strcpy(this->course, course);
}

//set description to that off passed parameter
void Task::setDes(const char des[]) 
{
    strcpy(this->des, des);
}

//set due date to that of passed paramete
void Task::setDueDate(const char dueDate[])
{
    strcpy(this->dueDate, dueDate);
}
