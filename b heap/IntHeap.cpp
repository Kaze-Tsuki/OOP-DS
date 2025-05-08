#include <iostream>
#include <vector>

using namespace std;

class IntHeap {
private:
    vector<int> heap; // Vector to store the heap elements
public:
    IntHeap() {} // Constructor

    // Function to insert a new element into the heap
    void insert(int value) {
        heap.push_back(value); // Add the new element to the end of the vector
        int index = heap.size() - 1; // Get the index of the new element

        // Bubble up the new element to maintain the heap property
        while (index > 0) {
            int parentIndex = (index - 1) / 2; // Calculate the parent index
            if (heap[index] < heap[parentIndex]) {
                swap(heap[parentIndex], heap[index]); // Swap with parent if necessary
                index = parentIndex; // Move up to the parent index
            } else {
                break; // Stop if the heap property is satisfied
            }
        }
    }

    // Function to remove the root element (minimum) from the heap
    void removeRoot() {
        if (heap.empty()) return; // If the heap is empty, do nothing

        heap[0] = heap.back(); // Replace the root with the last element
        heap.pop_back(); // Remove the last element

        int index = 0; // Start from the root index

        // Bubble down the new root to maintain the heap property
        while (index < heap.size()) {
            int leftChildIndex = 2 * index + 1; // Calculate the left child index
            int rightChildIndex = 2 * index + 2; // Calculate the right child index
            int smallestIndex = index; // Assume the current index is the smallest

            // Check if the left child exists and is smaller than the current smallest
            if (leftChildIndex < heap.size() && heap[leftChildIndex] < heap[smallestIndex]) {
                smallestIndex = leftChildIndex;
            }

            // Check if the right child exists and is smaller than the current smallest
            if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[smallestIndex]) {
                smallestIndex = rightChildIndex;
            }

            // If no swap is needed, break out of the loop
            if (smallestIndex == index) break;

            swap(heap[index], heap[smallestIndex]); // Swap with the smallest child
            index = smallestIndex; // Move down to the smallest child's index
        }
    }

    // Function to get the root element (minimum) from the heap
    int getRoot() const {
        if (heap.empty()) throw runtime_error("Heap is empty"); // If the heap is empty, throw an error
        return heap[0]; // Return the root element
    }

    // Function to check if the heap is empty
    bool isEmpty() const {
        return heap.empty(); // Return true if the heap is empty
    }

    // Function to get the size of the heap
    int size() const {
        return heap.size(); // Return the size of the heap
    }
};

int main() {
    IntHeap heap; // Create an instance of IntHeap

    // Insert elements into the heap
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);
    heap.insert(4);

    cout << "Heap elements after insertion:" << endl;
    while (!heap.isEmpty()) {
        cout << heap.getRoot() << " "; // Print the root element
        heap.removeRoot(); // Remove the root element
    }
    cout << endl; // Print a newline after all elements are printed

    return 0; // Return success
}
