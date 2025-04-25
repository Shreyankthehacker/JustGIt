#include "stmm.h"
#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int>> add(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    std::vector<std::vector<int>> result(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

std::vector<std::vector<int>> subtract(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    std::vector<std::vector<int>> result(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

std::vector<std::vector<int>> strassenMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    int m = B[0].size();
    int k = A[0].size();

    if (n == 1 && m == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int mid = n / 2;

    std::vector<std::vector<int>> A11(mid, std::vector<int>(mid)), A12(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> A21(mid, std::vector<int>(mid)), A22(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> B11(mid, std::vector<int>(mid)), B12(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> B21(mid, std::vector<int>(mid)), B22(mid, std::vector<int>(mid));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    std::vector<std::vector<int>> P1 = strassenMultiply(A11, subtract(B12, B22));
    std::vector<std::vector<int>> P2 = strassenMultiply(add(A11, A12), B22);
    std::vector<std::vector<int>> P3 = strassenMultiply(add(A21, A22), B11);
    std::vector<std::vector<int>> P4 = strassenMultiply(A22, subtract(B21, B11));
    std::vector<std::vector<int>> P5 = strassenMultiply(add(A11, A22), add(B11, B22));
    std::vector<std::vector<int>> P6 = strassenMultiply(subtract(A12, A22), add(B21, B22));
    std::vector<std::vector<int>> P7 = strassenMultiply(subtract(A11, A21), add(B11, B12));

    std::vector<std::vector<int>> C11 = add(subtract(add(P5, P4), P2), P6);
    std::vector<std::vector<int>> C12 = add(P1, P2);
    std::vector<std::vector<int>> C21 = add(P3, P4);
    std::vector<std::vector<int>> C22 = add(subtract(add(P5, P1), P3), P7);

    std::vector<std::vector<int>> result(n, std::vector<int>(m));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            result[i][j] = C11[i][j];
            result[i][j + mid] = C12[i][j];
            result[i + mid][j] = C21[i][j];
            result[i + mid][j + mid] = C22[i][j];
        }
    }

    return result;
}
