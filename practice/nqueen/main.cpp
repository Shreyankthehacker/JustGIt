#include <iostream>
#include "nqueen.h"

using namespace std;

int main() {
    int N = 4;
    NQueenSolver solver(N);
    vector<vector<string>> solutions = solver.getSolutions();

    cout << "Total solutions for " << N << "-Queens: " << solutions.size() << endl;
    for (const auto& solution : solutions) {
        for (const string& row : solution)
            cout << row << endl;
        cout << endl;
    }

    return 0;
}
