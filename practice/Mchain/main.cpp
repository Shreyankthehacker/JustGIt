#include <iostream>
#include <vector>
#include "matrix_chain.h"
using namespace std;

int main() {
    vector<int> dimensions = {40, 20, 30, 10, 30};
    int result = matrixChainMultiplication(dimensions);
    cout << "Minimum number of multiplications: " << result << endl;
    return 0;
}
