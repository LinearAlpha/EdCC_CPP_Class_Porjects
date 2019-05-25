/******************************************************************************
* PROJECT: Final Project
* FILE: FileIO.h
* AUTHOR(S): Dean Ferris, Ton That Quynh Thong , Minpyo Kim & Kalkidan Tamirat
* DATE: 3/12/2019
* DESCRIPTION: This console-based program imitates a library database & allows
*			   user to add/delete books, bibliophiles, and view their activity
******************************************************************************/
#ifndef _FILEIOTEMP_
#define _FILEIOTEMP_

#include <vector>
#include <string>
#include "Bibliophile.h"
#include "Book.h"
#include "Activity.h"

//Function prototype
void message(const std::string& tmp);
std::string directoryInfo(const int& option);
void writeBibliophileFile(const Bibliophile& aBibliophile);
void writeBookFile(const Book& aBook);
void deleteBibliophileFile(std::vector<Bibliophile> allBibliphile);
std::vector<Bibliophile> updateBibliophileFile();
std::vector<Book> updateBookFile();
void deleteOrChangeBookFile(std::vector<Book>& allBook);
void writeActivityFile(const std::vector<Activity>& allActivity);
std::vector<Activity> updateActivityFile();

#endif // !_FILEIOTEMP_
