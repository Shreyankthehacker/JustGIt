#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hasCycleBFS(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);

    // Calculate in-degree of each node
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;

    // Start with nodes having in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return count != V; // If not all nodes were processed, there's a cycle
}


