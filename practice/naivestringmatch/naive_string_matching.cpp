#include "naive_string_matching.h"
#include <iostream>

using namespace std;

int naiveSearch(const string& text, const string& pattern) {
    int m = pattern.length();
    int n = text.length();
    
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            return i;  // Match found at index i
        }
    }
    return -1;  // No match found
}
