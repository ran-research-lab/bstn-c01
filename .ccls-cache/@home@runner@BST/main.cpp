#include <iostream>
#include "BST.h"
#include "ccom3034.h"

using namespace std;


int main() {
	BSTN T;
	T.insertRec(10);
	T.insertRec(20);
	T.insertRec(5);

	expect(T.recSearch(5)->key == 5);
	expect(T.recSearch(25) == NULL);
	expect(T.recSearch(10)->key == 10);

	T.remove(10);
	expect(T.recSearch(10) == NULL);
	expect( T.inOrder() == "5 20 ");
	
	assertionReport();
}