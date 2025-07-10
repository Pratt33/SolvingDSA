#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() - 1, n = grid[0].size() - 1;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return f(m, n, grid, dp);
    }

    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return 1e9;

        if (dp[i][j] != -1) return dp[i][j];

        int up = grid[i][j] + f(i - 1, j, grid, dp);
        int left = grid[i][j] + f(i, j - 1, grid, dp);

        return dp[i][j] = min(up, left);
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int result = sol.minPathSum(grid);
    cout << "Minimum Path Sum: " << result << endl;

    return 0;
}