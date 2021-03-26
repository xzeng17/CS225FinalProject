#include "digraph.h"
#include "graph.h"
#include "../fileloaders/fileloader.h"

#include<string>
#include <iostream>

using namespace std;

DiGraph::DiGraph(const string& filename, double loadfactor) {
    try{
        FileLoader(this, filename, loadfactor);
    } catch (runtime_error e) {
        cout<<e.what()<<endl;
    }
}

Type DiGraph::type() const {
    return type_;
}