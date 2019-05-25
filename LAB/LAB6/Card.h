/*******************************************************************************
* PROJECT: Lab6
* FILE:	Card.h
* AUTHORS: Dean Ferris and, Minpyo Kim
* DATE: 02/24/2019
* DESCRIPTION: Class defintion of Card, and function prototyping
*******************************************************************************/
#ifndef _CARD_
#define _CARD_

#include <string>

/******************************************************************************
 * CLASS: Card
 * DESCRIPTION: card class properties
 * Data members: int face - index of faceArr
 *				 int suit - index of suitArr
 *				 static const std::string faceArr[] - array with pre-filld with
 *													  face of card
 *				 static const std::string suitArr[] - array with pre-filld with
 *													  suit of card
 ******************************************************************************/
class Card
{
	//Allow class DeckOfCard access to Class Card
	friend class DeckOfCard;
private:
	//Data members
	int face,
		suit;
	static const std::string faceArr[];
	static const std::string suitArr[];
public:
	//Member functions prototyping
	Card();
	Card(int suitRc, int faceRc);
	std::string getFace() const;
	std::string getSuit() const;
};

#endif // !_CARD_