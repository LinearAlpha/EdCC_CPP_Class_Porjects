/*******************************************************************************
* PROJECT: Lab6
* FILE:	DeckOfCard.cpp
* AUTHORS: Dean Ferris and, Minpyo Kim
* DATE: 02/24/2019
* DESCRIPTION: Source file for DeckOfCards.h
*******************************************************************************/
#include <string>
#include <ctime>
#include <stdexcept>
#include "DeckOfCard.h"

//Card counter
const int numOfCard = 51;

/******************************************************************************
* FUNCTION: DeckOfCard
* DESCRIPTION: constructor of object, and filling array of deck
******************************************************************************/
DeckOfCard::DeckOfCard()
{
	//x - index number of deck
	//i - index number of suitArr
	//j - index number of faceArr
	int x = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			Card temp(i, j);
			deck[x] = temp;
			x++;
		}
	}
}

/******************************************************************************
* FUNCTION: shuffle
* DESCRIPTION: This function randomly swaps cards in deck of cards
******************************************************************************/
void DeckOfCard::shuffle()
{
	srand(time(NULL));
	int tempRand;
	for (int i = 0; i < numOfCard + 1; i++)
	{
		tempRand = rand() % (numOfCard + 1);
		Card temp1 = deck[tempRand];
		deck[tempRand] = deck[i];
		deck[i] = temp1;
	}
}

/******************************************************************************
* FUNCTION: getNumOfCardLeft
* DESCRIPTION: returns index value of deckOfCards left in deck
* OUTPUT: int - number of card left
******************************************************************************/
int DeckOfCard::getNumOfCardLeft() const
{
	return currentCard + 1;
}

/******************************************************************************
* FUNCTION: resetNumCard
* DESCRIPTION: Reseting number current of card in the deckOfCard
******************************************************************************/
void DeckOfCard::resetNumCard()
{
	currentCard = numOfCard;
}

/******************************************************************************
* FUNCTION: dealCard
* DESCRIPTION: deal and display value of card drawn
* OUTPUT: std::string - card information that composed of a string
******************************************************************************/
std::string DeckOfCard::dealCard() const
{
	//Throw error message if recived variavle is out of range
	if (currentCard >= 0 && currentCard <= numOfCard + 1)
	{
		currentCard--;
		return deck[currentCard + 1].getFace() + " of " +
			deck[currentCard + 1].getSuit();
	}
	else
		throw std::out_of_range("Number of card(s) to draw from deck"
			"must be beteen 1 & 52");
}

//Declaration of variable(s)
int DeckOfCard::currentCard = numOfCard;