#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data = 0;
    Node* next;
    Node() {
        this->data = 0;
        this->next = nullptr;
    }
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to detect cycle length
int solve(Node* head) {
    // Handle empty list or single node
    if (!head || !head->next) return -1;

    Node* slow = head;
    Node* fast = head;

    // Detect cycle using Floyd's algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // Cycle detected
        if (slow == fast) {
            // Count length of cycle
            int cnt = 1;
            slow = slow->next;
            while (slow != fast) {
                slow = slow->next;
                cnt++;
            }
            return cnt;
        }
    }

    // No cycle found
    return -1;
}

// Main function to test solve
int main() {
    // Test Case 1: Linked list with a cycle
    // Create nodes: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (cycle back to node with data 3)
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    // Create cycle: 5 -> 3
    head1->next->next->next->next->next = head1->next->next;

    cout << "Test Case 1 (Cycle exists): Length of cycle = " << solve(head1) << endl;
    // Expected output: 3 (cycle: 3 -> 4 -> 5 -> 3)

    // Test Case 2: Linked list without a cycle
    // Create nodes: 1 -> 2 -> 3 -> 4
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);

    cout << "Test Case 2 (No cycle): Length of cycle = " << solve(head2) << endl;
    // Expected output: -1 (no cycle)

    // Clean up memory (Note: For cyclic list, manual cleanup is complex; skipping for simplicity)
    // For head2 (no cycle), we can safely delete
    Node* current = head2;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}