#include <iostream>
#include "naive_string_matching.h"

using namespace std;

int main() {
    string text = "ABACADABRACADABRA";
    string pattern = "ABRA";

    int result = naiveSearch(text, pattern);

    if (result != -1) {
        cout << "Pattern found at index " << result << endl;
    } else {
        cout << "Pattern not found!" << endl;
    }

    return 0;
}
