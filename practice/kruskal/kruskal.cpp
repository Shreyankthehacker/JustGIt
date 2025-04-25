#include "kruskal.h"
#include <algorithm>

using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) return;

        if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
};

Graph::Graph(int V) {
    this->V = V;
}

void Graph::addEdge(int u, int v, int weight) {
    edges.push_back({weight, u, v});
}

int Graph::kruskalMST() {
    sort(edges.begin(), edges.end());

    DSU dsu(V);
    int totalCost = 0;

    for (auto &[weight, u, v] : edges) {
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            totalCost += weight;
        }
    }

    return totalCost;
}
