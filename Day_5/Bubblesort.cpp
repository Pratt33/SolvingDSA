#include <bits/stdc++.h>
using namespace std;
//                  Best    Avg     Worst   Space
//Bubble Sort	    O(n)	O(n²)	O(n²)	O(1)
void bubble_sort(int arr[], int n) {
    for (int i = 0; i <= n - 2; i++) { // Outer loop runs n-1 times
        for (int j = 0; j <= n - 2 - i; j++) { // Inner loop runs (n-1-i) times (n-2) for j+1
            if (arr[j] > arr[j + 1]) { // Compare adjacent elements
                swap(arr[j], arr[j + 1]); // Swap if out of order
            }
        }
    }
}

int main() {
    int n;
    cin >> n; // Input the size of the array
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input the array elements
    }
    bubble_sort(arr, n); // Call the bubble sort function
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Output the sorted array
    }
    return 0;
}