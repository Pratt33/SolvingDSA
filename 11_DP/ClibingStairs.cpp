#include <iostream>
#include <vector>
using namespace std;

// Method 1: Recursive (Slow)
class SolutionRecursive {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// Method 2: DP with Array (Bottom-Up)
class SolutionDP {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;

        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// Method 3: Optimized DP (O(1) Space)
class SolutionOptimized {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;

        int prev1 = 1, prev2 = 1;

        for (int i = 2; i <= n; ++i) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    return 0;
}