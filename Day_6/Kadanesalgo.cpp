#include <vector>
#include <climits> // For LONG_MIN

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        long long sum = 0; // Initialize sum to 0
        long long maxi = LONG_MIN; // Initialize maxi to the smallest possible value

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i]; // Add the current element to the sum

            // Update maxi if the current sum is greater
            if (sum > maxi) {
                maxi = sum;
            }

            // If the sum becomes negative, reset it to 0
            if (sum < 0) {
                sum = 0;
            }
        }

        return maxi; // Return the maximum subarray sum
    }
};

#include <iostream>

int main() {
    Solution sol;
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = sol.maxSubArray(nums);
    std::cout << "Maximum Subarray Sum: " << result << std::endl; // Output: 6
    return 0;
}