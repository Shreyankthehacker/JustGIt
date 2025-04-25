#include <iostream>
#include "bst.h"

int main() {
    BinarySearchTree bst;

    // Insert values into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Find node with minimum value
    Node* minNode = bst.findMin();
    if (minNode) {
        std::cout << "Minimum value in BST: " << minNode->data << std::endl;
    }

    // Find nodes at distance 2 from root
    std::cout << "Nodes at distance 2 from root: ";
    bst.printNodeAtKDistance(2);
    std::cout << std::endl;

    // Find the maximum height of the BST
    int maxHeight = bst.getMaxHeight();
    std::cout << "Maximum height of BST: " << maxHeight << std::endl;

    // Count the leaf nodes
    int leafNodes = bst.countLeafNodes();
    std::cout << "Number of leaf nodes: " << leafNodes << std::endl;

    return 0;
}
