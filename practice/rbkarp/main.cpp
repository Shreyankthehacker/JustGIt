#include <iostream>
#include "rb.h"

using namespace std;

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    int result = rabinKarpSearch(text, pattern);

    if (result != -1) {
        cout << "Pattern found at index " << result << endl;
    } else {
        cout << "Pattern not found!" << endl;
    }

    return 0;
}

