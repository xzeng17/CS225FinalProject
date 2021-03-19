#pragma once
#include<map>
#include<set>
#include<vector>
#include<string>

using namespace std;

#include "graph.h"

class UdGraph: public Graph {
    public:
        void buildMap(string& filename, double loadFactor);

    private:



};