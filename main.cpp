#include <iostream>
#include <string>
#include "graph.h"

#include <fstream>
#include <istream>
using namespace std;

// int main (int argc, char** argv) {
int main () {
    //string filename = "assets/test.csv";
    string filename = "assets/musae_git_edges.csv";

    Graph g;
    g.buildMap(filename,0.2);

    cout<<"two random nodes picked are: "<<endl;
    cout<<"point 1: "<<g.getRandom()<<endl;
    cout<<"point 2: "<<g.getRandom()<<endl;


    // string data;
    // ifstream file;
    // file.open(filename);
    // while (getline (file, data)) {
    // // Output the text from the file
    // cout << data <<endl;
    // }

    return 0;
}


// <------------for test output------------>

// int main () {
//     string filename = "assets/test.csv";
//     //string filename = "assets/musae_git_edges.csv";

//     string data;
//     ifstream file;
//     file.open(filename);
    
//     // set position to the end
//     file.seekg(0, file.end);

//     // get total word count
//     int length = file.tellg();
    
//     // set position to the begining
//     file.seekg (0, file.beg);
    
//     cout<<length<<" line: "<<__LINE__<<endl;

//     while (getline (file, data)) {
//     // Output the text from the file
//     cout << data <<endl;
//     }

//     return 0;
// }