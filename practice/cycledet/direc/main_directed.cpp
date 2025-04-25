#include <iostream>
#include "graph_directed.h"

int main() {
    GraphDirected g(4); // Create a graph with 4 vertices

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    if (g.hasCycle()) {
        std::cout << "Graph has a cycle.\n";
    } else {
        std::cout << "Graph does not have a cycle.\n";
    }

    return 0;
}
