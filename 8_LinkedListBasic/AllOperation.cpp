#include <bits/stdc++.h>
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

Node* removehead(Node* head){
    if(head==nullptr) return nullptr;  // Check if the list is empty
    Node* temp=head;  // Store the head node
    head=head->next;  // Move head to the next node
    delete temp;  // Delete the old head node
    return head;  // Return the new head
}

Node* removetail(Node* head){
    if(head==nullptr) return nullptr;  // Check if the list is empty
    if(head->next==nullptr){  // If there's only one node
        delete head;  // Delete the only node
        return nullptr;  // Return null as the new head
    }
    Node* temp=head;  // Store the head node
    while(temp->next->next!=nullptr){  // Traverse to the second last node
        temp=temp->next;  // Move to the next node
    }
    delete temp->next;  // Delete the last node
    temp->next=nullptr;  // Set the next of the second last node to null
    return head;  // Return the new head
}
int main() {
    // Initialize the linked list from an array
    vector<int> arr = {2, 5, 8, 7};
    Node* head = ConvertArrtoLL(arr);
    
    // Print the original list
    cout << "Original linked list: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    
    // Remove head and print the list
    head = removehead(head);
    cout << "After removing head: ";
    current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    
    // Remove tail and print the list
    head = removetail(head);
    cout << "After removing tail: ";
    current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    
    // Print the current head value
    cout << "Current head value: " << (head ? to_string(head->data) : "null") << endl;
    
    // Clean up memory
    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}