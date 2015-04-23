#include <iostream>
#include <fstream>
#include <string>
#include "movieTree.h"

using namespace std;

//did not consider this function complicated or significant enough to put a lengthy description here or in the ducomentation file
MovieTree::MovieTree(MovieNode* _root)
{
	root = _root;//all this function does is set the root. I know, weird, but it worked
}

//did not consider this function complicated or significant enough to put a lengthy description here or in the ducomentation file
MovieTree::~MovieTree()
{
	
}

/*printMovieInventory

	Prototype: void printMovieInventory(MovieNode* root)
	Description: print all the movies in the binary search tree for this program
	Expected Inputs: root, which is a MovieNode pointer
	Expected Outputs: function is void (no outputs)
	Preconditions: No user-activated functions are necessary before this function can run. The only necessary function is
		the creation of the root for the binary search tree, which happens automatically before any user prompts are called.
	Postconditions: There are no expected changes to the state of the program after this function has run 

*/

void MovieTree::printMovieInventory(MovieNode* current) //this follows the convention from lecture
{
	if(current->leftChild != NULL)
	{
		printMovieInventory(current->leftChild); //function calls itself on the left child
    }
    cout << current->title << " (" << current->year << ")" << endl; //prints movie in the desired format of Title (year)
    if(current->rightChild != NULL)
    {
		printMovieInventory(current->rightChild); //function calls itself on the right child
    }
}

/*addMovieNode

	Prototype: void addMovieNode(MovieNode* m)
	Description: adds movies to the binary search tree for this program
	Expected Inputs: m, which is a MovieNode pointer
	Expected Outputs: function is void (no outputs)
	Preconditions: No user-activated functions are necessary before this function can run. The only necessary function is
		the creation of the root for the binary search tree, which happens automatically before any user prompts are called.
	Postconditions: after this function runs, the program's binary search tree will have a new movie node in its proper place

*/

void MovieTree::addMovieNode(MovieNode* m) //pretty straightforward, follows lecture convention as well
{
	bool placed = false;
	MovieNode* c = root; //starts at root
	while (!placed)
	{
		if (m->title < c->title) //if the movie to be added has a title lower alphabetically than the current title
		{
			if (c->leftChild == NULL)
			{
				m->parent = c;
				c->leftChild = m;
				placed = true;
			}
		}
		else //if the movie to be added has a title higher alphabetically than the current title
		{
			if (c->rightChild == NULL)
			{
				m->parent = c;
				c->rightChild = m;
				placed = true;
			}
		}
		if (!placed)
		{
			if (m->title < c->title)
			{
				c = c->leftChild;
			}
			else
			{
				c = c->rightChild;
			}
		}
	}
}

/*searchMovieTree

	Prototype: MovieNode* searchMovieTree(std::string title)
	Description: searches the binary search tree for a match with the title specified
	Expected Inputs: title, which is a string
	Expected Outputs: a MovieNode pointer which pointers to the movie with the specified title
	Preconditions: No user-activated functions are necessary before this function can run. The only necessary function is
		the creation of the root for the binary search tree, which happens automatically before any user prompts are called.
	Postconditions: There are no expected changes to the state of the program after this function has run 

*/

MovieNode* MovieTree::searchMovieTree(std::string name) //very similar to above function
{
	bool found = false;
	MovieNode* c = root; //starts at root
	while (!found)
	{

		if (name < c->title) //if the movie you're looking for has a title lower alphabetically than the current title
		{
			if (c->leftChild != NULL)
			{
				c = c->leftChild;
			}
			else
			{
				found = true;
				cout << "Movie not found." << endl;
			}
		}
		else if (name > c->title) //if the movie you're looking for has a title higher alphabetically than the current title
		{
			if (c->rightChild != NULL)
			{
				c = c->rightChild;
			}
			else
			{
				found = true;
				cout << "Movie not found." << endl;
			}
		}
		else if (name == c->title) //if the movie you're looking for has the same title as the current title
		{
			found = true;
			return c;
		}
	}
}

