#include <bits/stdc++.h>
using namespace std;

// Function to find two indices in the array whose corresponding values sum up to the target
vector<int> twoSum(vector<int> &arr, int target) {
    // Create an unordered map to store the value and its corresponding index
    unordered_map<int, int> unmap;

    // Iterate through the array
    for (int i = 0; i < arr.size(); i++) {
        // Calculate the complement value needed to reach the target
        int complement = target - arr[i];

        // Check if the complement value exists in the map
        if (unmap.find(complement) != unmap.end()) {
            // If found, return the indices of the complement and the current element
            return {unmap[complement], i};
        }

        // If not found, store the current element and its index in the map
        unmap[arr[i]] = i;
    }

    // If no such pair is found, return an empty vector
    return {};
}

int main() {
    int n, target;

    // Read the number of elements in the array and the target sum
    cin >> n >> target;

    // Create a vector to store the array elements
    vector<int> arr(n);

    // Read the array elements from the input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the twoSum function to find the indices of the two numbers
    vector<int> result = twoSum(arr, target);

    // Check if the result is empty (no pair found)
    if (result.empty()) {
        cout << "No Element Found For This Target" << endl;
    } else {
        // If a pair is found, print the indices
        cout << result[0] << " " << result[1] << endl;
    }

    return 0;
}