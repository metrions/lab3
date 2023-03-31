#include <iostream>
#include "tree.h"
using namespace std;


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int count = countLeaves(root);
    cout << endl << "Number of leaves: " << count << endl;
    return 0;
}