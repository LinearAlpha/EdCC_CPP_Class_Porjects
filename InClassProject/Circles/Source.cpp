/******************************************************************************
* Project: Circles
* File: Source.cpp
* Authors: Minpyo Kim
* Date: 01/07/2019
* Description: This console - based program greets the
*              user and lists the authors' names.
******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double pi = 3.14159;
	int r1 = 10, r2 = 15, r3 = 20, r4 = 25;
	double a1, a2, a3, a4;
	a1 = r1 * pi;
	a2 = r2 * pi;
	a3 = r3 * pi;
	a4 = r4 * pi;
	cout << setprecision(1) << fixed << showpoint << right;
	cout << setw(10) << "radius" << setw(10) << "Area" << endl;
	cout << setw(10) << r1 << setw(10) << a1 << endl;
	cout << setw(10) << r2 << setw(10) << a2 << endl;
	cout << setw(10) << r3 << setw(10) << a3 << endl;
	cout << setw(10) << r4 << setw(10) << a4 << endl;
	getchar();
	return 0;
}