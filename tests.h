#include <iostream>

using namespace std;

void runAll();

// test Movie class
void test_movie();
void test_movie_startWith();

// test MovieBST class
void test_moviebst();
void test_moviebst_constructor();
void test_moviebst_destructor();
void test_moviebst_contains();
void test_moviebst_insert();
void test_moviebst_countDepth();

void START_TEST(string testname){
    cout << "Start " << testname << endl;
}

void END_TEST(string testname) {
    cout << "End " << testname << endl << endl;
}

void assertEquals(bool expected, bool actual, string testDescription) {
    if (expected == actual) {
        cout<<"PASSED: " << testDescription << endl;
    } else {
        cout<< "  FAILED: "<< testDescription << endl
        <<"  Expected: "<< expected << " Actual: " << actual << endl;
    }
}

void assertEquals(int expected, int actual, string testDescription) {
    if (expected == actual) {
        cout << "PASSED: " << testDescription << endl;
    } else {
        cout<< "  FAILED: "<< testDescription << endl
        <<"  Expected: "<< expected << " Actual: " << actual << endl;
    }
}
