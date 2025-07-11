#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i >= prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(buy){
            profit = max(
                -prices[i] + f(i + 1, 0, prices, dp), // buy today
                f(i + 1, 1, prices, dp)               // skip buying
            );
        } else {
            profit = max(
                prices[i] + f(i + 2, 1, prices, dp),  // sell today, cooldown next day
                f(i + 1, 0, prices, dp)               // skip selling
            );
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, -1)); // +2 to avoid out-of-bound for i+2
        return f(0, 1, prices, dp); // Start from day 0 with permission to buy
    }
};

int main() {
    vector<int> prices = {1, 2}; // You can test with other cases too

    Solution sol;
    int result = sol.maxProfit(prices);
    cout << "Maximum Profit with Cooldown: " << result << endl;

    return 0;
}