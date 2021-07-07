#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

/*
    неочевидная идея, см. https://youtu.be/fqsuy5rwZhk
*/

int main() {
    int64_t K;
    cin >> K;
    string sequence;
    cin >> sequence;

    size_t counter = 0;
    size_t prevLength = 0;

    for (size_t i = K; i < sequence.size(); ++i) {
        if (sequence[i] == sequence[i - K]) {
            ++prevLength;
            counter += prevLength;                
        } else {
            prevLength = 0;
        }
    }
    cout << counter << '\n';

    return 0;
}