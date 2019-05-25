/*******************************************************************************
* PROJECT: Lab6
* FILE:	Card.cpp
* AUTHORS: Dean Ferris and, Minpyo Kim
* DATE: 02/24/2019
* DESCRIPTION: Source file for Card.h
*******************************************************************************/
#include <string>
#include "Card.h"

/******************************************************************************
* Function: Card
* Description: Constructor of object.
* Input: int suitRc - index number of suit
*        int faceRc - index number of face
******************************************************************************/
Card::Card() {}; //default constractor
Card::Card(int suitRc, int faceRc) : face(faceRc), suit(suitRc) {}

/******************************************************************************
* Function: getFace
* DESCRIPTION: Receive face information form data members then, transfer to
*			   requesting function
* OUTPUT: std::string - return face value and index number
******************************************************************************/
std::string Card::getFace() const
{
	return faceArr[face];
}

/******************************************************************************
* Function: getSuit
* DESCRIPTION: Receive suit information form data members then, transfer to
*			   requesting function
* OUTPUT: std::string - return suit value and index number
******************************************************************************/
std::string Card::getSuit() const
{
	return suitArr[suit];
}

//initilizing static string arrays for deckOfCards, face and value
const std::string Card::faceArr[] = { "2", "3", "4", "5", "6", "7", "8",
									"9", "10", "Jack", "Queen", "King",
									"Ace" };
const std::string Card::suitArr[] = { "Diamonds", "Heart", "Club", "Spades" };