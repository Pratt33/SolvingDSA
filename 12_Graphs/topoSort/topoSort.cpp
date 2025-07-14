#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Helper DFS function
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& s) {
        vis[node] = true;  // Mark current node as visited

        // Visit all neighbors (adjacent vertices)
        for (int j = 0; j < adj[node].size(); j++) {
            int neighbor = adj[node][j];
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis, s);  // Recursive DFS call
            }
        }

        // After all children are visited, push current node to stack
        s.push(node);
    }

    // Main function to return topological order
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V, 0);  // Visited array
        stack<int> s;            // Stack to store order

        // Visit each node (for disconnected components too)
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, s);
            }
        }

        // Pop from stack to get topological order
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};