#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

// Function to create a linked list from an array
Node* createLinkedList(int arr[], int n) {
    if (n == 0) return NULL;
    
    Node* head = new Node(arr[0]);
    Node* current = head;
    
    for (int i = 1; i < n; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Function to print a linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data;
        if (current->next != NULL) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

// Function to free the memory of a linked list
void deleteList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

bool isPalindrome(Node *head) {
    if (!head || !head->next) return true;  // Empty or single node list is a palindrome
    
    // Find the middle of the list
    Node* slow = head;
    Node* fast = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse the second half of the list
    Node* prev = NULL;
    Node* curr = slow->next;
    
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // Compare first half and reversed second half
    Node* first = head;
    Node* second = prev;  // Head of reversed second half
    
    while (second) {
        if (first->data != second->data) return false;
        first = first->next;
        second = second->next;
    }
    
    return true;
}

int main() {
    // Test case 1: Palindrome (odd length) - 1->2->3->2->1
    int arr1[] = {1, 2, 3, 2, 1};
    Node* list1 = createLinkedList(arr1, 5);
    cout << "List 1: ";
    printList(list1);
    cout << "Is palindrome: " << (isPalindrome(list1) ? "Yes" : "No") << endl;
    
    // Test case 2: Palindrome (even length) - 1->2->2->1
    int arr2[] = {1, 2, 2, 1};
    Node* list2 = createLinkedList(arr2, 4);
    cout << "\nList 2: ";
    printList(list2);
    cout << "Is palindrome: " << (isPalindrome(list2) ? "Yes" : "No") << endl;
    
    // Test case 3: Not a palindrome - 1->2->3->4
    int arr3[] = {1, 2, 3, 4};
    Node* list3 = createLinkedList(arr3, 4);
    cout << "\nList 3: ";
    printList(list3);
    cout << "Is palindrome: " << (isPalindrome(list3) ? "Yes" : "No") << endl;
    
    // Test case 4: Single element (always a palindrome)
    int arr4[] = {5};
    Node* list4 = createLinkedList(arr4, 1);
    cout << "\nList 4: ";
    printList(list4);
    cout << "Is palindrome: " << (isPalindrome(list4) ? "Yes" : "No") << endl;
    
    // Test case 5: Empty list (considered a palindrome)
    Node* list5 = NULL;
    cout << "\nList 5: Empty list";
    cout << "\nIs palindrome: " << (isPalindrome(list5) ? "Yes" : "No") << endl;

    // Free memory
    deleteList(list1);
    deleteList(list2);
    deleteList(list3);
    deleteList(list4);
    
    return 0;
}