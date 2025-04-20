#include <iostream>
#include <vector>
using namespace std;

// Function to demonstrate various operations on vectors
void exploreVectors() {
    // Initialize a vector
    vector<int> v = {10, 20, 30, 40};

    // Erase a single element
    v.erase(v.begin() + 1); // Erases the element at index 1 (20)
    cout << "After erasing 20: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Erase a range of elements
    v = {10, 20, 30, 40}; // Reset vector
    v.erase(v.begin() + 1, v.begin() + 3); // Erases elements in the range [1, 3) i.e., 20 and 30
    cout << "After erasing 20 and 30: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Insert single element
    v = {100, 100};
    v.insert(v.begin(), 300); // Inserts 300 at the beginning
    cout << "After inserting 300: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Insert multiple occurrences of an element
    v.insert(v.begin() + 1, 2, 10); // Inserts 10 twice at position 1
    cout << "After inserting 10 twice: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Copy elements from another vector and insert
    vector<int> copy(2, 50); // A vector with two 50s
    v.insert(v.begin(), copy.begin(), copy.end()); // Inserts elements of 'copy' at the beginning
    cout << "After copying elements: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Display size of the vector
    cout << "Size of the vector: " << v.size() << endl;

    // Pop the last element
    v.pop_back();
    cout << "After popping the last element: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Swap contents of two vectors
    vector<int> v1 = {10, 20}, v2 = {30, 40};
    v1.swap(v2);
    cout << "After swapping v1 and v2:" << endl;
    cout << "v1: ";
    for (int x : v1) cout << x << " ";
    cout << endl;
    cout << "v2: ";
    for (int x : v2) cout << x << " ";
    cout << endl;

    // Clear the vector
    v.clear();
    cout << "After clearing the vector, is it empty? " << (v.empty() ? "Yes" : "No") << endl;
}

int main() {
    exploreVectors();
    return 0;
}