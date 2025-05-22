#include <iostream>

using namespace std;

class BSTNode 
{
private:
    int data;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;
public:
    BSTNode(int value);
    int getData();
    int ChildCount() const;
    BSTNode* getLeft();
    BSTNode* getRight();
    void setLeft(BSTNode* node);
    void setRight(BSTNode* node);
    void setData(int value);
    ~BSTNode();
};

class BST 
{
private:
    BSTNode* root;
    void insert(BSTNode* node, int value);
    void inorderTraversal(BSTNode* node);
    void preorderTraversal(BSTNode* node);
    void postorderTraversal(BSTNode* node);
public:
    BST();
    void insert(int value);
    void Traverse(int order);
    BSTNode* search(int value, BSTNode* parent);
    BSTNode* search(int value);
    void remove(int value);
    void clear(BSTNode* node);
    ~BST();
};