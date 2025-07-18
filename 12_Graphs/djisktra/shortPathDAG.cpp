#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges){
    // Step 1: Build adjacency list representation of the graph
    // adj[u] contains all neighbors of vertex u with their edge weights
    // Each element is pair<destination, weight>
    vector<vector<pair<int, int>>> adj(n);
    
    // Process each edge and add to adjacency list
    for(auto& edge : edges){
        int u = edge[0];    // source vertex
        int v = edge[1];    // destination vertex  
        int wt = edge[2];   // weight of edge u->v
        
        // Add edge u->v with weight wt to adjacency list
        // Since it's a DAG, we only add in one direction
        adj[u].push_back({v, wt});
    }

    // Step 2: Initialize distance array
    // dist[i] = shortest distance from source (vertex 0) to vertex i
    vector<int> dist(n, 1e9);  // Initialize all distances to infinity
    dist[0] = 0;               // Distance from source to itself is 0
    
    // Step 3: Use BFS-like approach with queue
    // NOTE: This is NOT the optimal algorithm for DAG!
    // Optimal would be: Topological Sort + Relaxation
    // But this BFS approach will still work for finding shortest paths
    
    // Queue stores pairs of {weight, node}
    // weight = cumulative distance from source to this node
    // node = current vertex being processed
    queue<pair<int, int>> pq;  // Note: name 'pq' is misleading, it's actually a queue
    
    // Start BFS from source vertex 0 with distance 0
    pq.push({0, 0});  // {distance_to_node, node_id}
    
    // Step 4: Process vertices using BFS
    while(!pq.empty()){
        // Get the front element from queue
        int wt = pq.front().first;    // Current distance to this node
        int node = pq.front().second; // Current node being processed
        pq.pop();                     // Remove from queue
        
        // Step 5: Process all neighbors of current node
        // Try to relax all outgoing edges from current node
        for(auto& nbr : adj[node]){
            int neighbor = nbr.first;   // Destination vertex of the edge
            int edge_weight = nbr.second; // Weight of edge from node to neighbor
            
            // Calculate new distance to neighbor via current node
            int nwt = edge_weight + wt;  // new_weight = current_distance + edge_weight
            
            // Step 6: Edge Relaxation
            // If we found a shorter path to neighbor, update it
            if(nwt < dist[neighbor]){
                dist[neighbor] = nwt;           // Update shortest distance
                pq.push({nwt, neighbor});       // Add neighbor to queue for further processing
            }
            
            // NOTE: In DAG, we don't need to worry about revisiting nodes
            // because there are no cycles, so this relaxation will eventually
            // converge to the shortest distances
        }
    }
    
    // Step 7: Post-processing - Handle unreachable vertices
    // Convert unreachable vertices (distance = infinity) to -1
    // This is often required by problem statements
    for(int i = 0; i < n; i++){
        if(dist[i] == 1e9){
            dist[i] = -1;  // Mark unreachable vertices as -1
        }
    }
    
    // Return the shortest distances from source to all vertices
    return dist;
}

/*
ALGORITHM ANALYSIS:
- Time Complexity: O(V + E) in best case, but can be O(V * E) in worst case
  due to multiple queue insertions for same vertex
- Space Complexity: O(V + E) for adjacency list + O(V) for distance array
  
IMPORTANT NOTES:
1. This is NOT the optimal algorithm for DAG shortest path
2. Optimal approach: Topological Sort + Relaxation in O(V + E)
3. This BFS approach works but may process vertices multiple times
4. For DAG, we could process vertices in topological order exactly once

BETTER ALGORITHM FOR DAG:
1. Find topological ordering of vertices using DFS/Kahn's algorithm
2. Process vertices in topological order
3. For each vertex, relax all outgoing edges
4. This guarantees each vertex is processed exactly once
*/