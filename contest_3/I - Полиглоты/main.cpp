#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <memory>

using namespace std;

int main() {
    set<string> intersectionSet;
    unordered_set<string> unionSet;
    int N;
    cin >> N;
    int M;
    cin >> M;
    string language;
    for (int i = 0; i < M; ++i) {
        cin >> language;
        intersectionSet.insert(language);
        unionSet.insert(move(language));
    }

    for (int i = 1; i < N; ++i) {
        cin >> M;
        set<string> languages;
        for (int i = 0; i < M; ++i) {
            cin >> language;
            languages.insert(language);
            unionSet.insert(move(language));
        }
        set<string> newIntersection;
        set_intersection(intersectionSet.begin(), intersectionSet.end(), languages.begin(), languages.end(), inserter(newIntersection, newIntersection.begin()));
        intersectionSet = move(newIntersection);
    }

    cout << intersectionSet.size() << '\n';
    for (const auto& lang : intersectionSet) {
        cout << lang << '\n';
    }

    cout << unionSet.size() << '\n';
    for (const auto& lang : unionSet) {
        cout << lang << '\n';
    }

    return 0;
}