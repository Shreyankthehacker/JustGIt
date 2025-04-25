#ifndef NQUEEN_H
#define NQUEEN_H

#include <bits/stdc++.h>
using namespace std;

class NQueenSolver {
    int N;
    vector<vector<string>> solutions;

    bool isSafe(int row, int col, vector<string>& board);  // Declaration only
    void solve(int row, vector<string>& board);  // Declaration only

public:
    NQueenSolver(int N);  // Declaration only
    vector<vector<string>> getSolutions();  // Declaration only
};

#endif
