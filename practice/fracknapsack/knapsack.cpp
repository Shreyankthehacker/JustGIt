#include "knapsack.h"
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;

    bool operator<(const Item& other) const {
        return ratio > other.ratio;
    }
};

FractionalKnapsack::FractionalKnapsack(int W, const vector<int>& weights, const vector<int>& values)
    : W(W), weights(weights), values(values) {}

double FractionalKnapsack::solve() {
    int n = weights.size();
    vector<Item> items(n);

    for (int i = 0; i < n; ++i) {
        items[i].weight = weights[i];
        items[i].value = values[i];
        items[i].ratio = (double)values[i] / weights[i];
    }

    sort(items.begin(), items.end());

    double totalValue = 0.0;
    int remainingWeight = W;

    for (const auto& item : items) {
        if (remainingWeight == 0) break;

        if (item.weight <= remainingWeight) {
            totalValue += item.value;
            remainingWeight -= item.weight;
        } else {
            totalValue += item.value * ((double)remainingWeight / item.weight);
            remainingWeight = 0;
        }
    }

    return totalValue;
}
