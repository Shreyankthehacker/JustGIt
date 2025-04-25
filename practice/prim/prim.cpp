#include "prim.h"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int weight) {
    adj[u].emplace_back(v, weight);
    adj[v].emplace_back(u, weight);
}

int Graph::primMST() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);

    pq.push({0, 0});
    key[0] = 0;

    int totalCost = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalCost += key[u];

        for (auto &[v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    return totalCost;
}
