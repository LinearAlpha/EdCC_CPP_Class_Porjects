#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

void display(int arr[], int size);
void swap(int arr[], int tmp1, int tmp2);
void insertionSort(int arr[], int size);
void accoutingSort(int arr[], int size);
void merge(vector<int> &av, vector<int> &aLeft, vector<int> &aRight);
void mergeSort(vector<int> &av);



int main()
{
	srand(time(NULL));
	int arr[10000], arr2[10000];
	for (int i = 0; i < 10000; i++)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < 10000; i++)
	{
		arr2[i] = arr[i];
	}
	/*auto start = chrono::high_resolution_clock::now();
	insertionSort(arr, 10000);
	auto finsh = chrono::high_resolution_clock::now();
	cout << chrono::duration_cast<std::chrono::nanoseconds > (finsh - start).count() << endl;
	display(arr, 10000);*/
	auto start = chrono::high_resolution_clock::now();
	accoutingSort(arr, 10000);
	auto finsh = chrono::high_resolution_clock::now();
	cout << chrono::duration_cast<std::chrono::nanoseconds> (finsh - start).count() << endl;
	display(arr, 10000);
	
	
	
	display(arr, 10000);
	getchar();
	return 0;
}

void display(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void swap(int arr[], int tmp1, int tmp2)
{
	int tmp = arr[tmp1];
	arr[tmp1] = arr[tmp2];
	arr[tmp2] = tmp;

}

//insert sort - time O(n^2)
void insertionSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int position = i;
		while (position > 0 && arr[position - 1] > arr[position])
		{
			swap(arr, position, position - 1);
			position = position - 1;
		}
	}
}

void accoutingSort(int arr[], int size)
{
	int temp[100]; 
	for (int i = 0; i < size; i++)
		temp[arr[i]]++;
	int index = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 1; i <= temp[i]; j++)
		{
			arr[index] = i;
			index++;
		}
	}
}

//merge sort
void mergeSort(vector<int> &av)
{
	if (av.size() > 0)
	{
		vector<int> aLeft;
		for (int i = 0; i < av.size() / 2; i++)
			aLeft.push_back(av.at(i));
		vector<int> aRight;
		for (int i = av.size() / 2; i < av.size(); i++)
		{
			aRight.push_back(av.at(i));
			mergeSort(aLeft);
			mergeSort(aRight);
			merge(av, aLeft, aRight);
		}
	}

void merge(vector<int> &av, vector<int> &aLeft, vector<int> &aRight)
{
	int i1 = 0;
	int i2 = 0;
	for (int i = 0; i < av.size(); i++)
	{
		if (i2 > aRight.size() - 1 || (i1 <= aLeft.size() - 1 && aLeft.at(i1) <= aRight.at(i2)))
		{
			av.at(i) = aLeft.at(i1);
			i1++;
		}
		else
		{
			av.at(i) = aRight.at(i2);
			i2++;
		}
	}
}