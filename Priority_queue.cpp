#include <iostream>
#include <vector>
using namespace std;

// Custom priority queue class using heapify
class PriorityQueue {
private:
    vector<int> heap; // Internal heap representation

    // Heapify down: Fix the heap property from top to bottom
    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;  // Left child
        int right = 2 * index + 2; // Right child

        // Compare left child
        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        // Compare right child
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        // If the smallest isn't the root, swap and recurse
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Heapify up: Fix the heap property from bottom to top
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;

        // If the current node is smaller than its parent, swap them
        if (index > 0 && heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent); // Recur for the parent
        }
    }

public:
    // Push an element into the priority queue
    void push(int val) {
        heap.push_back(val);       // Add the new element at the end
        heapifyUp(heap.size() - 1); // Fix the heap property
    }

    // Pop the top element (smallest element)
    void pop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }

        // Replace the root with the last element and remove the last element
        heap[0] = heap.back();
        heap.pop_back();

        // Fix the heap property
        heapifyDown(0);
    }

    // Get the top element (smallest element)
    int top() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return heap[0]; // Root of the heap
    }

    // Check if the priority queue is empty
    bool empty() {
        return heap.empty();
    }

    // Print the elements of the heap (for debugging)
    void print() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    // Push elements into the priority queue
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(1);

    // Print the priority queue
    cout << "Priority Queue: ";
    pq.print();

    // Top element
    cout << "Top element: " << pq.top() << endl;

    // Pop elements
    pq.pop();
    cout << "After popping, Priority Queue: ";
    pq.print();

    pq.pop();
    cout << "After popping again, Priority Queue: ";
    pq.print();

    return 0;
}

