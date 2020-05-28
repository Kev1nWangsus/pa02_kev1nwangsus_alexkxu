// movies.cpp
// Authors: Shuo Wang and Alex Xu

#include "movies.h"
#include <iostream>
#include <string>

using namespace std;

// Movie
Movie::Movie(string n, double r, int d) : title(n), rating(r), depth(d), parent(0), left(0), right(0) {};

bool Movie::startWith(string s) {
    return (title.rfind(s, 0) == 0);
}

// MovieBST
MovieBST::MovieBST() : root(0) {}

MovieBST::~MovieBST() {
    clear(root);
}

bool MovieBST::contains(string mtitle) const {
    if (!root) return false;
    return containsHelper(root, mtitle);
}

bool MovieBST::containsHelper(Movie* m, string mtitle) const {
    if (!m) return false;
    if (m->title == mtitle) return true;
    if (containsHelper(m->left, mtitle)) return true;
    return containsHelper(m->right, mtitle);
}

void MovieBST::clear(Movie *m) {
    if (m) {
        clear(m->left);
        clear(m->right);
    }
}

bool MovieBST::insert(string name, double rating) {
    if (!root) {
        root = new Movie(name, rating, 0);
        return true;
    }
    return insert(name, rating, root, 0);
}

bool MovieBST::insert(string name, double rating, Movie *m, int depth) {
    if (name == m->title)
        return false;
    depth++;
    if (name < m->title) {
        if (m->left) {
            return insert(name, rating, m->left, depth);
        } else {
            m->left = new Movie(name, rating, depth);
            m->left->parent = m;
            return true;
        }
    } else {
        if (m->right) {
            return insert(name, rating, m->right, depth);
        } else {
            m->right = new Movie(name, rating, depth);
            m->right->parent = m;
            return true;
        }
    }
}

void MovieBST::printPreOrder() const {
    printPreOrder(root);
}

void MovieBST::printPreOrder(Movie *m) const {
    if (m) {
        cout << m->title << ", " << m->rating << ", " << m->depth << endl;
        printPreOrder(m->left);
        printPreOrder(m->right);
    }
}

void MovieBST::printInOrder() const {
    printInOrder(root);
}

void MovieBST::printInOrder(Movie *m) const {
    if (m) {
        printInOrder(m->left);
        cout << m->title << ", " << m->rating << ", " << m->depth << endl;
        printInOrder(m->right);
    }
}

void MovieBST::printPostOrder() const {
    printPostOrder(root);
}

void MovieBST::printPostOrder(Movie *m) const {
    if (m) {
        printPostOrder(m->left);
        printPostOrder(m->right);
        cout << m->title << ", " << m->rating << ", " << m->depth << endl;
    }
}

int MovieBST::countDepth(string name) {
    return countDepth(name, root);
}

int MovieBST::countDepth(string name, Movie *m) {
    if (!m) return 0;
    if (m->title == name) {
        return m->depth;
    } else if (name > m->title) {
        return countDepth(name, m->right);
    } else {
        return countDepth(name, m->left);
    }
}

Movie* MovieBST::getFirstMovie(string prefix, Movie *m) {
    if (!m) return nullptr;
    if (prefix > m->title) {
        return getFirstMovie(prefix, m->right);
    } else {
        if (m->startWith(prefix)) return m;
        return getFirstMovie(prefix, m->left);
    }
}

void MovieBST::printHighest(string prefix) {
    Movie *first = getFirstMovie(prefix, root);
    Movie *highest = searchHighest(prefix, first);
    if (!highest) return;
    cout << "Best movie is " << highest->title 
         << " with rating " 
         << highest->rating << endl;
}

Movie* MovieBST::searchHighest(string prefix, Movie *m) {
    if (!m) {
        return nullptr;
    }
    Movie *l = searchHighest(prefix, m->left);
    Movie *r = searchHighest(prefix, m->right);
    bool flag = m->startWith(prefix);
    if (!flag) {
        if (!l && !r) return nullptr;
        else if (!l) return r;
        else if (!r) return l;
        else return (r->rating > l->rating) ? r : l;
    } else {
        if (!l && !r) return m;
        if (!l) return (r->rating > m->rating) ? r : m;
        else if (!r) return (l->rating > m->rating) ? l : m;
        else return (r->rating > l->rating && r->rating > m->rating) ? r : (l->rating > r->rating && l->rating > m->rating) ? l : m;
    }
}

