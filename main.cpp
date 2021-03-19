#include <iostream>
#include <string>
#include "graphs/udgraph.h"

#include <fstream>
#include <istream>
using namespace std;

// int main (int argc, char** argv) {
int main () {
    // string filename = "assets/test.csv";

    string filename = "assets/musae_git_edges.csv";

    UdGraph g;
    g.buildMap(filename,0.4);

    cout<<"two random nodes picked are: "<<endl;
    srand(time(0));
    string nodeA = g.getRandom();
    string nodeB = g.getRandom();
    cout<<"point A: "<<nodeA<<endl;
    cout<<"point B: "<<nodeB<<endl;

    int distance = g.getSocialDistance(nodeA, nodeB);
    cout<<"Social distance between A and B are: "<<distance<<endl;

    // for (int i=1; i<= 5; i++) {
    //     string testfile = "assets/test";
    //     testfile+=to_string(i);
    //     testfile+=".csv";
    //     Graph test;
    //     test.buildMap(testfile, 1);

    //     int distance = test.getSocialDistance("0", "5");    
    //     cout<<"test "<<i<<" result: "<<distance<<endl;
    // }
    /*
        test1 should see -1
        test2 should see 5
        test3 should see 2
        test4 should see 2
        test5 should see -1
    */

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