#include <vector>
#include <algorithm>
using namespace std;

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    // Base case: first day
    if(day == 0) {
        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            if(i != last) {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];
    // Recursive case
    int maxi = 0;
    for(int i = 0; i < 3; i++) {
        if(i != last) {
            int point = points[day][i] + f(day - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // Initially, no activity has been done ? pass last = 3
    return f(n - 1, 3, points, dp);
}