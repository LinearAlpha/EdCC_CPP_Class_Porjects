/******************************************************************************
 * Project: LAB5
 * File: MovieInfo.h
 * Authors: Minpyo Kim
 * Date: 02/13/2019
 * Description: This file is containting defintion of class, and prototyp that
 *               giving brief information about class used on LAB5
******************************************************************************/
#ifndef _MOVIEINFO_
#define _MOVIEINFO_
#include <string>

/*******************************************************************************
* class MovieInfo with data members string title, director, rating, int year.
* and member functions setTitle, getTitle, setDirector, getDirector, setRating,
* getRating, setYear, getYear, setRtScore, getRtScore
******************************************************************************/
class MovieInfo
{
private:
	//Data members
	std::string title,
		director,
		rating;
	int year;
	double rtScore;
public:
	//Member functions prototyping
	MovieInfo(std::string title, std::string director, std::string rating, int year, double rtScore);
	MovieInfo(const MovieInfo& movie);
	void setTitle(std::string title);
	std::string getTitle() const;
	void setDirector(std::string director);
	std::string getDirector() const;
	void setRating(std::string rating);
	std::string getRating() const;
	void setYear(int year);
	int getYear() const;
	void setRtScore(double rtScore);
	double getRtScore() const;
	bool equals(const std::string rcTitle);
	std::string toString();
};

#endif // !_MOVIEINFO_