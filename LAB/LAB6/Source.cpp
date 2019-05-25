/*******************************************************************************
* PROJECT: Lab6
* FILE:	source.cpp
* AUTHORS: Dean Ferris and, Minpyo Kim
* DATE: 02/24/2019
* DESCRIPTION: This program shuffle poker card and allow the user to chose how
*	 	many cards to draw from the deck. When the deck is completely 
*		drawn, user is prompted for a new selction of reshuffle or exit
*******************************************************************************/
#include <iostream>
#include <string>
#include "DeckOfCard.h"
#include "BulletProof.h"

using namespace std;

//Function prototyping and template
template <typename T>
void bulletProof(T& input, const int& lowBound, const int& upBound);
inline void cleanPipe();
void displayCard(DeckOfCard& cardTrans, const int& numOfDealTrans);
void reShuffle(DeckOfCard& cardTrans, bool& input);

/******************************************************************************
* FUNCTION: main
* DESCRIPTION: This function shuffles and deals the cards
******************************************************************************/
int main()
{
	//Declaration of variables
	DeckOfCard card;
	card.shuffle();
	bool input;
	int numOfDeal;
	cout << "Welcome to EdCC Casino, Happy Gambling!\n\n" << endl;
	do
	{
		cout << "Type 0 to exit, and 1 to deal card" << endl;
		cout << "> ";
		cin >> input;
		bulletProof(input, 0, 1);
		if (input)
		{
			cout << "\nHow many cards would you like? ";
			cin >> numOfDeal;
			bulletProof(numOfDeal, 0, card.getNumOfCardLeft());
			displayCard(card, numOfDeal);
		}
		if (card.getNumOfCardLeft() == 0)
			reShuffle(card, input);
	} while (input);
	cout << "\n\nThank you for playing!" << endl;
	cout << "\n\tPress enter to exit." << endl;
	//end program
	getchar();
	return 0;
}

/******************************************************************************
* Function: bulletProof
* Description: function prompts user for input than validate it
* Input: T& input - User input that transfered.
*		 int& lowBound - lower bound of selection.
*		 int& upBound - upper bound of selection.
******************************************************************************/
template <typename T>
void bulletProof(T& input, const int& lowBound, const int& upBound)
{
	//Declaration of variables
	bool check = true;
	while (check)
	{
		if (cin.fail())
		{
			cleanPipe();
			cout << "\n\n\tPlease select ''0'' to exit, or ''1'' "
				"to deal a card." << endl;
			cout << "\t> ";
			cin >> input;
		}
		else if (lowBound > input || input > upBound)
		{
			cleanPipe();
			cout << "\n\n\tPlease enter a number between "
				<< lowBound + 1 << " and " << upBound;
			cout << endl << "\t> ";
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
* Function: displayCard
* Description: Display card information that was drawn based on user input
* INPUT: DeckOfCard& cardTrans - the object of card that is transferd
*		 const int& numOfDealTrans - number of card to print
******************************************************************************/
void displayCard(DeckOfCard& cardTrans, const int& numOfDealTrans)
{
	for (int i = 0; i < numOfDealTrans; i++)
	{
		cout << "\n\t";
		//Check condition shows error
		try
		{
			cout << cardTrans.dealCard() << endl;
		}
		catch (out_of_range& e)
		{
			cout << e.what() << endl;
			break;
		}
	}
	cout << "\n\nThere are " << cardTrans.getNumOfCardLeft() <<
		" cards left to draw from!\n\n" << endl;
}

/******************************************************************************
* Function: reShuffle
* Description: Display message and prompt user to select between exit
*		program or, re-shuffle the deck of cards and start over
* INPUT: DeckOfCard& cardTrans - the object of card creation
*		 bool& input - true -> re-shuffle, false -> exit
******************************************************************************/
void reShuffle(DeckOfCard& cardTrans, bool& input)
{
	cout << "\n\nType 1 to re-shuffle the deck, 0 to exit." << endl;
	cout << "> ";
	cin >> input;
	bulletProof(input, 0, 100);
	if (input)
	{
		cardTrans.shuffle();
		cardTrans.resetNumCard();
	}
}