#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
using namespace std;

class Knapsack {
    int W;
    vector<int> weights;
    vector<int> values;

public:
    Knapsack(int W, const vector<int>& weights, const vector<int>& values);
    int solve();
};

#endif
