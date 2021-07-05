#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    unordered_set<int> positionsWithZeroX;
    unordered_set<int> positionsWithNonZeroX;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y ;
        if (x == 0) {
            positionsWithZeroX.insert(y);
        } else {
            positionsWithNonZeroX.insert(x);
        }
    }
    cout << positionsWithZeroX.size() + positionsWithNonZeroX.size() << '\n';

    return 0;
}