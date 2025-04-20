#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

class Solution {
public:
    int capacity(vector<int>& weights, int cap) {
        int days = 1; // First day.
        int load = 0;
        int n = weights.size(); // Size of array.
        for (int i = 0; i < n; i++) {
            if (load + weights[i] > cap) {
                days += 1; // Move to next day.
                load = weights[i]; // Load the weight.
            } else {
                // Load the weight on the same day.
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // Find maximum and summation:
        int mini = INT_MIN, maxi = 0; // Initialize mini to INT_MIN and maxi to 0.
        int n = weights.size(); // Size of the array.
        for (int i = 0; i < n; i++) {
            mini = max(mini, weights[i]); // Update mini to the maximum element.
            maxi += weights[i];           // Update maxi to the summation of the array.
        }

        // Apply binary search:
        int low = mini, high = maxi;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int numberOfDays = capacity(weights, mid);
            if (numberOfDays <= days) {
                high = mid - 1; // Try to find a smaller capacity.
            } else {
                low = mid + 1; // Increase the capacity.
            }
        }
        return low;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;
    int result1 = solution.shipWithinDays(weights1, days1);
    cout << "Example 1: " << result1 << endl; // Expected output: 15

    // Example 2
    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;
    int result2 = solution.shipWithinDays(weights2, days2);
    cout << "Example 2: " << result2 << endl; // Expected output: 6

    // Example 3
    vector<int> weights3 = {1, 2, 3, 1, 1};
    int days3 = 4;
    int result3 = solution.shipWithinDays(weights3, days3);
    cout << "Example 3: " << result3 << endl; // Expected output: 3

    return 0;
}