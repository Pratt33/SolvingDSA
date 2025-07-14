#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();          // Number of rows in the image
        int n = image[0].size();       // Number of columns in the image

        // Create a visited matrix to keep track of visited cells
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Initialize queue for BFS traversal starting from (sr, sc)
        queue<pair<int, int>> q;
        q.push({sr, sc});              // Push the starting cell to the queue
        vis[sr][sc] = 1;               // Mark the starting cell as visited

        // Store the original color of the starting pixel
        int oldColor = image[sr][sc];

        // Arrays to simplify the 4-directional movement: up, right, down, left
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        // Perform BFS traversal
        while (!q.empty()) {
            int r = q.front().first;   // Current row
            int c = q.front().second;  // Current column
            q.pop();                   // Dequeue current cell

            // Change the color of the current cell
            image[r][c] = color;

            // Explore all 4 neighboring directions
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];   // Neighboring row
                int ncol = c + dcol[i];   // Neighboring column

                // Check for valid bounds and necessary conditions:
                // 1. Inside the grid
                // 2. Not already visited
                // 3. Same color as the starting pixel (oldColor)
                // 4. Not already set to the new color
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    !vis[nrow][ncol] &&
                    image[nrow][ncol] == oldColor &&
                    image[nrow][ncol] != color) {
                    
                    vis[nrow][ncol] = 1;          // Mark as visited
                    q.push({nrow, ncol});         // Add to queue for further exploration
                }
            }
        }

        // Return the updated image after flood fill
        return image;
    }
};