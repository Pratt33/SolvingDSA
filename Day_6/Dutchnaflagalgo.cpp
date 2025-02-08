#include <bits/stdc++.h> 
using namespace std;

/**
 * Function to sort an array containing only 0s, 1s, and 2s using 
 * the Dutch National Flag algorithm.
 * @param arr Pointer to the input array.
 *        - `int arr[]` is equivalent to `int *arr` when passed to a function.
 *        - This function works only for statically allocated arrays.
 *        - For dynamically allocated arrays (`new int[n]`), `vector<int>` is recommended.
 * @param n Size of the array.
 */
void sort012(int *arr, int n) {
    int low = 0, mid = 0, high = n - 1;

    // Traverse the array until mid crosses high
    while (mid <= high) {
        if (arr[mid] == 0) {
            // Swap 0 to the beginning and move both pointers
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        } 
        else if (arr[mid] == 2) {
            // Swap 2 to the end and decrease high pointer
            swap(arr[mid], arr[high]);
            high--;
        } 
        else {
            // If the element is 1, just move mid forward
            mid++;
        }
    }
}

int main() {
    int n;
    
    // Input array size
    cin >> n;
    vector<int> arr(n);  // Using vector instead of VLA

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array
    sort012(arr.data(), n);  // Pass raw pointer to the function

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}