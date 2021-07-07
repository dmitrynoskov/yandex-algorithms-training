#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>

using namespace std;

/*
    определение из условия: медиана - член последовательности, который окажется на L-м месте, если последовательность упорядочить по неубыванию
    альтернативное определение: медиана - минимальное число, для которого найдется хотя бы L членов последовательности, не превосходящих его 
    исходя из последнего определения вложенным левым бинарным поиском можно найти медиану (внешний цикл - перебор медианы, внутренний цикл - бинарный поиск по отсортированной последовательности)
*/

int64_t findLeftMedian(const vector<int64_t>& lhs, const vector<int64_t>& rhs) {

    int64_t left = min(lhs[0], rhs[0]);
    int64_t right = max(lhs.back(), rhs.back());
    while (left < right) {
        int64_t mid = (left + right) < 0 ? (left + right - 1) / 2 : (left + right) / 2;
        if (distance(lhs.begin(), upper_bound(lhs.begin(), lhs.end(), mid)) + distance(rhs.begin(), upper_bound(rhs.begin(), rhs.end(), mid)) >= lhs.size() ) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}


int main() {
    int64_t N, L;
    cin >> N >> L;
    vector<vector<int64_t>> sequences;
    sequences.reserve(N);
    for (int64_t i = 0; i < N; ++i) {
        vector<int64_t> sequence;
        sequence.reserve(L);
        for (int64_t j = 0; j < L; ++j) {
            int64_t number;
            cin >> number;
            sequence.push_back(number);
        }
        sequences.push_back(move(sequence));
    }

    for (auto it1 = sequences.begin(); it1 != prev(sequences.end()); ++it1) {
        for (auto it2 = next(it1); it2 != sequences.end(); ++it2) {
            cout << findLeftMedian(*it1, *it2) << '\n';
        }        
    }

    return 0;
}