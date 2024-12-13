// problem Statement  = given a circular linkList , you have to make list in increasing order , and to find the sum of elements and no of elements in the list

// approach --> first Detect the Circular Point , break it and the sort it and sum and count elements

#include<iostream>

using namespace std;
// fast and slow approach 

Node* circleDetection(Node* root) {
    if (root == NULL || root->next == NULL) {
        return root;  // No cycle if the list is empty or has only one node.
    }

    Node *slow = root;
    Node *fast = root;

    // Step 1: Detect if a cycle exists using slow and fast pointers.
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {  // Cycle detected
            break;
        }
    }

    // If no cycle was detected, return the original list.
    if (fast == NULL || fast->next == NULL) {
        return root;
    }

    // Step 2: Find the start of the cycle and break it.
    // Reset slow to the head, keep fast where it is.
    slow = root;

    // Move both pointers one step at a time; they will meet at the start of the cycle.
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Now, `slow` and `fast` are at the start of the cycle.
    // Find the last node in the cycle to break the link.
    Node* cycleStart = slow;
    Node* temp = cycleStart;
    while (temp->next != cycleStart) {
        temp = temp->next;
    }

    // Break the cycle by setting the next of the last node in the cycle to NULL.
    temp->next = NULL;

    return root;
}

