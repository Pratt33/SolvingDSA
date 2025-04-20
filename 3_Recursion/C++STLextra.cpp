#include <bits/stdc++.h>
using namespace std;

// Comparator function for sorting pairs
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second > p2.second) return true;
    if (p1.second < p2.second) return false;
    // If second elements are equal, sort by the first element in decreasing order
    return p1.first > p2.first;
}

void explainExtra() {
    int a[] = {5, 2, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    vector<int> v = {3, 1, 4, 1, 5};

    // Basic sorting
    sort(a, a + n);              // Sort entire array in increasing order
    sort(v.begin(), v.end());    // Sort vector in increasing order

    // Partial sorting
    sort(a + 2, a + 4);          // Sort a subarray [a[2], a[3]] in increasing order

    // Sorting in decreasing order
    sort(a, a + n, greater<int>());

    // Sorting an array of pairs
    pair<int, int> arr[] = {{1, 2}, {2, 1}, {4, 1}};
    int m = sizeof(arr) / sizeof(arr[0]);
    // Sort by the second element, and if they are equal, sort by the first element in decreasing order
    sort(arr, arr + m, comp);

    // Printing the sorted array of pairs
    cout << "Sorted pairs: ";
    for (const auto& p : arr) {
        cout << "{" << p.first << ", " << p.second << "} ";
    }
    cout << endl;

    // Built-in functions
    int num = 7;
    int cnt = __builtin_popcount(num); // Count number of 1's in binary representation of num
    cout << "Number of 1's in binary of " << num << ": " << cnt << endl;

    // Using next_permutation for generating permutations
    string s = "123";
    sort(s.begin(), s.end()); // Ensure the string is sorted for generating permutations
    cout << "Permutations: " << endl;
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    // Find the maximum and minimum element
    int maxi = *max_element(a, a + n); // Find the maximum element in the array
    int mini = *min_element(a, a + n); // Find the minimum element in the array
    cout << "Max element: " << maxi << endl;
    cout << "Min element: " << mini << endl;
}

int main() {
    explainExtra(); // Call the function to demonstrate features
    return 0;
}