/*printMoviesInGenre

	Prototype: void printMoviesInGenre(MovieNode* current, std::string genre)
	Description: finds all the movies within the specified genre and prints them
	Expected Inputs: current, which is a MovieNode pointer
	Expected Outputs: function is void (no outputs)
	Preconditions: No user-activated functions are necessary before this function can run. The only necessary function is
		the creation of the root for the binary search tree, which happens automatically before any user prompts are called.
	Postconditions: There are no expected changes to the state of the program after this function has run 

*/

void MovieTree::printMoviesInGenre(MovieNode* current, string genre)
{
	if(current->leftChild != NULL)
	{
		printMoviesInGenre(current->leftChild, genre); //function calls itself on the left child
    }
    if(current->genre == genre) //if the genre of the current movie is the same as the one you're looking for
    {
		cout << current->title << " (" << current->year << ")" << endl; //prints movie in the desired format of Title (year)
	}
    if(current->rightChild != NULL)
    {
		printMoviesInGenre(current->rightChild, genre); //function calls itself on the right child
    }
}

/*printMoviesAboveRating

	Prototype: void printMoviesAboveRating(MovieNode* current, double rating)
	Description: finds all the movies at or above the specified rating and prints them
	Expected Inputs: current, which is a MovieNode pointer
	Expected Outputs: function is void (no outputs)
	Preconditions: No user-activated functions are necessary before this function can run. The only necessary function is
		the creation of the root for the binary search tree, which happens automatically before any user prompts are called.
	Postconditions: There are no expected changes to the state of the program after this function has run 

*/

void MovieTree::printMoviesAboveRating(MovieNode* current, double rating)
{
	if(current->leftChild != NULL)
	{
		printMoviesAboveRating(current->leftChild, rating); //function calls itself on the left child
    }
    if(current->rating >= rating) //if the rating of the current movie is the same as or higher than the one you're looking for
    {
		cout << current->title << " (" << current->year << ")" << endl; //prints movie in the desired format of Title (year)
	}
    if(current->rightChild != NULL)
    {
		printMoviesAboveRating(current->rightChild, rating); //function calls itself on the right child
    }
}

/*printMoviesBelowRating

	Prototype: void printMoviesBelowRating(MovieNode* current, double rating)
	Description: finds all the movies at or below the specified rating and prints them
	Expected Inputs: current, which is a MovieNode pointer
	Expected Outputs: function is void (no outputs)
	Preconditions: No user-activated functions are necessary before this function can run. The only necessary function is
		the creation of the root for the binary search tree, which happens automatically before any user prompts are called.
	Postconditions: There are no expected changes to the state of the program after this function has run 

*/

void MovieTree::printMoviesBelowRating(MovieNode* current, double rating)
{
	if(current->leftChild != NULL)
	{
		printMoviesBelowRating(current->leftChild, rating); //function calls itself on the left child
    }
    if(current->rating <= rating) //if the rating of the current movie is the same as or lower than the one you're looking for
    {
		cout << current->title << " (" << current->year << ")" << endl; //prints movie in the desired format of Title (year)
	}
    if(current->rightChild != NULL)
    {
		printMoviesBelowRating(current->rightChild, rating); //function calls itself on the right child
    }
}

/*printOlderMovies

	Prototype: void printOlderMovies(MovieNode* current, int year)
	Description: finds all the movies as old or older than the specified year and prints them
	Expected Inputs: current, which is a MovieNode pointer
	Expected Outputs: function is void (no outputs)
	Preconditions: No user-activated functions are necessary before this function can run. The only necessary function is
		the creation of the root for the binary search tree, which happens automatically before any user prompts are called.
	Postconditions: There are no expected changes to the state of the program after this function has run 

*/

