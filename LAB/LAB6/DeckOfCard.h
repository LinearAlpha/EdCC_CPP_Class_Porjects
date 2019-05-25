/*******************************************************************************
* PROJECT: Lab6
* FILE:	DeckOfCards.h
* AUTHORS: Dean Ferris and, Minpyo Kim
* DATE: 02/24/2019
* DESCRIPTION: This file is containting class defintion of DeckOfCard, and
*			   function prototyping
*******************************************************************************/
#ifndef _DECKOFCARD_
#define _DECKOFCARD_

#include <vector>
#include <string>
#include "Card.h"

/******************************************************************************
 * CLASS: DeckOfCards
 * DESCRIPTION: deck of cards class properties
 * Data members: Card deck[52] - array of card deck with size 52
 *		 static int currentCard - value of currentCard
 ******************************************************************************/
class DeckOfCard
{
private:
	//Data members
	Card deck[52];
	static int currentCard;
public:
	//Member functions prototyping
	DeckOfCard();
	void shuffle();
	int getNumOfCardLeft() const;
	void resetNumCard();
	std::string dealCard() const;
};

#endif // !_DECKOFCARD_