#include "movie.h"
#include <iostream>
#include <string>

using namespace std;

movieBST::movieBST() : root(0) {}

movieBST::~movieBST() {
    clear(root);
}

void movieBST::clear(Movie *m) {
    if (m) {
        clear(m->left);
        clear(m->right);
    }
}

bool movieBST::insert(string name, double rating) {
    if (!root) {
        root = new Movie(name, rating, 0);
        return true;
    }
    return insert(name, rating, root, 0);
}

bool movieBST::insert(string name, double rating, Movie *m, int depth) {
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

void movieBST::printPreOrder() const {
    printPreOrder(root);
}
void movieBST::printPreOrder(Movie *m) const {
    if (m) {
        cout << m->title << ", " << m->rating << ", " << m->depth << endl;
        printPreOrder(m->left);
        printPreOrder(m->right);
    }
}

void movieBST::printInOrder() const {
    printInOrder(root);
}
void movieBST::printInOrder(Movie *m) const {
    if (m) {
        printInOrder(m->left);
        cout << m->title << ", " << m->rating << ", " << m->depth << endl;
        printInOrder(m->right);
    }
}

void movieBST::printPostOrder() const {
    printPostOrder(root);
}
void movieBST::printPostOrder(Movie *m) const {
    if (m) {
        printPostOrder(m->left);
        printPostOrder(m->right);
        cout << m->title << ", " << m->rating << ", " << m->depth << endl;
    }
}

int movieBST::count() const {
    return count(root);
}

int movieBST::count(Movie *m) const {
    if (m) {
        return 1 + count(m->left) + count(m->right); 
    }
    return 0;
}

// movieBST::Movie *movieBST::getMovieFor(string prefix, Movie *m) const {
//     if (m) {
//         if (m->title == prefix) {
//             return m;
//         } else if (m->title > name){
//             return getMovieFor(name, m->left);
//         } else {
//             return getMovieFor(name, m->right);
//         }
//     }
//     return nullptr;
// }


