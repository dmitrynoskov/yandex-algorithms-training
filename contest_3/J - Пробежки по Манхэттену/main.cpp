#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct CoordArea {
    int bMax, bMin, bMax_, bMin_;
    /*
   	 * решение с перебором всех точек при поиске пересечения не проходит по времени
     * нужно решение, которое определяет пересечение возможных локаций за О(1)
     * чтобы описать прямоугольник в декартовой системе координат со сторонами, параллельными осям координат,
     * достаточно 4 чисел: xMin, xMax, yMin, yMax
     * искать пересечение двух прямоугольников, заданных таким образом за О(1) достаточно легко
     *
     * в нашем случае возможные локации - это такой же прямоугольник, но повёрнутый относительно осей координат
     * множество точек, удалённых на манхэттенское расстояние от некоторой начальной точки, на координатной оси
     * образуют квадрат, повёрнутый на угол 45 градусов относительно координатных осей
     * пересечение таких квадратов в общем случае образует прямоугольник
     * для описания такого прямоугольника нужно знать характеристики четырёх его диагоналей
     * уравнение прямой y = k*x + b при наклоне прямоугольника 45 градусов вырождается в y = x + b
     * прямоугольник ограничен четырьмя диагоналями:
     * y = x + bMax (левая верхняя)
     * y = x + bMin (правая нижняя)
     * y = -x + bMax_ (правая верхняя)
     * y = -x + bMin_ (левая нижняя)
     *
     * в итоге для описания манхэттенских прямоугольников достаточно знать 4 числа (свободные члены в уравнениях 
     * ограничивающих прямоугольник прямых) и не перепутать порядок хранения этих чисел
     *
     */

    /*
     *  левая верхняя       правая верхняя
     *         . . . . * . . . .
     *         . . . * . * . . .
     *         . . * . . . * . .
     *         . * . . . . . * .
     *         . . * . . . * . .
     *         . . . * . * . . .
     *         . . . . * . . . .
     *  левая нижняя        правая нижняя
     */
};

CoordArea extend(const CoordArea& initial, int extension) {
    /*
     * математически расширение прямоугольника на n манхэттенских расстояний приведёт к увеличению смещения
     * каждой диагоналей на n в сторону расширения прямоугольника
     */
    return {initial.bMax + extension, initial.bMin - extension, initial.bMax_ + extension, initial.bMin_ - extension};
}

CoordArea intersection(const CoordArea& lhs, const CoordArea& rhs) {
    int bMax, bMin, bMax_, bMin_;
    bMax = min(lhs.bMax, rhs.bMax);
    bMin = max(lhs.bMin, rhs.bMin);
    bMax_ = min(lhs.bMax_, rhs.bMax_);
    bMin_ = max(lhs.bMin_, rhs.bMin_);
    return {bMax, bMin, bMax_, bMin_};
}

struct Coord{
    int x, y;
};

vector<Coord> getCoords(const CoordArea& area) {
    vector<Coord> result;
    for (int b = area.bMin; b <= area.bMax; ++b) {
        for (int b_ = area.bMin_; b_ <= area.bMax_; ++b_) {
            /*
             * здесь точка x, y удовлетворяет двум условиям:
             * y = x + b;
             * y = -x + b_;
            */
            if ((b + b_) % 2 == 0)  { //координаты должны быть целыми числами
                int y = (b + b_) / 2;
                int x = y - b;
                result.push_back({x, y});
            }

        }
    }
    return result;
}

int main() {
    int t, d, n;
    cin >> t >> d >> n;
    CoordArea possibleLocations = {0, 0, 0, 0};
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        CoordArea possibleGPSLocations = extend({y-x, y-x, y+x, y+x}, d);
        CoordArea possibleMoveLocations = extend(possibleLocations, t);
        possibleLocations = intersection(possibleMoveLocations, possibleGPSLocations);
    }
    auto answer = getCoords(possibleLocations);
    cout << answer.size() << '\n';
    for (const auto& [x, y] : answer) {
        cout << x << ' ' << y << '\n';
    }
    return 0;
}