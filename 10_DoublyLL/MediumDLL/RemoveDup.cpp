#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList{
    private:
    node* head;

    public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void buildFromArray(int arr[], int n) {
        if (n == 0) return;

        head = new node(arr[0]);
        node* tail = head;

        for (int i = 1; i < n; i++) {
            node* newNode = new node(arr[i]);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void removedup() {
        if (head == nullptr) return;

        node* current = head;
        while (current != nullptr && current->next != nullptr) {
            node* runner = current->next;
            while (runner != nullptr && runner->data == current->data) {
                node* duplicate = runner;
                runner = runner->next;
                free(duplicate);
            }

            current->next = runner;
            if (runner != nullptr) {
                runner->prev = current;
            }

            current = current->next;
        }
    }
};

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    DoublyLinkedList dll;
    dll.buildFromArray(arr, n); // Build the doubly linked list from the array
    cout << "Doubly Linked List: ";
    dll.printList(); // Print the list in forward direction
    cout << endl;
    dll.removedup();
    cout<<"List after removing dups: ";
    dll.printList();
    return 0;
}