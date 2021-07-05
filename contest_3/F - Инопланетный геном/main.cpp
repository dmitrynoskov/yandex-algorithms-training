#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int findEntries (unordered_map<int, int>& firstGenome, const unordered_set<int>& secondGenome) {
    int result = 0;
    for (const auto& code: secondGenome) {
        result += firstGenome[code];
    }
    return result;
}

int getCode (char lhs, char rhs) {
    int result = 0;
    result += static_cast<int>(lhs) - static_cast<int>('A');
    result *= 100;
    result += static_cast<int>(rhs) - static_cast<int>('A');
    return result;
}

unordered_map<int, int> getGenomeMap (const string& inputSequence) {
    unordered_map<int, int> result;
    auto it1 = inputSequence.begin();
    auto it2 = next(it1);
    while(it2 != inputSequence.end()) {
        int code = getCode(*it1, *it2);
        ++result[code];
        ++it1;
        ++it2;
    }
    return result;
}

unordered_set<int> getGenomeSet (const string& inputSequence) {
    unordered_set<int> result;
    auto it1 = inputSequence.begin();
    auto it2 = next(it1);
    while(it2 != inputSequence.end()) {
        int code = getCode(*it1, *it2);
        result.insert(code);
        ++it1;
        ++it2;
    }
    return result;
}



int main() {
    string sequence;
    cin >> sequence;
    auto firstGenome = getGenomeMap(sequence);
    cin >> sequence;
    auto secondGenome = getGenomeSet(sequence);

    cout << findEntries(firstGenome, secondGenome) << '\n';

    return 0;
}