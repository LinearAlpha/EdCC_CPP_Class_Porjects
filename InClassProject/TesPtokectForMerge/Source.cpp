#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	cout << "Eneter string: " << endl;
	getline(cin, input);
	//out putting the first latters
	size_t index = -1;
	cout << input.at(0);
	do
	{
		index = input.find(' ', index + 1);
		if (index != string::npos)
			cout << input.at(index + 1);
	} while (index != string::npos);
	cout << endl;
	//output indivisual words
	cout << input.at(0);
	index = -1;
	size_t prevIndex = 0;
	do
	{
		index = input.find(' ', index + 1);
		if (index != string::npos)
		{
			cout << input.substr(prevIndex + 1, index - prevIndex - 1) << endl;
			prevIndex = index;
		}
	} while (index != string::npos);
	cout << input.substr(prevIndex + 1) << endl;


	getchar();
	return 0;
}