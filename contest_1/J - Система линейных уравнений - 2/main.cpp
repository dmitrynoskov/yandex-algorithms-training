#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <cmath>
 
using namespace std;

enum class SolutionType {
    NO_SOLUTION = 0,
    INFINITE_LINEAR = 1,
    SINGLE_SOLUTION = 2,
    INFINITE_ANY_Y = 3,
    INFINITE_ANY_X = 4,
    INFINITE_ANY_XY = 5
};
 
double getSquareDeterminant(double a0, double a1, double b0, double b1) {
    return (a0 * b1 - a1 * b0);
}
 
bool isZero(double number) {
    static const double EPS = 1e-6;
    return abs(number) < EPS;
}
 
pair<SolutionType, vector<double>> solveLinearSquareSystem(double a, double b, double c, double d, double e, double f) {
    vector<double> solution;
 
    double determinant = getSquareDeterminant(a, b, c, d);
    double determinantX = getSquareDeterminant(e, b, f, d);
    double determinantY = getSquareDeterminant(a, e, c, f);
 
    if (!isZero(determinant)) { //существует только одно решение системы
        solution.emplace_back(determinantX / determinant);
        solution.emplace_back(determinantY / determinant);
        return make_pair(SolutionType::SINGLE_SOLUTION, solution);
 
    } else if ((isZero(determinantX) && isZero(determinantY))) {  //бесконечное количество решений (или 0 решений, если неправильные коэффициенты)
 
        if (isZero(a) && isZero(b) && isZero(e)) { // если одно из уравнений вида 0*х + 0y = 0, скопируем коэффициенты из второго, чтобы потом не делать лишние проверки
            a = c;
            b = d;
            e = f;
        }
 
        if (isZero(c) && isZero(d) && isZero(f)) { // если одно из уравнений вида 0*х + 0y = 0, скопируем коэффициенты из второго, чтобы потом не делать лишние проверки
            c = a;
            d = b;
            f = e;
        }
 
        if ((isZero(a) && isZero(b) && !isZero(e)) || (isZero(c) && isZero(d) && !isZero(f))) { // случай 0*х + 0*y != 0
            return make_pair(SolutionType::NO_SOLUTION, solution);
 
        } else if (isZero(a) && isZero(b) && isZero(c) && isZero(d)) { // случай 0*х + 0*y = 0
            return make_pair(SolutionType::INFINITE_ANY_XY, solution);
 
        } else if (isZero(a)) { // случай 0*x + b*y = e; 
            solution.emplace_back(e / b);
            return make_pair(SolutionType::INFINITE_ANY_X, solution);
 
        } else if (isZero(b)) { //случай a*x + 0*y = e;
            solution.emplace_back(e / a);
            return make_pair(SolutionType::INFINITE_ANY_Y, solution);
 
        } else { // линейное уравнение a*x + b*y = e;
            solution.emplace_back(-a / b);
            solution.emplace_back(e / b);
            return make_pair(SolutionType::INFINITE_LINEAR, solution);
        }
 
    } else { // по Крамеру не существует решений
        return make_pair(SolutionType::NO_SOLUTION, solution);
    }
}
 
int main() {
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    auto [solutionType, solution] = solveLinearSquareSystem(a, b, c, d, e, f);
    cout << static_cast<int>(solutionType);
    for (auto i : solution) {
        cout << ' ' << i;
    }
 
 
    return 0;
}