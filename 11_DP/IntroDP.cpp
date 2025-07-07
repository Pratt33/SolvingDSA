#include <bits/stdc++.h>
using namespace std;

// Function to calculate nth Fibonacci number using memoization (top-down approach)
int f(int n, vector<int> &dp){
    // Base cases: Fib(0) = 0, Fib(1) = 1
    if(n <= 1) return n;
    
    // If value already computed, return it from dp array (memoization)
    if(dp[n] != -1) return dp[n];
    
    // Store and return the computed value to avoid recomputation
    return dp[n] = f(n-1, dp) + f(n-2, dp);
}

int main() {
    int n;
    cin >> n;  // Input the Fibonacci number to compute
    
    // Memoization approach (top-down)
    vector<int> dp(n+1, -1);  // Initialize dp array with -1 (uncomputed state)
    cout << f(n, dp) << endl;  // Compute and print using memoization
    
    // Tabulation approach (bottom-up) - space optimized
    int prev2 = 0;  // Represents Fib(0)
    int prev = 1;   // Represents Fib(1)
    
    // Iteratively compute Fibonacci numbers up to n
    for(int i = 2; i <= n; i++){
        int curi = prev + prev2;  // Current Fibonacci number
        prev2 = prev;             // Update previous two values
        prev = curi;              // Update previous value
    }
    
    // After loop, prev contains Fib(n)
    cout << prev;
    
    return 0;
}