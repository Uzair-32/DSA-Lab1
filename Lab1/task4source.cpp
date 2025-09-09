#include <iostream>
#include <string>
using namespace std;


int findPatternNaive(const string& text, const string& pattern) {
    if (pattern.empty()) return -1; // handle empty pattern

    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) return i; // found at index i
    }
    return -1; // not found
}

