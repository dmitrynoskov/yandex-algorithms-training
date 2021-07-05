#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct ProductOfThree {
    int64_t firstNumber;
    int64_t secondNumber;
    int64_t thirdNumber;
    int64_t product() const {
        return firstNumber * secondNumber * thirdNumber;
    };
};

struct ProductOfTwo {
    int64_t firstNumber;
    int64_t secondNumber;
    int64_t product() const {
        return firstNumber * secondNumber;
    };
};

ProductOfThree getThreeIndexes(const std::vector<int64_t>& sequence) {
    ProductOfThree highestProductOfThree;
    ProductOfTwo highestProductOfTwo;
    ProductOfTwo lowestProductOfTwo;
    int64_t highest;
    int64_t lowest;

    lowest = min(sequence[0], sequence[1]);
    highest = max(sequence[0], sequence[1]);
    
    highestProductOfTwo = {sequence[0], sequence[1]};
    lowestProductOfTwo = {sequence[0], sequence[1]};

    highestProductOfThree = {sequence[0], sequence[1], sequence[2]};

    for (size_t index = 2; index < sequence.size(); ++index) {
        int64_t current = sequence[index];

        if (current * highestProductOfTwo.product() > current * lowestProductOfTwo.product()) {
            if (current * highestProductOfTwo.product() > highestProductOfThree.product()) {
                highestProductOfThree.firstNumber = highestProductOfTwo.firstNumber;
                highestProductOfThree.secondNumber = highestProductOfTwo.secondNumber;
                highestProductOfThree.thirdNumber = current;
            }
        } else {
            if (current * lowestProductOfTwo.product() > highestProductOfThree.product()) {
                highestProductOfThree.firstNumber = lowestProductOfTwo.firstNumber;
                highestProductOfThree.secondNumber = lowestProductOfTwo.secondNumber;
                highestProductOfThree.thirdNumber = current;
            }
        }

        if (current * highest > current * lowest) {
            if ((current * highest) > highestProductOfTwo.product()) {
                highestProductOfTwo.firstNumber = highest;
                highestProductOfTwo.secondNumber = current;
            }
        } else {
            if ((current * lowest) > highestProductOfTwo.product()) {
                highestProductOfTwo.firstNumber = lowest;
                highestProductOfTwo.secondNumber = current;
            }
        }

        if ((current * highest) < (current * lowest)) {
            if ((current * highest) < lowestProductOfTwo.product()) {
                lowestProductOfTwo.firstNumber = highest;
                lowestProductOfTwo.secondNumber = current;
            }
        } else {
            if ((current * lowest) < lowestProductOfTwo.product()) {
                lowestProductOfTwo.firstNumber = lowest;
                lowestProductOfTwo.secondNumber = current;
            }
        }

        highest = max(current, highest);
        lowest = min(current, lowest);

    }

    return highestProductOfThree;
}

int main() {
    
    vector<int64_t> inputSequence;
    {
        int64_t element;
        while(cin >> element) {
            inputSequence.push_back(element);
        }
    }
    
    auto answer = getThreeIndexes(inputSequence);
    cout << answer.firstNumber << ' ' << answer.secondNumber << ' ' << answer.thirdNumber;

    return 0;
}