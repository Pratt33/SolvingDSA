#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& nums, int target) {
    int n = nums.size(); // Size of the array
    int low = 0, high = n - 1;

    // Perform binary search
    while (low <= high) {
        int mid = low + (high - low) / 2; // Safer way to compute mid
        if (nums[mid] == target) {
            return mid; // Target found
        }
        else if (target > nums[mid]) {
            low = mid + 1; // Search right half
        }
        else {
            high = mid - 1; // Search left half
        }
    }
    return -1; // Target not found
}

int main() {
    std::vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = binarySearch(a, target);
    if (ind == -1) {
        std::cout << "The target is not present." << std::endl;
    }
    else {
        std::cout << "The target is at index: " << ind << std::endl;
    }
    return 0;
}