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
        MovieNode* searchMovieTree(std::string);
        void printMoviesInGenre(MovieNode* current, std::string genre);

    protected:
    private:
        MovieNode* root;
};

#endif // MOVIETREE_H
