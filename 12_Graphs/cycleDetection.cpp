#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<bool> vis(V, false);

        // Step 1: Build adjacency list
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Undirected graph
        }

        // Step 2: Handle disconnected graph (multiple components)
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis)) return true; // cycle found
            }
        }
        return false; // no cycle found
    }

    // Step 3: DFS with cycle detection
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (int j = 0; j < adj[node].size(); j++) {
            int neighbor = adj[node][j];

            if (neighbor == parent) continue; // Skip edge to parent

            if (vis[neighbor]) return true; // Found a back edge → cycle

            if (dfs(neighbor, node, adj, vis)) return true; // Recurse
        }

        return false; // No cycle found in this path
    }
};

int main() {
    Solution sol;
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    bool hasCycle = sol.isCycle(V, edges);
    cout << (hasCycle ? "Cycle found" : "No cycle") << endl;
}