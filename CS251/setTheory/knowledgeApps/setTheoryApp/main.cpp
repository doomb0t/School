/*
 * =====================================================================================
 *
 *       Filename:  setApp.cpp
 *
 *    Description:  Set Theory Knowledge App
 *
 *        Version:  1.0
 *        Created:  04/13/15 12:21:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC CS251
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <iterator>
#include <gmpxx.h>

using namespace std;

void splitLine(vector <string> &words, string currentLine, mpz_class limit);
mpz_class elementCount(string currentLine);
string intersection(vector <string> setA, vector <string> setB);
string unions(vector <string> setA, vector <string> setB);
string relative(vector <string> setA, vector <string> setB, int key);
string symmetric(vector <string> setA, vector <string> setB);
string crossProduct(vector <string> setA, vector <string> setB);
string powerSet(vector <string> setA, vector <string> setB);
bool inSet(string anElement, vector <string> aSet);

int main()
{
	//initializing variables
	mpz_class nValue = 0;
	string input;
	string s_setA, s_setB;
	vector <string> lineArray, v_setA, v_setB;
	
	cout << "Enter n: ";
	cin >> nValue;
	
	cin.ignore(100, '\n');

	cout << "Enter set A (separated by space): ";
	getline(cin, s_setA);
	cout << "Enter set B (separated by space): ";
	getline(cin, s_setB);

	if (elementCount(s_setA) >= nValue && elementCount(s_setB) >= nValue)
	{
		splitLine(v_setA, s_setA, nValue);
		splitLine(v_setB, s_setB, nValue);

		cout << intersection(v_setA, v_setB) << endl;
		cout << unions(v_setA, v_setB) << endl;
		cout << relative(v_setA, v_setB, 0) << endl;
		cout << relative(v_setB, v_setA, 1) << endl;
		cout << symmetric(v_setA, v_setB) << endl;
		cout << crossProduct(v_setA, v_setB) << endl;
		cout << powerSet(v_setA, v_setB) << endl;
	}
	else
	{
		cout << "Not enough elements entered. Bye!" << endl;
	}
}

//function to separate a line into words white space is the delimeter
void splitLine(vector <string> &words, string currentLine, mpz_class limit)
{
	istringstream ss(currentLine);
	istream_iterator<string> begin(ss), end;
	vector<string> arrayTokens(begin, end);
	
	for (size_t index = 0; index < limit; index++)
	{
		words.push_back(arrayTokens[index]);
        }
}

mpz_class elementCount(string currentLine){
	mpz_class temp=0;
	istringstream ss(currentLine);
	istream_iterator<string> begin(ss), end;
	vector<string> arrayTokens(begin, end);
	temp = arrayTokens.size();
	return temp;
}

bool inSet(string anElement, vector <string> aSet)
{
	bool ret = false;
	for (size_t index = 0; index < aSet.size(); index++)
	{
		if (anElement == aSet[index])
		{
			ret = true;
			break;
		}
	}
	return ret;
}

string intersection(vector <string> setA, vector <string> setB)
{
	string rString = "Intersection of A and B has ";
	mpz_class counter = 0;
	vector <string> foundElements;

	for (size_t i = 0; i < setA.size(); i++)
	{
		if (inSet(setA[i], setB))
		{
			foundElements.push_back(setA[i]);
			counter++;
		}
	}

	rString.append(counter.get_str() + " elements: ");

	if (counter > 0)
	{
		for (size_t index = 0; index < counter; index++)
		{
			rString.append(foundElements[index] + " ");
		}
	}
	return rString;
}

string unions(vector <string> setA, vector <string> setB)
{
	string rString = "Union of A and B has ";
	mpz_class counter = 0;
	vector <string> foundElements;

	foundElements = setA;
	counter = foundElements.size();
	for (size_t i = 0; i < setB.size(); i++)
	{
		if (!inSet(setB[i], setA))
		{		foundElements.push_back(setB[i]);
				counter++;
		}
	}


	rString.append(counter.get_str() + " elements: ");

	if (counter > 0)
	{
		for (size_t index = 0; index < counter; index++)
		{
			rString.append(foundElements[index] + " ");
		}
	}
	return rString;
}

string relative(vector <string> setA, vector <string> setB, int key)
{
	string rString = "Relative complement of A and B has ";
	mpz_class counter = 0;
	vector <string> foundElements;

	if (key == 1){
		rString = "Relative complement of B and A has ";
	}

	for (size_t i = 0; i < setA.size(); i++)
	{
		if (!inSet(setA[i], setB)) //function takes element and set terurns true or false
		{
			foundElements.push_back(setA[i]);
			counter++;
		}
	}

	rString.append(counter.get_str() + " elements: ");

	if (counter > 0)
	{
		for (size_t index = 0; index < counter; index++)
		{
			rString.append(foundElements[index] + " ");
		}
	}
	return rString;
}

string symmetric(vector <string> setA, vector <string> setB)
{
	string rString = "Symmetric difference of A and B has ";
	mpz_class counter = 0;
	vector <string> foundElements;

	for (size_t i = 0; i < setA.size(); i++)
	{
		if (!inSet(setA[i], setB))
		{
			foundElements.push_back(setA[i]);
			counter++;
		}
	}

	for (size_t i = 0; i < setB.size(); i++)
	{
		if (!inSet(setB[i], setA))
		{
			foundElements.push_back(setB[i]);
			counter++;
		}
	}

	rString.append(counter.get_str() + " elements: ");

	if (counter > 0)
	{
		for (size_t index = 0; index < counter; index++)
		{
				rString.append(foundElements[index] + " ");
		}
	}
	return rString;
}

string crossProduct(vector <string> setA, vector <string> setB)
{
	string rString = "The cross product of A and B has ";
	mpz_class counter = setA.size()*setB.size();

	rString.append(counter.get_str() + " elements: ");

	for (size_t i = 0; i < setA.size(); i++)
	{
		for (size_t k = 0; k < setB.size(); k++)
		{
			rString.append("(" + setA[i] + "," + setB[k] + ") ");
		}
	}

	return rString;
}

string powerSet(vector <string> setA, vector <string> setB)
{
	string rString = "The cardinality of the power set of the cross product of A and B is ";
	mpz_class counter = setA.size()*setB.size();
	mpz_class temp = 2;
	for (size_t index = 1; index < counter; index++)
	{
		temp = 2 * temp;
	}


	rString.append(temp.get_str());
	return rString;
}
