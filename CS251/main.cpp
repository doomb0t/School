
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
void getInjective(vector <string> &oneTone, string *set1, string *set2, int base, const mpz_class n1, const mpz_class n2);
void swap(string *a, string *b);
void printVector(vector <string> inComing);
void getSurjective(vector <string> &functions, string *set1, string *set2, int base, const mpz_class n1, const mpz_class n2);
void getBijective(vector <string> &functions, string *set1, string *set2, int base, const mpz_class n1, const mpz_class n2);
void getFunctions(vector <string> &functions, string *set1, string *set2, int base, const mpz_class n1, const mpz_class n2);
mpz_class calcElem(mpz_class n1, mpz_class n2);

int main(){
	//initializing variables
	mpz_class nSet1  = 0;
	mpz_class nSet2  = 0;
	mpz_class nTest1 = 0;
	mpz_class nTest2 = 0;
	string s_setA, s_setB;
	vector <string> lineArray, v_setA, v_setB, v_Injective, v_Surjective, v_Bijective, v_allFunctions;

	cout << "Enter set A (separated by space): ";
	getline(cin, s_setA);
        nSet1 = elementCount(s_setA);
	
        cout << "Enter set B (separated by space): ";
        getline(cin, s_setB);	
        nSet2 = elementCount(s_setB);
        
	if (elementCount(s_setA) >= nSet1 && elementCount(s_setB) >= nSet2)
	{
		splitLine(v_setA, s_setA, nSet1);
		splitLine(v_setB, s_setB, nSet2);
		string* p_setA = &v_setA[0];
		string* p_setB = &v_setB[0];

                //print all functions
                cout << "There are " << pow(v_setA.size(), v_setB.size()) << " functions from A to B: " << endl;
                getFunctions(v_allFunctions, p_setA, p_setB, 0, v_setA.size(), v_setB.size());
                printVector(v_allFunctions);
		
                //print injective
                cout << "There are " << calcElem(v_setA.size(), v_setB.size()) << " injective functions from A to B: " << endl;
		getInjective(v_Injective, p_setA, p_setB, 0, v_setA.size(), v_setB.size());
		printVector(v_Injective);

		cout << "Enter number of elements in sets(separated by space): ";
		cin >> nTest1 >> nTest2;

		cout << "The answer for |Domain| = " << nTest1 << " and |Codomain| = " << nTest2 << " is " << calcElem(nTest1, nTest2) << endl;

	}
	else
	{
		cout << "Not enough elements entered. Bye!" << endl;
	}
}

//function to separate a line into words white space is the delimeter
void splitLine(vector <string> &words, string currentLine, mpz_class limit){
	istringstream ss(currentLine);
	istream_iterator<string> begin(ss), end;
	vector<string> arrayTokens(begin, end);

	for (size_t index = 0; index < limit; index++)
	{
		words.push_back(arrayTokens[index]);
	}
}

//function to count possible elements in the string
mpz_class elementCount(string currentLine){
	mpz_class temp = 0;
	istringstream ss(currentLine);
	istream_iterator<string> begin(ss), end;
	vector<string> arrayTokens(begin, end);
	temp = arrayTokens.size();
	return temp;
}

//function to get 1-1 function
void getInjective(vector <string> &oneTone, string *set1, string *set2, int base, const mpz_class n1, const mpz_class n2)
{
	if (base == n1)
        {
		string temp = "{";
		for (size_t k = 0; k < n1; k++)
		{
			temp.append("(" + set1[k] + "," + set2[k] + ")");
		}
		temp.append("}");
		oneTone.push_back(temp);
	}
	else
	{
		for (int j = base; j < n2; j++) 
                {
			swap((set2 + base), (set2 + j));
			getInjective(oneTone, set1, set2, base + 1, n1, n2);
			swap((set2 + base), (set2 + j));
		}
	}
}
//function to swap elements works with getoneToOne function
void swap(string *a, string *b)
{
	string c = *a;
	*a = *b;
	*b = c;
}

//Prints out the vector elements
void printVector(vector <string> inComing){

	for (size_t i = 0; i < inComing.size(); i++)
	{
		cout << inComing[i];
	}
        cout << endl;
}

//function to calculate # of possible answers for 1-1 function
mpz_class calcElem(mpz_class n1, mpz_class n2)
{
	mpz_class temp = 1;
	mpz_class counter = n2;
	for (size_t i = 0; i < n1; i++)
	{
		temp = counter * temp;
		counter--;
	}
	return temp;
}

void getFunctions(vector <string> &oneTone, string *set1, string *set2, int base, const mpz_class n1, const mpz_class n2)
{
	if (base == n1)
        {
		string temp = "{";
		for (size_t k = 0; k < n1; k++)
		{
			temp.append("(" + set1[k] + "," + set2[k] + ")");
		}
		temp.append("}");
		oneTone.push_back(temp);
	}
	else
	{
		for (int j = base; j < n2; j++) 
                {
			swap((set2 + base), (set2 + j));
			getFunctions(oneTone, set1, set2, base + 1, n1, n2);
			swap((set2 + base), (set2 + j));
		}
	}
}


void getSurjective(vector <string> &oneTone, string *set1, string *set2, int base, const mpz_class n1, const mpz_class n2)
{
	if (base == n1)
        {
		string temp = "{";
		for (size_t k = 0; k < n1; k++)
		{
			temp.append("(" + set1[k] + "," + set2[k] + ")");
		}
		temp.append("}");
		oneTone.push_back(temp);
	}
	else
	{
		for (int j = base; j < n2; j++) 
                {
			swap((set2 + base), (set2 + j));
			getInjective(oneTone, set1, set2, base + 1, n1, n2);
			swap((set2 + base), (set2 + j));
		}
	}
}

void getBijective(vector <string> &oneTone, string *set1, string *set2, int base, const mpz_class n1, const mpz_class n2)
{
	if (base == n1){
		string temp = "{";
		for (size_t k = 0; k < n1; k++)
		{
			temp.append("(" + set1[k] + "," + set2[k] + ")");
		}
		temp.append("}");
		oneTone.push_back(temp);
	}
	else
	{
		for (int j = base; j < n2; j++) 
                {
			swap((set2 + base), (set2 + j));
			getInjective(oneTone, set1, set2, base + 1, n1, n2);
			swap((set2 + base), (set2 + j));
		}
	}
}

