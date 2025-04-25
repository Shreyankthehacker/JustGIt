#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfsCycle(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<pair<int, int>> q; // {node, parent}
    visited[start] = true;
    q.push({start, -1});

    while (!q.empty()) {
        auto [node, parent] = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                return true; // Found a cycle
            }
        }
    }

    return false;
}

bool hasCycleBFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (bfsCycle(i, adj, visited))
                return true;
        }
    }

    return false;
}
