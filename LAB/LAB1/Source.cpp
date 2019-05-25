/******************************************************************************
 * Project: LAB1
 * File: Source.cpp
 * Authors: Minpyo Kim, Dean Ferris
 * Date: 01/02/2019
 * Description: Tsunami Events pre & port 2010 including earthequick magnitude
******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

//struct that includes title, magnitude and, date of event
struct tsunamiEvents
{
	string titile;
	double MAG;
	int month;
	int date;
	int year;
};

int main()
{
	//declaration of pointer array with 5 indexes
	tsunamiEvents* tsunami[5];
	tsunamiEvents tsunami0 = { "Solomon Islands", 8.1, 4, 2, 2007 };
	tsunami[0] = &tsunami0;
	tsunamiEvents tsunami1 = { "Samoa" , 8.1, 9, 21, 2009 };
	tsunami[1] = &tsunami1;
	tsunamiEvents tsunami2 = { "Sumatra" , 7.7, 10, 25, 2010 };
	tsunami[2] = &tsunami2;
	tsunamiEvents tsunami3 = { "New Zelend" , 6.3, 2, 22, 2011 };
	tsunami[3] = &tsunami3;
	tsunamiEvents tsunami4 = { "Chile" , 8.3, 9, 16, 2015 };
	tsunami[4] = &tsunami4;
	cout << "Tsunami Events caused by the earthquake pre & post 2010:" << endl;
	//loop through the array and display title, magnitude and, 
	//date of tsunami event
	for (int i = 0; i < 5; i++)
	{
		cout << "\tCountry Name:\t" << tsunami[i]->titile << endl;
		cout <<	" \tMagnitude:\t" << tsunami[i]->MAG << endl;
		cout << "\tDate:\t\t" << tsunami[i]->month << "/" << tsunami[i]->date << "/"
			<< tsunami[i]->year << endl;
		cout << "\tReference Year:\t";
		if (tsunami[i]->year < 2010)
			cout << "- pre 2010";
		else if (tsunami[i]->year > 2010)
			cout << "- post 2010";
		else
			cout << "- 2010";
		cout << endl << endl << endl;
	}
	//pause screen to look at displayed information

	getchar();
	return 0;
}