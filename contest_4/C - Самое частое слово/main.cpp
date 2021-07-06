#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <string_view>

using namespace std;

int main() {
    map<string, int> wordFrequencies;

    string word;
    while(cin >> word) {
        ++wordFrequencies[move(word)];
    }

    int maxFrequency = (*wordFrequencies.begin()).second;
    string_view mostCommonWord = (*wordFrequencies.begin()).first;
    for (const auto& [word, frequency] : wordFrequencies) {
        if (frequency > maxFrequency) {
            maxFrequency = frequency;
            mostCommonWord = word;
        }
    }

    cout << mostCommonWord << '\n';

    return 0;
}