#include <bits/stdc++.h>
using namespace std;
// User function Template for C++
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Step 1: Initialize distances to all vertices as infinity
        // Using 1e8 as infinity (large enough value)
        vector<int> dist(V, 1e8);
        
        // Distance to source vertex is 0
        dist[src] = 0;
        
        // Get total number of edges for iteration
        int e = edges.size();
        
        // Step 2: Main Bellman-Ford algorithm
        // Relax all edges V-1 times (where V is number of vertices)
        // Why V-1? Because shortest path can have at most V-1 edges
        for(int i = 0; i < V-1; i++) {
            // Flag to track if any distance was updated in this iteration
            // If no update happens, we can terminate early (optimization)
            bool flag = false;
            
            // Process all edges in this iteration
            for(int j = 0; j < e; j++) {
                // Extract edge information: u -> v with weight wt
                int u = edges[j][0];    // source vertex of edge
                int v = edges[j][1];    // destination vertex of edge
                int wt = edges[j][2];   // weight of edge
                
                // Skip if source vertex u is unreachable (still at infinity)
                // No point in relaxing from unreachable vertex
                if(dist[u] == 1e8) continue;
                
                // Edge Relaxation: Check if going through u gives shorter path to v
                // If dist[u] + wt < dist[v], then update dist[v]
                if(dist[u] + wt < dist[v]) {
                    flag = true;                    // Mark that we made an update
                    dist[v] = dist[u] + wt;        // Update distance to v
                }
            }
            
            // Early termination optimization:
            // If no distance was updated in this iteration, 
            // it means we've found all shortest paths
            if(!flag) {
                return dist;
            }
        }
        
        // Step 3: Check for negative weight cycles
        // After V-1 iterations, if we can still relax any edge,
        // it means there's a negative cycle in the graph
        for(int j = 0; j < e; j++) {
            // Extract edge information again
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            // Skip unreachable vertices
            if(dist[u] == 1e8) continue;
            
            // If we can still relax an edge after V-1 iterations,
            // negative cycle exists
            if(dist[u] + wt < dist[v]) {
                // Negative cycle detected!
                // Return vector with single element -1 to indicate this
                vector<int> ans;
                ans.push_back(-1);
                return ans;
            }
        }
        
        // No negative cycle found, return the shortest distances
        return dist;
    }
};

/*
Time Complexity: O(V * E) where V = vertices, E = edges
Space Complexity: O(V) for distance array

Key Points:
1. Bellman-Ford can handle negative weights (unlike Dijkstra)
2. It can detect negative cycles
3. Works by relaxing all edges V-1 times
4. If relaxation is possible in Vth iteration, negative cycle exists
5. Returns -1 if negative cycle is detected
*/