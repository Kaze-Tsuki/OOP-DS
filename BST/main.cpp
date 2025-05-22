#include "BST.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(8);
    // tree.insert(6);

    tree.Traverse(1); // In-order traversal

    cout << "\nSearching for 7: " << (tree.search(7) ? "Found" : "Not Found") << endl;
    cout << "Searching for 20: " << (tree.search(20) ? "Found" : "Not Found") << endl;

    tree.remove(5);
    cout << "In-order traversal after removing 5: \n";
    tree.Traverse(1); // In-order traversal
    cout << endl;
}