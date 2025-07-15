#include <bits/stdc++.h>
using namespace std;

// Function to detect a cycle in a directed graph using Kahn's Algorithm
bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> adj(n);  // Adjacency list

    // Convert edge list to adjacency list (adjusting for 1-based indexing)
    for (auto &edge : edges) {
        int u = edge.first - 1;  // Convert to 0-based
        int v = edge.second - 1;
        adj[u].push_back(v);
    }

    // Step 1: Compute in-degree for each node
    vector<int> inDegree(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Step 2: Push all nodes with in-degree 0 into queue
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Perform Kahn’s algorithm
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Step 4: If topological sort size != number of nodes → Cycle exists
    return topo.size() != n;
}

int main() {
    int n = 4;
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2} // cycle: 2 → 3 → 4 → 2
    };

    if (detectCycleInDirectedGraph(n, edges)) {
        cout << "Cycle detected\n";
    } else {
        cout << "No cycle\n";
    }

    return 0;
}