#include <iostream>

using namespace std;

struct node
{
    int value;
    node* next;
    node* prev;
    node(int val) : value(val), next(nullptr), prev(nullptr) {}
};


class Deque
{
private:
    node* head;
    node* tail;
public:
    Deque() : head(nullptr), tail(nullptr) {}
    ~Deque() {
        while (head) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push_front(int val) {
        node* newNode = new node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void push_back(int val) {
        node* newNode = new node(val);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void pop_front() {
        if (head == nullptr) return;
        node* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr; // Update the new head's prev pointer
        else tail = nullptr; // If the deque is now empty
        delete temp;
    }
    void pop_back() {
        if (tail == nullptr) return;
        if (head == tail) { // Only one element
            delete tail;
            head = nullptr;
            tail = nullptr;
            return;
        }
        node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr; // Update the new tail's next pointer
        else head = nullptr; // If the deque is now empty
        delete temp;
    }
    int front() {
        if (head == nullptr) throw runtime_error("Deque is empty");
        return head->value;
    }
    int back() {
        if (tail == nullptr) throw runtime_error("Deque is empty");
        return tail->value;
    }
    bool isEmpty() {
        return head == nullptr;
    }
};

int main()
{
    Deque dq;
    dq.push_back(10); // Add one element to the deque
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;
    dq.push_front(4); // Add one element to the deque
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;
    dq.pop_front(); // Remove the only element
    cout << "Deque is empty: " << (dq.isEmpty() ? "true" : "false") << endl;

    dq.pop_back(); // Remove the only element
    cout << "Deque is empty: " << (dq.isEmpty() ? "true" : "false") << endl;
    return 0;
}