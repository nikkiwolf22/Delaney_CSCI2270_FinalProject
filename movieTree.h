#ifndef MOVIETREE_H
#define MOVIETREE_H

struct MovieNode{ //this is the structure for all the movies
    std::string title;
    int year;
    std::string genre;
    double rating;
    MovieNode *parent = NULL;
    MovieNode *leftChild = NULL;
    MovieNode *rightChild = NULL;
};

class MovieTree //this is the class with all its glorious functions
{
    public:
        MovieTree(MovieNode* _root);
        ~MovieTree();
        void printMovieInventory(MovieNode* root);
        void addMovieNode(MovieNode* m);
        MovieNode* searchMovieTree(std::string title);
        void printMoviesInGenre(MovieNode* current, std::string genre);
        void printMoviesAboveRating(MovieNode* current, double rating);
        void printMoviesBelowRating(MovieNode* current, double rating);
        void printOlderMovies(MovieNode* current, int year);
        void printNewerMovies(MovieNode* current, int year);
        void recommendMovies(MovieNode* current, std::string genre, double rating);
        void randomMovieInfo(MovieNode* current);
		
    protected:
    private:
        MovieNode* root;
};

#endif // MOVIETREE_H
