#include <iostream>
#include<iomanip>

using namespace std;

void convertToCanadian(double &tmep);

int main()
{
	double dollars;
	cout << "Enter US dollars: ";
	cin >> dollars;
	cin.clear;
	cin.ignore(100, '\n');
	convertToCanadian(dollars);
	cout << "$" << dollars << " Canadian" << endl;
	getchar();
	return 0;
}

void convertToCanadian(double &temp)
{
	temp /= 0.77;
	return;
}