#pragma once

#include<map>
#include<set>
#include<vector>
#include<string>

using namespace std;

class Graph{
    public:
        void buildMap(string& filename, double loadFactor);
        set<string>& getSet(const string& key);
        bool contains(const string& node);
        string getRandom();
        int getSocialDistance(const string& node, const string& target);
        
    private:
        unsigned total_ = 0;
        map<string, set<string>> graph_;
        vector<string>listOfNodes_;
        void addNode(const string& lhs, const string& rhs);
        void addToList(const string& node);

        void print(const vector<string>& v);
};