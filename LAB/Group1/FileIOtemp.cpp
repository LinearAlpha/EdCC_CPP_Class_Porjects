/******************************************************************************
* PROJECT: Final Project
* FILE: FileIO.cpp
* AUTHOR(S): Dean Ferris, Ton That Quynh Thong, Minpyo Kim and Kalkidan Tamirat
* DATE: 3/12/2019
* DESCRIPTION: This console-based program imitates a library database & allows
*			   user to add/delete books, bibliophiles, and view their activity.
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <ios>
#include <direct.h>
#include "FileIOtemp.h"

using namespace std;

void message(const string& tmp)
{
	string message = "File not open " + tmp;
	throw invalid_argument(message);
}

string directoryInfo(const int& option)
{	
	if (option == 1)
	{		
		return "AllBibliophile.txt";
	}
	else if (option == 2)
	{		
		return "AllBooks.txt";
	}
	else if (option == 3)
	{		
		return  "AllActivity.txt";
	}
	else
		throw out_of_range("Please select option");
}

//Write Bibliophile, by appending at the end of the file, each time one bibliophile.
void writeBibliophileFile(const Bibliophile& aBibliophile)
{	
	ofstream file(directoryInfo(1), ios::app);
	if ((file.is_open()))
	{
		file << aBibliophile.getName() << ".";
		file << aBibliophile.getSID() << ".";
		file << aBibliophile.getOccupation();
		file << '\n';
		file.close();
	}
	else
	{
		message(directoryInfo(1));
	}
}

//Delete Bibliophile from here. Overide the file. whole vector.
void deleteBibliophileFile(vector<Bibliophile> allBibliphile)
{
	ofstream file(directoryInfo(1), ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < allBibliphile.size(); i++)
		{
			file << allBibliphile.at(i).getName() << ".";
			file << allBibliphile.at(i).getSID() << ".";
			file << allBibliphile.at(i).getOccupation();
			file << '\n';
		}
		file.close();
	}
	else
		message(directoryInfo(1));
}

//Assign the all Bibliophile from the text file.
vector<Bibliophile> updateBibliophileFile()
{
	vector<Bibliophile> tempReturn;
	string name, occupation, sID;
	ifstream file(directoryInfo(1), ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, name, '.');
			getline(file, sID, '.');
			getline(file, occupation);
			Bibliophile temp(name, sID, occupation);
			tempReturn.push_back(temp);
		}
		tempReturn.pop_back(); //Back door cleanbuffer.
		file.close();
	}
	else
		message(directoryInfo(1));
	return tempReturn;
}

//Write book, by appending at the end of the file, each time one book.
void writeBookFile(const Book& aBook)
{
	ofstream file(directoryInfo(2), ios::app);
	if (file.is_open())
	{
		file << aBook.getBookTitle() << "." <<
			aBook.getBookAuthor() << "." <<
			aBook.getPublisher() << "." <<
			aBook.getEdition() << "." <<
			aBook.getBookISBN() << "." <<
			aBook.getBookYearPublished();
		file << '\n';
		file.close();
	}
	else
		message(directoryInfo(2));
}

//Delete Book from here. Overide the file. whole vector.
void deleteOrChangeBookFile(vector<Book>& allBook)
{
	ofstream file(directoryInfo(2), ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < allBook.size(); i++)
		{
			file << allBook.at(i).getBookTitle() << "." <<
				allBook.at(i).getBookAuthor() << "." <<
				allBook.at(i).getPublisher() << "." <<
				allBook.at(i).getEdition() << "." <<
				allBook.at(i).getBookISBN() << "." <<
				allBook.at(i).getBookYearPublished();
			file << '\n';
		}
		file.close();
	}
	else
		message(directoryInfo(2));
}

//Assign the all book from the text file.
vector<Book> updateBookFile()
{	
	vector<Book> tempReturn;
	string title, author, publisher, yearPublishedString, edition, iSBN, SID;
	int yearPublishedInt = 0;
	ifstream file(directoryInfo(2));
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, title, '.');
			getline(file, author, '.');
			getline(file, publisher, '.');
			getline(file, edition, '.');
			getline(file, iSBN, '.');
			getline(file, yearPublishedString);
			yearPublishedInt = stoi(yearPublishedString); //convert string to int.
			Book temp(title, author, edition, yearPublishedInt, publisher, iSBN);
			tempReturn.push_back(temp);
		}
		tempReturn.pop_back(); //Back door cleanbuffer.
		file.close();
	}
	else
		message(directoryInfo(2));
	return tempReturn;
}

void writeActivityFile(const vector<Activity>& allActivity)
{
	ofstream file(directoryInfo(3), ios::trunc);
	if (file.is_open())
	{
		if (allActivity.size() > 0)
		{
			for (size_t i = 0; i < allActivity.size(); i++)
			{
				file << allActivity.at(i).getSID() << ".";
				file << allActivity.at(i).getISBN() << ".";
				file << allActivity.at(i).getCheckedOutDate() << ".";
				file << allActivity.at(i).getDueDate() << ".";
				file << allActivity.at(i).getCheckedInDate() << ".";
				file << '\n';
			}
		}
		file.close();
	}
	else
		message(directoryInfo(3));
}

//Update the record from here.
vector<Activity> updateActivityFile()
{
	vector<Activity> tempReturn;
	ifstream file(directoryInfo(3));
	string sID, iSBN, checkOutDate, dueDate, checkInDate;
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, sID, '.');
			getline(file, iSBN, '.');
			getline(file, checkOutDate, '.');
			getline(file, dueDate, '.');
			getline(file, checkInDate, '.');
			Activity tempActivity(sID, iSBN, checkOutDate);
			tempActivity.setCheckedInDate(checkInDate);
			tempReturn.push_back(tempActivity);
			file.ignore(100, '\n');
		}
		tempReturn.pop_back(); //Back door cleanbuffer.
		file.close();
	}
	else
		message(directoryInfo(3));
	return tempReturn;
}
