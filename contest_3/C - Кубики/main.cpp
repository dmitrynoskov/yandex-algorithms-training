#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set<int> readSet(int quantity) {
    set<int> result;
    for (int i = 0; i < quantity; ++i) {
        int color;
        cin >> color;
        result.insert(color);
    }
    return result;
}

ostream& operator << (ostream& ostream, const vector<int>& vec){
    ostream << vec.size() << '\n';
    for (auto i : vec) {
        ostream << i << ' ';
    }
    return ostream << '\n';
}

int main() {
    int N, M;
    cin >> N >> M;

    const auto AnnaSet = readSet(N);
    const auto BorisSet = readSet(M);
    vector<int> intersection;
    vector<int> AnnaOnly;
    vector<int> BorisOnly;

    set_intersection(AnnaSet.begin(), AnnaSet.end(), BorisSet.begin(), BorisSet.end(),
                          back_inserter(intersection));

    set_difference(AnnaSet.begin(), AnnaSet.end(), BorisSet.begin(), BorisSet.end(),
                          back_inserter(AnnaOnly));

    set_difference(BorisSet.begin(), BorisSet.end(), AnnaSet.begin(), AnnaSet.end(),
                          back_inserter(BorisOnly));

    cout << intersection << AnnaOnly << BorisOnly;

    return 0;
}