//
// Created by Rafael Arce Nazario on 11/17/20.
//

#include "BST.h"
#include <iostream>
using namespace  std;

void BSTN::clear() {
    while (root) remove(root->key);
}

BTNode* BSTN::search(int k) const {
    BTNode* cur = root;
    while (cur) {
        if (k == cur->key)     { return cur;}
        else if (k < cur->key) { cur = cur->left; }
        else                   { cur = cur->right; }
    }
    return NULL;
}

BTNode* BSTN::searchRec( int k, BTNode *cur) const {
    if (!cur) return NULL;
    if (k == cur->key) return cur;
    if (k < cur->key)  return searchRec(k, cur->left);
    return searchRec(k, cur->right);
}

void BSTN::insertRec(int k , BTNode *r) {
    if (k < r->key) {
        if (r->left == NULL) r->left = new BTNode(k);
        else insertRec(k, r->left);
    }
    else {  // k is greater than r->key
        if (r->right == NULL) r->right = new BTNode(k);
        else insertRec(k, r->right);
    }
}

void BSTN::insert(int k) {
    BTNode *cur;
    BTNode *n = new BTNode(k);

    if (!root) {
        // This tree is empty, the new node is the root!
        root = n;
    }
    else {
        // Lets search the tree for a place to insert....
        cur = root;
        while (cur) {
            if (k < cur->key){
                // The value to insert is less than current node
                if (cur->left == NULL) {
                    // If we have reached a node who lacks a left child
                    // then our new node will be the left child
                    cur->left = n;
                    nodecount++;
                    cur = NULL;
                }
                else {
                    // keep looking for a place to insert, on the left subtree
                    cur = cur->left;
                }
            }
            else {
                // The value to insert is greater or equal than current node
                if (cur->right == NULL){
                    // If we have reached a node who lacks a right child
                    // then our new node will be the right child
                    cur->right = n;
                    nodecount++;
                    cur = NULL;
                }
                else {
                    // keep looking for a place to insert, on the right subtree
                    cur = cur->right;
                }
            }
        }
    }
}

void BSTN::remove(int k, BTNode *r) {
    BTNode *parent = NULL;
    BTNode *cur = r;
    while (cur) { // Search for node
        if (cur->key == k) { // Node found
            if (cur->left == NULL && cur->right == NULL) {        // Remove leaf
                if (!parent) { // Node is root
                    root = NULL;
                }
                else if (parent->left == cur)
                    parent->left = NULL;
                else
                    parent->right = NULL;
                delete cur;
            }
            else if (cur->left && cur->right == NULL) {    // Remove node with only left child
                if (!parent) // Node is root
                    root = cur->left;
                else if (parent->left == cur)
                    parent->left = cur->left;
                else
                    parent->right = cur->left;
                delete cur;
            }
            else if (cur->left == NULL && cur->right) {    // Remove node with only right child
                if (!parent) // Node is root
                    root = cur->right;
                else if (parent->left == cur)
                    parent->left = cur->right;
                else
                    parent->right = cur->right;
                delete cur;
            }
            else {                                  // Remove node with two children
                // Find successor (leftmost child of right subtree)
                BTNode *suc = cur->right;

                while (suc->left )
                    suc = suc->left;
                int successorData = suc->key;
                remove(suc->key, cur);     // Remove successor
                cur->key = successorData;
            }
            return; // Node found and removed
        }
        else if (cur->key < k) { // Search right
            parent = cur;
            cur = cur->right;
        }
        else {                     // Search left
            parent = cur;
            cur = cur->left;
        }
    }
    return; // Node not found
}


string BSTN::toString() const {
    string st;
    toString(st, root, 0);
    return st;
}

void BSTN::toString(string &st, BTNode *cur, int dist) const{
    if (cur) {
        if (cur->right) toString(st, cur->right, dist + 1);
        for (int i = 0; i < dist; i++) st += "    ";
        st = st + to_string(cur->key) + "\n";
        if (cur->left) toString(st, cur->left, dist + 1);
    }
}