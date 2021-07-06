#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

int main() {
    unordered_map<string, unordered_set<int>> stressPositions;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        auto it = find_if(word.begin(), word.end(), [](unsigned char c) { return isupper(c); });
        int position = it - word.begin();
        *it = tolower(*it);
        stressPositions[move(word)].insert(position);
    }

    string word;
    int errorCount = 0;
    while(cin >> word) {
        vector<int> stresses;
        for (auto it = word.begin(); it != word.end(); ++it) {
            if (isupper(*it)) {
                stresses.push_back(it - word.begin());
                *it = tolower(*it);
            }
        }
        if (stresses.empty() || stresses.size() > 1 || (!stressPositions[word].empty() && !stressPositions[word].count(stresses[0]))) {
            ++errorCount;
        }
    }

    cout << errorCount << '\n';

    return 0;
}