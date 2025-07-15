#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); // Size of the grid (n x n)

        // If the start or end cell is blocked (1), there's no path possible
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) 
            return -1;

        // Visited matrix to ensure we don't revisit the same cell
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        // Queue for BFS. Each element stores {{row, col}, steps_so_far}
        queue<pair<pair<int, int>, int>> q;

        // All 8 possible directions (including diagonals)
        vector<int> drow = {-1, -1, 0, 1, 1, 1, 0, -1}; // up-left to left-up clockwise
        vector<int> dcol = {0, 1, 1, 1, 0, -1, -1, -1};

        // Mark starting cell as visited and enqueue it with step count 1
        vis[0][0] = true;
        q.push({{0, 0}, 1}); // {{row, col}, steps}

        // Begin BFS traversal
        while (!q.empty()) {
            // Get front of queue
            int r = q.front().first.first;   // current row
            int c = q.front().first.second;  // current col
            int st = q.front().second;       // current step count
            q.pop();

            // If destination is reached, return the path length
            if (r == n - 1 && c == n - 1) {
                return st;
            }

            // Explore all 8 possible directions
            for (int i = 0; i < 8; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check if new cell is inside grid bounds
                // The cell must be free (0)
                // It should not have been visited already
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n &&
                    grid[nrow][ncol] == 0 && !vis[nrow][ncol]) {

                    // Mark new cell as visited
                    vis[nrow][ncol] = true;

                    // Enqueue new cell with incremented step count
                    q.push({{nrow, ncol}, st + 1});
                }
            }
        }

        // If BFS completes without reaching (n-1, n-1), return -1
        return -1;
    }
};