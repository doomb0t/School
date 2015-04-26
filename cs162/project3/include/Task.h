/*
 * =====================================================================================
 *
 *       Filename:  Task.h
 *
 *    Description:  header file for Task Class
 *
 *        Version:  1.0
 *        Created:  02/06/2015 08:52:32 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen, 
 *   Organization:  PCC
 *
 * =====================================================================================
 */

#ifndef TASK
#define TASK

using namespace std;

const int MAX_CHAR = 100;

class Task
{
 public:
     //constructor
     Task();
     Task(const char course[],const char des[], const char dueDate[]);

     //access
     void getCourse(char course[]) const;
     void getDes(char des[]) const;
     void getDueDate(char dueDate[]) const;
     void print() const;
  
     //mutator
     void setCourse(const char course[]);
     void setDes(const char des[]);
     void setDueDate(const char dueDate[]);

private:
     char course[MAX_CHAR];
     char des[MAX_CHAR];
     char dueDate[MAX_CHAR];
};

#endif
