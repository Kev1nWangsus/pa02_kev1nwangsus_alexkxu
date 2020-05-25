#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>

using namespace std;

class movieBST
{
    public:
        movieBST();
        ~movieBST();
        bool insert(string name, double rating);
        void printPreOrder() const;
        void printInOrder() const;
        void printPostOrder() const;
        int count() const;
        string search();
        bool contains(string name) const;

    private:
        struct Movie{
            string title;
            double rating;
            int depth;
            Movie *left, *right, *parent;
            Movie(string n="", double r=0, int d=0) : title(n), rating(r), depth(d), left(0), right(0), parent(0) {}
        };
        Movie *root;

        Movie *getMovieFor(string prefix, Movie *m) const;
        void clear(Movie *m);
        bool insert(string name, double rating, Movie *m, int depth);
        void printPreOrder(Movie *m) const;
        void printInOrder(Movie *m) const;
        void printPostOrder(Movie *m) const;
        int count(Movie *m) const;
        
};

#endif