void MovieTree::printOlderMovies(MovieNode* current, int year)
{
	if(current->leftChild != NULL)
	{
		printOlderMovies(current->leftChild, year); //function calls itself on the left child
    }
    if(current->year <= year) //if the creation year of the current movie is the same as or older than the one you're looking for
    {
		cout << current->title << " (" << current->year << ")" << endl; //prints movie in the desired format of Title (year)
	}
    if(current->rightChild != NULL)
    {
		printOlderMovies(current->rightChild, year); //function calls itself on the right child
    }
}

/*printNewerMovies

	Prototype: void printNewerMovies(MovieNode* current, int year)
	Description: finds all the movies as new or newer than the specified year and prints them
	Expected Inputs: current, which is a MovieNode pointer
	Expected Outputs: function is void (no outputs)
	Preconditions: No user-activated functions are necessary before this function can run. The only necessary function is
		the creation of the root for the binary search tree, which happens automatically before any user prompts are called.
	Postconditions: There are no expected changes to the state of the program after this function has run 

*/

void MovieTree::printNewerMovies(MovieNode* current, int year)
{
	if(current->leftChild != NULL)
	{
		printNewerMovies(current->leftChild, year); //function calls itself on the left child
    }
    if(current->year >= year) //if the creation year of the current movie is the same as or newer than the one you're looking for
    {
		cout << current->title << " (" << current->year << ")" << endl; //prints movie in the desired format of Title (year)
	}
    if(current->rightChild != NULL)
    {
		printNewerMovies(current->rightChild, year); //function calls itself on the right child
    }
}

/*recommendMovies

	Prototype: void recommendMovies(MovieNode* current, std::string genre, double rating)
	Description: takes in a genre and a rating from the user, and finds and prints all movies within that genre and at or above that rating
	Expected Inputs: current, which is a MovieNode pointer
	Expected Outputs: function is void (no outputs)
	Preconditions: No user-activated functions are necessary before this function can run. The only necessary function is
		the creation of the root for the binary search tree, which happens automatically before any user prompts are called.
	Postconditions: There are no expected changes to the state of the program after this function has run 

*/

void MovieTree::recommendMovies(MovieNode* current, std::string genre, double rating)
{
	if(current->leftChild != NULL)
	{
		recommendMovies(current->leftChild, genre, rating); //function calls itself on the left child
    }
    if(current->rating >= rating && current->genre == genre) //if the rating of the current movie is the same as or higher than the one you're looking for,
															 //and the genre of the current movie is the same as the one you're looking for
    {
		cout << current->title << " (" << current->year << ")" << endl; //prints movie in the desired format of Title (year)
	}
    if(current->rightChild != NULL)
    {
		recommendMovies(current->rightChild, genre, rating); //function calls itself on the right child
    }
}

/*randomMovieInfo

	Prototype: void randomMovieInfo(MovieNode* current)
	Description: generates a random number between 0 and 99 and prints the movie info for the movie at that index within the original movieList array.
		Also prompts the user for if they want to see other movies of the same genre, and if so, prints them
	Expected Inputs: current, which is a MovieNode pointer
	Expected Outputs: function is void (no outputs)
	Preconditions: No user-activated functions are necessary before this function can run. The only necessary function is
		the creation of the root for the binary search tree, which happens automatically before any user prompts are called.
	Postconditions: There are no expected changes to the state of the program after this function has run 

*/

void MovieTree::randomMovieInfo(MovieNode* current)
{
	//prints the info for the randomly selected movie
	cout << "If you're looking for a random movie to watch, \nwe recommend " << current->title << "." << endl;
	cout << "It's a " << current->rating << "-star rated movie on IMDB made in " << current->year << ",\nand it's one of the best films in the " << current->genre << " genre." << endl;
	cout << "Would you like us to find movies similar to this? Yes (Y) / No (N)" << endl;
	string input;
	cin >> input;
	if(input == "Y" || "y") //if the user hits yes for the rpevious prompt
	{
		cout << "Wonderful! Here are movies within the same genre:" << endl;
		printMoviesInGenre(root, current->genre); //calls printMoviesInGenre for the randomly selected movie's genre
	}
}
