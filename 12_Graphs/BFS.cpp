#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(int n, vector<vector<int>> &adj) {
        vector<int> vis(n, 0); // visited array of size n
        vector<int> bfs;       // to store BFS result
        queue<int> q;

        vis[0] = 1; // start from node 0
        q.push(0);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            // Traverse all adjacent nodes
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1; // mark as visited
                    q.push(it);  // enqueue
                }
            }
        }
        return bfs;
    }
};

int main() {
    // Number of nodes and edges
    int n = 5, m = 4;
    
    // Create adjacency list
    vector<vector<int>> adj(n);

    // Sample undirected edges
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4}
    };

    // Fill adjacency list
    for(auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph
    }

    // Create Solution object
    Solution obj;

    // Get BFS traversal
    vector<int> result = obj.bfs(n, adj);

    // Print the result
    cout << "BFS Traversal: ";
    for(int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}