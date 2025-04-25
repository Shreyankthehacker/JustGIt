#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    Graph(int V);
    void addEdge(int u, int v);
    bool hasCycle();

private:
    int V; // Number of vertices
    std::vector<std::vector<int>> adjList;

    bool dfs(int v, std::vector<bool>& visited, std::vector<bool>& inStack, int parent);
};

#endif
