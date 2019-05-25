#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

void setName(Student& student);
vector<string> getName(const vector<Student*>& list);
void addAndDelecte();

int main()
{
	Student student1(123, "Kim", "test");
	Student student2(333, "test", "test2");
	Student student3(444, "test4", "test5");
	vector<Student*> studens;
	studens.push_back(&student1);
	studens.push_back(&student2);
	studens.push_back(&student3);
	vector<string> names = getName(studens);
	for (int i = 0; i < names.size(); i++)
		cout << names.at(i) << " ";
	cout << endl;
	cout << "Num Students = " << Student::getNumStudens() << endl;
	addAndDelecte();
	cout << "Num Students = " << Student::getNumStudens() << endl;
	//end program
	getchar();
	return 0;
}

void setName(Student& student)
{
	cout << "Last name: ";
	string input;
	getline(cin, input);
	student.setLastName(input);
}

vector<string> getName(const vector<Student*>& list)
{
	vector<string> names;
	for (int i = 0; i < list.size(); i++)
		names.push_back(list.at(i)->getName());
	return names;
}

void addAndDelecte()
{
	Student student(1, "a", "b");
	cout << "-Num Students = " << Student::getNumStudens() << endl;
	student.~Student();
	cout << "-Num Students = " << Student::getNumStudens() << endl;
}