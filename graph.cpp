#include<map>
#include<set>
#include<vector>
#include<string>
#include <fstream>
#include <istream>
#include <iostream>

#include "graph.h"
using namespace std;

void Graph::buildMap(string& filename, double loadfactor) {
    string lhs, rhs, line;  
    ifstream file;
    file.open(filename);

    loadfactor = min(loadfactor, 1.0);  // cannot have too much data

    // set position to the end
    file.seekg(0, file.end);
    // get total word count
    size_t lineNumber = (file.tellg() / 11) * loadfactor;    // total nodes are 37700
    // set position to the begining
    file.seekg(0, file.beg);
    
    while (getline(file, line) && lineNumber > 0) {
    //while (getline(file, line) ) {
        cout<<line<<endl;                           // print raw data
        lineNumber--;                                // loop counter
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

    cout<<"Report map size after build: "<<graph_.size()<<endl;          
    cout<<"Report vector size after build: "<<listOfNodes_.size()<<endl;
    // print(listOfNodes_);    // print list to make sure all data were parsed correctly
    file.close();
}

set<string>& Graph::getSet(const string& key){
    return graph_[key];
}

bool Graph::contains(const string& node) {
    if (graph_.find(node) == graph_.end()) return false;
    return true;
}

string Graph::getRandom() {
    unsigned random_idx = rand() % (total_+1);
    cout<<"random index: "<<random_idx<<endl;
    return listOfNodes_[random_idx-1];
}

// -------------------private helpers----------------------
void Graph::addNode(const string& lhs, const string& rhs){
    if (!contains(lhs)) {
            graph_[lhs] = set<string>{rhs};
    } else {
        graph_[lhs].insert(rhs);
    }
}

void Graph::addToList(const string& node) {
    if (!contains(node)) {
        listOfNodes_.push_back(node);
        total_ ++;
    }
}

void Graph::print(const vector<string>& v) {
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