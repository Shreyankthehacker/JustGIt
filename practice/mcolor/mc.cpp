#include "mc.h"
#include <iostream>

using namespace std;

bool canColor(int m, int v, const vector<vector<int>>& graph, vector<int>& colors) {
    for (int i = 0; i < graph[v].size(); i++) {
        if (graph[v][i] == 1 && colors[i] == m) {
            return false;
        }
    }
    return true;
}

bool mColoringUtil(const vector<vector<int>>& graph, int m, int v, vector<int>& colors) {
    int n = graph.size();
    if (v == n) {
        return true;
    }

    for (int color = 1; color <= m; color++) {
        if (canColor(color, v, graph, colors)) {
            colors[v] = color;
            if (mColoringUtil(graph, m, v + 1, colors)) {
                return true;
            }
            colors[v] = 0;
        }
    }
    return false;
}

bool mColoring(const vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> colors(n, 0);

    return mColoringUtil(graph, m, 0, colors);
}
