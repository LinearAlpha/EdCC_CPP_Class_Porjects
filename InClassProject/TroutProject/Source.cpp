#include <iostream>
#include <stdexcept>

using namespace std;

class Trout
{
	friend ostream& operator<<(ostream& output, const Trout& t)
	{
		output << "Lenght = " << t.lenght << "inches, weight = " << t.weight << "pound.";
		return output;
	}
public:
	Trout()
		: lenght(16), weight(1.5)
	{ };
	Trout(int transLength, double transWeight)
		: lenght(transLength), weight(transWeight)
	{ };

	int getLenght()
	{
		return lenght;
	}

	double getWeigth()
	{
		return weight;
	}

	bool operator<(const Trout& other)
	{
		if (lenght == other.lenght)
			return (weight < other.weight);
		else
			return (lenght < other.lenght);
	}




private:
	int lenght;
	double weight;
};

int main()
{
	Trout* list[3];
	Trout* t = new Trout(12, 1);
	list[0] = new Trout(12, 0);
	cout << *list[0] << endl;

	getchar();
	return 0;
}