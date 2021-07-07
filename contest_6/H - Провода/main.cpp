#include <iostream>
#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

/*
    бинарный поиск по ответу
*/

int64_t rBinSearch(int64_t left, int64_t right, const vector<int64_t>& wires, int64_t K,
                   function<bool(const vector<int64_t>&, int64_t, int64_t)> check) {
    while (left < right) {
        int64_t mid = (left + right + 1) / 2;
        if (check(wires, K, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

bool check(const vector<int64_t>& wires, int64_t K, int64_t length) {
    auto it = wires.begin();
    int64_t counter = 0;
    while (it != wires.end() && counter < K) {
        counter += (*it) / length;
        ++it;
    }
    return counter >= K;
}

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> wires;
    wires.reserve(N);
	int64_t maxElement = 0;
    for (int64_t i = 0; i < N; ++i) {
        int64_t length;
        cin >> length;
        wires.push_back(length);
    	if (length > maxElement){
			maxElement = length;    
    	}         
    }
    //sort(wires.begin(), wires.end(), greater<int64_t>());

    int64_t L = 0;
    int64_t R = maxElement * K;
    cout << rBinSearch(L, R, wires, K, check) << '\n';

    return 0;
}