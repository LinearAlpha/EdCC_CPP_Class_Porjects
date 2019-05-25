#include <stdexcept>
#include "Pizza.h"

Pizza::Pizza()
{
	diameter = 12;
	numSlices = 6;
	cost = 5.99;
}

Pizza::Pizza(int diameter, int numSlices, double cost)
{
	Pizza::diameter = diameter;
	this->numSlices = numSlices;
	this->cost = cost;
}

int Pizza::getDiameter() const
{
	return diameter;
}

int Pizza::getNumSlices() const
{
	return numSlices;
}

double Pizza::getCost() const
{
	return cost;
}

void Pizza::setDiameter(int diameter)
{
	if (diameter == 12 || diameter == 14 || diameter == 16)
		this->diameter = diameter;
	else
		throw invarild_argument("Diameter must be 12, 14, or 16.")
}

void Pizza::setNumSlice(int numSlices)
{
	this->numSlices = numSlices;
}

void Pizza::setCost(double cost)
{
	this->cost = cost;
}
