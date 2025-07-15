#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();  // Get number of rows and columns

        // effort[r][c] stores the minimum effort required to reach cell (r, c)
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

        // Min-heap priority queue: stores {effort_so_far, row, col}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        // Start from the top-left corner (0,0) with 0 effort
        effort[0][0] = 0;
        pq.push({0, 0, 0});  // {effort, row, col}

        // Movement directions: up, down, left, right
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};

        // Begin Dijkstra's traversal
        while (!pq.empty()) {
            // Get the current cell with minimum effort so far
            auto [diff, r, c] = pq.top();
            pq.pop();

            // If we reached the destination (bottom-right), return the effort
            if (r == m - 1 && c == n - 1) return diff;

            // Explore all 4 neighboring directions
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check if the new cell is within the grid bounds
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n) {
                    // Calculate the effort to reach the new cell
                    // The effort is the max difference seen so far in the path
                    int newEffort = max(diff, abs(heights[nrow][ncol] - heights[r][c]));

                    // If this new path offers a smaller effort to reach (nrow, ncol), update and push
                    if (newEffort < effort[nrow][ncol]) {
                        effort[nrow][ncol] = newEffort;
                        pq.push({newEffort, nrow, ncol});
                    }
                }
            }
        }

        // Control should not reach here, but return 0 just in case
        return 0;
    }
};