/*
 * =====================================================================================
 *
 *       Filename:  Lab4.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/08/2015 04:46:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
/*
* =====================================================================================
*
* Filename: project3.cpp
*
* Description: user file for project3 task tracker
*
* Version: 1.0
* Created: 02/06/2015 11:57:16 AM
* Revision: none
* Compiler: gcc
*
* Author: Jonathon Sonesen
* Organization: PCC
*
* =====================================================================================
*/
#include <iostream>
#include <cstring>
#include "Student.h"
#include "StudentList.h"
#include "UserInput.h"
using namespace std;
//UI Functions
void menuOut();
char userIn();
void runUserIn(char userIn, StudentList& list);
void get(Student& aStudent);
void inCourse(char course[]);
int main()
{
    char choice;
    char fileName[MAX_CHAR] = "students.txt";
    StudentList Slist(fileName);
    menuOut();
    choice = userIn();
    while (choice != 'q')
    {
        runUserIn(choice, Slist);
        menuOut();
        choice = userIn();
    }
    return 0;
}
//Displays the main menu
void menuOut()
{
    cout << "Welcome to the Student List Manager!\n";
    cout << "\t(A):add entry\n";
    cout << "\t(L):list of Students\n";
    cout << "\t(S):search by Student ID\n";
    cout << "\t(R):removeStudent\n";
    cout << "\t(Q):exit program\n";
}
//reads user input
char userIn()
{
    char in;
    in = getChar("Please enter your choice:");
    return in;
}
//actually runs the command
void runUserIn(char userIn, StudentList& list)
{
    Student entry;
    Student match;
    char thisid[MAX_CHAR] = "G123456789";
    switch (userIn)
    {
    case 'a':
        //  getNewTask(entry);
        // list.addTask(entry);
        break;
    case 'l':
        list.printAll();
        break;
    case 'r':
        list.remove(thisid, match);
        break;
    case 's':
 
        list.search(thisid, match);
        cout << match.id << match.gpa;
        break;
    default:
        cout << "Illegal option!\n";
        break;
    }
}
//gets the course name for searching
void inCourse(char course[])
{
    getString("Please enter the course to searc by: ", course, MAX_CHAR);

}
