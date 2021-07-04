#include <iostream>
#include <string>

using namespace std;

int main() {
    int tRoom, tCond, tResult;
    string mode;
    cin >> tRoom >> tCond >> mode;
    if (mode == "freeze") {
        if (tRoom > tCond) {
            tResult = tCond;
        } else {
            tResult = tRoom;
        }
    } else if (mode == "heat") {
        if (tRoom > tCond) {
            tResult = tRoom;
        } else {
            tResult = tCond;
        }
    } else if (mode == "auto") {
        tResult = tCond;
    } else {
        tResult = tRoom;
    }
    cout << tResult << '\n';
    return 0;
}