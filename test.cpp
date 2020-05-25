#include "movie.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv) {
    bool flag = false;
    if(strcmp(argv[1], "true") == 0){
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

    movieBST lanfanqie;
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)) {
        lanfanqie.insert(movieName, movieRating);
    }

    lanfanqie.printPreOrder();
    movieFile.close();
    return 0;

}

bool parseLine(string &line, string &movieName, double &movieRating) {
    if(line.length() <= 0) return false;
    string tempRating = "";

    bool flag = false;
    movieName = tempRating = "", movieRating = 0.0, flag = false;

    for (int i = 0; i < line.length(); i++){
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