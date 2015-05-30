#include <iostream>
#include <iomanip>
#include "clist.h"

#pragma GCC diagnostic ignored "-Wunused-variable"

using namespace std;

int main()
{
	node * head = NULL;
    node * copy = NULL;
    build(head);
    display(head);
	cout << endl;

	cout << "# of nodes:   " << setw(4) <<  count(head) << endl;
	cout << "sum of nodes: " << setw(4) <<    sum(head) << endl;
	cout << "# of nodes:   " << setw(4) << countR(head) << endl;
	cout << "sum of nodes: " << setw(4) <<   sumR(head) << endl;

    display(head); //resulting list after your function call!

    destroy(head); //deallocate nodes

	/*
    //If your question needs a second copy of the list, 
    //you can make one by calling the duplicate function:
    cout <<"Here is a duplicate list: ";
    duplicate(copy);
    display(copy);
	*/
    
    return 0;
}
