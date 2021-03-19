// #define CATCH_CONFIG_MAIN

#include "../cs225/catch/catch.hpp"
#include "../graphs/udgraph.h"

using namespace std;

TEST_CASE("testBFS", "[valgrind][weight=1]") {
    vector<int> expected = {-1,5,2,2,-1};
    for (int i=1; i<= 5; i++) {
        string testfile = "tests/testInputBFS/test";
        testfile+=to_string(i);
        testfile+=".csv";
        UdGraph test;
        test.buildMap(testfile, 1);
        int distance = test.getSocialDistance("0", "5");    
        REQUIRE(distance == expected[i-1]);
    }
/*
        test1 should see -1
        test2 should see 5
        test3 should see 2
        test4 should see 2
        test5 should see -1
*/
}
