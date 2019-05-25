/*******************************************************************************
* PROJECT: Lab6
* FILE:	BulletProof.cpp
* AUTHORS: Dean Ferris and, Minpyo Kim
* DATE: 02/24/2019
* DESCRIPTION: Source file of BulletProof.h
*******************************************************************************/
#include <iostream>
#include <string>
#include <stdexcept>
#include "BulletProof.h"

using namespace std;

/******************************************************************************
* Function: voletProof
* Description: This function will promot user input and validate it
* Input: T& input - User input that transfered.
*		 int& lowBound - lower bound of selection.
*		 int& upBound - upper bound of selection.
******************************************************************************/
template <typename T>
void voletProof(T& input, const int& lowBound, const int& upBound)
{
	if (input > lowBound && input < upBound || !(cin.fail))
	{
	}
	else
	{
		throw std::out_of_range("Invalid input");
	}
	cleanPipe();
}

/******************************************************************************
* Function: cleanPipe
* Description: This function clears the string variable.
******************************************************************************/
inline void cleanPipe()
{
	cin.clear();
	cin.ignore(100, '\n');
}