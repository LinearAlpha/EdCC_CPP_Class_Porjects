#ifndef _PIZZA_
#define _PIZZA_

class Pizza
{
public:
	Pizza();
	Pizza(int diameter, int numSlices, double cost);
	int getDiameter() const;
	int getNumSlices() const;
	double getCost() const;
	void setDiameter(int diameter);
	void setNumSlice(int numSlices);
	void setCost(double cost);


private:
	int diameter,
		numSlices;
	double cost;
};

#endif // !_PIZZA_




