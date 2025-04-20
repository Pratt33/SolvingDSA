#include <iostream>
using namespace std;

// Function to demonstrate the usage of pairs
void explainPair() {
    // Simple pair
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;

    // Nested pair
    pair<int, pair<int, int>> nestedPair = {4, {5, 6}};
    cout << nestedPair.first << " " 
         << nestedPair.second.first << " " 
         << nestedPair.second.second << endl;

    // Array of pairs
    pair<int, int> arr[] = {{7, 8}, {9, 0}, {1, 2}};
    cout << arr[1].second << endl;
}

int main() {
    explainPair();
    return 0;
}