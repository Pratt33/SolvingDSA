#include <bits/stdc++.h>
using namespace std;

// Your subset sum functions
int f(int i, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(k == 0) return true;
    if(i == 0) return (arr[0] == k);

    if(dp[i][k] != -1) return dp[i][k];

    bool notTake = f(i-1, k, arr, dp);
    bool take = false;
    if(k >= arr[i]){
        take = f(i-1, k - arr[i], arr, dp);
    }

    return dp[i][k] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(n-1, k, arr, dp);
}

// Main function
int main() {
    vector<int> arr = {1, 2, 3, 4};  // Example array
    int k = 6;                       // Target sum

    if(subsetSumToK(arr.size(), k, arr))
        cout << "Subset with sum " << k << " exists." << endl;
    else
        cout << "Subset with sum " << k << " does NOT exist." << endl;

    return 0;
}