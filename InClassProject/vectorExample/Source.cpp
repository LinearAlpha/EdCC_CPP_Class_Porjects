#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> nums;
	int input;
	do
	{
		cout << "Enter a positive integer (-1 to stop): ";
		cin >> input;
		cin.ignore(100, '\n');
		if (input > -1)
			nums.push_back(input);
	} while (input > -1);
	cout << "You entered " << nums.size() << "integer." << endl;
	double avg = 0;
	for (int i = 0; i < nums.size(); i++)
		avg += nums.at(i);
	avg /= nums.size();
	cout << "The average is " << avg << endl;
	getchar();
	return 0;
}