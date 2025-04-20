#include <bits/stdc++.h>
using namespace std;
//                  Best    Avg     Worst   Space
//Selection Sort	O(n²)	O(n²)	O(n²)	O(1)
void selection_sort(int arr[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        int min = i; // Assume the current position is the minimum
        for (int j = i + 1; j <= n - 1; j++) { // Start from i + 1
            if (arr[j] < arr[min]) { // Compare with arr[min]
                min = j; // Update the index of the smallest element
            }
        }
        // Swap the smallest element with the current element
        swap(arr[min], arr[i]);
    }
}

int main() {
    int n;
    cin >> n; // Input the size of the array
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input the array elements
    }
    selection_sort(arr, n); // Call the selection sort function
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Output the sorted array
    }
    return 0;
}