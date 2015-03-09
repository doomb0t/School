/*
 * =====================================================================================
 *
 *       Filename:  lab5.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/20/2015 11:44:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

struct Student
{
    char * name;
    float gpa;
};

Student ** createStudentList(char ** names, int size);
bool destroyStudentList(Student ** studentList, int size);
Student * createStudent(const char name[], float gpa);
bool destroyStudent(Student * &aStudent);

int main()
{
    float gpa = 3.5;
    Student * aStudent = createStudent("jon",gpa);
  //  cout << aStudent.name << " " << aStudent.gpa << '\n';
    destroyStudent(aStudent);
    return 0;
}

Student * createStudent(const char name[], float gpa)
{       
    Student *aStudent;
    aStudent = new Student;   
    aStudent->name= new char[strlen(name) + 1];
    strcpy(aStudent->name, name);
    
    aStudent->gpa = gpa;
    
    cout << aStudent->name << " " << aStudent->gpa << '\n';
    return aStudent;
}

bool destroyStudent(Student * &aStudent)
{
    if(aStudent->name != NULL)
    {   
        delete [] aStudent->name;
        delete aStudent;
    }
    return false;
}

Student ** createStudentList(char ** names, int size)
{

}


