#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkPlanar(int holeWidth, int holeLength, int brickWidth, int brickLength) {
    if (((brickLength <= holeLength) && (brickWidth <= holeWidth)) ||
        (brickLength <= holeWidth) && (brickWidth <= holeLength)) {
        return true;
    }
    return false;
}

int main() {

    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    string answer = "NO";

    if (checkPlanar(D, E, A, B) || checkPlanar(D, E, B, C) || checkPlanar(D, E, A, C)) {
        answer = "YES";
    }

    cout << answer << '\n';

    return 0;
}