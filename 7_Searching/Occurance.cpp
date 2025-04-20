#include <iostream>
#include <vector>
using namespace std;

int myLowerBound(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int result = n; // Initialize to arr.size() if no lower bound exists

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            result = mid; // Update result to the current index
            high = mid - 1; // Search in the left half
        } else {
            low = mid + 1; // Search in the right half
        }
    }

    return result;
}

int myUpperBound(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int result = n; // Initialize to arr.size() if no upper bound exists

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            result = mid; // Update result to the current index
            high = mid - 1; // Search in the left half
        } else {
            low = mid + 1; // Search in the right half
        }
    }

    return result;
}

int count(vector<int>& arr, int n, int x) {
    int l = myLowerBound(arr, n, x);
    int u = myUpperBound(arr, n, x);

    // Check if the target exists in the array
    if (l == n || arr[l] != x) {
        return -1; // Target not found
    }

    // Return the count of occurrences
    return u - l;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int x = 2;

    int result = count(arr, arr.size(), x);
    cout << "Count of " << x << ": " << result << endl;

    return 0;
}