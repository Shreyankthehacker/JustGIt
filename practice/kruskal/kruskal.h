#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <tuple>

using namespace std;

class Graph {
    int V;
    vector<tuple<int, int, int>> edges;

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    int kruskalMST();
};

#endif
