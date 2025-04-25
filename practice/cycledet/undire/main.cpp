#include <iostream>
#include "graph.h"

int main() {
    Graph g(5); // Create a graph with 5 vertices

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    if (g.hasCycle()) {
        std::cout << "Graph has a cycle.\n";
    } else {
        std::cout << "Graph does not have a cycle.\n";
    }

    return 0;
}
