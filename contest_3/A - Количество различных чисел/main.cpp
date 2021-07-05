#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main () {
    const vector<int> inputSequence = [] {
        vector<int> sequence;
        int number;
        while (cin >> number) {
            sequence.push_back(number);
        }
        return sequence;
    } ();
    cout << unordered_set<int>(inputSequence.begin(), inputSequence.end()).size() << '\n';

    return 0;
}