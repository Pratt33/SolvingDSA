#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Build the adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            // If undirected: adj[v].push_back({u, wt});
        }

        // Step 2: Min-heap and distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src}); // {distance, node}

        // Step 3: Dijkstra’s main loop
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &nbr : adj[node]) {
                int neighbor = nbr.first;
                int wt = nbr.second;

                if (dist[neighbor] > d + wt) {
                    dist[neighbor] = d + wt;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        return dist;
    }
};