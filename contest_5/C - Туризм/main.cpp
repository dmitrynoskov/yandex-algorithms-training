#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_map>

using namespace std;

/*
    основная идея: использовать заранее посчитанные префиксные суммы для нахождения разницы на интервале за О(1)
*/

struct Point {
    int x, y;
};

unordered_map<int, int64_t> buildDirectPrefixSum (const vector<Point>& points) {
    unordered_map<int, int64_t> prefixSum;
    prefixSum[1] = 0;
    for (auto i = 0; i < points.size() - 1; ++i) {
        if (points[i+1].y > points[i].y) {
            prefixSum[i+2] = prefixSum[i+1] + (points[i+1].y - points[i].y);
        } else {
            prefixSum[i+2] = prefixSum[i+1];
        }
    }
    return prefixSum;
}
unordered_map<int, int64_t> buildReversePrefixSum (const vector<Point>& points) {
    unordered_map<int, int64_t> prefixSum;
    prefixSum[points.size()] = 0;
    for (auto i = points.size() - 1; i > 0; --i) {
        if (points[i-1].y > points[i].y) {
            prefixSum[i] = prefixSum[i+1] + (points[i-1].y - points[i].y);
        } else {
            prefixSum[i] = prefixSum[i+1];
        }
    }
    return prefixSum;
}

int main() {
    int N, M;
    cin >> N;

    vector<Point> points;
    points.reserve(N);
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    auto directPrefixSum = buildDirectPrefixSum(points);
    auto reversePrefixSum = buildReversePrefixSum(points);
    vector<int64_t> outputSequence;

    cin >> M;
    outputSequence.reserve(M);
    for (int i = 0; i < M; ++i) {
        int xStart, xStop;
        cin >> xStart >> xStop;
        if (xStart <= xStop) {
            outputSequence.push_back(directPrefixSum[xStop] - directPrefixSum[xStart]);
        } else {
            outputSequence.push_back(reversePrefixSum[xStop] - reversePrefixSum[xStart]);
        }
    }

    for (auto i : outputSequence) {
        cout << i << '\n';
    }

    return 0;
}