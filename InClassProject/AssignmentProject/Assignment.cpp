#include "Assignment.h"
#include <string>
#include <stdexcept>

using namespace std;

int Assignment::dueYear = 0;

Assignment::Assignment(string title, string description, int points,
	int dueDate, int dueMoth)
{
	Assignment::title = title;
	Assignment::description = description;
	setPoints(points);
	if (dueMoth > 0 && dueMoth < 13)
		Assignment::dueMoth = dueMoth;
	else
		throw out_of_range("Monthe must be 1 ... 12");
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (dueDate < 1 || dueDate > daysInMonth[Assignment::dueMoth - 1])
		throw out_of_range("Date does not match month");
	else
		Assignment::dueDate = dueDate;
}
string Assignment::getTitle()
{
	return title;
}
string Assignment::getDedcription()
{
	return description;
}
void Assignment::setDescription(string description)
{
	Assignment::description = description;
}
int Assignment::getPoints()
{
	return points;
}
void Assignment::setPoints(int point)
{
	if (point > 0)
		Assignment::points = point;
	else
		throw out_of_range("Point must be positive");
}
string Assignment::getDate()
{
	//month/date/year
	return to_string(dueMoth) + "/" + to_string(dueDate) + "/" +
		to_string(dueYear);
}
string Assignment::toString()
{
	return title + " is due " + getDate() + ". and is worth" + to_string(points) +
		"points.";
}