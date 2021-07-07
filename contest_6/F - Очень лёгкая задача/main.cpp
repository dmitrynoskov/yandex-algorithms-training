#include <iostream>
#include <cstdint>
#include <functional>

using namespace std;

/*
    бинарный поиск по ответу
*/

int64_t lBinSearch(int64_t left, int64_t right, int64_t N, int64_t x, int64_t y,
                   function<bool(int64_t, int64_t, int64_t, int64_t)> check) {
    while (left < right) {
        int64_t mid = (left + right) / 2;
        if (check(N, x, y, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

bool check(int64_t N, int64_t x, int64_t y, int64_t time) {
    return (time / x) + (time / y) >= N;
}

int main() {
    int64_t N, x, y;
    cin >> N >> x >> y;

    int64_t L = 0;
    int64_t R = N * min(x, y);
    if (N == 1) {
        cout << min(x, y) << '\n';
    } else {
        cout << min(x, y) + lBinSearch(L, R, N-1, x, y, check) << '\n';
    }

    return 0;
}