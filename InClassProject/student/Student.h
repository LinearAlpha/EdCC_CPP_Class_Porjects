#ifndef _STUDENT_
#define _STUDENT_

#include <string>

class Student
{
private:
	std::string lastName;
	std::string firstName;
	int points;
	Student(const Student& student);
	static int numStudents;
public:
	const int SID;
	Student(int studenId, std::string lastName, std::string firstName);
	~Student();
	std::string getName() const;
	int getPints();
	void setLastName(std::string lastName);
	void setFirstName(std::string firstName);
	void addPoints(int newPoint);
	bool equals(const Student& s);
	static int getNumStudens()
	{
		return numStudents;
	}
};

#endif // !_STUDENT_