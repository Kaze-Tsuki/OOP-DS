#include <iostream>

using namespace std;

class stack{
private:
    typedef struct node{
        int data;
        node* next;
        node(int d): data(d), next(nullptr) {}
    }node;
    node *up = nullptr;
public:
    stack() = default;
    ~stack(){
        while(up != nullptr){
            node* temp = up;
            up = up->next;
            delete temp;
        }
    }
    void push(int d){
        node* newNode = new node(d);
        newNode->next = up;
        up = newNode;
    }
    int pop(){
        if(up == nullptr) return -1; // Stack is empty
        int data = up->data;
        node* temp = up;
        up = up->next;
        delete temp;
        return data;
    }
    bool isEmpty(){
        return up == nullptr;
    }
    int top(){
        if(up == nullptr) return -1; // Stack is empty
        return up->data;
    }
    void printStack(){
        node* current = up;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};