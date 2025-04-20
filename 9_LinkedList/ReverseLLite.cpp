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

Node* reverseLinkedList(Node *head)
{
    Node* temp = head;
    Node* prev = NULL;

    while(temp){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
Node* createList(int arr[], int n) {
    if (n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < n; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    // Test case 1: Normal linked list
    int arr1[] = {1, 2, 3, 4, 5};
    Node* head1 = createList(arr1, 5);
    cout << "Original List 1: ";
    printList(head1);
    head1 = reverseLinkedList(head1);
    cout << "Reversed List 1: ";
    printList(head1);

    // Test case 2: Single element
    int arr2[] = {10};
    Node* head2 = createList(arr2, 1);
    cout << "Original List 2: ";
    printList(head2);
    head2 = reverseLinkedList(head2);
    cout << "Reversed List 2: ";
    printList(head2);

    // Test case 3: Empty list
    Node* head3 = NULL;
    cout << "Original List 3: ";
    printList(head3);
    head3 = reverseLinkedList(head3);
    cout << "Reversed List 3: ";
    printList(head3);

    return 0;
}