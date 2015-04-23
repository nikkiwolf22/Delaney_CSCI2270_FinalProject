#ifndef MOVIETREE_H
#define MOVIETREE_H

struct MovieNode{
    std::string title;
    int year;
    std::string genre;
    double rating;
    MovieNode *parent = NULL;
    MovieNode *leftChild = NULL;
    MovieNode *rightChild = NULL;
};

class MovieTree
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
