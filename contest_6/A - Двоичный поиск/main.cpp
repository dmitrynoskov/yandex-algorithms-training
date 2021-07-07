#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int64_t> sequence;
    for (int i = 0; i < N; ++i) {
        int64_t number;
        cin >> number;
        sequence.push_back(number);
    }
    sort(sequence.begin(), sequence.end());
    for (int i = 0; i < K; ++i) {
        int64_t number;
        cin >> number;
        if (binary_search(sequence.begin(), sequence.end(), number)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}