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

    // void sumpairbrute(int sum) {
    //     if(head == nullptr) {
    //         cout << "List is empty" << endl;
    //         return;
    //     }

    //     vector<pair<int, int>> pairs; // To store all found pairs
    //     node* temp1 = head;

    //     while(temp1 != nullptr) {
    //         node* temp2 = temp1->next; // Start from next node to avoid duplicate pairs
            
    //         while(temp2 != nullptr && temp2->data+ temp1->data <= sum) {
    //             if(temp1->data + temp2->data == sum) {
    //                 pairs.emplace_back(temp1->data, temp2->data);
    //             }
    //             temp2 = temp2->next;
    //         }
    //         temp1 = temp1->next;
    //     }
    //     if(pairs.empty()) {
    //         cout << "No pairs found with sum " << sum << endl;
    //     } else {
    //         for(const auto& p : pairs) {
    //             cout << "(" << p.first << ", " << p.second << ") ";
    //         }
    //     }
    // }

    node* findtail(){
        if(head == nullptr) {
            cout << "List is empty" << endl;
            return nullptr;
        }

        node* tail=head;
        while(tail->next!=nullptr){
            tail = tail->next; // Move to the last node
        }
        return tail; // Return the tail node
    }
    
    void sumpair(int sum){
        node* left=head;
        node* right=findtail(); // Find the tail node
        vector<pair<int, int>> pairs;

        if(left==nullptr || right==nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        //sorted doubly linked list
        while(left->data<=right->data){
            if(left->data+right->data==sum){
                pairs.emplace_back(left->data, right->data);
                left = left->next; // Move left pointer to the next node
                right = right->prev; // Move right pointer to the previous node
            } else if(left->data+right->data<sum){
                left=left->next; // Move left pointer to the next node
            } else{
                right=right->prev; // Move right pointer to the previous node
            }
        }
        for(const auto& p : pairs) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    DoublyLinkedList dll;
    dll.buildFromArray(arr, n); // Build the doubly linked list from the array
    cout << "Doubly Linked List: ";
    dll.printList(); // Print the list in forward direction
    cout << endl;

    int sum=5;
    cout << "Pairs with sum " << sum << ": ";
    dll.sumpair(sum); // Find pairs with the given sum
    return 0;
}