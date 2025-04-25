#include "bm.h"
#include <iostream>
#include <vector>

using namespace std;

void badCharacterHeuristic(const string& pattern, vector<int>& badChar) {
    int m = pattern.length();
    for (int i = 0; i < m; i++) {
        badChar[pattern[i]] = i;
    }
}

int boyerMooreSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> badChar(256, -1);
    badCharacterHeuristic(pattern, badChar);

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            return s;
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } else {
            s += max(1, j - badChar[text[s + j]]);
        }
    }

    return -1;
}
