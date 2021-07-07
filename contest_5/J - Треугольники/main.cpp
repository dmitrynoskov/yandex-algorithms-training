#include <iostream>
#include <cstdint>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
    основная идея: для каждой точки создадим вектор расстояний до всех остальных точек.
    отсортируем вектор и с помощью метода двух указателей найдём все соседние точки с одинаковыми расстояниями до исходной
    пусть для исходной точки есть m равноудалённых точек, тогда количество равнобедренных треугольников с вершиной в исходной точке равно m * (m - 1) / 2 
    (есть m способов выбрать вторую точку и m - 1 способ выбрать вторую точку, но так как треугольники ABC и ACB - один и тот же треугольник, то произведение нужно поделить на 2)
    получим сложность О(N^2*logN), для 1500 точек приемлимо

    замечания:
    1) если найдутся равносторонние треугольники, то при таком способе они будут подсчитаны несколько раз. Теорема: не существует равносторонних треугольников с вершинами в целочисленных координатах.
    2) для исходной точки две равноудалённые соседние точки могут находиться в диаметрально противоположных направлениях (тогда треугольник выродиться в прямую). такие треугольники подсчитывать нельзя
    способ обработки: при обработке точки создадим множество координат соседних точек. при этом координату можно брать относительно рассматриваемой точки. 
    тогда для каждой соседней точки найдем относительные координаты x = x1 - x0, y = y1 - y0
    проверяем, если во множестве существует соседняя точка с координатами (-х, -y), то такой треугольник в будущем засчитывать не надо, количество вхождений можно сразу уменьшить на 1 и никак отдельно не обрабатывать этот случай
    при проходе двумя указателями, далее добавляем во множество точку {x, y}
    3) при вычислении расстояний нет смысла извлекать квадратный корень между суммой квадратов координат

*/

struct Point {
    int64_t x, y;
    bool operator ==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator != (const Point& other) const {
        return !(*this == other);
    }
};

struct PointHasher {    
    size_t operator()(const Point& point) const {
        return hash<int64_t>()(point.x) + 193 * hash<int64_t>()(point.y);
    }
};

int main() {
    int64_t n;
    cin >> n;
    vector<Point> points;
    for (int64_t i = 0; i < n; ++i) {
        int64_t x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    int64_t answer = 0;

    for (auto& point : points) {
        vector<int64_t> distancesToOther;
        unordered_set<Point, PointHasher> neighboorsSet;
        for (auto& neighboor : points) {
            if (point != neighboor) {
                int64_t x = neighboor.x - point.x;
                int64_t y = neighboor.y - point.y;
                int64_t distance = x * x + y * y;
                distancesToOther.push_back(distance);
                if (neighboorsSet.count({-x, -y})) {
                    --answer;
                }
                neighboorsSet.insert({x, y});
            }
        }
        sort(distancesToOther.begin(), distancesToOther.end());
     
        size_t right = 0;
        for (size_t left = 0; left < distancesToOther.size();) {
            while (right < distancesToOther.size() && distancesToOther[left] == distancesToOther[right]) {
                ++right;
            }
            answer += ((right - left) * (right - left - 1)) / 2;
        	left = right;
        }

    }    

    cout << answer << '\n';

    return 0;
}