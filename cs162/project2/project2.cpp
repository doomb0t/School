/* CS162 Task Manager Program
 * Written By: Jonathon Sonesen
 *
 * This program tracks assignments
 **/
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

const int MAX_CHAR = 100;
const int MAX_TASK = 100;

//struct def
struct tasks
{
	char course[MAX_CHAR];
	char description[MAX_CHAR];
	char dueDate[MAX_CHAR];
}

//prototypes
void add_task(tasks list[]);
void edit_tasks(tasks list[]);
void remove_task(tasks list[]);
void load_DB(tasks list[]);
void write_DB();
void menu();
void showAll(tasks list[]);
void course_Search(tasks list[]);
void date_Search(tasks list[]);
void desc_Search(tasks list[]);

int main()
{	
	//declare struct array for editiing tasks
	tasks toDo[MAX_TASK];
//	load_DB(toDo[MAX_TASK]);
	addTask(toDo[]);
	write_DB();
	cin.get();
	return 0;

}

/*void load_DB(tasks list[])
{
	ifstream fileIn;
	fileIn.open("tasks.txt");

	while (!fileIn.eof())
	{
		for(int i = 0; i < MAX_TASK; i++)
		{
			fileIn.get(list[i].course, MAX_CHAR, "\n");
		}
		for(int i = 0; i < MAX_TASK; i++)
		{
			fileIn.get(list[i].description, MAX_CHAR, "\n");
		}
		for(int i = 0; i < MAX_TASK; i++)
		{
			fileIn.get(list[i].date, MAX_CHAR, "\n");
		}
	}
	fileIn.clear();
	fileIn.close();
	return;
}*/

void add_Task(tasks list[])
{
	cout << "Please enter the course name:";
	cin >> list[0].course;
	cout << "\nPlease enter the description(100 char max):";
	cin >> list[0].description;
	cout << "\nPlease enter the due date:";
	cin >> list[0].dueDate;
	return;
}
void write_DB(tasks list[])
{
	ofstream fileOut;
	fileOut.open("tasks.txt");
	for(int i = 0; i < MAX_TASK; i++)
	{
		fileOut << list[i].course << list[i].description << list[i].dueDate;
	}
	return;
}
void desc_search()
{
	return;
}
