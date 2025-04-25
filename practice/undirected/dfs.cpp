#include <iostream>
#include <vector>
using namespace std;

bool dfsCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfsCycle(neighbor, node, adj, visited))
                return true;
        } else if (neighbor != parent) {
            return true; // Found a cycle
        }
    }

    return false;
}

bool hasCycleDFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfsCycle(i, -1, adj, visited))
                return true;
        }
    }

    return false;
}
