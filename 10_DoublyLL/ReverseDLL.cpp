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

    void reversedllbrute(){
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }

        node* temp=head;
        stack<int> st;
        while(temp!=nullptr){ // Push all elements onto the stack
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head; // Reset temp to head
        while(!st.empty()){
            temp->data = st.top(); // Assign the top element from the stack
            st.pop(); // Remove the top element from the stack
            temp = temp->next;
        }
        delete temp; // Clean up the temporary pointer
    }

    void reversedll(){
        if(head==nullptr || head->next==nullptr){
            return; // No need to reverse if the list is empty or has only one node
        }

        node* current=head;
        node* temp=nullptr;

        while(current!=nullptr){
            temp=current->prev; // Initialize temp to the previous of current
            current->prev=current->next; // Set the previous of current to next
            current->next=temp; // Set the next of current to temp

            current=current->prev; // Move to the next node (which is now previous)
        }

        head=temp->prev; // Update head to the new first node
    }
};

int main() {
    int arr[] = {2, 5, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    DoublyLinkedList dll;
    dll.buildFromArray(arr, n); // Build the doubly linked list from the array
    cout << "Doubly Linked List: ";
    dll.printList(); // Print the list in forward direction
    cout << endl;

    dll.reversedll(); // Reverse the doubly linked list
    cout << "Reversed Doubly Linked List: ";
    dll.printList(); // Print the list in forward direction after reversal
    return 0;
}