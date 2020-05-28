#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include "movies.h"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);
void timer(int trials, vector<string> list);

int main(int argc, char** argv) {
    if(argc < 4) {
        cerr << "Usage: " << argv[0] << " arg1 arg2 arg3" << endl;
        exit(1);
    }

    bool flag = false;
    if(strcmp(argv[1], "true") == 0) {
        flag = true;
    } else if(strcmp(argv[1], "false") == 0) {
        flag = false;
    } else {
        cerr << "Argument 1 must be a boolean (true/false)" << endl;
        exit(1);
    }
    
    ifstream movieFile (argv[2]);
    string line, movieName;
    double movieRating;

    if (movieFile.fail()) {
        cerr << "Could not open file " << argv[2];
        exit(1);
    }

    // Create an objects of the BST class you defined 
    // to contain the name and rating in the input file

    // Read each file and store the name and rating
    MovieBST IMDb;
    vector<string> list;
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
        IMDb.insert(movieName, movieRating);
        list.push_back(movieName);
    }

    if (flag) {
        string prefix(argv[3]);
        IMDb.printPreOrder();
        cout << endl;
        IMDb.printHighest(prefix);
    } else {
        int trials = atoi(argv[3]);
        timer(trials, list); 
    }

    movieFile.close();
    return 0;
}

bool parseLine(string &line, string &movieName, double &movieRating) {
    if(line.length() <= 0) return false;
    string tempRating = "";

    bool flag = false;
    movieName = tempRating = "", movieRating = 0.0, flag = false;

    for (int i = 0; i < line.length(); i++) {
        if(flag) tempRating += line[i];
        else if(line[i]==','&& line[0]!='"') flag = true;
        else {
            if(i==0 && line[0]=='"') continue;
            if(line[i]=='"'){ i++; flag=true; continue;}
            movieName += line[i];
        }
    }
    
    movieRating = stod(tempRating);
    return true;
}

void timer(int trials, vector<string> list) {
    MovieBST test;
    clock_t start, end;
    double time, mintime = -1, maxtime = 0, avgtime = 0;
    ofstream data("time_data.csv");
    data << "N. N_visited" << endl;

    for (int i = 0; i < list.size(); i++) {
        data << i << ", ";
        test.insert(list[i]);
        data << test.countDepth(list[i]) << endl;
    }
    data.close();

    for (int i = 0; i < trials; i++) {
        start = clock();
        for (int j = 0; j < list.size(); j++) test.contains(list[j]);
        end = clock();
        time = (end - start) / (double)CLOCKS_PER_SEC;

        cout << "trial " << i+1 << ": " << time*1000 << "ms" << endl;
        if (mintime == -1 || time < mintime) mintime = time;
        if (time > maxtime) maxtime = time;
        avgtime += time;
    }
    avgtime /= trials;

    cout << "Time elapsed to search all nodes over " << trials << " trials: " << endl;
    cout << "   minimum time: " << mintime*1000 << "ms" << endl;
    cout << "   maximum time: " << maxtime*1000 << "ms" << endl;
    cout << "   average time: " << avgtime*1000 << "ms" << endl;
}
