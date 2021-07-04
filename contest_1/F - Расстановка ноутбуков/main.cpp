#include <iostream>
#include <algorithm>

usinf namespace std;

int main() {
    int widthFirst, lengthFirst, widthSecond, lengthSecond;

    cin >> widthFirst >> lengthFirst >> widthSecond >> lengthSecond;
    int gluedByWidth = (widthFirst + widthSecond) * max(lengthFirst, lengthSecond);
    int gluedByLength = (lengthFirst + lengthSecond) * max(widthFirst, widthSecond);
    int rotatedFirst = (lengthFirst + widthSecond) * max(lengthSecond, widthFirst);
    int rotatedSecond = (lengthSecond + widthFirst) * max(lengthFirst, widthSecond);

    int minArea = min(min(gluedByWidth, gluedByLength), min(rotatedFirst, rotatedSecond));

    int tableWidth, tableLength;
    if (minArea == gluedByWidth) {
        tableWidth = widthFirst + widthSecond;
        tableLength = max(lengthFirst, lengthSecond);
    } else if (minArea == gluedByLength) {
        tableWidth = max(widthFirst, widthSecond);
        tableLength = lengthFirst + lengthSecond;
    } else if (minArea == rotatedFirst){
        tableWidth = lengthFirst + widthSecond;
        tableLength = max(lengthSecond, widthFirst);
    } else {
        tableWidth = lengthSecond + widthFirst;
        tableLength = max(lengthFirst, widthSecond);
    }

    cout << tableWidth << ' ' << tableLength << '\n';

    return 0;
}