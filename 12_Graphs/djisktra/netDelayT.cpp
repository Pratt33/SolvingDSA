#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build the adjacency list
        // Each entry adj[u] contains a list of pairs (v, wt) meaning: u -> v with time wt
        vector<vector<pair<int, int>>> adj(n + 1); // 1-indexed
        for (auto& time : times) {
            int u = time[0], v = time[1], wt = time[2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Use Dijkstra's algorithm with a min-heap (priority queue)
        // Each heap entry is {current_time, current_node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k}); // Start from node k with time 0

        // Step 3: Distance array to store shortest time to each node
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0; // Starting node takes 0 time to reach itself

        // Step 4: Main Dijkstra loop
        while (!pq.empty()) {
            auto [curr_time, node] = pq.top();
            pq.pop();

            // Visit all neighbors of the current node
            for (auto [neighbor, weight] : adj[node]) {
                int new_time = curr_time + weight;

                // If we find a shorter path to the neighbor, update and push to heap
                if (new_time < dist[neighbor]) {
                    dist[neighbor] = new_time;
                    pq.push({new_time, neighbor});
                }
            }
        }

        // Step 5: After all reachable nodes are processed
        // Check if all nodes received the signal
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1; // Node is unreachable
            maxTime = max(maxTime, dist[i]);   // Track the slowest arrival time
        }

        return maxTime; // Minimum time for all nodes to receive the signal
    }
};

// Sample Main Function
int main() {
    Solution sol;

    // Sample input: 4 nodes, edges with times, start node k = 2
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };
    int n = 4;
    int k = 2;

    int result = sol.networkDelayTime(times, n, k);

    if (result != -1)
        cout << "Minimum time for all nodes to receive signal: " << result << " units\n";
    else
        cout << "Not all nodes are reachable from source node.\n";

    return 0;
}