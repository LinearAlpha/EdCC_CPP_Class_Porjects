#include <iostream>
#include <string>

using namespace std;

class CreditCard
{
public:
	CreditCard() {}
	CreditCard(long long cardNumber)
	{
		this->cardNumber = cardNumber;
	}
	long long getCardNumber()
	{
		return cardNumber;
	}
private:
	long long cardNumber;
};

class Address
{
public:
	Address() {};
	Address(string street, string city, string state)
	{
		this->street = street;
		this->city = city;
		this->state = state;
	}
	string getAddress()
	{
		return street + ", " + city + ", " + state;
	}
private:
	string street,
		city,
		state;
};

class Customer
{
public:
	Customer(string name, CreditCard card, string street, string city,
		string state)
	{
		this->name = name;
		this->card = card;
		Address addressTemp(street, city, state);
		this->address = addressTemp;
	}
	string getName()
	{
		return name;
	}
	CreditCard getCard()
	{
		return card;
	}
	string getAddress()
	{
		return address.getAddress();
	}
private:
	string name;
	CreditCard card;
	Address address;
};

class Purchase
{
public:
	Purchase(double total)
	{
		this->total = total;
	}
	double getTotal()
	{
		return total;
	}
	string getDetails(Customer customer)
	{
		//Not been store in data menber -> association
		return customer.getName() + " ,at " + customer.getAddress() +
			"has purchased $" + to_string(total) +
			" worth of merchandise using card number" +
			to_string(customer.getCard().getCardNumber()) + ".";
	}
private:
	double total;
};

int main()
{
	CreditCard card(123412341234L);
	Customer c("Minnie Mouse", card, "123 Maple Lane", "Seattle", "WA");
	Purchase p(12.95);
	//Asociation
	cout << p.getDetails(c) << endl;

	//end program
	getchar();
	return 0;
}