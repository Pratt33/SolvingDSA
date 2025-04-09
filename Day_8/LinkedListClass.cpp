#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data1, Node* next1 = nullptr) {  // Made next1 optional
        data = data1;
        next = next1;
    }
};

int main() {
    vector<int> arr = {2, 5, 8, 7};
    
    // Create the head node
    Node* head = new Node(arr[0]);
    
    // Create current pointer to help build the list
    Node* current = head;
    
    // Build the linked list from the vector
    for (size_t i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    
    // Print the linked list
    current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> nullptr" << endl;
    
    // Print memory information (like your original code)
    cout << "\nMemory details of first node:" << endl;
    cout << "Address of head node: " << head << endl;
    cout << "Data in head node: " << head->data << endl;
    cout << "Address of next node: " << head->next << endl;
    
    // Clean up memory
    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}