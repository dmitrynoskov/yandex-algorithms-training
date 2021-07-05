#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

/*
	основная идея:
    если у нас есть две точки a, b, причем a <= b, и: 
    a) искомое число x находится ближе к a, то можно утвержать, что x принадлежит (-∞, (b - a) / 2]
    b) искомое число x находится ближе к b, то можно утвержать, что x принадлежит [(b - a) / 2, +∞)
	
    из этой идеи можно по каждым двум частотам последовательности и информации, какая из частот ближе к искомой,
    последовательно обновлять допустимые границы искомой частоты
*/

struct Data {
    double value;
    bool isCloserThanPrevious;
};

pair<double, double> findRange (const vector<Data>& sequence) {
    double minFrequency = 30;
    double maxFrequency = 4000;

    for (int i = 1; i < sequence.size(); ++i) {
        if ((sequence[i-1].value < sequence[i].value) ^ sequence[i].isCloserThanPrevious) {
            double possibleMax = (sequence[i].value + sequence[i-1].value) / 2;
            maxFrequency = min(maxFrequency, possibleMax);
        } else {
            double possibleMin = (sequence[i].value + sequence[i-1].value) / 2;
            minFrequency = max(minFrequency, possibleMin);
        }
    }

    return {minFrequency, maxFrequency};
}


int main () {

    const vector<Data> inputSequence = [] {
        vector<Data> inputSequence;
        int n;
        cin >> n;
        inputSequence.reserve(n);
        double frequency;
        string relation;
       	cin >> frequency;
        inputSequence.push_back({frequency, true});
        for (int i = 1; i < n; ++i) {
            cin >> frequency;
            cin >> relation;
            if (relation == "closer") {
                inputSequence.push_back({frequency, true});
            } else {
                inputSequence.push_back({frequency, false});
            }

        }
        return inputSequence;
    } ();
    auto answer = findRange(inputSequence);
    cout << setprecision(7) << answer.first << ' ' << answer.second;
    return 0;
}