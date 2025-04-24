#include <iostream>

using namespace std;

class queue{
private:
    typedef struct node{
        int data;
        node* next;
        node(int d): data(d), next(nullptr) {}
    }node;
    node *head = nullptr;
    node *tail = nullptr;
public:
    queue() = default;
    ~queue(){
        while(head){
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push(int d){
        node* newNode = new node(d);
        if(!head){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop(){
        if(!head) return;
        node* temp = head;
        head = head->next;
        delete temp;
        if(!head) tail = nullptr; // If only one element
    }
    int front(){
        if(!head) throw runtime_error("Queue is empty");
        return head->data;
    }
    bool empty(){
        return head == nullptr;
    }
    void print(){
        node* current = head;
        while(current){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};