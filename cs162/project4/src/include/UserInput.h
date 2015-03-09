/*
 * =====================================================================================
 *
 *       Filename:  UserInput.h
 *
 *    Description: header file for standard user input
 *
 *        Version:  1.0
 *        Created:  02/20/2015 12:00:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: Jonathon Sonesen 
 *   Organization:  PCC CS162
 *
 * =====================================================================================
 */
#ifndef USER_INPUT_H
#define USER_INPUT_H 

//proto types
int getInt(const char prompt[]);
double getDouble(const char prompt[]);
char getChar(const char prompt[]);
void getString(const char prompt[], char inStr[], int maxChar);

#endif

