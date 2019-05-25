/******************************************************************************
 * Project: LAB5
 * File: MovieInfo.cpp
 * Authors: Minpyo Kim
 * Date: 02/13/2019
 * Description: This file is source file of MovieInfo.h
******************************************************************************/
#include "MovieInfo.h"
#include <string>

/******************************************************************************
* Function: MovieInfo
* Description: Constructor of object.
* Input: std::string title - title of movie
*        std::string director - director of movie
*        int year - year of movie published
*        double rtScore - rotten tomatoes score
******************************************************************************/
MovieInfo::MovieInfo(std::string title, std::string director,
	std::string rating, int year, double rtScore)
{
	setTitle(title);
	setDirector(director);
	setRating(rating);
	setYear(year);
	setRtScore(rtScore);
}

/******************************************************************************
* Function: MovieInfo
* Description: Constructor of object for copying.
* Input: const MovieInfo& movie - setted object that what to copy
******************************************************************************/
MovieInfo::MovieInfo(const MovieInfo& movie)
{
	setTitle(movie.title);
	setDirector(movie.director);
	setRating(movie.rating);
	setYear(movie.year);
	setRtScore(movie.rtScore);
}

/******************************************************************************
* Function: setTitle
* Description: This function will store title of movie
* Input: std::string title - movie title that user entered 
******************************************************************************/
void MovieInfo::setTitle(std::string title)
{
	MovieInfo::title = title;
}

/******************************************************************************
* Function: getTitle
* Description: Receive movie title form data members and transfer to function
*              that requested
* Outpu: std::string - transfering movie title
******************************************************************************/
std::string MovieInfo::getTitle() const
{
	return title;
}

/******************************************************************************
* Function: setDirector
* Description: This function will store director of movie
* Input: std::string director - movie director that user entered
******************************************************************************/
void MovieInfo::setDirector(std::string director)
{
	MovieInfo::director = director;
}

/******************************************************************************
* Function: getDirector
* Description: Receive director of movie form data members and transfer to 
*			   function that requested
* Outpu: std::string - transfering director of movie
******************************************************************************/
std::string MovieInfo::getDirector() const
{
	return director;
}

/******************************************************************************
* Function: setRating
* Description: This function will store rating of movie
* Input: std::string rating - that rating of movie that user entered
******************************************************************************/
void MovieInfo::setRating(std::string rating)
{
	MovieInfo::rating = rating;
}

/******************************************************************************
* Function: getRating
* Description: Receive rating of movie form data members and transfer to 
*              function that requested
* Outpu: std::string - transfering rating of movie
******************************************************************************/
std::string MovieInfo::getRating() const
{
	return rating;
}

/******************************************************************************
* Function: setYear
* Description: This function will store the published year of movie
* Input: int year - the published year of movie that user entered
******************************************************************************/
void MovieInfo::setYear(int year)
{
	MovieInfo::year = year;
}

/******************************************************************************
* Function: getYear
* Description: Receive published year of movie form data members and transfer 
*              to function that requested
* Outpu: int - transfering published year of movie
******************************************************************************/
int MovieInfo::getYear() const
{
	return year;
}

/******************************************************************************
* Function: setRtScore
* Description: This function will store the rotten tomatoes score of movie
* Input: double rtScore - the rotten tomatoes score of movie that user entered
******************************************************************************/
void MovieInfo::setRtScore(double rtScore)
{
	MovieInfo::rtScore = rtScore;
}

/******************************************************************************
* Function: getRtScore
* Description: Receive rotten tomatoes of movie form data members and transfer 
*              to function that requested
* Output: int - transfering rotten tomatoes of movie
******************************************************************************/
double MovieInfo::getRtScore() const
{
	return rtScore;
}

/******************************************************************************
* Function: equals
* Description: Receive rotten tomatoes of movie form data members and transfer
*              to function that requested
* Input: const std::string rcTitle - movie title that user entered
* Output: bool - true, title recived is in the storage
*             - flase, there is no matching title
******************************************************************************/
bool MovieInfo::equals(const std::string rcTitle)
{
	return (title == rcTitle);
}

/******************************************************************************
* Function: toString
* Description: Recall all of data members and compose in to string
* Output: std::string - movie information that composed to string
******************************************************************************/
std::string MovieInfo::toString()
{
	//Declare variable
	std::string temp(16, '\0');
	auto written = std::snprintf(&temp[0], temp.size(), "%.1f", rtScore);
	temp.resize(written);
	return "\nTitle: " + title + "\nDirector: " + director + "\nYear: " + 
		std::to_string(year) + "\nRating: " + rating + "\nRT-Score: " + temp +
		" %";
}
