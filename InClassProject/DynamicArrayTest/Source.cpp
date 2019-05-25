#include <iostream>

using namespace std;
 
double average(const double* arr, const int size);

int main()
{
	int count;
	cout << "How many grade: ";
	cin >> count;
	cin.ignore(100, '\n');
	double* grades = new double[count];
	for (int i = 0; i < count; i++)
	{
		cout << "Enetr grade #" << i << ": ";
		cin >> grades[i];
		cin.ignore(100, '\n');
	}
	cout << "The avg is " << average(grades, count) << endl;
	//end program
	delete grades;
	getchar();
}

double average(const double * arr, const int size)
{
	double temp = 0;
	for (int i = 0; i < size; i++)
		temp += arr[i];
	return temp / size;
}
