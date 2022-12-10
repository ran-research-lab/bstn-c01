// Su nombre aqui



#include "BST.h"
#include <vector>
using namespace std;


// Variables and macros for assertions, DO NOT CHANGE ****
int totalAssertions = 0;
int passedAssertions  = 0;
#define expect( chk )  \
    totalAssertions++; \
    if (!(chk)) \
        printf("\x1B[31mAssertion (%s) failed %s at line %d\033[0m\t\t\n", #chk, __FILE__,__LINE__); \
    else { \
        printf("\x1B[32mPassed line %d: %s\033[0m\t\t\n", __LINE__, #chk); \
        passedAssertions++; \
    }
#define assertionReport() { \
     printf("==========================================\n"); \
     printf("Passed %d of %d assertions\n",passedAssertions,totalAssertions); \
     printf("\n"); \
    }
//*******************************************************



int main() {
    vector<int> V{10,42,15,30,25,5};
    BSTN B;
    for(auto e: V ) { B.insert(e); }

    cout << B.toString() << endl;

    expect(B.inOrder() == "5 10 15 25 30 42 ");
    expect(B.successor(42) == -1);
    expect(B.successor(5)  == 10);
    assertionReport();
}
