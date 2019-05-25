/******************************************************************************
Project: Lab2
File: Source.cpp
Author: Anton Soderqvist, Ton That Quynh Thong, Minpyo Kim
Date: 1/9/2019
Description: This program takes in user input of temperatures and calculates
			 the median, max, min, and average of the data.
******************************************************************************/
#include <iostream>
#include <iomanip>
#include "ArrayFunctions.h"

using namespace std;

//function prototype
inline void cleanPipe();

int main()
{
	//declaring variable
	int max,
		i;
	long double arr[1000];
	cout << "enter how many" << endl << "> ";
	cin >> max;
	//clearing input pipe
	cleanPipe();
	while (!max)
	{
		cout << "Please re-enter how much data you have(greater than 0)." << endl;
		cout << "> ";
		cin >> max;
		//clearing input pipe
		cleanPipe();
	}
	cout << "Please enter data one at a time." << endl;
	for (i = 0; i < max; i++)
	{
		cout << "> ";
		cin >> arr[i];
		//clearing input pipe
		cleanPipe();
		while (!arr[i])
		{
			cout << "Please re-enter your last DATA point." << endl;
			cout << "> ";
			cin >> arr[i];
			//clearing input pipe
			cleanPipe();
		}
	}
	cout << setprecision(3) << fixed << showpoint;
	cout << "Average: " << calcAverage(arr, max) << endl;
	cout << "Max: " << findMax(arr, max) << endl;
	cout << "Min: " << findMin(arr, max) << endl;
	cout << "Median: " << calcMedian(arr, max) << endl;
	getchar();
	return 0;
}


/******************************************************************************
Function: cleanPipe
Description: clearing user input
******************************************************************************/
inline void cleanPipe()
{
	cin.clear();
	cin.ignore(100, '\n');
	return;
}