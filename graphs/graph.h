#pragma once

#include<map>
#include<set>
#include<vector>
#include<string>

using namespace std;

class Graph{
    public:
        virtual void buildMap(string& filename, double loadFactor) = 0;
        set<string>& getSet(const string& key);
        bool contains(const string& node);

        // return an existing node
        string getRandom();
        
        // helper function for derived class to constructe graph
        void addNode(const string& lhs, const string& rhs);
        void addToList(const string& node);
        void print(const vector<string>& v);

        /***
         * graph search algorithms
         */
        // Search a distance from a node to the target through BFS
        // Return -1 if there is no such connection between node and target
        int getShortestDistance(const string& node, const string& target); 

        // Search the shortest distance from a node to the target on a weighted map
        // Use Dijkstra’s algorithm
        // Return -1 if there is no such connection between node and target
        int getLeastWeightedDistance(const string& node, const string& target);

        // If there exist a walk from a node to the target within n walks, return true
        bool isReachableIDDFS(const string& node, const string& target, int n);

        // Lets suppose we want to start at a given node, 
        // and traval n-1 nodes and eventual get back to the start node.
        // Use DFS algorith
        // Return -1 if there is no such sized circle between node and target
        // function should make sure n>=3 for a valid cycle
        int findCircleWithNumberOfNodes(const string& node, int n);

        

    private:
        // Total number of nodes
        unsigned total_ = 0;
        // Representing our graph in a hashmap
        map<string, set<string>> graph_;
        // All unique nodes stored in a list for generating random node
        vector<string>listOfNodes_;
};