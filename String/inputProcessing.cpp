#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <sstream>
using namespace std;



/*
Contains examples of how to process strings and inputs
*/

/***************** 
* String to integer 
******************/

// stoi method
string s = "122";
int x = std::stoi(s);

// stringstream method
stringstream ss("123");
int x;
ss >> x;

/****************
 Input Processing 
*****************/

// 1. Sample Input (get each indvidiual element)
// 30 10 40
// 30 20 40
// 40 20 30

int item;
string line;

while (getline(cin,line)){
    cout << line << endl;
    cout << "hello" << endl;

    istringstream sstr(line);
    while(!sstr.eof()){
        sstr >> item;
        cout << item << endl;
    }
    cout << endl;
    }







