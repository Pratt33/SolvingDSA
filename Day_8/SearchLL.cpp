#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to search for a value in the linked list
bool searchInLL(Node* head, int target) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            return true;  // Found the target
        }
        current = current->next;
    }
    return false;  // Target not found
}

int main() {
    // Create a linked list: 10 -> 20 -> 30 -> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    
    // Search for values
    cout << "Searching for 20: " << (searchInLL(head, 20) ? "Found" : "Not Found") << endl;
    cout << "Searching for 25: " << (searchInLL(head, 25) ? "Found" : "Not Found") << endl;
    
    // Clean up memory
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}