#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Step 1: Build the adjacency list
        // Each node maps to a list of (neighbor, time) pairs
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t}); // Because the roads are bidirectional
        }

        // Step 2: Min-heap to always get the node with the smallest time
        // (time, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // Starting from node 0 with time 0

        // Step 3: Distance array initialized to infinity
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0; // Distance to source node is 0

        // Step 4: Ways array to count number of shortest paths
        vector<int> ways(n, 0);
        ways[0] = 1; // There's 1 way to reach the start node

        // Step 5: Dijkstra's algorithm loop
        while (!pq.empty()) {
            auto [tm, node] = pq.top();
            pq.pop();

            // Traverse all neighbors of the current node
            for (auto [neighbor, t] : adj[node]) {
                int nt = tm + t; // new time to reach neighbor

                // Case 1: Found a strictly shorter path
                if (nt < dist[neighbor]) {
                    dist[neighbor] = nt;
                    ways[neighbor] = ways[node]; // Inherit path count
                    pq.push({nt, neighbor});
                }
                // Case 2: Found an equally short path (add count)
                else if (nt == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        // Step 6: Return the number of shortest paths to node n-1
        return ways[n - 1];
    }
};

// ======================
// MAIN FUNCTION FOR TESTING
// ======================
int main() {
    Solution sol;

    // Test case:
    int n = 4;
    vector<vector<int>> roads = {
        {0, 1, 1},
        {0, 2, 1},
        {1, 3, 1},
        {2, 3, 1}
    };

    // Expected Output: 2 (0→1→3 and 0→2→3)
    int result = sol.countPaths(n, roads);
    cout << "Number of shortest paths from 0 to " << (n - 1) << ": " << result << endl;

    return 0;
}