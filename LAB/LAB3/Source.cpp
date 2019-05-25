/******************************************************************************
 * Project: LAB3
 * File: Source.cpp
 * Authors: Minpyo Kim, Alexandre Soper
 * Date: 01/16/2019
 * Description: A console based application that lets the user view a list
 of historical earthquakes, sorted by date, or alphabetically.
******************************************************************************/
//preproccesor directives
#include <iostream>
#include <string>
using namespace std;

//struct that includes title, magnitude and, date of event
struct tsunamiEvents
{
	string title;
	double MAG;
	int month;
	int date;
	int year;
};

//function prototypes
inline void cleanPipe();
void fillData(tsunamiEvents* tmp);
inline void displayMenu(int &tmp);
void sortAlpha(tsunamiEvents* trans);
void swap(tsunamiEvents* tmpTrans, int p1, int p2);
void sortDate(tsunamiEvents* tsunami);
void displayResult(tsunamiEvents* trans, int tmp);

//array size const
const int SIZE = 10;

/*************************************************************************
Func: main()
Desc: Controls the overall flow of the application
Output: int - generic return type
*************************************************************************/
int main()
{
	//declaration statements
	tsunamiEvents tsunami[SIZE];
	fillData(tsunami);
	int flag;
	do
	{
		displayMenu(flag);
		switch (flag)
		{
			//1 to sort by alphabet
		case 1:
			sortAlpha(tsunami);
			displayResult(tsunami, flag);
			break;
			//2 to sort by date
		case 2:
			sortDate(tsunami);
			displayResult(tsunami, flag);
			break;
		default:
			break;
		}
	} while (flag);
	cout << "All done! (Press enter again to exit)" << endl;
	getchar();
	return 0;
}

/************************************************************************
Func: fillData()
Desc: Populates a tsunamiEvents struct array with data
Input: tsunamiEvents* tmp - pointer to a tsunamiEvents array
************************************************************************/
void fillData(tsunamiEvents* tmp)
{
	tmp[0] = { "Solomon Islands", 8.1, 4, 2, 2007 };
	tmp[1] = { "Samoa" , 8.1, 9, 21, 2009 };
	tmp[2] = { "Sumatra" , 7.7, 10, 25, 2010 };
	tmp[3] = { "New Zealand" , 6.3, 2, 22, 2011 };
	tmp[4] = { "Chile" , 8.3, 9, 16, 2015 };
	tmp[5] = { "U.S.A - WA " , 5.1, 5, 18, 1980 };
	tmp[6] = { "Colombia" , 8.1, 12, 12, 1979 };
	tmp[7] = { "Philippines" , 7.9, 8, 16, 1976 };
	tmp[8] = { "Japan" , 8.4, 12, 21, 1946 };
	tmp[9] = { "U.S.A - AK" , 8.6, 4, 1, 1956 };
	return;
}

/************************************************************************
Func: cleanPipe()
Desc: Clears input pipe
************************************************************************/
inline void cleanPipe()
{
	cin.clear();
	cin.ignore(100, '\n');
}

/**********************************************************************
Func: displayMenu()
Desc: displays a menu of the user's options
Input: int &tmp - address of an int, to represent menu options
**********************************************************************/
inline void displayMenu(int &tmp)
{
	//declare variable and print options
	bool check = true;
	cout << "0 - Exit" << endl;
	cout << "1 - Order alphabetically" << endl;
	cout << "2 - Order by dates" << endl;
	cout << "> ";
	cin >> tmp;
	//tests input
	while (check)
	{
		if (cin.fail())
		{
			cleanPipe();
			cout << "please enter integer." << endl;
			cout << "> ";
			cin >> tmp;
		}
		else if (tmp < 0 || tmp > 2)
		{
			cleanPipe();
			cout << "Please enter 0, 1, or 2" << endl;
			cout << "> ";
			cin >> tmp;
		}
		else
			check = false;
	}
	cleanPipe();
}

/************************************************************************
Func: sortAlpha
Desc: Insert sorts every datum within the tsunamiEvents array, alphabetically
Input: tsunamiEvents* trans - pointer to an array of tsunamiEvents
************************************************************************/
void sortAlpha(tsunamiEvents* trans)
{
	for (int i = 1; i < SIZE; i++)
	{
		int position = i;
		while (position > 0 && trans[position - 1].title > trans[position].title)
		{
			swap(trans, position - 1, position);
			position = position - 1;
		}
	}
	return;
}

/************************************************************************
Func: swap()
Desc: Swaps the order of two elements in a given array of tsunamiEvents
Input: tsunamiEvents* trans - pointer to an array of tsunamiEvents
	   int p1 - array position 1
	   int p2 - array position 2
************************************************************************/
void swap(tsunamiEvents* tmpTrans, int p1, int p2)
{
	tsunamiEvents tmp = tmpTrans[p1];
	tmpTrans[p1] = tmpTrans[p2];
	tmpTrans[p2] = tmp;
	return;
}

/************************************************************************
Func: sortDate()
Desc: Bubble sorts every datum within the tsunamiEvents array, by date
Input: tsunamiEvents* trans - pointer to an array of tsunamiEvents
************************************************************************/
void sortDate(tsunamiEvents* trans)
{
	bool swapped;
	int yearMonthDateTemp1;
	int yearMonthDateTemp2;
	for (int i = 0; i < SIZE; i++)
	{
		swapped = false;
		for (int j = 1; j < (SIZE - i); j++)
		{
			//converts two tested date sets to integer YYYYMMDD formats
			yearMonthDateTemp1 = (trans[j].date + (trans[j].month * 100) + (trans[j].year * 10000));
			yearMonthDateTemp2 = (trans[j - 1].date + (trans[j - 1].month * 100) + (trans[j - 1].year * 10000));
			if (yearMonthDateTemp1 < yearMonthDateTemp2)
			{
				swap(trans, j, (j - 1));
				swapped = true;
			}
		}
		//if nothing else can be swapped, then exit
		if (!swapped)
			return;
	}
	return;
}

void displayResult(tsunamiEvents* trans, int tmp)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << trans[i].title << ", Magnitude " << trans[i].MAG << ", at "
			<< trans[i].month << "/" << trans[i].month << "/" << trans[i].year << endl;
	}
	return;
}