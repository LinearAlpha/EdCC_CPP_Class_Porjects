/******************************************************************************
 * Project: LAB4
 * File: Source.cpp
 * Authors: Dean Ferris, Minpyo Kim and, Phumiphat Siripanich
 * Date: 01/28/2019
 * Description: This program allow the users to enter movie information
 *              including title, director, year of release, rating and RTscore
******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*******************************************************************************
* class MovieInfo with data members string title, director, rating, int year.
* and member functions setTitle, getTitle, setdirector, getdirector, setRating,
* getRating, setYear, getYear, setRtScore, getRtScore
******************************************************************************/
class MovieInfo
{

private:
	string title,
		director,
		rating;
	int year;
	double rtScore;
public:
	void setTitle(string title)
	{
		MovieInfo::title = title;
	}
	string getTitle() const
	{
		return title;
	}
	void setdirector(string director)
	{
		MovieInfo::director = director;
	}
	string getdirector() const
	{
		return director;
	}
	void setRating(string rating)
	{
		MovieInfo::rating = rating;
	}
	string getRating() const
	{
		return rating;
	}
	void setYear(int year)
	{
		MovieInfo::year = year;
	}
	int getYear() const
	{
		return year;
	}
	void setRtScore(double rtScore)
	{
		MovieInfo::rtScore = rtScore;
	}
	double getRtScore() const
	{
		return rtScore;
	}
};

//function prototyping
inline void cleanPipe();
void display(int& input);
void setMovie(vector<MovieInfo>& movie);
void displayInfo(const vector<MovieInfo>& list, int& index);
void displayInfoMenu(const vector<MovieInfo>& list, int& input);
void editDelete(vector<MovieInfo>& list, int& input);

/*************************************************************************
* Function: cleanPipe
* Description: Controls the overall flow of the application.
* Output: int - generic return type
*************************************************************************/
int main()
{
	//vector used to store movie information
	vector<MovieInfo> movie;
	cout << "Movie Information..." << endl << endl;
	bool check = true;
	int input;
	//switch case statments
	do
	{
		display(input);
		switch (input)
		{
			//Exit the program
		default:
			check = false;
			break;
			//1 - adding movie information
		case 1:
			setMovie(movie);
			break;
			//2 - view the list of the movie and informations
		case 2:
			//checking is the vector is empty
			if (movie.empty())
			{
				cout << "There is no movie information in the system" << endl
					<< endl;
				break;
			}
			else
			{
				displayInfoMenu(movie, input);
				displayInfo(movie, input);
			}
			break;
			//3 - edit or delect movie information
		case 3:
			//checking is the vector is empty
			if (movie.empty())
			{
				cout << "There is no movie information in the system" << endl
					<< endl;
				break;
			}
			else
			{
				displayInfoMenu(movie, input);
				editDelete(movie, input);
			}
			break;
		}
	} while (check);
	cout << "Thank tou for using.";
	//End of programming
	getchar();
	return 0;
}

/****************************************************************
* Function: cleanPipe
* Description: This function clears the string variable.
****************************************************************/
inline void cleanPipe()
{
	cin.clear();
	cin.ignore(100, '\n');
}

/***************************************************************
* Function: display
* Description: This function will display option for the user.
* Input: int& input - users input
***************************************************************/
void display(int& input)
{
	//declare variable and print options
	bool check = true;
	cout << "0 - Exit" << endl << "1 - Add Movie Information" << endl
		<< "2 - View Movie Information " << endl << "3 - Edit/Delete Movie Information" << endl;
	cout << endl << "> ";
	cin >> input;
	//Volet proof the user input
	while (check)
	{
		if (cin.fail())
		{
			cleanPipe();
			cout << "Please eneter integer." << endl;
			cout << "> ";
			cin >> input;
		}
		else if (0 > input || input > 3)
		{
			cleanPipe();
			cout << "Pleae enetr between 1 to 3" << endl;
			cout << "> ";
			cin >> input;
		}
		else
			check = false;
	}
	cleanPipe();
	return;
}

