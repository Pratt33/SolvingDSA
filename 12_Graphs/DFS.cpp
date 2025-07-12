#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfsOG(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfs_ls) {
        vis[node] = 1;
        dfs_ls.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsOG(it, adj, vis, dfs_ls);
            }
        }
    }

  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> vis(adj.size(), 0);
        vector<int> dfs_ls;
        int start = 0;

        dfsOG(start, adj, vis, dfs_ls);
        return dfs_ls;
    }
};

int main() {
    int n = 5; // number of nodes
    vector<vector<int>> adj(n);

    // Sample undirected graph edges
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4}
    };

    // Building the adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // because the graph is undirected
    }

    Solution obj;
    vector<int> result = obj.dfs(adj);

    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}