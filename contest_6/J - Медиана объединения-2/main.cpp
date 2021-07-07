#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/*
    определение из условия: медиана - член последовательности, который окажется на L-м месте, если последовательность упорядочить по неубыванию
    альтернативное определение: медиана - минимальное число, для которого найдется хотя бы L членов последовательности, не превосходящих его 
    исходя из последнего определения вложенным левым бинарным поиском можно найти медиану (внешний цикл - перебор медианы, внутренний цикл - бинарный поиск по отсортированной последовательности)
*/

struct Params {
    int64_t x1, d1, a, c, m;
    /* x[i] = x[1] if i == 1
     * x[i] = x[i-1] + d[i-1] if i == [2...L]
     * d[i] = d[1] if i == 1
     * d[i] = (a * d[i-1] + c) mod m if i >= 2
     */
};

vector<int64_t> getSequence (const Params& params, int64_t size) {
    vector<int64_t> sequence;
    sequence.reserve(size);
    sequence.push_back(params.x1);

    vector<int64_t> dCoeffs;
    dCoeffs.reserve(size);
    dCoeffs.push_back(params.d1);
    for (int64_t i = 1; i < size; ++i) {
        dCoeffs.push_back((params.a * dCoeffs.back() + params.c) % params.m);
    }

    for (int64_t i = 1; i < size; ++i) {
        sequence.push_back(sequence.back() + dCoeffs[i-1]);
    }

    return sequence;
}

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
        int64_t x1, d1, a, c, m;
        cin >> x1 >> d1 >> a >> c >> m;
        sequences.push_back(getSequence({x1, d1, a, c, m}, L));
    }

    for (auto it1 = sequences.begin(); it1 != prev(sequences.end()); ++it1) {
        for (auto it2 = next(it1); it2 != sequences.end(); ++it2) {
            cout << findLeftMedian(*it1, *it2) << '\n';
        }
    }

    return 0;
}