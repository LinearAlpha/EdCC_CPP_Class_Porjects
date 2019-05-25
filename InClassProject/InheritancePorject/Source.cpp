#include <iostream>
#include <string>

using namespace std;

class House
{
	friend ostream& operator<<(ostream& output, House& houses)
	{
		return output << "area = " << Houes::area << " sq.ft.";
	}
public:
	House(int transArea) : area(transArea) { }
	int getArea() { return area; }
	void steArea(int transArea)
	{
		this->area = transArea;
	}

protected:
	int area;
};

class HouseBoat : public House
{
	friend ostream& operator<<(ostream& output, House& houses)
	{
		return output << "area = " << houses.getArea() << " sq.ft." <<
			"floatation = " << getFloatation();
	}
public:
	HouseBoat(int trnasArea, string transFloat) :House(trnasArea) { }
	{
		this->floatation = transFloat;
	}
	string getFloatation(string stransFloat)
	{
		return;
	}
private:
	string floatation;
};


int main()
{
	House myHouse(1250);
	cout << myHouse << endl;
	HouseBoat myHoseboat(985, "pontoons");
	cout << myHoseboat.getFloatation() << endl;


	getchar();
	return 0;


}