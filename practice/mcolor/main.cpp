#include <iostream>
#include "mc.h"

using namespace std;

int main() {
    int m = 3;  
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    if (mColoring(graph, m)) {
        cout << "Graph can be colored with " << m << " colors." << endl;
    } else {
        cout << "Graph cannot be colored with " << m << " colors." << endl;
    }

    return 0;
}
