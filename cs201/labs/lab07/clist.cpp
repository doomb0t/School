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
    if(head == NULL) return 0;

    int count = 1;
    node* current = head->next;

    while (current != head) {
        count++;
        current = current->next;
        }
    return count;
}

//recursive counting action
int countR(node* head)
{   
    if(head == NULL) return 0;
    return counthelp(head, head);
}

//iterative summation
int sum(node* head)
{
    if(head == NULL) return 0;

    int sum = getdata(head);
    node* current = head->next;

    while (current != head) {
        sum += getdata(current);
        current = current->next;
        }
    return sum;
}

//recursive summation
int sumR(node * head)
{
    if(head == NULL) return 0;
    return sumhelp(head, head);
}

//get integer from list
int getdata(node * link)
{
    return link->data;
}

int counthelp (node* head, node * current)
{
    if (current->next != head) {
        return 1 + counthelp (head, current->next);
    }
    return 1;
}

int sumhelp(node* head, node* current)
{
    if (current->next != head) {
        return getdata(current) + sumhelp (head, current->next);
    }
    return getdata(current);
}
