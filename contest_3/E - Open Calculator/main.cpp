#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    set<int> displayedNumbers;
    set<int> enteredNumbers;
    set<int> absentNumbers;

    for (int i = 0; i < 3; ++i) {
        int number;
        cin >> number;
        displayedNumbers.insert(number);
    }


    int inputNumber;
    cin >> inputNumber;
    while (inputNumber > 0) {
        int digit = inputNumber % 10;
        enteredNumbers.insert(digit);
        inputNumber /= 10;
    }

    set_difference(enteredNumbers.begin(), enteredNumbers.end(), displayedNumbers.begin(), displayedNumbers.end(), inserter(absentNumbers, absentNumbers.begin()));

    cout << absentNumbers.size() << '\n';

    return 0;
}