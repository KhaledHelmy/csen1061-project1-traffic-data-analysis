#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}

int main () {
    ifstream input("city.txt");
    for(string line; getline( input, line ); ) {
        if (line.find("href=\"#roads-") != string::npos) {
            string roadName = line.substr(0, line.size()-4);
            roadName = roadName.substr(12);
            vector <string> res = split(roadName, '>');
            cout << "\"" << res[1] << "\"" << ", ";
        }
    }
}
