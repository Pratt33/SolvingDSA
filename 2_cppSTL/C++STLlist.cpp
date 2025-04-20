#include <iostream>
#include <list>
#include <deque>
using namespace std;

// Function to demonstrate the usage of std::list
void explainList() {
    // Initialize a list of integers
    list<int> ls;

    // Lists are dynamic containers, similar to vectors, but optimized for insertion/removal at both ends.
    ls.push_back(2); // Adds 2 to the back: {2}
    ls.emplace_back(4); // Adds 4 to the back: {2, 4}

    // In contrast to vectors, lists are implemented as doubly linked lists, making insertion/removal more efficient.
    ls.push_front(1); // Adds 1 to the front: {1, 2, 4}
    ls.emplace_front(0); // Adds 0 to the front: {0, 1, 2, 4}

    // Print the elements of the list
    cout << "List after operations: ";
    for (int x : ls) {
        cout << x << " ";
    }
    cout << endl;

    // Other functions of lists (similar to vectors):
    ls.pop_front(); // Removes the first element: {1, 2, 4}
    cout << "After pop_front(): ";
    for (int x : ls) {
        cout << x << " ";
    }
    cout << endl;

    ls.pop_back(); // Removes the last element: {1, 2}
    cout << "After pop_back(): ";
    for (int x : ls) {
        cout << x << " ";
    }
    cout << endl;

    // Clear the list
    ls.clear();
    cout << "Is the list empty after clear()? " << (ls.empty() ? "Yes" : "No") << endl;
}

void exploreDeque() {
    // Deque (Double-ended queue) allows efficient insertion and deletion at both ends.
    deque<int> dq;

    // Adding elements to the back and front
    dq.push_back(10);    // {10}
    dq.emplace_back(20); // {10, 20}
    dq.push_front(5);    // {5, 10, 20}
    dq.emplace_front(1); // {1, 5, 10, 20}
    }
int main() {
    explainList();
    return 0;
}