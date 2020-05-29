// tests.cpp
// Authors: Shuo Wang and Alex Xu

#include "movies.h"
#include "utility.h"
#include "tests.h"
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int main() { 
    runAll();
    return 0;
}

void runAll() {
    test_movie();
    test_moviebst();
}

void test_movie() {
    START_TEST("test_movie");
    test_movie_startWith();
    END_TEST("test_movie");
}

void test_moviebst() {
    START_TEST("test_moviebst");
    void test_moviebst_constructor();
    void test_moviebst_destructor();
    void test_moviebst_contains();
    void test_moviebst_insert();
    void test_moviebst_countDepth();
    END_TEST("test_moviebst");
}

void test_movie_startWith() {
    string test1 = "startWith(): compare with empty string";
    Movie m1{"Parasite", 10.0, 0};
    string s1 = "";
    assertEquals(m1.startWith(s1), true, test1);

    string test2 = "startWith(): compare with equal string";
    string s2 = "Para";
    assertEquals(m1.startWith(s2), true, test2);

    string test3 = "startWith(): compare with unequal string";
    string s3 = "site";
    assertEquals(m1.startWith(s3), false, test3);
}

void test_moviebst_constructor() {
    // this one is fine if it doesn't crash
    string test1 = "MovieBST(): empty MovieBST";
    MovieBST mbst1;
    assertEquals(mbst1.contains(""), false, test1);
}

void test_moviebst_destructor() {
    // no surface-level problems as long as it doesn't crash
    // test for leaks in valgrind
    string test1 = "~MovieBST(): removing empty MovieBST";
    MovieBST mbst1;
    mbst1.~MovieBST();
    assertEquals(true, true, test1);
}

void test_moviebst_contains() {
    string test1 = "contains(): empty MovieBST";
    MovieBST mbst1;
    string s1 = "Jaws";
    assertEquals(mbst1.contains(s1), false, test1);

    string test2 = "contains(): empty string";
    string s2 = "";
    mbst1.insert(s2, 1.0);
    assertEquals(mbst1.contains(s2), true, test2);

    string test3 = "contains(): does not contain parameter";
    string s3 = "Green Book";
    assertEquals(mbst1.contains(s3), false, test3);
}

void test_moviebst_insert() {
    string test1 = "insert(): inserting into empty MovieBST";
    MovieBST mbst1;
    string s1 = "Interstellar";
    assertEquals(mbst1.insert(s1, 9.5), true, test1);

    string test2 = "insert(): inserting into non-empty MovieBST";
    string s2 = "Ferris Beuller's Day Off";
    assertEquals(mbst1.insert(s2, 9.0), true, test2);

    string test3 = "insert(): inserting repeated movie";
    string s3 = s1;
    assertEquals(mbst1.insert(s3, 9.5), false, test3);
}

void test_moviebst_countDepth(){
    string test1 = "countDepth(): depth of root";
    MovieBST mbst1;
    string s1 = "Skyfall";
    mbst1.insert(s1, 7.7);
    assertEquals(mbst1.countDepth(s1), 0, test1);

    string test2 = "countDepth(): depth of leaf of root";
    string s2 = "The Girl";
    mbst1.insert(s2, 9.0);
    assertEquals(mbst1.countDepth(s2), 1, test2);

    string test3 = "countDepth(): depth of non-existent Movie";
    string s3 = "Amelie";
    assertEquals(mbst1.countDepth(s3), -1, test3);
}
