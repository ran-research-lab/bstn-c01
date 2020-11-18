// Su nombre aqui

#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

#include "BST.h"
#include <vector>
using namespace std;


TEST_CASE( "Pushing and popping to the AStack", "[AStack]" ) {
    vector<int> V{10,15,25,5,30};
    BSTN B;
    for(auto e: V ) B.insert(e);

    cout << B.toString() << endl;
    CHECK(B.search(10)->key == 10);
    CHECK(B.search(5)->key == 5);
    B.remove(10);
    cout << B.toString() << endl;
    CHECK(B.search(10) == NULL);

    B.clear();
    B.insert(42);
    cout << B.toString() << endl;



//	LStack S(20);
//	for(int i = 0; i < 10; i++) S.push(i*10);
//    CHECK( S.toString() == "90 80 70 60 50 40 30 20 10 0 ");
//    int ctr = 0;
//    while(!S.isEmpty()) {
//        S.pop();
//        ctr++;
//    }
//    CHECK( ctr == 10);
}
