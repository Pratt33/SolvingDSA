#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to calculate length and print the linked list
int LengthLL(Node* head) {
    int cnt = 0;
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
        cnt++;
    }
    cout << "\nLength of linked list: " << cnt << endl;
    return cnt;  // Added return statement
}

int main() {
    // Create a simple linked list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    // Print the list and get its length
    cout << "Linked List: ";
    int length = LengthLL(head);  // Now using the return value
    
    // Clean up memory
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}