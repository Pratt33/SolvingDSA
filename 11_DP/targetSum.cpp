#include <bits/stdc++.h>
using namespace std;

// Recursive + Memoization function
int f(int i, int currSum, int target, vector<int>& nums, vector<vector<int>> &dp, int offset) {
    if (i == 0) {
        int plus = currSum + nums[0];
        int minus = currSum - nums[0];

        int cnt = 0;
        if (plus == target) cnt++;
        if (minus == target) cnt++;

        return cnt;
    }

    if (dp[i][currSum + offset] != -1) return dp[i][currSum + offset];

    int add = f(i - 1, currSum + nums[i], target, nums, dp, offset);
    int sub = f(i - 1, currSum - nums[i], target, nums, dp, offset);

    return dp[i][currSum + offset] = add + sub;
}

// Wrapper function
int targetSum(int n, int target, vector<int>& arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int offset = totalSum;
    vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1));
    return f(n - 1, 0, target, arr, dp, offset);
}

// Main function
int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int n = nums.size();

    int ways = targetSum(n, target, nums);
    cout << "Number of ways to reach target sum: " << ways << endl;

    return 0;
}