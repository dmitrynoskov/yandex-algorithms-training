#include <iostream>
#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

/*
    отсортируем школьников по росту, далее бинарный поиск по ответу
    при проверке ответа используем метод двух указателей на последовательности отсортированных по росту школьников
*/

int64_t lBinSearch(int64_t left, int64_t right, const vector<int64_t>& growth, int64_t R, int64_t C,
                   function<bool(const vector<int64_t>&, int64_t, int64_t, int64_t)> check) {
    while (left < right) {
        int64_t mid = (left + right) / 2;
        if (check(growth, R, C, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

bool check(const vector<int64_t>& growth, int64_t R, int64_t C, int64_t discomfort) {

    /*
        у нас есть отсортированный вектор роста школьников, необходимое количество бригад R, количество людей в бригаде C
        для текущего значения неудобства (разница между максимальным и минимальным ростом школьников в бригаде) и размера людей в бригаде, будем считать, сколько бригад можно образовать
    */
    int64_t counter = 0;
    auto it1 = growth.begin();
    auto it2 = it1 + min(C, distance(it1, growth.end()));

    do {
        it2 = it1 + min(C, distance(it1, growth.end()));
        if (((*prev(it2) - *it1) <= discomfort) && (distance(it1, it2) == C)) {
            ++counter;
            it1 = it2;
        } else {
            ++it1;
        }      
    } while ((it2 != growth.end()) && (counter < R));

    return counter >= R;
}


int main() {
    int64_t N, R, C;
    cin >> N >> R >> C;
    vector<int64_t> growth;
    growth.reserve(N);
    for (int64_t i = 0; i < N; ++i) {
        int64_t number;
        cin >> number;
        growth.push_back(number);
    }
    sort(growth.begin(), growth.end());
    
    int64_t left = 0;
    int64_t right = growth.back() - growth[0];

    cout << lBinSearch(left, right, growth, R, C, check) << '\n';

    return 0;
}