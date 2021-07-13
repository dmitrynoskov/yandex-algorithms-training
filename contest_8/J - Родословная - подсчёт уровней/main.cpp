#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <deque>

using namespace std;
/*
    решения с наивным BFS или DFS TL'ятся
*/

int main() {
    // создадим два словаря: потомок - родитель и родитель - {потомок1, потомок2, ...}
    unordered_map<string, string> childToParent;
    unordered_map<string, vector<string>> parentToChildren;

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        string parent;
        string child;
        cin >> child >> parent;
        childToParent[child] = parent;
        parentToChildren[parent].push_back(child);
    }

    // обойдем в ширину словарь родитель - {потомок1, потомок2, ...}. основное свойство обхода - родитель встречается раньше предка
    vector<string> BFS = [&] {
        string forefather; // родоначальник - это такой предок, который не является ничьим потомком, отсюда поиск в ключах словарей
        for (const auto&[parent, children] : parentToChildren) {
            if (!childToParent.count(parent)) {
                forefather = parent;
            }
        }
        vector<string> breadthFirstSearch;
        deque<string> deq;
        deq.push_back(forefather);

        while (!deq.empty()) {
            breadthFirstSearch.push_back(deq.front());
            for (const auto& children : parentToChildren[deq.front()]) {
                deq.push_back(children);
            }
            deq.pop_front();
        }

        return breadthFirstSearch;
    }();

    // создадим словарь: человек - высота в генеалогическом дереве
    unordered_map<string, size_t> genealogicalHeight;
    for (const auto& person : BFS) {
        genealogicalHeight[person] = 0;
    }
    // обойдем BFS в прямом порядке исключая родоначальника и обновим количество потомков
    for (auto it = next(BFS.begin()); it != BFS.end(); ++it) {
        genealogicalHeight[*it] = genealogicalHeight[childToParent[*it]] + 1;
    }
 
    sort(BFS.begin(), BFS.end());

    for (const auto& name : BFS) {
        cout << name << ' ' << genealogicalHeight[name] << '\n';
    }

    return 0;
}
