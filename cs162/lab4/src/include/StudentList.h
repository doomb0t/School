/*
 * =====================================================================================
 *
 *       Filename:  StudentList.h
 *
 *    Description:  Header file for student list class
 *
 *        Version:  1.0
 *        Created:  02/08/2015 04:33:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC CS162
 *
 * =====================================================================================
 */
#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include "Student.h"

const int MAX_STUDENT = 100;

class StudentList
{
public:
    //Constructors
    StudentList();
    StudentList(const char fileName[]);

    //accessor
    bool get(int index, Student &aStudent) const;
    int search(const char id[], Student& match) const;
    void printAll() const;
    //mutators
    void addStudent(Student &toAdd);
    bool remove(const char id[], Student& aStudent);
    void loadStudentList(const char fileName[]);
private:
    Student     list[MAX_CHAR];
    int         size;
};
#endif

