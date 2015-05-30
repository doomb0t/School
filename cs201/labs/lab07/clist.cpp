/*
 * =====================================================================================
 *
 *       Filename:  clist.cpp
 *
 *    Description:  functions for lab07 circularly linked list 
 *
 *        Version:  1.0
 *        Created:  05/29/2015 10:32:04 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  
 *
 * =====================================================================================
 */
#include "clist.h"

//iterative counting action
int count(node* head)
{
    int count = 0;
    node* current = head;
    while (current->next != head) {
        count++;
        if(current->next == NULL)
            current = head;
        else
            current = current->next;
        }
    return count;
}

//recursive counting action
int countR(node* head)
{
    int count = 0;
    if(head == NULL)
        return 0;
    return count + countR(head->next);
}

//iterative summation
int sum(node* head)
{
    int sum = 0;
    node* current = head;
    while (current != head) {
        sum += getdata(current);
        if(current->next == NULL)
            current = head;
        current = current->next;
        }
    return sum;
}

//recursive summation
int sumR(node * head)
{
    int count = 0;
    if(head == NULL)
        return 0;
    return count + countR(head->next);
}

//get integer from list
int getdata(node * link)
{
    return link->data;
}
