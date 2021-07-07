#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

/*
    основная идея: метод двух указателей, одним проходим всю последовательность, второй двигаем влево или вправо в зависимости от суммы значений под
этими указателями
    решения за О(N^2) TL'ятся
*/

int main() {
    int N, K;
    cin >> N >> K;

    vector<int64_t> prefixSum;
    prefixSum.reserve(N + 1);
    prefixSum.push_back(0);
    for (int i = 0; i < N; ++i){
        int number;
        cin >> number;
        prefixSum.push_back(prefixSum.back() + number);
    }

    size_t counter = 0;
    auto leftIt = prefixSum.begin();
    auto rightIt = prev(prefixSum.end());

    while(rightIt != prefixSum.begin()) {
        if ((*rightIt - *leftIt > K)) {
            while((*rightIt - *leftIt > K) && (leftIt < rightIt)) {
                ++leftIt;
            }
        } else if ((*rightIt - *leftIt < K)) {
            while((*rightIt - *leftIt < K) && (leftIt != prefixSum.begin())) {
                --leftIt;
            }
        }
        if (*rightIt - *leftIt == K) {
            ++counter;
        }
        --rightIt;

    }

    cout << counter << '\n';


    return 0;
}