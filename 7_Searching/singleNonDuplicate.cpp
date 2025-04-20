#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        // Handle edge cases
        if (high == 0) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[high] != nums[high - 1]) return nums[high];

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if nums[mid] is the single element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // If mid is even, then the single element is on the right side
            // If mid is odd, then the single element is on the left side
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1; // This line should never be reached if the input is valid
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Single element in nums1: " << solution.singleNonDuplicate(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    cout << "Single element in nums2: " << solution.singleNonDuplicate(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {1};
    cout << "Single element in nums3: " << solution.singleNonDuplicate(nums3) << endl;

    // Test case 4
    vector<int> nums4 = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    cout << "Single element in nums4: " << solution.singleNonDuplicate(nums4) << endl;

    return 0;
}