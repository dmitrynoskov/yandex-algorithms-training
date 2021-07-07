#include <iostream>
#include <cstdint>
#include <functional>

using namespace std;

/*
    бинарный поиск по ответу
*/

int64_t lBinSearch(int64_t left, int64_t right, int64_t a, int64_t b, int64_t c,
                   function<bool(int64_t, int64_t, int64_t, int64_t)> check) {
    while (left < right) {
        int64_t mid = (left + right) / 2;
        if (check(a, b, c, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

bool check(int64_t a, int64_t b, int64_t c, int64_t x) {
    //2*a + 3*b + 4*c + 5*x >= 3.5
    //домножим на 10 и перегруппируем, чтобы остаться в целых числах
    return 10 * (2 * a + 3 * b + 4 * c + 5 * x) >= 35 * (a + b + c + x);
}

int main() {
    int64_t a, b, c;
    cin >> a >> b >> c;

    int64_t L = 0;
    int64_t R = (a + b + c);

    cout << lBinSearch(L, R, a, b, c, check) << '\n';

    return 0;
}