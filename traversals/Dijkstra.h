#pragma once
#include "traversal.h"
#include <set>
#include <iterator>
#include <vector>
#include <queue>
#include "../structs/comparator.hpp"

using namespace std;

class Dijkstra: public Traversal {
    public:
        Dijkstra(Graph * graph, const NodeStep& start);
        Traversal::Iterator begin();
        Traversal::Iterator end();
        
        void add(const NodeStep & t);
        NodeStep pop();
        NodeStep peek() const;
        bool empty() const;
        set<string> & getSet(const string & node) const;
        bool contains(const string & node) const;
        vector<string> getPath(string keyNode);

    private:
        Graph* graph_;
        NodeStep start_;
        priority_queue<pair<NodeStep, int>, vector<pair<NodeStep, int>>, myComparator> prQueue_; //min Heap
        
        NodeStep u_;
        map<string, int> distance_; //map from vertex to distance
        map<string, string> parent_; //map from vertex to parent vertex
};
