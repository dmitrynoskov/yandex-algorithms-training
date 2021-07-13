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

    // создадим словарь: человек - количество потомков
    unordered_map<string, size_t> childrenQuantity;
    for (const auto& person : BFS) {
        childrenQuantity[person] = 0;
    }
    // обойдем BFS в обратном порядке и обновим количество потомков
    for (auto it = BFS.rbegin(); it != BFS.rend(); ++it) {
        for (const auto& child: parentToChildren[*it]) {
            childrenQuantity[*it] += childrenQuantity[child] + 1;
        }
    }

    sort(BFS.begin(), BFS.end());

    for (const auto& name : BFS) {
        cout << name << ' ' << childrenQuantity[name] << '\n';
    }

    return 0;
}
