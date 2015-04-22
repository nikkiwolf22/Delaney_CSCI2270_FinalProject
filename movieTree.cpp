#include <iostream>
#include <fstream>
#include <string>
#include "movieTree.h"

using namespace std;

MovieTree::MovieTree(MovieNode* _root)
{
	root = _root;//all this function does is set the root. I know, weird, but it worked
}

MovieTree::~MovieTree()
{
	
}

void MovieTree::printMovieInventory(MovieNode* current) //this follows the convention from lecture
{
	if(current->leftChild != NULL)
	{
		printMovieInventory(current->leftChild);
    }
    cout << current->title << " (" << current->year << ")" << endl;
    if(current->rightChild != NULL)
    {
		printMovieInventory(current->rightChild);
    }
}

void MovieTree::addMovieNode(MovieNode* m) //pretty straightforward, follows lecture convention as well
{
	bool placed = false;
	MovieNode* c = root;
	while (!placed)
	{
		if (m->title < c->title)
		{
			if (c->leftChild == NULL)
			{
				m->parent = c;
				c->leftChild = m;
				placed = true;
			}
		}
		else
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

MovieNode* MovieTree::searchMovieTree(std::string name) //very similar to above function
{
	bool found = false;
	MovieNode* c = root;
	while (!found)
	{

		if (name < c->title)
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
		else if (name > c->title)
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
		else if (name == c->title)
		{
			found = true;
			return c;
		}
	}
}

void MovieTree::printMoviesInGenre(MovieNode* current, string genre)
{
	if(current->leftChild != NULL)
	{
		printMoviesInGenre(current->leftChild, genre);
    }
    if(current->genre == genre)
    {
		cout << current->title << " (" << current->year << ")" << endl;
	}
    if(current->rightChild != NULL)
    {
		printMoviesInGenre(current->rightChild, genre);
    }
}
