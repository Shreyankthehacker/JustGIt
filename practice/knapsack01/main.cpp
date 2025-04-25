#include <iostream>
#include "knapsack.h"

using namespace std;

int main() {
    int W = 50;
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};

    Knapsack knapsack(W, weights, values);
    int result = knapsack.solve();

    cout << "Maximum value in knapsack: " << result << endl;

    return 0;
}
