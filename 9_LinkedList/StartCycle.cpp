#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* firstNode(Node* head) {
    if(!head || !head->next) return nullptr;  // Fixed condition

    Node* slow = head;
    Node* fast = head;

    // Detect cycle
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) break;
    }

    // No cycle found
    if(slow != fast) return nullptr;

    // Find first node of cycle
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Helper function to create a cycle in the list
void createCycle(Node* head, int pos) {
    if(pos == -1) return;
    
    Node* cycleNode = nullptr;
    Node* current = head;
    int index = 0;
    
    while(current->next) {
        if(index == pos) {
            cycleNode = current;
        }
        current = current->next;
        index++;
    }
    current->next = cycleNode;
}

// Helper function to print list (for non-cyclic parts)
void printList(Node* head, int limit = 10) {
    Node* temp = head;
    int count = 0;
    while(temp && count < limit) {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    cout << endl;
}

int main() {
    // Test case 1: List with cycle
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    
    // Create cycle: 5 points back to 2
    createCycle(head1, 1);
    
    cout << "List with cycle (first 5 elements): ";
    printList(head1);
    
    Node* cycleNode1 = firstNode(head1);
    if(cycleNode1) {
        cout << "Cycle starts at node with value: " << cycleNode1->data << endl;
    } else {
        cout << "No cycle found" << endl;
    }

    // Test case 2: List without cycle
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    
    cout << "\nList without cycle: ";
    printList(head2);
    
    Node* cycleNode2 = firstNode(head2);
    if(cycleNode2) {
        cout << "Cycle starts at node with value: " << cycleNode2->data << endl;
    } else {
        cout << "No cycle found" << endl;
    }

    // Test case 3: Single node without cycle
    Node* head3 = new Node(1);
    
    cout << "\nSingle node list: ";
    printList(head3);
    
    Node* cycleNode3 = firstNode(head3);
    if(cycleNode3) {
        cout << "Cycle starts at node with value: " << cycleNode3->data << endl;
    } else {
        cout << "No cycle found" << endl;
    }

    return 0;
}