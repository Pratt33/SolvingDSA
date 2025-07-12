#include <bits/stdc++.h>
using namespace std;

int main() {
    // Adjacency Matrix Representation of a Graph
    // Space Complexity: O(n^2) for an n-node graph
    // (adjacency matrix is O(n^2))
    
    int n, m;
    cin >> n >> m; // n = number of nodes, m = number of edges

    // Initialize adjacency matrix with 0
    int adj[n+1][n+1] = {0}; // using n+1 to handle 1-based indexing

    // Input m edges for the graph
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v; // edge from u to v

        adj[u][v] = 1; // for directed graph
        // If the graph is undirected, you would also do:
        // adj[v][u] = 1;
    }

    // ----------------------------------------------------------

    // Adjacency List Representation of a Graph
    // Space Complexity: O(n + m) for n nodes and m edges
    // Efficient for sparse graphs

    vector<int> adjList[n+1]; // using n+1 to handle 1-based indexing

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v; // edge from u to v

        adjList[u].push_back(v); // directed edge from u to v

        // If the graph is undirected, you would also do:
        // adjList[v].push_back(u);
    }

    return 0;
}