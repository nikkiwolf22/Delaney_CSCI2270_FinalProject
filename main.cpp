#include <iostream>
#include <fstream>
#include <string>
#include "movieTree.h"
#include <time.h> //used for the srand call, see below

using namespace std;

//function prototypes
void readFile(MovieNode*, string);
void printMenu();

int main()
{
	srand (time(NULL)); //this is a seed for randomization based on uptime for the 
	MovieNode movieList[100]; //making an array to read in the movies
	string filename = "";

	/* 
	This loop will ask the user for the filename, and if the filename is incorrect,
	will allow the user to try again. Once a valid filename is entered, the loop will terminate.
	*/
	bool fileLoop = true;
	while(fileLoop){
		cout<<"Enter the name of the data file (ex: Movies.txt):"<<endl;
		cin>>ws;
		getline(cin, filename);
		//test to make sure the file actually exists
		ifstream testFile;
		testFile.open(filename.c_str());
		if(testFile.is_open() == false){
			cout<<"Woops! Could not open file named: " << filename<<endl;
			cout<<"Check spelling/capitalization and retry."<<endl;
		}
		else{
			testFile.close();
			cout<<"Loading movie data from file named: "<< filename<<endl;
			fileLoop = false;
			break;
		}
	}
	
	readFile(movieList, filename);
	MovieTree tree = MovieTree(&movieList[0]); //this constructor only sets the root (see .h file)
	for (int k=1;k<100;k++)
	{
		tree.addMovieNode(&movieList[k]); //adding each movie after the root to the list at index k
	}
	string input; //makes a string to accent user input
	
	cout << "Thanks for Choosing Jess' Movie Database! \nWe have a repository with the top 100 movies right now,\norganized by year, most applicable genre, and rating!\nHow how you like to begin?" << endl;
	printMenu(); //se below
	cin >> input;
	bool running = true; //allows command 10 to exit
	while (running) //the following are all pretty self-explanatory except when otherwise commented. It's just a lot of couts and cins
	{
		if (input == "1")
		{
			cout << "================================================================================" << endl; //spacer for visual convenience
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
			cout << "Due to the quality of the movies our database houses, we do not \nhave records below an 8.3 star IMDB rating (out of 10)." << endl;
			cout << "Enter a minimum rating to search for:" << endl;
			string holder, _rating;
			getline(cin, holder);
			getline(cin, _rating);
			double rating = stod(_rating);
			cout << "================================================================================" << endl;
			cout << "We were able to find these titles above a(n) " << rating << " IMDB rating:" << endl;
			tree.printMoviesAboveRating(&movieList[0], rating);
			printMenu();
			cin >> input;
		}
		else if (input == "5")
		{
			cout << "Due to the quality of the movies our database houses, we do not \nhave records below an 8.3 star IMDB rating (out of 10)." << endl;
			cout << "Enter a maximum rating to search for:" << endl;
			string holder, _rating;
			getline(cin, holder);
			getline(cin, _rating);
			double rating = stod(_rating);
			cout << "================================================================================" << endl;
			cout << "We were able to find these titles below a(n) " << rating << " IMDB rating:" << endl;
			tree.printMoviesBelowRating(&movieList[0], rating);
			printMenu();
			cin >> input;
		}
		else if (input == "6")
		{
			cout << "What is the most recent year you'd like to see?" << endl;
			string holder, _year;
			getline(cin, holder);
			getline(cin, _year);
			int year = stoi(_year);
			cout << "================================================================================" << endl;
			cout << "We were able to find these titles made on or before "<< year << ":" << endl;
			tree.printOlderMovies(&movieList[0], year);
			printMenu();
			cin >> input;
		}
		else if (input == "7")
		{
			cout << "What is the least recent year you'd like to see?" << endl;
			string holder, _year;
			getline(cin, holder);
			getline(cin, _year);
			int year = stoi(_year);
			cout << "================================================================================" << endl;
			cout << "We were able to find these titles made on or after "<< year << ":" << endl;
			tree.printNewerMovies(&movieList[0], year);
			printMenu();
			cin >> input;
		}
		else if (input == "8")
		{
			cout << "Our database houses the following genres:" << endl;
			cout << "Action, Adventure, Crime, Comedy, Drama, Fantasy, Mystery, \nRomance, Science Fiction, and Western." << endl;
			cout << "Which genre would you like us to recommend?" << endl;
			string holder, genre, _rating;
			getline(cin, holder);
			getline(cin, genre);
			cout << "Great! Next, let's talk about ratings.\nDue to the quality of the movies our database houses, we do not \nhave records below an 8.3 star IMDB rating (out of 10)." << endl;
			cout << "Enter a minimum rating for us to recommend:" << endl;
			getline(cin, _rating);
			double rating = stod(_rating);
			cout << "================================================================================" << endl;
			cout << "Here our our viewing recommendations for you:" << endl;
			cout << genre << " " << rating << endl;
			tree.recommendMovies(&movieList[0], genre, rating);
			printMenu();
			cin >> input;
		}
		else if (input == "9")
		{
			cout << "================================================================================" << endl;
			int index = rand() % 100; //generates a random number betweek 0 and 99 based on the seed above
			tree.randomMovieInfo(&movieList[index]);
			printMenu();
			cin >> input;
		}
		else if (input == "10")
		{
			cout << "Goodbye!" << endl;
			running = false;
		}
		else //if the input the user puts in wasn't any of the above
		{
			cin >> input;
		}
	}
}

/*readFile

	Prototype: void readFile(MovieNode*, string)
	Description: reads the provided file line-for-line and makes a MovieNode item out of each line's information
	Expected Inputs: none (takes no parameters)
	Expected Outputs: function is void (no outputs)
	Preconditions: No user-activated functions are necessary before this function can run
	Postconditions: after this function runs, the MovieList array will have a MovieNode at index 0,
		which will allow for root creation for our binary search tree
*/

void readFile(MovieNode* movieList, string filename)
{
	ifstream infile(filename); //opening a file with that file name
	if (infile.is_open())
	{
		int i=0;
		//temp variables for the data at hand:
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

/*printMenu

	Prototype: void printMenu()
	Description: print all the movies in the binary search tree for this program
	Expected Inputs: none (takes no parameters)
	Expected Outputs: function is void (no outputs)
	Preconditions: No user-activated functions are necessary before this function can run
	Postconditions: There are no expected changes to the state of the program after this function has run
*/

void printMenu()
{
	cout << "======Main Menu=====" << endl;
	cout << "1. Print the entire movie inventory" << endl;
	cout << "2. Find information on a title" << endl;
	cout << "3. Find movies within a genre" << endl;
	cout << "4. Find movies above a certain rating" << endl;
	cout << "5. Find movies below a certain rating" << endl;
	cout << "6. Find movies older than a certain date" << endl;
	cout << "7. Find movies newer than a certain date" << endl;
	cout << "8. Recommended movies based on genre and rating" << endl;
	cout << "9. I'm feeling lucky (random)" << endl;
	cout << "10. Quit" << endl;
}

