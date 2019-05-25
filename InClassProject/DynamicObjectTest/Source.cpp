#include <iostream>
#include"Pizza.h"

using namespace std;

Pizza* makePizza();
void displayDetails(const Pizza* myPizza);

int main()
{
	Pizza* myPizza = makePizza();
	displayDetails(myPizza);

}

Pizza * makePizza()
{
	int size,
		slices;
	double cost;



	cout << "size: ";
	cin >> size;
	cin.ignore(100, '\n');
	cout << "slices: ";
	cin >> slices;
	cin.ignore(100, '\n');
	cost = 12.95;
	Pizza* pizza = new Pizza(size, slices, cost);
	return pizza;
}

void displayDetails(const Pizza * myPizza)
{
	cout << "You ordered a " << myPizza->setDiameter() <<
		" inch pizza"
}
