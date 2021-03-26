// #define CATCH_CONFIG_MAIN

#include "../cs225/catch/catch.hpp"
#include "../graphs/udgraph.h"
#include "../traversals/BFS.h"

using namespace std;

TEST_CASE("testBFS", "[valgrind][weight=1]") {
    vector<int> expected = {-1,5,2,2,-1};
    for (int i=1; i<= 5; i++) {
        string testfile = "tests/testInputBFS/test";
        testfile+=to_string(i);
        testfile+=".csv";
        UdGraph test;
        test.buildMap(testfile, 1);
        string nodeA = "0", nodeB = "5";
        int distance = test.getShortestDistance(nodeA, nodeB);    
        REQUIRE(distance == expected[i-1]);
    }
}

TEST_CASE("testBFS with Iterators", "[valgrind][weight=1]") {
    vector<int> expected = {-1,5,2,2,-1};
    for (int i=1; i<= 5; i++) {
        string testfile = "tests/testInputBFS/test";
        testfile+=to_string(i);
        testfile+=".csv";
        UdGraph test;
        test.buildMap(testfile, 1);
        BFS bfs(&test, NodeStep("0", 0));
        int distance = -1;          // need to have a wraper function and update the test case
        for (NodeStep ns : bfs) {   // exact same test as above but using iterator
            if (ns == "5") {
                distance = ns.step;
                break;
            }
        }
        REQUIRE(distance == expected[i-1]);
    }
}

