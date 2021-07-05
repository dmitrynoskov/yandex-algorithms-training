#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    unordered_set<int> positions;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        if  ((a >= 0) && (b >= 0) && ((a + b) == N-1)) {
            positions.insert(b + 1);
        }
    }
    cout << positions.size() << '\n';

    return 0;
}