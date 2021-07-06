#include <iostream>
#include <unordered_map>
#include <cstdint>

using namespace std;

int main() {
    unordered_map<int64_t, int64_t> widthToHeight;

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int64_t w, h;
        cin >> w >> h;
        if (h > widthToHeight[w]) {
            widthToHeight[w] = h;
        }
    }

    int64_t maxHeight = 0;
    for (auto [width, height] : widthToHeight) {
        maxHeight += height;
    }

    cout << maxHeight << '\n';

    return 0;
}