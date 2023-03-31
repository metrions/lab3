#include <iostream>
using namespace std;


struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

int countLeaves(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->val << " ";
        return 1;
    }
    int count = countLeaves(root->left) + countLeaves(root->right);
    return count;
}