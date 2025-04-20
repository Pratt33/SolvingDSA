#include <iostream>
using namespace std;
#include <vector>

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int val) : data(val), next(nullptr) {}
};

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if(!head || !head->next) return head;
    
    SinglyLinkedListNode* newhead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return newhead;
}

// Helper function to print the list
void printList(SinglyLinkedListNode* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a list from vector
SinglyLinkedListNode* createList(const vector<int>& vals) {
    if(vals.empty()) return nullptr;
    SinglyLinkedListNode* head = new SinglyLinkedListNode(vals[0]);
    SinglyLinkedListNode* curr = head;
    for(size_t i = 1; i < vals.size(); i++) {
        curr->next = new SinglyLinkedListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    // Test case 1: Normal list
    vector<int> test1 = {1, 2, 3, 4, 5};
    SinglyLinkedListNode* list1 = createList(test1);
    cout << "Original: ";
    printList(list1);
    list1 = reverse(list1);
    cout << "Reversed: ";
    printList(list1);

    // Test case 2: Single element
    vector<int> test2 = {10};
    SinglyLinkedListNode* list2 = createList(test2);
    cout << "Original: ";
    printList(list2);
    list2 = reverse(list2);
    cout << "Reversed: ";
    printList(list2);

    // Test case 3: Empty list
    vector<int> test3 = {};
    SinglyLinkedListNode* list3 = createList(test3);
    cout << "Original: ";
    printList(list3);
    list3 = reverse(list3);
    cout << "Reversed: ";
    printList(list3);

    return 0;
}