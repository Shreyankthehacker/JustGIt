#include "graph.h"
#include <iostream>

Graph::Graph(int V) : V(V), adjList(V) {}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

bool Graph::dfs(int v, std::vector<bool>& visited, std::vector<bool>& inStack, int parent) {
    visited[v] = true;
    inStack[v] = true;

    for (int neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, inStack, v)) {
                return true;
            }
        } else if (inStack[neighbor] && neighbor != parent) {
            return true;
        }
    }

    inStack[v] = false;
    return false;
}

bool Graph::hasCycle() {
    std::vector<bool> visited(V, false);
    std::vector<bool> inStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, inStack, -1)) {
                return true;
            }
        }
    }

    return false;
}
