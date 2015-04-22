#include <iostream>
#include <fstream>
#include <string>
#include "movieTree.h"

using namespace std;

//function prototypes
void readFile(MovieNode*, string);
void printMenu();

int main()
{
	MovieNode movieList[100]; //making an array to read in the movies
	string filename = "movies.txt"; //read in the CLA for filename
	readFile(movieList, filename); //read the file
	MovieTree tree = MovieTree(&movieList[0]); //this constructor only sets the root (see .h file)
	for (int k=1;k<100;k++)
	{
		tree.addMovieNode(&movieList[k]); //adding each movie after the root to the list
	}
	string input;
	
	cout << "Thanks for Choosing Jess' Movie Database! \nWe have a repository with the top 100 movies right now,\norganized by year, most applicable genre, and rating!\nHow how you like to begin?" << endl;
	printMenu();
	cin >> input;
	bool running = true;
	while (running)
	{
		if (input == "1")
		{
			cout << "================================================================================" << endl;
			cout << "Here is a list of our movies:" << endl;
			tree.printMovieInventory(&movieList[0]);
			printMenu();
			cin >> input;
		}
		else if (input == "2")
		{
			cout << "Which title are you looking for?" << endl;
			string holder, title;
			getline(cin, holder);
			getline(cin, title);
			cout << "================================================================================" << endl;
			MovieNode *mov = tree.searchMovieTree(title);
			if(mov != NULL)
			{
				cout << "Here is the imformation we were able to finnd on that movie:" << endl;
				cout << "Title: " << mov->title << endl;
				cout << "Yeasr: " << mov->year << endl;
				cout << "Most Applicable Genre: " << mov->genre << endl;
				cout << "IMDB Rating: " << mov->rating << endl;
			}
			printMenu();
			cin >> input;
		}
		else if (input == "3")
		{
			cout << "Our database houses the following genres:" << endl;
			cout << "Action, Adventure, Crime, Comedy, Drama, Fantasy, Mystery, \nRomance, Science Fiction, and Western." << endl;
			cout << "Which genre would you like to browse?" << endl;
			string holder, genre;
			getline(cin, holder);
			getline(cin, genre);
			cout << "================================================================================" << endl;
			cout << "We were able to find these titles within the " << genre << " genre:" << endl;
			tree.printMoviesInGenre(&movieList[0], genre);
			printMenu();
			cin >> input;
		}
		else if (input == "4")
		{
			
			printMenu();
			cin >> input;
		}
		else if (input == "5")
		{
			
			printMenu();
			cin >> input;
		}
		else if (input == "6")
		{
			cout << "Goodbye!" << endl;
			running = false;
		}
		else
		{
			cin >> input;
		}
	}
}

void readFile(MovieNode* movieList, string filename)
{
	ifstream infile(filename);
	if (infile.is_open())
	{
		int i=0;
		//temp variables for the data at hand
		string _title;
		int _year;
		string _genre;
		double _rating;
		string line;
		while (getline(infile, line))
		{
			//TL;DR: reading through the file and comma separating to find the info I need per line
			int comma = line.find(",");
			_title = line.substr(0,comma);
			line = line.substr(comma+1);
			comma = line.find(",");
			_year = stoi(line.substr(0,comma));
			line = line.substr(comma+1);
			comma = line.find(",");
			_genre = line.substr(0,comma);
			line = line.substr(comma+1);
			_rating = stod(line);
			movieList[i].title = _title;
			movieList[i].year = _year;
			movieList[i].genre = _genre;
			movieList[i].rating = _rating;
			i++;
		}
		infile.close();
	}
}

void printMenu()
{
	cout << "======Main Menu=====" << endl;
	cout << "1. Print the entire movie inventory" << endl;
	cout << "2. Find information on a title" << endl;
	cout << "3. Find movies within a genre" << endl;
	cout << "4. Find movies above a certain rating" << endl;
	cout << "5. Recommended movies based on genre and rating" << endl;
	cout << "6. Quit" << endl;
}

