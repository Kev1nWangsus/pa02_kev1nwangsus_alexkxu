// movies.h
// Authors: Shuo Wang and Alex Xu
// class declaration for Movie and MovieBST

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <string>

using namespace std;

class Movie {
    public:
        Movie(string n="", double r=0.0, int d=0);
        bool startWith(string s);

    private:
        string title;
        double rating;
        int depth;
        Movie *left, *right, *parent;
    
    friend class MovieBST;
};

class MovieBST
{
    public:
        MovieBST(); // constructor
        ~MovieBST(); // destructor

        // public functions
        bool insert(string name, double rating=0.0);
        void printPreOrder() const;
        void printInOrder() const;
        void printPostOrder() const;

        void printHighest(string prefix); // this will use search highest
        int countDepth(string name);
        bool search(string mtitle);
 
    private:
        Movie *root; // the movie node with depth 0

        // private functions
        void clear(Movie *m);
        bool insert(string name, double rating, Movie *m, int depth); // inserthelper
        void printPreOrder(Movie *m) const;
        void printInOrder(Movie *m) const;
        void printPostOrder(Movie *m) const;

        Movie* getFirstMovie(string prefix, Movie *m); // search for the Moive that starts 
                                                    // with the target prefix and 
                                                    // has the smallest depth 
        Movie* searchHighest(string prefix, Movie *m); // search for highest rating movie
                                                       // that starts with target prefix
        int countDepth(string name, Movie *m);
        bool search(string name, Movie* m);
};

#endif
