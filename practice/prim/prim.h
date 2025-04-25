#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include <utility>

using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    int primMST();
};

#endif
