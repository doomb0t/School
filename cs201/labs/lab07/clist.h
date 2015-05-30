/*
 * =====================================================================================
 *
 *       Filename:  clist.h
 *
 *    Description:  function protoypes for lab07 circularly linked list 
 *
 *        Version:  1.0
 *        Created:  05/29/2015 10:32:04 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC CS201
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstring>
#include <cctype>

struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node*& head);  //supplied
void display(node* head);  //supplied
void destroy(node*& head); //supplied
void duplicate(node*& new_copy); //provides a duplicate copy of the list

/* *****************YOUR TURN! ******************************** */
//Write your function prototype(s) here:
int count(node* head);
int countR(node* head);
int sum(node* head);
int sumR(node * head);
int getdata(node * link);

