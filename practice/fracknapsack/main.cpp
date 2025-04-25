#include <iostream>
#include "knapsack.h"

using namespace std;

int main() {
    int W = 50;
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};

    FractionalKnapsack knapsack(W, weights, values);
    double result = knapsack.solve();

    cout << "Maximum value in fractional knapsack: " << result << endl;

    return 0;
}
