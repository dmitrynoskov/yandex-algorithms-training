#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

using namespace std;

int main() {
    int N;
    unordered_map<string, string> synonyms;

    string word1, word2;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> word1 >> word2 ;
        synonyms[word1] = word2;
        synonyms[move(word2)] = move(word1);
    }

    cin >> word1;
    cout << synonyms[word1] << '\n';

    return 0;
}