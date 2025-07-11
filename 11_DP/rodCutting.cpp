#include <bits/stdc++.h>
using namespace std;

// Function to compute the maximum profit by cutting rod of length 'n'
int f(int i, int n, vector<int> &price, vector<vector<int>>& dp) {
    // Base case: If only rod of length 1 is available (i==0),
    // you can cut it into as many length-1 pieces as you want.
    return (i == 0) ? (n * price[0]) : dp[i][n];

    if(dp[i][n] != -1) return dp[i][n];

    int cut = INT_MIN;
    int rodLength = i + 1;

    // Choice 1: Cut the rod at current length if possible
    if(rodLength <= n) {
        cut = price[i] + f(i, n - rodLength, price, dp);
    }

    // Choice 2: Do not cut at current length, move to smaller length
    int notCut = f(i - 1, n, price, dp);

    // Store and return the maximum of both choices
    return dp[i][n] = max(cut, notCut);
}

// Wrapper function to initialize DP table and start recursion
int cutRod(vector<int> &price, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, n, price, dp);
}

// Main function to run the code
int main() {
    int n = 8; // Length of the rod

    // Price array where price[i] is the price of rod length i+1
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    // Call the function to get the max profit
    int maxProfit = cutRod(price, n);

    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}