#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Main function that initializes the DP table and calls the recursive helper
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return f(coins.size() - 1, amount, coins, dp);
    }

private:
    // Recursive function with memoization
    int f(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // Base case: only one type of coin (index 0)
        // If the amount can be formed using only this coin (i.e., divisible), return 1 way; else 0
        
        if (i == 0) return (amount % coins[0] == 0);
        // Return memoized result if already computed
        if (dp[i][amount] != -1) return dp[i][amount];
        // If the coin value is less than or equal to amount, we can take it
        // and stay at same index because we can use the same coin multiple times
        int takeIt = 0;
        if (coins[i] <= amount) {
            takeIt = f(i, amount - coins[i], coins, dp);
        }
        // Skip current coin and move to previous one
        int notTakeIt = f(i - 1, amount, coins, dp);
        // Total ways = ways by taking the coin + ways by not taking the coin
        return dp[i][amount] = notTakeIt + takeIt;
    }
};

int main() {
    Solution sol;

    int amount = 5;
    vector<int> coins = {1, 2, 5};

    int result = sol.change(amount, coins);
    cout << "Number of combinations: " << result << endl;

    return 0;
}
