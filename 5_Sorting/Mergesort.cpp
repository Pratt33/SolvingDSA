#include <bits/stdc++.h>
using namespace std;
//                  Best        Avg       Worst     Space
//Merge Sort	O(n log n)	O(n log n)	O(n log n)	O(n)
void merge(int arr[], int low, int mid, int high) {
    vector<int> temp;  // Temporary array for merging
    int left = low, right = mid + 1;

    // Merge the two sorted halves
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy any remaining elements from left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy any remaining elements from right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted elements back into original array
    for (int i = 0; i < temp.size(); i++) {
        arr[low + i] = temp[i];  // Use original `low`
    }
}

void mergesort(int arr[], int low, int high) {
    if (low >= high) return;  // Base case

    int mid = (low + high) / 2;
    mergesort(arr, low, mid);       // Sort left half
    mergesort(arr, mid + 1, high);  // Sort right half
    merge(arr, low, mid, high);     // Merge both halves
}

int main() {
    int n;
    cin >> n;
    int arr[n];  
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}