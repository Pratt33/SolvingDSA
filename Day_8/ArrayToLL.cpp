#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {  // Made next1 optional with default nullptr
        data = data1;
        next = next1;
    }
};

Node* ConvertArrtoLL(vector<int> &arr) {
    if (arr.empty()) return nullptr;  // Handle empty array case
    
    Node* head = new Node(arr[0]);
    Node* mover = head;
    
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;  
        mover = temp;        
    }
    
    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> nullptr" << endl;
}

void deleteLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node* head = ConvertArrtoLL(arr);
    
    // Print the entire linked list
    cout << "Complete linked list: ";
    printLinkedList(head);
    
    // Print just the head data (as in your original code)
    cout << "\nHead node data: " << head->data << endl;
    
    // Print memory addresses for understanding
    cout << "\nMemory addresses:" << endl;
    cout << "Head address: " << head << endl;
    cout << "Second node address: " << head->next << endl;
    
    // Clean up memory
    deleteLinkedList(head);
    
    return 0;
}