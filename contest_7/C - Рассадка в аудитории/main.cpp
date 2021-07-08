#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
    метод решения - сортировка событий (метод сканириующей прямой)
    основная идея:  разместим всех студентов вдоль оси Ox и отсортируем по координате
    создадим вектор вариантов, элементы этого вектора - векторы с координатами студентов, соответствующими этому варианту
    первому студенту (левому) присвоим вариант №1, добавим в вектор вариантов вектор с одним элементом - координатой первого студента
    далее для каждого следующего студента будем искать самый маленький вариант, подходящий под условием с расстоянием между студентами D
    если не находится подходящего варианта, то добавляем новый вариант, в него записываем вектор с координатой текущего студента
    если вариант находится, то в конец вектора этого варианта добавляем координату текущего студента

    пример:

    1 3 4 6 7 8 11 14 - координаты студентов, D = 2
    
    в конце работы алгоритма получим:
    1 var: ind : 1, 4, 7, 11, 14
    2 var: ind: 3, 6
    3 var: ind: 8

    {{1, 4, 7, 11, 14}, {3, 6}, {8}}
    */

int main() {
    int64_t N, D;
    cin >> N >> D;
    vector<int64_t> points;
    unordered_map<int64_t, size_t> pointsToIndex;
    points.reserve(N);
    for (int64_t i = 0; i < N; ++i) {
        int64_t point;
        cin >> point;
        points.push_back(point);
        pointsToIndex[point] = i;
    }

    sort(points.begin(), points.end());
    vector<vector<int64_t>> variants;
    variants.push_back({points[0]});

    for (size_t i = 1; i < points.size(); ++i) {
        auto it1 = variants.begin();
        while (it1 != variants.end() && ((points[i] - it1->back()) <= D)) {
            ++it1;
        }

        if (it1 != variants.end()) {
            it1->push_back(points[i]);
        } else {
            variants.push_back({points[i]});
        }
    }

    cout << variants.size() << '\n';
    vector<int64_t> answer;
    answer.resize(N);
    for (size_t i = 0; i < variants.size(); ++i) {
        for (auto point : variants[i]) {
            answer[pointsToIndex[point]] = i + 1;
        }
    }
    for (auto point : answer) {
        cout << point << ' ';
    }

    return 0;
}