#include <iostream>
#include <vector>
using namespace std;

// Function to demonstrate the usage of vectors
void explainVectors() {
    // Vectors are dynamic arrays that can grow in size
    vector<int> v;
    v.push_back(1); // Add element to the end
    cout << v[0] << " ";

    v.emplace_back(2); // Adds element to the end, slightly faster than push_back
    cout << v[1] << endl;

    // Vector of pairs
    vector<pair<int, int>> vec;
    vec.emplace_back(3, 4); // Adds a pair to the vector
    vec.push_back({5, 6});  // Adds another pair to the vector

    // Creating a vector with specific values
    vector<int> v1(5, 20); // Initialize a vector of size 5 with all elements as 20
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;

    // Empty vector initialized with default size
    vector<int> v2(5); // Initialize with size 5, values will be 0 or garbage depending on the compiler
    for (int x : v2) {
        cout << x << " ";
    }
    cout << endl;

    // Copying a vector
    vector<int> v3(v1); // Copy all elements of v1 into v3
    for (int x : v3) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    explainVectors();
    return 0;
}