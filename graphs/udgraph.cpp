#include "udgraph.h"

#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include <fstream>
#include <istream>
#include <iostream>

using namespace std;

void UdGraph::buildMap(string& filename, double loadfactor) {
    string lhs, rhs, line;  
    ifstream file;
    file.open(filename);

    loadfactor = min(loadfactor, 1.0);  // cannot have too much data

    // set position to the end
    file.seekg(0, file.end);
    // get total word count
    size_t totalByte = file.tellg();
    size_t lineNumber = totalByte > 100 ? totalByte/11 * loadfactor : totalByte/1 * loadfactor;    // total nodes are 37700
    // set position to the begining
    file.seekg(0, file.beg);
    
    while (getline(file, line) && lineNumber > 0) {
    //while (getline(file, line) ) {
        cout<<line<<endl;                           // print raw data
        lineNumber--;                               // loop counter
        if (line[0]<'0' || line[0] >'9') continue;  // skip header

        // extract nodes from csv format
        unsigned idx=0;
        while (idx < line.size() && line[idx] != ',') {
            lhs += line[idx++];
        }
        idx++;
        while (idx < line.size() && line[idx] != ',') {
            rhs += line[idx++];
        }

        // undirected graph, add edge both ways
        addToList(lhs);
        addToList(rhs);
        addNode(lhs, rhs);
        addNode(rhs, lhs);
        lhs.clear(); rhs.clear();
    }

    file.close();
}