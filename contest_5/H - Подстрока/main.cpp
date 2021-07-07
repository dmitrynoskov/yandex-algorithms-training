#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

/*
    основная идея: метод двух указателей
*/

int main() {
    int64_t n, k;
    cin >> n >> k;
    string sequence;
    cin >> sequence;

    size_t maxLength = 0;
    size_t firstIndex = 0;
    size_t right = 0;
    unordered_map<char, int64_t> symbols;

    for (size_t left = 0; left < sequence.size(); ++left) {
        while (right < sequence.size() && symbols[sequence[right]] < k) {
            ++symbols[sequence[right]];
            ++right; 
        }
        if (right - left > maxLength) {
            firstIndex = left;
            maxLength = right - left;
        }
        --symbols[sequence[left]];
    }
    cout << maxLength << ' ' << firstIndex + 1 << '\n';

    return 0;
}