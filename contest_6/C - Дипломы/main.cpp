#include <iostream>
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

/*
    бинарный поиск по ответу
*/

int64_t lBinSearch(int64_t left, int64_t right, int64_t n, int64_t w, int64_t h,
                   function<bool(int64_t n, int64_t w, int64_t h, int64_t size)> check) {
    while (left < right) {
        int64_t mid = (left + right) / 2;
        if (check(n, w, h, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

bool check(int64_t n, int64_t w, int64_t h, int64_t size) {
    return (size / w) * (size / h) >= n;
}

int main() {
    int64_t w, h, n;
    cin >> w >> h >> n;

    int64_t L = max(w, h);
    int64_t R = max(w, h) * n;

    int64_t answer = lBinSearch(L, R, n, w, h, check);

    cout << answer << '\n';

    return 0;
}