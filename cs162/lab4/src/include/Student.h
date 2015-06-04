/*
 * =====================================================================================
 *
 *       Filename:  Student.h
 *
 *    Description:  Header file for student class
 *
 *        Version:  1.0
 *        Created:  02/08/2015 04:25:05 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *
 *   Organization: PCC CS162 
 *
 * =====================================================================================
 */
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;
const int MAX_CHAR = 100;

struct Student
{       
    char id[MAX_CHAR];
    float gpa;
};
#endif
