#include <iostream>
#include <vector>
using namespace std;

int findKRotation(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    // If the array is not rotated, return 0
    if (arr[low] <= arr[high]) {
        return 0;
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Prevents potential overflow

        // Check if mid is the smallest element
        if (arr[mid] < arr[mid - 1]) {
            return mid;  // The number of rotations is equal to the index of the smallest element
        }
        if (arr[mid] > arr[mid + 1]) {
            return mid + 1;  // The smallest element is at mid + 1
        }

        // If the left half is sorted, the smallest element is in the right half
        if (arr[low] <= arr[mid]) {
            low = mid + 1;
        } else {  // Otherwise, the smallest element is in the left half
            high = mid - 1;
        }
    }

    return 0;  // Default case (should not be reached for a valid rotated sorted array)
}

int main() {
    // Test Case 1: Array is rotated 4 times
    vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test Case 1: " << findKRotation(arr1) << " rotations" << endl;  // Output: 4

    // Test Case 2: Array is not rotated
    vector<int> arr2 = {0, 1, 2, 4, 5, 6, 7};
    cout << "Test Case 2: " << findKRotation(arr2) << " rotations" << endl;  // Output: 0

    // Test Case 3: Array is rotated 3 times
    vector<int> arr3 = {6, 7, 0, 1, 2, 4, 5};
    cout << "Test Case 3: " << findKRotation(arr3) << " rotations" << endl;  // Output: 2

    // Test Case 4: Array with only one element
    vector<int> arr4 = {1};
    cout << "Test Case 4: " << findKRotation(arr4) << " rotations" << endl;  // Output: 0

    // Test Case 5: Array rotated once
    vector<int> arr5 = {3, 1, 2};
    cout << "Test Case 5: " << findKRotation(arr5) << " rotations" << endl;  // Output: 1

    return 0;
}