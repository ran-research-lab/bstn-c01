//
// Created by Rafael Arce Nazario on 11/17/20.
//

#ifndef MAIN_BST_H
#define MAIN_BST_H
#include <cstdlib>
#include <iostream>
#include <string>
using namespace  std;

class BTNode {
public:
    int key;                // Element for this node
    BTNode *left;          // Pointer to left child
    BTNode *right;         // Pointer to right child

    // Constructors
    BTNode(int val = 0, BTNode* l = NULL, BTNode *r = NULL)
    { left = l; right = r; key = val; }

    // return TRUE if a leaf node, FALSE otherwise
    bool isLeaf() const { return (left == NULL) && (right == NULL); }
};

// Binary Search Tree implementation
class BSTN {
private:
    BTNode *root; // Root of the BST
    int nodecount; // Number of nodes in the BST

    void insertRec( int k, BTNode *root);
    void remove(int k, BTNode *r);
    BTNode* searchRec( int k, BTNode *root) const;
    void toString(string &st, BTNode *cur, int dist) const;
    void inOrder(BTNode *r, string &st) const;
public:

    BSTN() { root = NULL; nodecount = 0; }

    // Given a key k, returns a pointer to the node, if found,
    // otherwise returns NULL
    BTNode* search(int k) const;

    // Given a key k, returns a pointer to the node, if found,
    // otherwise returns NULL. Uses a recursive search algorithm.
    BTNode* recSearch(int k) const {
        return searchRec(k, root);
    }

    // This is the helper function that calls the actual recursive inOrder
    // function.
    string inOrder() const {
        string st;
        inOrder(root, st);
        return st;
    }

    // Given a key, returns the key of the succesor in the tree (if found).
    // If the key is not found, or has no successor, returns -1.
    int successor(int k) const;

    // Deletes all the nodes
    void clear();

    // Insert a key into the tree.
    void insertRec(int k) {
        if (!root) // case when tree is empty
            root = new BTNode(k);
        else insertRec( k, root);
        nodecount++;
    }
    void insert(int k);

    // Remove a record from the tree
    void remove(int k) { remove(k, root);  nodecount--; }

    string toString() const;

};

#endif //MAIN_BST_H
