#include "Huffman.h"

Node::Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}

bool Compare::operator()(Node* a, Node* b) {
    return a->freq > b->freq;
}

Huffman::Huffman() : root(nullptr) {}

Huffman::~Huffman() {
    freeTree(root);
}

void Huffman::freeTree(Node* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

void Huffman::buildCodes(Node* node, std::string str) {
    if (!node) return;
    if (!node->left && !node->right)
        codes[node->ch] = str;
    buildCodes(node->left, str + "0");
    buildCodes(node->right, str + "1");
}

void Huffman::build(const std::string& text) {
    std::unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
    for (auto& p : freq)
        pq.push(new Node(p.first, p.second));
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    root = pq.top();
    buildCodes(root, "");
}

std::string Huffman::encode(const std::string& text) {
    std::string result;
    for (char ch : text)
        result += codes[ch];
    return result;
}

std::string Huffman::decode(const std::string& encoded) {
    std::string result;
    Node* node = root;
    for (char bit : encoded) {
        node = (bit == '0') ? node->left : node->right;
        if (!node->left && !node->right) {
            result += node->ch;
            node = root;
        }
    }
    return result;
}
