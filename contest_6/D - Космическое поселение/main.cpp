#include <iostream>
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

/*
    бинарный поиск по ответу
*/

struct Rectangle {
    int64_t width;
    int64_t height;
};

int64_t rBinSearch(int64_t left, int64_t right, Rectangle room, Rectangle field, int64_t roomsQuantity,
                   function<bool(Rectangle, Rectangle, int64_t, int64_t)> check) {
    while (left < right) {
        int64_t mid = (left + right + 1) / 2;
        if (check(room, field, roomsQuantity, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

bool check(Rectangle room, Rectangle field, int64_t roomsQuantity, int64_t armor) {
    room.height += 2*armor;
    room.width += 2*armor;
    return (field.width / room.width) * (field.height / room.height) >= roomsQuantity;
}

int main() {
    int64_t n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;

    Rectangle livingRoomHorizontalOriented = {a, b};
    Rectangle livingRoomVerticalOriented = {b, a};
    Rectangle field = {w, h};

    int64_t L = 0;
    int64_t R = min(h, w);

    int64_t possibleAnswerFirst = rBinSearch(L, R, livingRoomHorizontalOriented, field, n, check);
    int64_t possibleAnswerSecond = rBinSearch(L, R, livingRoomVerticalOriented, field, n, check);

    cout << max(possibleAnswerFirst, possibleAnswerSecond) << '\n';

    return 0;
}