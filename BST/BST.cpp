#include <iostream>
#include "BST.h"

using namespace std;

BSTNode::BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}

int BSTNode::getData() {
    return data;
}

int BSTNode::ChildCount() const {
    int count = 0;
    if (left != nullptr) count++;
    if (right != nullptr) count++;
    return count;
}

BSTNode* BSTNode::getLeft() {
    return left;
}

BSTNode* BSTNode::getRight() {
    return right;
}

void BSTNode::setLeft(BSTNode* node) {
    left = node;
}

void BSTNode::setRight(BSTNode* node) {
    right = node;
}

void BSTNode::setData(int value) {
    data = value;
}

BSTNode::~BSTNode() {
    // Destructor to clean up the node
    if (left == nullptr)
        delete left;
    if (right == nullptr)
        delete right;
}

BST::BST() : root(nullptr) {}

void BST::insert(int value) {
    if (root == nullptr) {
        root = new BSTNode(value); // Create the root node
        return;
    }
    insert(root, value);
}

void BST::insert(BSTNode* node, int value) {
    BSTNode* parrent = nullptr;
    while (node != nullptr) {
        parrent = node; // Keep track of the parent node
        if (value < node->getData()) {
            node = node->getLeft(); // Move to the left subtree
        } else if (value > node->getData()) {
            node = node->getRight(); // Move to the right subtree
        } else {
            return; // Value already exists in the tree
        }
    }
    if (value < parrent->getData()) {
        parrent->setLeft(new BSTNode(value)); // Insert as left child
    } else {
        parrent->setRight(new BSTNode(value)); // Insert as right child
    }
}

void BST::inorderTraversal(BSTNode* node) {
    if (node != nullptr) {
        inorderTraversal(node->getLeft());
        cout << node->getData() << " ";
        inorderTraversal(node->getRight());
    }
}

void BST::preorderTraversal(BSTNode* node) {
    if (node != nullptr) {
        cout << node->getData() << " ";
        preorderTraversal(node->getLeft());
        preorderTraversal(node->getRight());
    }
}

void BST::postorderTraversal(BSTNode* node) {
    if (node != nullptr) {
        postorderTraversal(node->getLeft());
        postorderTraversal(node->getRight());
        cout << node->getData() << " ";
    }
}

BSTNode* BST::search(int value, BSTNode* parent)
{
    BSTNode* current = root;
    while (current != nullptr) {
        if (value == current->getData()) {
            return current; // Value found
        }
        parent = current; // Keep track of the parent node
        if (value < current->getData()) {
            current = current->getLeft(); // Search left subtree
        } else {
            current = current->getRight(); // Search right subtree
        }
    }
    return nullptr; // Value not found
}

BSTNode* BST::search(int value) {
    return search(value, nullptr);
}

void BST::remove(int value) {
    BSTNode* current = root;
    BSTNode* parent = nullptr;
    
    current = search(value, parent); // Find the node to be deleted

    if (current == nullptr) {
        cout << "Value not found in the tree." << endl;
        return; // Value not found
    }

    // Node with only one child or no child
    if (current->ChildCount() == 0) {
        if (parent == nullptr) {
            root = nullptr; // Tree is empty now
        } else if (parent->getLeft() == current) {
            parent->setLeft(nullptr);
        } else {
            parent->setRight(nullptr);
        }
        delete current; // Free the memory of the deleted node
    } else if (current->ChildCount() == 1) {
        BSTNode* child = (current->getLeft() != nullptr) ? current->getLeft() : current->getRight();
        if (parent == nullptr) {
            root = child; // Tree is empty now
        } else if (parent->getLeft() == current) {
            parent->setLeft(child);
        } else {
            parent->setRight(child);
        }
        delete current; // Free the memory of the deleted node
    } else { // Node with two children
        BSTNode* successorParent = current;
        BSTNode* successor = current->getRight();
        while (successor->getLeft() != nullptr) {
            successorParent = successor;
            successor = successor->getLeft();
        }
        current->setData(successor->getData()); // Copy the inorder successor's data to this node
        if (successorParent != current) {
            successorParent->setLeft(successor->getRight()); // Remove the inorder successor
        } else {
            successorParent->setRight(successor->getRight());
        }
        successor->setRight(nullptr);
        delete successor; // Free the memory of the inorder successor
    }
}

void BST::Traverse(int order) {
    switch (order) {
        case 1:
            cout << "Inorder Traversal: ";
            inorderTraversal(root);
            break;
        case 2:
            cout << "Preorder Traversal: ";
            preorderTraversal(root);
            break;
        case 3:
            cout << "Postorder Traversal: ";
            postorderTraversal(root);
            break;
        default:
            cout << "Invalid traversal order." << endl;
    }
    cout << endl;
}

void BST::clear(BSTNode* node) {
    // delete all nodes in the subtree rooted at node
    if (node != nullptr) {
        clear(node->getLeft());
        clear(node->getRight());
        delete node;
    }
}

BST::~BST() {
    clear(root); // Clear the entire tree
    root = nullptr; // Set root to nullptr after clearing
}
