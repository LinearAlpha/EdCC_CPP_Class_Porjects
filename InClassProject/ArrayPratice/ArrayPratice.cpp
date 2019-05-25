#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);

int main()
{
	srand(time(NULL));
	int nums[100];
	for (int i = 0; i < 100; i++)
		nums[i] = rand() % 100;
	for (int i = 0; i < 100; i++)
		cout << nums[i] << " ";
	cout << endl << endl;
	cout << "85 is at index " << linearSearch(nums, 100, 85) << endl << endl;
	sort(nums, nums + 100);
	for (int i = 0; i < 100; i++)
		cout << nums[i] << " ";
	cout << endl << endl;
	cout << "85 is at index " << binarySearch(nums, 100, 85) << endl;
	getchar();
	return 0;
}

int linearSearch(int arr[], int size, int target)
{
	int index = -1;
	for (int i = 0; i < size && index < 0; i++)
	{
		if (arr[i] == target)
			index = i;
	}
	return index;
}

int binarySearch(int arr[], int size, int target)
{
	int first = 0,
		last = size - 1,
		index = -1;
	while (first <= last && index < 0)
	{
		int middle = (first + last) / 2;
		if (arr[middle] > target)
			index = middle;
		else if (arr[middle] > target)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return index;
}