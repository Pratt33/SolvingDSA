#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to perform Topological Sort using Kahn's Algorithm (BFS-based)
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> ans;             // Stores the final topological ordering
        vector<int> inDeg(V, 0);     // inDeg[i] = number of incoming edges to node i

        // Step 1: Compute in-degree of each node
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < edges[i].size(); j++) {
                inDeg[edges[i][j]]++;   // Increase in-degree for each neighbor
            }
        }

        // Step 2: Push all nodes with in-degree 0 to the queue
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(inDeg[i] == 0) {
                q.push(i); // Node with no dependencies
            }
        }

        // Step 3: Perform BFS
        while(!q.empty()) {
            int node = q.front();  // Get node with in-degree 0
            q.pop();
            ans.push_back(node);   // Add it to the topological order

            // Reduce in-degree of all its neighbors
            for(int j = 0; j < edges[node].size(); j++) {
                int neighbor = edges[node][j];
                inDeg[neighbor]--;       // Remove the dependency

                // If in-degree becomes 0, push it to the queue
                if(inDeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If graph had a cycle, not all nodes would be processed
        // In such a case, ans.size() < V

        return ans; // Return topological sort order
    }
};