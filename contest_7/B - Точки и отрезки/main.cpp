#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;;

/*
    метод решения - сортировка событий (метод сканириующей прямой)
    разместим все точки на одной прямой (причем если на одну координату приходятся и начало отрезка и конец отрезка и проверяемая точка, то порядок событий слева направо такой: начало отрезка, проверка, конец отрезка)
    и отсортируем
    заведём счетчик текущих отрезков и пройдем по всем событиям слева направо
    при вводе не забудем сохранить порядок проверямых точек (сохраним в событии значение индекса последним полем, сортировка по индексу ни на что не влияет), чтобы вывести ответ в требуемом формате
*/

enum class PointType {
    START = -1,
    CONTROL = 0,
    FINISH = 1
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, PointType, int>> points;
    points.reserve(2 * n + m);

    for (int i = 0; i < n; ++i) {
        int pos1, pos2;
        cin >> pos1 >> pos2;
        int startPos = min(pos1, pos2);
        int finishPos = max(pos1, pos2);
        points.emplace_back(startPos, PointType::START, 0);
        points.emplace_back(finishPos, PointType::FINISH, 0);
    }
    for (int i = 0; i < m; ++i) {
        int point;
        cin >> point;
        points.emplace_back(point, PointType::CONTROL, i);
    }

    sort(points.begin(), points.end());

    int segmentsCount = 0;
    vector<int> answer;
    answer.resize(m);

    for (const auto&[point, pointType, index] : points) {
        if (pointType == PointType::CONTROL) {
            answer[index] = segmentsCount;
        } else if (pointType == PointType::START) {
            ++segmentsCount;
        } else {
            --segmentsCount;
        }
    }

    for (auto point : answer) {
        cout << point << ' ';
    }

    return 0;
}