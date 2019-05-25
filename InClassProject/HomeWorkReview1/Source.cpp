#include <iostream>
#include <string>

using namespace std;

int getAge();
bool displayInfo(string transName, int transAge);

int main()
{
	int x = 12;
	string name;
	bool test;
	do
	{
		//get user name
		cout << "Please type full name in order of first last: ";
		getline(cin, name);
		//get user's age
		x = getAge();
		test = displayInfo(name, x);
	} while (test == false);
	//end program
	getchar();
	return 0;
}

int getAge()
{
	int age;
	cout << "How old are you: ";
	cin >> age;
	cin.clear();
	cin.ignore(100, '\n');
	return age;
}

/******************************************************************************
* Function: displayIfo
* Description: Display user can enter the club or no
* Input: strin transName – the user's name
*        int transAge – the user's age
* Output: bool – ture when age is more then 21, else retun false
******************************************************************************/
bool displayInfo(string transName, int transAge)
{
	cout << "Name: " << transName << endl;
	cout << "Age: " << transAge << endl;

	if (transAge >= 21)
	{
		cout << "welcone to the club, " << transName << "!" << endl;
		return true;
	}
	else
	{
		cout << "Your are under the minimum age abd cabbit enter." << endl;
		return false;
	}
}