#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findNearest(const vector<int>& sequence, int element) {
    int answer = sequence[0];
    int delta = abs(answer - element);

    for (auto i : sequence){
        if (abs(i - element) < delta) {
            answer = i;
            delta = abs(answer - element);
        }
    }    
    return answer;
}

int main() {
    
    int N, x;
    cin >> N;
    vector<int> inputSequence;
    inputSequence.reserve(N);
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        inputSequence.push_back(number);
    }
    cin >> x;

    cout << findNearest(inputSequence, x) << '\n';

    return 0;
}