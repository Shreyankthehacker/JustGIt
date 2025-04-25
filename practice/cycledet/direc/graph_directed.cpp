#include "graph_directed.h"
#include <iostream>

GraphDirected::GraphDirected(int V) : V(V), adjList(V) {}

void GraphDirected::addEdge(int u, int v) {
    adjList[u].push_back(v);
}

bool GraphDirected::dfs(int v, std::vector<bool>& visited, std::vector<bool>& inStack) {
    visited[v] = true;
    inStack[v] = true;

    for (int neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, inStack)) {
                return true;
            }
        } else if (inStack[neighbor]) {
            return true; // Cycle found
        }
    }

    inStack[v] = false;
    return false;
}

bool GraphDirected::hasCycle() {
    std::vector<bool> visited(V, false);
    std::vector<bool> inStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, inStack)) {
                return true;
            }
        }
    }

    return false;
}
