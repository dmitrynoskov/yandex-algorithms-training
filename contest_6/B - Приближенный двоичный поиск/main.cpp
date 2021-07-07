#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

/*
    двоичный поиск средствами стандартной бибилиотеки
*/

int main() {
    int N, K;
    cin >> N >> K;
    vector<int64_t> sequence;
    for (int i = 0; i < N; ++i) {
        int64_t number;
        cin >> number;
        sequence.push_back(number);
    }
    for (int i = 0; i < K; ++i) {
        int64_t number;
        cin >> number;
        auto it = lower_bound(sequence.begin(), sequence.end(), number);
        if (it == sequence.begin()) {
            cout << *sequence.begin() <<'\n';
        } else if (it == sequence.end()) {
            cout << *prev(it) << '\n';
        } else {
            int64_t biggerNumber = *it;
            int64_t lowerNumber = *prev(it);
            if ((biggerNumber - number) < (number - lowerNumber)) {
                cout << biggerNumber << '\n';
            } else {
                cout << lowerNumber << '\n';
            }
        }
    }

    return 0;
}