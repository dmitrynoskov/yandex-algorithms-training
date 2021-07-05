#include <iostream>
#include <unordered_set>
#include <memory>
#include <string>

using namespace std;

int main() {

    string word;
    unordered_set<string> dictionary;
    while (cin >> word) {
        dictionary.insert(move(word));
    }
    cout << dictionary.size() << '\n';
    
    return 0;
}