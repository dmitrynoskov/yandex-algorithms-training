#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getSequenceType(const vector<int>& sequence) {
    string answer = "CONSTANT";
    bool isConstant = true;
    bool isAscending = true;
    bool isWeaklyAscending = true;
    bool isDescending = true;
    bool isWeaklyDescending = true;

    if (sequence.size() > 1) {
        for (size_t i = 0; i < sequence.size() - 1; ++i) {
            if (isConstant && (sequence[i] != sequence[i+1])) {
                isConstant = false;
            }
            if (isAscending && (sequence[i] >= sequence[i+1])) {
                isAscending = false;
            }
            if (isWeaklyAscending && (sequence[i] > sequence[i+1])) {
                isWeaklyAscending = false;
            }
            if (isDescending && (sequence[i] <= sequence[i+1])) {
                isDescending = false;
            }
            if (isWeaklyDescending && (sequence[i] < sequence[i+1])) {
                isWeaklyDescending = false;
            }
        }

        if (isConstant) {
            answer = "CONSTANT";
        } else if (isAscending) {
            answer = "ASCENDING";
        } else if (isWeaklyAscending) {
            answer = "WEAKLY ASCENDING";
        } else if (isDescending) {
            answer = "DESCENDING";
        } else if (isWeaklyDescending) {
            answer = "WEAKLY DESCENDING";
        } else {
            answer = "RANDOM";
        }
    }

    return answer;
}

int main() {
    
    vector<int> inputSequence;
    {
        int element;
        bool flag = true;
        while(flag) {
            cin >> element;
            if (element != -2e9) {
                inputSequence.push_back(element);
            } else {
                flag = false;
            }            
        }
    }
    
    cout << getSequenceType(inputSequence);

    return 0;
}