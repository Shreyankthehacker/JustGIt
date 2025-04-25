#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
using namespace std;

class FractionalKnapsack {
    int W;
    vector<int> weights;
    vector<int> values;

public:
    FractionalKnapsack(int W, const vector<int>& weights, const vector<int>& values);
    double solve();
};

#endif
