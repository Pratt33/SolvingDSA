#include <iostream>
#include <vector>
using namespace std;

// Function to demonstrate the usage of iterators with vectors
void exploreIterators() {
    // Initialize a vector with values {10, 20, 30, 40}
    vector<int> v = {10, 20, 30, 40};

    // Iterator pointing to the beginning of the vector
    vector<int>::iterator it = v.begin(); // Points to the first element (10)

    // Move iterator to the next position
    it++;
    cout << "Value at the second position: " << *(it) << endl; // Prints 20

    // Iterator pointing to the end of the vector
    it = v.end(); // Points to the memory address after the last element
    it--; // Move back to point to the last element (40)
    cout << "Value at the last position using end(): " << *(it) << endl;

    // Reverse iterators
    cout << "First element using rend(): " << *(v.rend() - 1) << endl;
    cout << "Last element using rbegin(): " << *(v.rbegin()) << endl;

    // Accessing the last element directly using back()
    cout << "Last element using back(): " << v.back() << endl;

    // Printing the entire vector using different methods
    cout << "Printing the vector using iterators: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    cout << "Printing the vector using auto with iterators: ";
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    cout << "Printing the vector using range-based for loop: ";
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    exploreIterators();
    return 0;
}