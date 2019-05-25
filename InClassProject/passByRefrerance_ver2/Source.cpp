#include <iostream>
#include <string>
#include <iomanip>

//using namespace std;

struct bookInfo
{
	int year;
	std::string title;
};

inline void cleanPie();
void displayInfo(bookInfo &book);

int main()
{
	bookInfo book[100];
	bool flag;
	int counter = 0, size = 0;
	do
	{
		displayInfo(book[counter]);
		std::cout << "enter 0 exit, 1 to continue" << std::endl << "> ";
		std::cin >> flag;
		if (std::cin.fail())
		{
			flag = true;
		}
		cleanPie();
		counter++;
	} while (flag);
	for (int i = 0; i < counter; i++)
	{
		if (book[counter].title.length() > size)
			size = book[i].title.length();
	}
	std::cout << std::left;
	for (int i = 0; i < counter; i++)
	{
		std::cout << std::setw(size + 3) << book[i].title << std::setw(4) << book[i].year << std::endl;
	}
	getchar();
	return 0;
}

inline void cleanPie()
{
	std::cin.clear();
	std::cin.ignore(100, '\n');
}

void displayInfo(bookInfo &book)
{
	std::cout << "please eneter the name of the book: ";
	std::getline(std::cin, book.title);
	std::cout << "Please enetet year: ";
	std::cin >> book.year;
	while (std::cin.fail())
	{
		cleanPie();
		std::cout << "please enetr integer: ";
		std::cin >> book.year;
	}
	cleanPie();
}

