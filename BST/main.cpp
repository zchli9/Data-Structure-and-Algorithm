#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree<int> bst;

    // Inserting elements
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);
    bst.insert(25);
    bst.insert(35);

    std::cout << "Initial tree (in-order traversal):" << std::endl;
    bst.printTree();

    std::cout << "\nRemoving a leaf node (5):" << std::endl;
    bst.remove(5);
    bst.printTree();

    std::cout << "\nRemoving a node with one child (10):" << std::endl;
    bst.remove(10);
    bst.printTree();

    std::cout << "\nRemoving a node with two children (30):" << std::endl;
    bst.remove(30);
    bst.printTree();

    std::cout << "\nRemoving the root node (20):" << std::endl;
    bst.remove(20);
    bst.printTree();

    std::cout << "\nAttempting to remove an element not in the tree (40):" << std::endl;
    bst.remove(40);
    bst.printTree();

    std::cout << "\nRemoving all elements to make the tree empty:" << std::endl;
    bst.remove(15);
    bst.remove(25);
    bst.remove(35);
    bst.printTree();

    return 0;
}
