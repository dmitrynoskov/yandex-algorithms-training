#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using Color = int64_t;

/*
    основная идея: найти количество уникальных сортов, 
    затем методом двух указателей находить такие отрезки входной последовательности, количество уникальных цветов в которых будет равно искомому
*/

int main() {
    int64_t N, K;
    cin >> N >> K;

    vector<int64_t> trees;
    trees.reserve(N);
    for (int64_t i = 0; i < N; ++i) {
        Color c;
        cin >> c;
        trees.push_back(c);
    }
    int64_t fullPalette = unordered_set<Color>(trees.begin(), trees.end()).size();

    int64_t minStart = 0;
    int64_t minFinish = trees.size()-1;

    int64_t right = 0;
    unordered_map<Color, int64_t> currentPalette;
    ++currentPalette[trees[right]];

    for (int64_t left = 0; left < trees.size(); ++left) {
        while((right != trees.size()) && (currentPalette.size() != fullPalette)) {
            ++right;
            if (right != trees.size()) {
                ++currentPalette[trees[right]];
            }
        }

        if (right == trees.size()) {
            right = trees.size() - 1;
        } else if (right - left < minFinish - minStart) {
            minStart = left;
            minFinish = right;
        }
        if (currentPalette[trees[left]] <= 1) {
            currentPalette.erase(trees[left]);
        } else {
            --currentPalette[trees[left]];
        }
    }


    cout << minStart + 1 << ' ' << minFinish + 1 << '\n';


    return 0;
}