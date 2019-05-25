/******************************************************************************
Project: Lab2
File: ArrayFunction.h
Author: Anton Soderqvist, Ton That Quynh Thong, Minpyo Kim
Date: 1/9/2019
Description: This program takes in user input of temperatures and calculates
			 the median, max, min, and average of the data.
******************************************************************************/
#ifndef _ArrayFunctions_
#define _ArrayFunctions_

/****************************************************
* Function: sort
* Description: This function will sort the array from
*			   the lowest number to largest number.
* Input: T* arr - The array contains data from user.
*		 int size - The size of the array.
* Output: Sorted array.
****************************************************/
template <typename T>
void sort(T* arr, int size)
{
	//Condition to sort the array.
	for (int i = 1; i < size; i++)
	{
		//Declare the key variable.
		T key = arr[i];
		int j = i - 1;
		//Looping to sort array.
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	return;
}

/*******************************************************************
* Function: calcAverage
* Description: This function will calculate the average of the array
* Input: T* arr - The array contains data from user.
*		 int size - The size of the array.
* Output: long double avg - the average.
********************************************************************/
template <typename T>
long double calcAverage(T* arr, int size)
{
	//Decalre average variable.
	long double avg = 0;
	//This loop will adding up to avg variable.
	for (int i = 0; i < size; i++)
	{
		//Adding up to avg.
		avg += arr[i];
	}
	//Return the average.
	return avg = avg / (double)size;
}

/*****************************************************************
* Function: findMax
* Description: This function will find the max value in the array
* Input: T* arr - The array contains data from user.
*		 int size - The size of the array.
* Output: double largest - the largest value in the array.
*****************************************************************/
template <typename T>
T findMax(T* arr, int size)
{
	//Declare the largest variable.
	double largest = arr[0];
	//This loop will find out the largest value in array.
	for (int i = 0; i < size; i++)
	{
		//Condition to find out the largest value.
		if (largest < arr[i])
		{
			//Current largest value.
			largest = arr[i];
		}
	}
	//Return value after find out the largest value.
	return largest;
}

/*****************************************************************
* Function: findMin
* Description: This function will find the min value in the array
* Input: T* arr - The array contains data from user.
*		 int size - The size of the array.
* Output: double y - the smalest value in the array.
*****************************************************************/
template <typename T>
T findMin(T* arr, int size)
{
	//Declare the variable to find smallest value.
	double y = arr[0];
	//This loop will find out the smallest value.
	for (int x = 0; x < size; x++)
	{
		//Condition to find smallest value in array.
		if (y > arr[x])
		{
			//Current smallest value.
			y = arr[x];
		}
		else
		{
			break;
		}
	}
	//Return smallest value.
	return y;
}

/********************************************************************
* Function: calcMedian
* Description: This function will find out the median value in array
* Input: T* arr - The array contains data from user.
*		 int size - The size of the array.
* Output: arr[tmp] - the median value in the array.
*******************************************************************/
template <typename T>
long double calcMedian(T* arr, int size)
{
	//decare the variable
	T arrTrans[10000];
	for (int i = 0; i < size; i++)
	{
		arrTrans[i] = arr[i];
	}
	sort(arrTrans, size);
	if (!(size % 2))//if even number
	{
		int tmp1 = (size / 2) - 1;
		int tmp2 = tmp1 + 1;
		return (arr[tmp1] + arr[tmp2]) / 2;
	}
	else
	{
		int tmp = (int)(size / 2);
		return arrTrans[tmp];
	}
}

#endif