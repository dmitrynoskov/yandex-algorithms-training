#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

using namespace std;

int main() {
    unordered_map<string, int> wordEntries;

    string word;
    while(cin >> word) {
        cout << wordEntries[move(word)]++ << ' ';
    }

    return 0;
}