#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};

class DoublyLinkedList{
    private:
    Node* head;

    public:
    DoublyLinkedList(){
        head=nullptr;
    }

    void buildFromArray(int arr[], int n){
        if(n==0) return;

        head=new Node(arr[0]); // Create the head node
        Node* tail=head; // Tail pointer to keep track of the last node

        for(int i=1; i<n; i++){
            Node* newNode=new Node(arr[i]); // Create a new node
            tail->next=newNode; // Link the new node to the last node
            newNode->prev=tail; // Link the last node to the new node
            tail=newNode; // Move the tail pointer to the new node
        }
    }

    void printList(){
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }

        Node* current=head; // Start from the head node

        while(current!=nullptr){
            cout<<current->data<<" "; // Print the data of the current node
            current=current->next; // Move to the next node
        }
    }

    void printReverse(){
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }

        Node* tail=head;
        
        while(tail->next!=nullptr){ // Move to the last node
            tail=tail->next;
        }
        // Now tail points to the last node
        while(tail!=nullptr){
            cout<<tail->data<<" "; // Print the data of the current node
            tail=tail->prev; // Move to the previous node
        }
    }

    void deletehead(){
        if(head == nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
    
        Node* temp = head; // Store the head node
        head = head->next; // Move the head pointer to the next node
        if(head != nullptr){
            head->prev = nullptr; // Set the previous pointer of the new head to null
        }
        delete temp; // Delete the old head node
    }

    void deleteTail(){
        if(head==nullptr || head->next==nullptr){
            deletehead(); // If there's only one node, delete it using deletehead()
            return;
        }
        Node* tail=head;
        while(tail->next!=nullptr){ // Move to the last node
            tail=tail->next;
        }
        // Now tail points to the last node
        Node* prevNode = tail->prev; // Store the previous node
        tail->prev = nullptr; // Set the previous pointer of the tail to null
        prevNode->next = nullptr; // Set the next pointer of the previous node to null
        delete tail; // Delete the last node
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

    dll.deletehead(); // Delete the head node
    cout<<"List After Deleting Head: ";
    dll.printList(); // Print the list in forward direction
    cout << endl;

    dll.deleteTail(); // Delete the tail node
    cout<<"List After Deleting Tail: ";
    dll.printList(); // Print the list in forward direction
    cout << endl;
    return 0;
}