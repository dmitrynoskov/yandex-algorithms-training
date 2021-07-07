#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

/*
    основная идея: использовать метод двух указателей
*/

int main() {
    int64_t n, r;
    cin >> n >> r;

    vector<int64_t> points;
    points.reserve(n);
    for (int64_t i = 0; i < n; ++i) {
        int64_t distance;
        cin >> distance;
        points.push_back(distance);
    }

    int64_t counter = 0;

    auto last = points.begin();

    for (auto first = points.begin(); first != points.end(); ++first) {
        while (last != points.end() && ((*last - *first) <= r)) {
            ++last;
        }
        counter += distance(last, points.end());
    }
    cout << counter << '\n';

    return 0;
}