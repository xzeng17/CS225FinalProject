#pragma once

#include<map>
#include<set>
#include<vector>
#include<string>

using namespace std;

enum Type {
    undirected,
    directed
};

class Graph{
    public:
        Type type_;
        virtual Type type() const = 0;
        virtual set<string>& getSet(const string& key);
        virtual bool contains(const string& node);

        // return an existing node
        virtual string getRandom();
        
        // helper function for derived class to constructe graph
        virtual void addNode(const string& lhs, const string& rhs);
        virtual void addToList(const string& node);
        virtual unsigned size() const;
        /***
         * graph search algorithms
         */
        // Search a distance from a node to the target through BFS
        // Return -1 if there is no such connection between node and target
        virtual int getShortestDistance(const string& node, const string& target); 

        // Search the shortest distance from a node to the target on a weighted map
        // Use Dijkstra’s algorithm
        // Return -1 if there is no such connection between node and target
        virtual int getLeastWeightedDistance(const string& node, const string& target);

        // If there exist a walk from a node to the target within n walks, return true
        virtual bool isReachableIDDFS(const string& node, const string& target, int n);

        // Lets suppose we want to start at a given node, 
        // and traval n-1 nodes and eventual get back to the start node.
        // Use DFS algorith
        // Return -1 if there is no such sized circle between node and target
        // function should make sure n>=3 for a valid cycle
        virtual int findCircleWithNumberOfNodes(const string& node, int n);
        
        
        //  <----------Iterator wraper methods---------->
        virtual void bfs(const string& beginNode);

    private:
        // Representing our graph in a hashmap
        map<string, set<string>> graph_;
        // All unique nodes stored in a list for generating random node
        vector<string>listOfNodes_;
};

