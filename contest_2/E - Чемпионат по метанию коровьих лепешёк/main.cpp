#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<int>& sequence) {
    int possibleDistance = -1;
    int winnerDistance = sequence.front();
    int winnerIndex = 0;
    int winnerCount = 1;

    for (int i = 1; i < sequence.size(); ++i) {
        if (sequence[i] == winnerDistance) {
            ++winnerCount;
        }
        if (sequence[i] > winnerDistance) {
            winnerDistance = sequence[i];
            winnerIndex = i;
            winnerCount = 1;
        }
    }

    for (int i = 1; i < sequence.size() - 1; ++i) {
        if ((sequence[i] % 5 == 0) && ((sequence[i] / 5) % 2 != 0) &&
            (((i >= winnerIndex) && (winnerCount > 1)) || (i > winnerIndex)) &&
            (sequence[i] > sequence[i + 1]) && (sequence[i] > possibleDistance)) {
            possibleDistance = sequence[i];
        }
    }

    if (possibleDistance > 0) {
        int counter = 0;
        for (int i : sequence) {
            if (i > possibleDistance) {
                ++counter;
            }
        }
        return counter + 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> inputSequence;
    for (int i = 0; i < n; ++i) {
        int distance;
        cin >> distance;
        inputSequence.push_back(distance);
    }

    cout << solve(inputSequence) << '\n';

    return 0;
}