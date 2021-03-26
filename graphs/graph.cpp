#include<string>
#include <fstream>
#include <istream>
#include <iostream>

#include "graph.h"
#include "../structs/nodestep.hpp"
#include "../traversals/BFS.h"
using namespace std;

set<string>& Graph::getSet(const string& key){
    return graph_[key];
}

bool Graph::contains(const string& node) {
    if (graph_.find(node) == graph_.end()) return false;
    return true;
}

unsigned Graph::size() const {
    return listOfNodes_.size();
}

string Graph::getRandom() {
    unsigned random_idx = rand() % (total_);
    return listOfNodes_[random_idx];
}

// -------------------helpers----------------------
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



// ---------------end helpers----------------------

int Graph::getShortestDistance(const string& node, const string& target) {
    // use BFS to search the smallest distance from node to target

    // cout<<"<----------Searching Distance BFS NonIterator Method---------->"<<endl;
    // if (!contains(node) || !contains(target)) return-1;
    // set<string> visited;
    
    // queue<NodeStep> q;
    // q.push(NodeStep(node, 0));

    // while (!q.empty()) {
    //     NodeStep cur = q.front(); q.pop();
    //     visited.insert(cur.node);
    //     if (cur.node == target) return cur.step;
    //     set<string> next = graph_[cur.node];
    //     for (auto it=next.begin(); it!=next.end(); ++it) {
    //         string nextNode = (*it);
    //         if (visited.find(nextNode) != visited.end()) continue;
    //         q.push(NodeStep(nextNode, cur.step+1));
    //     }
    // } 

    cout<<"<----------Searching Distance BFS Iterator Method---------->"<<endl;
    BFS bfs(this, NodeStep(node, 0));
    for (NodeStep it : bfs) {
        if (it == target) return it.step;
    }
    
    return -1;
}

int Graph::getLeastWeightedDistance(const string& node, const string& target) {
    // need implementation

    return 0;
}

bool Graph::isReachableIDDFS(const string& node, const string& target, int n) {
    // need implementation
    
    return false;
}

int Graph::findCircleWithNumberOfNodes(const string& node, int n) {
    // need implementation
    
    return 0;
}

//  <----------Iterator wraper methods---------->
void Graph::bfs(const string& beginNode) {         
    BFS bfs(this, NodeStep(beginNode, 0));
    for (auto it = bfs.begin(); it != bfs.end(); ++it) {
        cout<<(*it)<<endl;
    }
}
