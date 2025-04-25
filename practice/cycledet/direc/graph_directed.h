#ifndef GRAPH_DIRECTED_H
#define GRAPH_DIRECTED_H

#include <vector>

class GraphDirected {
public:
    GraphDirected(int V);
    void addEdge(int u, int v);
    bool hasCycle();

private:
    int V; // Number of vertices
    std::vector<std::vector<int>> adjList;

    bool dfs(int v, std::vector<bool>& visited, std::vector<bool>& inStack);
};

#endif
