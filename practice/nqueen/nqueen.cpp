#include "nqueen.h"

using namespace std;

NQueenSolver::NQueenSolver(int N) {
    this->N = N;
}

bool NQueenSolver::isSafe(int row, int col, vector<string>& board) {
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') return false;
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') return false;
        if (col + (row - i) < N && board[i][col + (row - i)] == 'Q') return false;
    }
    return true;
}

void NQueenSolver::solve(int row, vector<string>& board) {
    if (row == N) {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < N; ++col) {
        if (isSafe(row, col, board)) {
            board[row][col] = 'Q';
            solve(row + 1, board);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> NQueenSolver::getSolutions() {
    vector<string> board(N, string(N, '.'));
    solve(0, board);
    return solutions;
}
