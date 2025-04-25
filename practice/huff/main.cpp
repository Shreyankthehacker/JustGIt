#include <iostream>
#include "Huffman.h"

int main() {
    std::string text = "huffman coding example";
    Huffman h;
    h.build(text);
    std::string encoded = h.encode(text);
    std::string decoded = h.decode(encoded);
    std::cout << "Original: " << text << "\n";
    std::cout << "Encoded: " << encoded << "\n";
    std::cout << "Decoded: " << decoded << "\n";
    return 0;
}
