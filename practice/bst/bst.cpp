#include "bst.h"
#include <iostream>
#include <queue>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

void BinarySearchTree::insert(int val) {
    insert(root, val);
}

void BinarySearchTree::insert(Node*& root, int val) {
    if (!root) {
        root = new Node(val);
        return;
    }

    if (val < root->data) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

// Find node with minimum value
Node* BinarySearchTree::findMin() {
    return findMin(root);
}

Node* BinarySearchTree::findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

// Print node at distance k from root
void BinarySearchTree::printNodeAtKDistance(int k) {
    printNodeAtKDistance(root, k);
}

void BinarySearchTree::printNodeAtKDistance(Node* root, int k) {
    if (!root) return;
    if (k == 0) {
        std::cout << root->data << " ";
        return;
    }
    printNodeAtKDistance(root->left, k - 1);
    printNodeAtKDistance(root->right, k - 1);
}

// Get the maximum height of the tree
int BinarySearchTree::getMaxHeight() {
    return getMaxHeight(root);
}

int BinarySearchTree::getMaxHeight(Node* root) {
    if (!root) return 0;
    int leftHeight = getMaxHeight(root->left);
    int rightHeight = getMaxHeight(root->right);
    return std::max(leftHeight, rightHeight) + 1;
}

// Count leaf nodes
int BinarySearchTree::countLeafNodes() {
    return countLeafNodes(root);
}

int BinarySearchTree::countLeafNodes(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
