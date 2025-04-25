#include "rb.h"
#include <iostream>
#include <cmath>

using namespace std;

int rabinKarpSearch(const string& text, const string& pattern, int prime) {
    int n = text.length();
    int m = pattern.length();
    int i, j;
    int d = 256;
    int q = prime;

    int h = 1;
    int p = 0;
    int t = 0;

    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    for (i = 0; i < m; i++) {
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }

    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == m) {
                return i;
            }
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) {
                t = t + q;
            }
        }
    }

    return -1;
}
