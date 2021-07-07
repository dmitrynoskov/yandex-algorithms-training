#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
    основная идея: метод двух указателей подобно merge sort
*/

struct AnswerData {
    int tShirtColor;
    int trousersColor;
    int delta;
};

int main() {
    int N, M;
    cin >> N;
    vector<int> tShirts, trousers;
    for (int i = 0; i < N; ++i){
        int color;
        cin >> color;
        tShirts.push_back(color);
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int color;
        cin >> color;
        trousers.push_back(color);
    }

    auto it1 = tShirts.begin();
    auto it2 = trousers.begin();

    AnswerData answerData = {*it1, *it2, abs(*it1 - *it2)};

    for (int i = 0; i < tShirts.size() + trousers.size(); ++i) {
        if (abs(*it1 - *it2) < answerData.delta) {
            answerData = {*it1, *it2, abs(*it1 - *it2)};
        }
        if ((it1 != tShirts.end()) && (it2 == trousers.end() || (*it1 <= *it2))){
            ++it1;
        } else {
            ++it2;
        }
    }

    cout << answerData.tShirtColor << ' ' << answerData.trousersColor << '\n';

    return 0;
}