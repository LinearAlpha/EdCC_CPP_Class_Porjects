#include "Student.h"
#include <string>

using namespace std;

Student::Student(int studenId, string lastName, string firstName) : SID(studenId)
{
	setLastName(lastName);
	setFirstName(firstName);
	points = 0;
	numStudents++;
}

Student::~Student()
{
	numStudents--;
}

string Student::getName() const
{
	return lastName + ", " + firstName;
}

int Student::getPints()
{
	return Student::points;
}

void Student::setLastName(string lastName)
{
	Student::lastName = lastName.substr(0, 25);
}

void Student::setFirstName(string firstName)
{
	Student::firstName = firstName.substr(0, 25);
}

void Student::addPoints(int newPoint)
{
	if (newPoint > 0)
	{
		points += newPoint;
	}
}

bool Student::equals(const Student& s)
{
	return(SID == s.SID);
}

int Student::numStudents = 0;