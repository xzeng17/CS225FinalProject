#include "Dijkstra.h"
#include <set>
#include <vector>
#include <iterator>
#include <map>
#include <stack>
#include <limits>

using namespace std;

Dijkstra::Dijkstra(Graph * graph, const NodeStep & start) {
    graph_ = graph;
    start_ = NodeStep(start.node, start.step);
    for (string & _node : graph_->getNodes()) {
        distance_[_node] = numeric_limits<int>::max();  //use max value for int type instead of infinity
        parent_[_node] = string();
    }
    distance_[start_.node] = 0;
    
    prQueue_.push(pair<NodeStep, int>(start_, distance_[start_.node]));

    u_ = start_;
}

vector<string> Dijkstra::getPath(string keyNode) {
    stack<string> s;
    vector<string> path;

    s.push(keyNode);
    string tmp = parent_[keyNode];

    while (tmp != string()) {
        s.push(tmp);
        tmp = parent_[tmp];
    }
    while (!s.empty()) {
        path.push_back(s.top());
        s.pop();
    }
    return path;
}

Traversal::Iterator Dijkstra::begin() {
    return Traversal::Iterator(this, start_);
}

Traversal::Iterator Dijkstra::end() {
    return Traversal::Iterator();
}

void Dijkstra::add(const NodeStep & ns) {
    if (u_.node != ns.node) {
        pair<string,string> edge = {u_.node, ns.node};
        if (distance_[u_.node] + graph_->getWeight(edge) < distance_[ns.node]) { 
            distance_[ns.node] = distance_[u_.node] + graph_->getWeight(edge);
            parent_[ns.node] = u_.node;
            prQueue_.push(pair<NodeStep, int> (ns, distance_[ns.node]));
        }
            
    }
}

NodeStep Dijkstra::pop() {
    u_ = peek();
    prQueue_.pop();
    return u_;
}

NodeStep Dijkstra::peek() const {
    return prQueue_.top().first;
}

bool Dijkstra::empty() const {
    return prQueue_.empty();
}

set<string> & Dijkstra::getSet(const string & node) const {
    return graph_->getSet(node);
}

bool Dijkstra::contains(const string & node) const {
    return graph_->contains(node);
}
