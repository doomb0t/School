/*
 * =====================================================================================
 *
 *       Filename:  StudentList.cpp
 *
 *    Description: object file lab4 studentlist 
 *
 *        Version:  1.0
 *        Created:  02/08/2015 04:46:12 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: Jonathon Sonesen
 *
 *   Organization:  PCC CS162
 *
 * =====================================================================================
 */
#include <fstream>
#include <iostream>
#include <cctype>
#include "StudentList.h"
#include<cstring>
using namespace std;

StudentList::StudentList()
{
    size = 0;
}

StudentList::StudentList(const char fileName[])
{
    size = 0;
    loadStudentList(fileName);
}
 
void StudentList::loadStudentList(const char fileName[])
{
    ifstream in;
    char id[MAX_CHAR];
    float gpa;
    Student aStudent;
    in.open(fileName);
    
    //clear stream if open faild and end function
    if(!in)
    {
        in.clear();
        cout << "Failes to open file";
        return;
    }

    in.get(aStudent.id, 100, ';');
        
        //go through end of file
        while(!in.eof())
        {
            in.ignore(100, ';');
            in >> aStudent.gpa;
            in.ignore(100, '\n');
            
            addStudent(aStudent);

            //start a new record
            in.get(id,MAX_CHAR, ';');
        }
        printAll();
    in.close();
} 

bool StudentList::get(int index, Student &aStudent) const
{

    if (index < 0 || index >= size)
        return false;

    list[index].id;
    list[index].gpa;
    return true;
}

int StudentList::search(const char id[], Student& match) const
{
    int index;
 
    for(index = 0; index < size; index++)
    {
        if (strcmp(id, list[index].id) == 0)
        { 
            cout << list[index].id << list[index].gpa;
            match = list[index];
            return index;
        }
        
    }
    cout << "nope";
    return -1;
}

bool StudentList::remove(const char id[], Student& aStudent)
{
    int index;
    if (search(id, aStudent) != -1)
    {
        index = search(id, aStudent);
        aStudent = list[index];

        for (int i = index; i < size; i++)
        {
            list[i] = list[i + 1];
        }
        
        return true;
    }
    return false;
}


//this adds enteries and it is cool
void StudentList::addStudent(Student &toAdd)
{

    list[size] = toAdd;
        size++;
}
// prints all the entries to stdout
void StudentList::printAll() const
{

    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << "ID: ";
        
        cout << list[i].id << '\n';
        cout << "\tGPA: ";
        cout << list[i].gpa << "\n";
    }
}
