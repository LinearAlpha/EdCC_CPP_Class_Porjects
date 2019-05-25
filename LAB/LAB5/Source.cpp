/******************************************************************************
 * Project: LAB5
 * File: Source.cpp
 * Authors: Minpyo Kim and Phumiphat Siripanich
 * Date: 02/13/2019
 * Description: This program allow the users to enter movie information
 *              including title, director, year of release, rating and RTscore
******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "MovieInfo.h"

using namespace std;

//function prototyping
template <typename T>
void voletProof(T& input, const int& lowBound, const int& upBound);
inline void cleanPipe();
void display(int& input);
void setMovie(vector<MovieInfo>& movie);
bool equalCheck(const vector<MovieInfo> movie, const string recived);
void displayInfoMenu(const vector<MovieInfo>& list, int& input);
void editDelete(vector<MovieInfo>& list, int& input);

/******************************************************************************
* Function: cleanPipe
* Description: Controls the overall flow of the application.
* Output: int - generic return type
******************************************************************************/
int main()
{
	//vector used to store movie information
	vector<MovieInfo> movie;
	cout << "Movie Information..." << endl << endl;
	bool check = true;
	int input;
	//switch case statments
	//default && 0 - Exit the program
	//1 - adding movie information
	//2 - view the list of the movie and informations
	//3 - edit or delect movie information
	do
	{
		display(input);
		switch (input)
		{

		default:
			check = false;
			break;
		case 1:
			setMovie(movie);
			break;
		case 2:
			//checking is the vector is empty
			if (movie.empty())
			{
				cout << "There is no movie information in the system" << endl
					<< endl;
				break;
			}
			else
			{
				displayInfoMenu(movie, input);
				cout << movie.at(input).toString() << endl << endl;
			}
			break;

		case 3:
			//checking is the vector is empty
			if (movie.empty())
			{
				cout << "There is no movie information in the system" << endl
					<< endl;
				break;
			}
			else
			{
				displayInfoMenu(movie, input);
				editDelete(movie, input);
			}
			break;
		}
	} while (check);
	cout << "Thank you for using." << endl;
	cout << "Press enter to exit the program";
	//End of programming
	getchar();
	return 0;
}

/******************************************************************************
* Function: voletProof
* Description: This function will validate user input, and pop up the message 
*			   to associate the user to enter right number
* Input: T& input - User input that transfered.
*		 int& lowBound - lower bound of selection.
*		 int& upBound - upper bound of selection.
******************************************************************************/
template <typename T>
void voletProof(T& input, const int& lowBound, const int& upBound)
{
	//Declare variable
	bool check = true;
	while (check)
	{
		if (cin.fail())
		{
			cleanPipe();
			cout << "Please enter integer." << endl;
			cout << "> ";
			cin >> input;
		}
		else if (lowBound > input || input > upBound)
		{
			cleanPipe();
			cout << "Pleae enter between " << lowBound << " to " << upBound;
			cout << endl << "> ";
			cin >> input;
		}
		else
			check = false;
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

/******************************************************************************
* Function: display
* Description: This function will display option for the user.
* Input: int& input - users input
******************************************************************************/
void display(int& input)
{
	//Printing menu options
	cout << "0 - Exit" << endl << "1 - Add Movie Information" << endl
		<< "2 - View Movie Information " << endl 
		<< "3 - Edit/Delete Movie Information" << endl;
	cout << "> ";
	cin >> input;
	voletProof(input, 0, 3);
	cout << endl;
	return;
}

/*******************************************************************
* Function: setMovie
* Description: This function allows the users to enter movie detail.
* Input: vector<MovieInfo>& movie - vector that store movie details
*******************************************************************/
void setMovie(vector<MovieInfo>& movie)
{
	//declare variable
	string title,
		director,
		rating;
	int year;
	double rtScore;
	cout << "Enter The Title Of The Movie: ";
	getline(cin, title);
	if (equalCheck(movie, title))
	{
		//Printing error message
		cout << "The movie is already on the system, "
			<< "please check information on our system." << endl;
		cout << "If it is diffrent movie, but has a same title"
			<< " please add ""/""" << "at the end of title." << endl << endl;
		return;
	}
	cout << "Enter The Director's Name: ";
	getline(cin, director);
	cout << "Enter The Release Year: ";
	cin >> year;
	//Volet proof
	voletProof(year, 1800, 9999);
	cout << "Enter The Rating: ";
	getline(cin, rating);
	cout << "Enter Rotten Tomato Score: ";
	cin >> rtScore;
	//Volet proof
	voletProof(rtScore, 0, 100);
	MovieInfo movieRecived(title, director, rating, year, rtScore);
	movie.push_back(movieRecived);
	cout << endl;
	return;
}

/******************************************************************************
* Function: equalCheck
* Description: This function is checking individual object that is there same
*              title in vector of object.
* Input: const vector<MovieInfo> movie - vector that stored movie information
*        const string recived - string variable that user intered
* Outpu: bool - ture, ther is same movie title in the system
*             - false, neither the vector is empty, or there is no matching
*               movie name
******************************************************************************/
bool equalCheck(const vector<MovieInfo> movie, const string recived)
{
	for (unsigned int i = 0; i < movie.size(); i++)
	{
		//Creating temperate object by increment of loop
		MovieInfo temp(movie.at(i));
		if (temp.equals(recived))
			return true;
		else if (movie.empty())
			return false;
	}
	return false;
}

/***************************************************************
* Function: displayInfoMenu
* Description: This function will display option for the user.
* Input: const vector<MovieInfo>& list - list of movies
*		 int& input - users input
***************************************************************/
void displayInfoMenu(const vector<MovieInfo>& list, int& input)
{
	//printing movie lists
	for (unsigned int i = 0; i < list.size(); i++)
	{
		cout << i + 1 << " - " << list.at(i).getTitle() << endl;
	}
	cout << "Select movie: ";
	cin >> input;
	voletProof(input, 1, list.size());
	input -= 1;
	return;
}

/******************************************************************
* Function: editDelete
* Description: This function allows the users to edit the movie
* detail or remove it completely.
* Input: vector<MovieInfo>& list - provide access to the movie class
*		 int& input - users input
*******************************************************************/
void editDelete(vector<MovieInfo>& list, int& input)
{
	//printing information sentence
	cout << "Edit Rotten Tomatoes Score or, Delete Movie Information"
		<< endl;
	//declare variable
	int temp;
	cout << "Enter 1 to edit Rotten tomato score" << endl;
	cout << "Enter 2 to delete the movie's information" << endl << "> ";
	cin >> temp;
	voletProof(temp, 1, 2);
	if (temp == 1)
	{
		double tmp1;
		cout << "Enter the new Rotten Tomatoes Score: ";
		cin >> tmp1;
		voletProof(tmp1, 0, 100);
		//replace variable
		list.at(input).setRtScore(tmp1);
	}
	else
	{
		//erase choosed index from the vector
		list.erase(list.begin() + input);
	}
	return;
}