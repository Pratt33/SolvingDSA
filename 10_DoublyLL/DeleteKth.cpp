#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    Node* getHead() {
        return head;
    }

    DoublyLinkedList() {
        head = nullptr;
    }

    void buildFromArray(int arr[], int n) {
        if (n == 0) return;

        head = new Node(arr[0]);
        Node* tail = head;

        for (int i = 1; i < n; i++) {
            Node* newNode = new Node(arr[i]);
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

        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteTail() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void deleteNode(Node* node) {
        if (node == nullptr || head == nullptr) {
            cout << "Invalid node or empty list" << endl;
            return;
        }

        // If node is head
        if (node == head) {
            deleteHead();
            return;
        }

        // If node is tail
        if (node->next == nullptr) {
            deleteTail();
            return;
        }

        // Node is in the middle
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;

        node->next = nullptr;
        node->prev = nullptr;
        delete node;
    }

    void traverseKth(int k) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        int cnt = 0;

        while (temp != nullptr && cnt < k) {
            temp = temp->next;
            cnt++;
        }

        if (temp == nullptr) {
            cout << "Position " << k << " is out of bounds" << endl;
            return;
        }

        deleteNode(temp);
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    DoublyLinkedList dll;
    dll.buildFromArray(arr, n);
    cout << "Original List: ";
    dll.printList();

    // Delete the 3rd node (index 2, 0-based)
    dll.deleteNode(dll.getHead()->next->next);
    cout << "List after deleting the 3rd node: ";
    dll.printList();

    // Alternatively, use traverseKth to delete the 4th node (index 3, 0-based)
    // dll.traverseKth(3);
    // cout << "List after deleting the 4th node: ";
    // dll.printList();

    return 0;
}