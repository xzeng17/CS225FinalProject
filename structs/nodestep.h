#pragma once

#include<string>
using std::string;

struct NodeStep {
    string node;
    int step;

    NodeStep(string node, int step):node(node), step(step){}
};