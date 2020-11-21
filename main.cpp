// Su nombre aqui

#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

#include "BST.h"
#include <vector>
using namespace std;


TEST_CASE( "Pushing and popping to the AStack", "[AStack]" ) {
    vector<int> V{10,42,15,25,5,30};
    BSTN B;
    for(auto e: V ) B.insert(e);

    CHECK(B.inOrder() == "5 10 15 25 30 42 ");
    CHECK(B.successor(42) == -1);
    CHECK(B.successor(5)  == 10);

}
