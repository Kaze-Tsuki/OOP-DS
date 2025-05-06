#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename Compare = less<T>>
class BinaryHeap {
private:
    vector<T> heap; // Vector to store the heap elements
public:
    BinaryHeap() {} // Constructor

    // Function to insert a new element into the heap
    void insert(const T& value) {
        heap.push_back(value); // Add the new element to the end of the vector
        int index = heap.size() - 1; // Get the index of the new element

        // Bubble up the new element to maintain the heap property
        while (index > 0) {
            int parentIndex = (index - 1) / 2; // Calculate the parent index
            if (Compare()(heap[index], heap[parentIndex])) {
                swap(heap[parentIndex], heap[index]); // Swap with parent if necessary
                index = parentIndex; // Move up to the parent index
            } else {
                break; // Stop if the heap property is satisfied
            }
        }
    }

    // Function to remove the root element (minimum or maximum) from the heap
    void removeRoot() {
        if (heap.empty()) return; // If the heap is empty, do nothing

        heap[0] = heap.back(); // Replace the root with the last element
        heap.pop_back(); // Remove the last element

        int index = 0; // Start from the root index

        // Bubble down the new root to maintain the heap property
        while (index < heap.size()) {
            int leftChildIndex = 2 * index + 1; // Calculate the left child index
            int rightChildIndex = 2 * index + 2; // Calculate the right child index
            int smallestIndex = index; // Assume the current index is the largest

            // Check if the left child exists and is smaller than the current largest
            if (leftChildIndex < heap.size() && Compare()(heap[leftChildIndex], heap[smallestIndex])) {
                smallestIndex = leftChildIndex;
            }

            // Check if the right child exists and is smaller than the current largest
            if (rightChildIndex < heap.size() && Compare()(heap[rightChildIndex], heap[smallestIndex])) {
                smallestIndex = rightChildIndex;
            }

            // If no swap is needed, break out of the loop
            if (smallestIndex == index) break;

            swap(heap[index], heap[smallestIndex]); // Swap with the largest child
            index = smallestIndex; // Move down to the largest child's index
        }
    }

    // Function to get the root element (minimum or maximum) from the heap
    T getRoot() const {
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

struct CustomPair {
    int first;
    int second;
    bool operator<(const CustomPair& other) const {
        if (first == other.first) {
            return second < other.second; // Compare based on the second element if first elements are equal
        }
        return first < other.first; // Compare based on the first element
    }
    bool operator>(const CustomPair& other) const {
        if (first == other.first) {
            return second > other.second; // Compare based on the second element if first elements are equal
        }
        return first > other.first; // Compare based on the first element
    }
    bool operator==(const CustomPair& other) const {
        return first == other.first && second == other.second; // Check if both elements are equal
    }
    bool operator!=(const CustomPair& other) const {
        return !(*this == other); // Check if not equal using the equality operator
    }
    bool operator<=(const CustomPair& other) const {
        return *this < other || *this == other; // Check if less than or equal to using the less than and equality operators
    }
    bool operator>=(const CustomPair& other) const {
        return *this > other || *this == other; // Check if greater than or equal to using the greater than and equality operators
    }
    friend ostream& operator<<(ostream& os, const CustomPair& p) {
        os << "(" << p.first << ", " << p.second << ")"; // Output the pair in (first, second) format
        return os; // Return the output stream
    }
    CustomPair(int a, int b) : first(a), second(b) {} // Constructor to initialize the pair
};

struct greaterPair {
    bool operator()(const CustomPair& a, const CustomPair& b) const {
        return a > b; // Compare pairs using the greater than operator
    }
};

int main() {
    BinaryHeap<CustomPair, greaterPair> heap; // Create a binary heap of CustomPair with greater than comparison
    heap.insert(CustomPair(1, 2)); // Insert pairs into the heap
    heap.insert(CustomPair(3, 4));
    heap.insert(CustomPair(2, 3));
    heap.insert(CustomPair(5, 6));
    heap.insert(CustomPair(4, 5));
    heap.insert(CustomPair(6, 7));

    cout << "Heap elements after insertion:" << endl;
    while (!heap.isEmpty()) {
        cout << heap.getRoot() << " "; // Print the root element
        heap.removeRoot(); // Remove the root element
    }
    cout << endl; // Print a newline after all elements are printed
    return 0;
}
