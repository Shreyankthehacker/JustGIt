#ifndef KMP_H
#define KMP_H

#include <string>

int kmpSearch(const std::string& text, const std::string& pattern);
void computeLPSArray(const std::string& pattern, int* lps);

#endif
