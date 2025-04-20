#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* findMiddle(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;
    return slow;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find the middle node
    Node* middle = findMiddle(head);
    if (middle) {
        cout << "Middle node data: " << middle->data << endl; // Output: 3
    } else {
        cout << "List is empty." << endl;
    }
    
    return 0;
}