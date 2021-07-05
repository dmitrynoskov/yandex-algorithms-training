#include <iostream>
#include <vector>
#include <tuple>
#include <cstdint>
#include <cmath>

using namespace std;

/*
	основная идея: найти две пары максимальных по модулю положительных и отрицательных чисел соответственно
     и количество положительных и отрицательных чисел в последовательности
    исходя из количества положительных и отрицательных чисел, посчитать результат из значений двух пар 
*/

void updatePositivePair(pair<int64_t, int64_t>& pairToUpdate, int64_t number){
    if (number > pairToUpdate.second){
        pairToUpdate.first = pairToUpdate.second;
        pairToUpdate.second = number;
    } else if (number > pairToUpdate.first) {
        pairToUpdate.first = number;
    }
}

void updateNegativePair(pair<int64_t, int64_t>& pairToUpdate, int64_t number){
    if (number < pairToUpdate.first){
        pairToUpdate.second = pairToUpdate.first;
        pairToUpdate.first = number;
    } else if (number < pairToUpdate.second) {
        pairToUpdate.second = number;
    }
}

pair<int64_t, int64_t> findMaxMultiplicationIndexes(const vector<int64_t>& sequence) {
    size_t negativeQuantity = 0;
    size_t positiveQuantity = 0;
    pair<int64_t, int64_t> positivePair = {-1, -1};
    pair<int64_t, int64_t> negativePair = {1, 1};
    pair<int64_t, int64_t> result;
    
    for (auto item : sequence) {
        if (item < 0) {
            updateNegativePair(negativePair, item);
            ++negativeQuantity;
        } else {
            updatePositivePair(positivePair, item);
            ++positiveQuantity;
        }
    }

    if ((negativeQuantity > 1) && (positiveQuantity > 1)) {
        int64_t positiveProduct = positivePair.first * positivePair.second;
        int64_t negativeProduct = negativePair.first * negativePair.second;
        result = positiveProduct > negativeProduct ? positivePair : negativePair; 
    } else if (negativeQuantity > 1) {
        result = negativePair;
    } else if (positiveQuantity > 1) {
        result = positivePair;
    } else {
        result = {negativePair.first, positivePair.second};
    }

    return result;
}

int main() {
    
    vector<int64_t> inputSequence;
    int64_t element;
    while(cin >> element) {
        inputSequence.push_back(element);
    }

    auto [first, second] = findMaxMultiplicationIndexes(inputSequence);
    cout << first << ' ' << second << '\n';

    return 0;
}