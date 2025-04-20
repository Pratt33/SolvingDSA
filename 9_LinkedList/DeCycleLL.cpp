#include <iostream>
using namespace std;

// Definition of Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Helper function to create a cycle
void createCycle(Node* head, int pos) {
    if(pos == -1) return;
    Node* cycleNode = head;
    Node* tail = head;
    while(tail->next) tail = tail->next;
    for(int i = 0; i < pos; i++) cycleNode = cycleNode->next;
    tail->next = cycleNode;
}

// Function to detect a cycle in the linked list
bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true; // Cycle detected
    }
    return false; // No cycle
}

int main() {
    // Test case 1: No cycle
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    cout << detectCycle(head1) << endl; // Output: 0
    
    // Test case 2: Has cycle
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    createCycle(head2, 1); // Creates cycle back to node 2
    cout << detectCycle(head2) << endl; // Output: 1
    
    // Test case 3: Single node no cycle
    Node* head3 = new Node(1);
    cout << detectCycle(head3) << endl; // Output: 0
    
    return 0;
}