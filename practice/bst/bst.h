#ifndef BST_H
#define BST_H

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree();

    void insert(int val);
    Node* findMin();
    void printNodeAtKDistance(int k);
    int getMaxHeight();
    int countLeafNodes();

private:
    Node* root;

    void insert(Node*& root, int val);
    Node* findMin(Node* root);
    void printNodeAtKDistance(Node* root, int k);
    int getMaxHeight(Node* root);
    int countLeafNodes(Node* root);
};

#endif
