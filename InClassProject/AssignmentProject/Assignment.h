#ifndef _ASSIGNMENT_
#define _ASSIFNMENT_

#include <string>
#include <stdexcept>

/*
* Class: Assignment
* Description: Represent assignment of class
*/
class Assignment
{
private:
	std::string title;
	std::string description;
	int points, // must be a positive value
		dueDate,
		dueMoth;
	static int dueYear;
public:
	Assignment(std::string title, std::string description, int points,
		int dueDate, int dueMoth);
	std::string getTitle();
	std::string getDedcription();
	void setDescription(std::string description);
	int getPoints();
	void setPoints(int pointd);
	std::string getDate();
	std::string toString();
	static void setYear(int year)
	{
		if (year > 0)
			dueYear = year;
		else
			throw std::out_of_range("Year must be a positive value");
	}
};
#endif // _ASSIGNMENT_
