#include <iostream>
#include "bm.h"

using namespace std;

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    int result = boyerMooreSearch(text, pattern);

    if (result != -1) {
        cout << "Pattern found at index " << result << endl;
    } else {
        cout << "Pattern not found!" << endl;
    }

    return 0;
}
