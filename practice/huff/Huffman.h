#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>
#include <queue>

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f);
};

struct Compare {
    bool operator()(Node* a, Node* b);
};

class Huffman {
    Node* root;
    std::unordered_map<char, std::string> codes;
    void buildCodes(Node* node, std::string str);
    void freeTree(Node* node);
public:
    Huffman();
    ~Huffman();
    void build(const std::string& text);
    std::string encode(const std::string& text);
    std::string decode(const std::string& encoded);
};

#endif
