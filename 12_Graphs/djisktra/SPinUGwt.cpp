#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        vector<int> dist(adj.size(), -1); // -1 = unvisited
        queue<int> q;
        
        dist[src] = 0;
        q.push(src);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        return dist;
    }
};