#include <iostream>
#include "stmm.h"

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    vector<vector<int>> result = strassenMultiply(A, B);

    cout << "Result of Strassen's Matrix Multiplication:" << endl;
    printMatrix(result);

    return 0;
}
