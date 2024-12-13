
// adding two doublyLinkList 

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* addTwoLists(Node* l1, Node* l2) {
    Node* curr1 = l1;
    Node* curr2 = l2;
    int carry = 0;

    // Resultant list head and tail
    Node* resultHead = nullptr;
    Node* resultTail = nullptr;

    // Traverse both lists from right to left
    while (curr1 || curr2 || carry) {
        int val1 = (curr1) ? curr1->data : 0;
        int val2 = (curr2) ? curr2->data : 0;

        // Calculate sum and carry
        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        // Create a new node for the result
        Node* newNode = new Node(digit);

        // Insert at the head of the resultant list
        if (!resultHead) {
            resultHead = resultTail = newNode;
        } else {
            newNode->right = resultHead;
            resultHead->left = newNode;
            resultHead = newNode;
        }

        // Move pointers left
        if (curr1) curr1 = curr1->left;
        if (curr2) curr2 = curr2->left;
    }

    return resultHead;
}

