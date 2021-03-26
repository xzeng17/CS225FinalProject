#include <iostream>
#include <string>
#include "graphs/udgraph.h"
#include "traversals/BFS.h"
#include "traversals/traversal.h"

#include <fstream>
#include <istream>
using namespace std;

void print(const vector<string>& v) {
    if (v.size() == 0) return;
    cout<<"[";
    for (unsigned i=0; i<v.size(); i++) {
        if (i == v.size()-1) {
            cout<<v[i];
        } else {
            cout<<v[i]<< ", ";
        }
    }
    cout<<"]"<<endl;
}


// int main (int argc, char** argv) {
int main () {
    // string filename = "assets/test.csv";

    // string filename = "assets/musae_git_edges.csv";

    // UdGraph g;
    // g.buildMap(filename,0.4);

    // cout<<"two random nodes picked are: "<<endl;
    // srand(time(0));
    // string nodeA = g.getRandom();
    // string nodeB = g.getRandom();
    // cout<<"point A: "<<nodeA<<endl;
    // cout<<"point B: "<<nodeB<<endl;

    // int distance = g.getShortestDistance(nodeA, nodeB);
    // cout<<"Social distance between A and B are: "<<distance<<endl;


    // <------------test new traversal based classes------------>
    string filename = "tests/testInputBFS/test2.csv";
    vector<int> expected = {-1,5,2,2,-1};
    UdGraph test(filename);
    test.bfs("3");
    // test.buildMap(filename, 1);

    // BFS bfs(&test, NodeStep("3", 0));
    // cout<<"*****calling iterator*****"<<endl;
    // for (auto it = bfs.begin(); it != bfs.end(); ++it) {
    //     cout<<(*it)<<endl;
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