#include <iostream>
#include <cstdint>
#include <functional>

using namespace std;

/*
    бинарный поиск по ответу
*/

int64_t rBinSearch(int64_t left, int64_t right, int64_t n, int64_t m, int64_t t,
                   function<bool(int64_t, int64_t, int64_t, int64_t)> check) {
    while (left < right) {
        int64_t mid = (left + right + 1) / 2;
        if (check(n, m, t, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

bool check(int64_t n, int64_t m, int64_t t, int64_t width) {
    //будем искать площадь клумбы по центру и сравнивать с площадью исходного прямоугольника
    return (2 * width <= n) && (2 * width <= m) && (n * m - (n - 2 * width) * (m - 2 * width) <= t);
}

int main() {
    int64_t n, m, t;
    cin >> n >> m >> t;

    int64_t L = 0;
    int64_t R = min(n, m);
    cout << rBinSearch(L, R, n, m , t, check) << '\n';

    return 0;
}