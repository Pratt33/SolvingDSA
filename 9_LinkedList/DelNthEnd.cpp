#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Your corrected function
Node* removeKthNode(Node* head, int K)
{
    Node* dummy = new Node(0);
    dummy->next = head;
    
    Node* slow = dummy;
    Node* fast = dummy;
    
    // Move fast K+1 steps ahead
    for(int i = 0; i <= K; i++) {
        if(!fast) return head; // K is larger than list length
        fast = fast->next;
    }
    
    // Move both until fast reaches end
    while(fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    // Remove the Kth node from end
    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    
    Node* newHead = dummy->next;
    delete dummy;
    return newHead;
}

int main() {
    // Create a sample linked list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    cout << "Original list: ";
    printList(head);
    
    int K = 2;
    head = removeKthNode(head, K);
    
    cout << "After removing " << K << "th node from end: ";
    printList(head);
    
    // Test case: Remove head node (K = length)
    K = 4;
    head = removeKthNode(head, K);
    
    cout << "After removing " << K << "th node from end: ";
    printList(head);
    
    // Test case: Remove last node (K = 1)
    K = 1;
    head = removeKthNode(head, K);
    
    cout << "After removing " << K << "th node from end: ";
    printList(head);
    
    return 0;
}