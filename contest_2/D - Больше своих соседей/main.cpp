#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<int>& sequence) {
    int answer = 0;
    if (sequence.size() > 2) {
        for (auto it = next(sequence.begin()); it != prev(sequence.end()); ++it) {
            if (((*it) > (*next(it))) && ((*it) > (*prev(it))) ) {
                ++answer;
            }
        }
    }
 
    return answer;
}

int main() {
    
    vector<int> inputSequence;
    int element;
    while(cin >> element) {
        inputSequence.push_back(element);
    }

    cout << solve(inputSequence) << '\n';

    return 0;
}