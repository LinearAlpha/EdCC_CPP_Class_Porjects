#include <iostream>
#include "Assignment.h"

using namespace std;

int main()
{
	int year = -1;
	while (year < 0)
	{
		cout << "What year is it? ";
		cin >> year;
		cin.clear();
		cin.ignore(100, '\n');
		try
		{
			Assignment::setYear(year);
		}
		catch (out_of_range& e)
		{
			cout << e.what() << endl;
			year = -1;
		}
	}
	try
	{
		Assignment lab1("Lab 1", "Write a class thet represent a cow", 100, 15, 2);
		cout << lab1.toString() << endl;
		Assignment lab2("Lab 2", "Write a class thet represent a cow", 100, 30, 20);
		cout << lab2.toString() << endl;
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}
	
	
	
	
	
	
	
	//end program
	getchar();
	return 0;
}