/*******************************************************************
* Function: setMovie
* Description: This function allows the users to enter movie detail.
* Input: vector<MovieInfo>& movie - vector that store movie details
*******************************************************************/
void setMovie(vector<MovieInfo>& movie)
{
	//declare variable
	string input;
	int input1 = 0;
	double rtInput = 0;
	//fillinf indivisual variavle
	movie.resize(movie.size() + 1);
	cout << "Enter The Title Of The Movie: ";
	getline(cin, input);
	movie.at(movie.size() - 1).setTitle(input);
	cout << "Enter The Director's Name: ";
	getline(cin, input);
	movie.at(movie.size() - 1).setdirector(input);
	cout << "Enter The Release Year: ";
	cin >> input1;
	bool check = true;
	//Volet proof the user input
	while (check)
	{
		if (cin.fail())
		{
			cleanPipe();
			cout << "Please enter integer." << endl;
			cout << "> ";
			cin >> input1;
		}
		else if (1900 > input1 || input1 > 9999)
		{
			cleanPipe();
			cout << "Please eneter between 1900 to 9999." << endl;
			cout << "> ";
			cin >> input1;
		}
		else
			check = false;
	}
	cleanPipe();
	movie.at(movie.size() - 1).setYear(input1);
	cout << "Enter The Rating: ";
	getline(cin, input);
	movie.at(movie.size() - 1).setRating(input);
	cout << "Enter Rotten Tomato Score: ";
	cin >> rtInput;
	check = true;
	//Volet proof the user input
	while (check)
	{
		if (cin.fail())
		{
			cleanPipe();
			cout << "Please enter integer." << endl;
			cout << "> ";
			cin >> rtInput;
		}
		else if (0 > rtInput || rtInput > 100)
		{
			cleanPipe();
			cout << "Please eneter between 0 to 100." << endl;
			cout << "> ";
			cin >> rtInput;
		}
		else
			check = false;
	}
	cleanPipe();
	movie.at(movie.size() - 1).setRtScore(rtInput);
	return;
}

/***************************************************************
* Function: displayInfoMenu
* Description: This function will display option for the user.
* Input: const vector<MovieInfo>& list - list of movies
*		 int& input - users input
***************************************************************/
void displayInfoMenu(const vector<MovieInfo>& list, int& input)
{
		//printing movie lists
		for (unsigned int i = 0; i < list.size(); i++)
		{
			cout << i + 1 << " - " << list.at(i).getTitle() << endl;
		}
		cout << "Selec movie: ";
		cin >> input;
		bool check = true;
		//Volet proof the user input
		while (check)
		{
			if (cin.fail())
			{
				cleanPipe();
				cout << "Please enter integer." << endl;
				cout << "> ";
				cin >> input;
			}
			else if (1 > input || input > list.size())
			{
				cleanPipe();
				cout << "Please eneter between 0 to " << list.size() << "."
					<< endl;
				cout << "> ";
				cin >> input;
			}
			else
				check = false;
		}
		input -= 1;
	return;
}

/***************************************************************
* Function: displayInfo
* Description: This function will display movie information.
* Input: const vector<MovieInfo>& list - list of movies.
*		 int& index - array index
***************************************************************/
void displayInfo(const vector<MovieInfo>& list, int& index)
{
	cout << endl << "Title: " << list.at(index).getTitle() << endl << endl;
	cout << "Director: " << list.at(index).getdirector() << endl << endl;
	cout << "Year: " << list.at(index).getYear() << endl << endl;
	cout << "Rating: " << list.at(index).getRating() << endl << endl;
	cout << "Rotten Tomatoes Scorce: " << list.at(index).getRtScore() << endl << endl;
	return;
}

/******************************************************************
* Function: editDelete
* Description: This function allows the users to edit the movie
* detail or remove it completely.
* Input: vector<MovieInfo>& list - provide access to the movie class
*		 int& input - users input
*******************************************************************/
void editDelete(vector<MovieInfo>& list, int& input)
{
	//printing information sentence
	cout << "Edit Rotten Tomatoes Score or, Delete Movie Information"
		<< endl;
	//declare variable
	int temp;
	cout << "Type 1, To Edit enter, or 2, to delete" << endl;
	cout << "1 or 2?" << endl << "> ";
	cin >> temp;
	bool check = true;
	//Volet proof the user input
	while (check)
	{
		if (cin.fail())
		{
			cleanPipe();
			cout << "Please enter integer." << endl;
			cout << "> ";
			cin >> temp;
		}
		else if (temp < 1 || temp > 2)
		{
			cleanPipe();
			cout << "Please eneter between 1 to 2." << endl;
			cout << "> ";
			cin >> temp;
		}
		else
			check = false;
	}
	if (temp == 1)
	{
		double tmp1;
		cout << "Enter the new Rotten Tomatoes Score: ";
		cin >> tmp1;
		check = true;
		//Volet proof the user input
		while (check)
		{
			if (cin.fail())
			{
				cleanPipe();
				cout << "Please enter integer." << endl;
				cout << "> ";
				cin >> tmp1;
			}
			else if (0 > tmp1 || tmp1 > 100)
			{
				cleanPipe();
				cout << "Please eneter between 0 to 100." << endl;
				cout << "> ";
				cin >> tmp1;
			}
			else
				check = false;
		}
		//replase variavle
		list.at(input).setRtScore(tmp1);
	}
	else
	{
		//erase choosed index from the vector
		list.erase(list.begin() + input);
	}
	return;
}