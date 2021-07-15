#include <iostream>
#include <unordered_set>
#include <cstdint>

using namespace std;

/*
    задача решается перебором всех возможных значений Z - количества квартир на этаже 
    обозначения из условия:
        K - номер квартиры
        M - количество этажей
        P - номер подъезда
        N - номер этажа
*/

int64_t getEntrance(int64_t K, int64_t M, int64_t Z) {
    return (K - 1) / (M * Z) + 1;
}

int64_t getFloor(int64_t K, int64_t M, int64_t Z) {
    int64_t entrance = getEntrance(K, M, Z);
    return (K - 1 - (entrance - 1) * M * Z) / Z + 1;
}

bool checkValidity(int64_t K, int64_t M, int64_t P, int64_t N, int64_t Z) {
    int64_t possibleEntrance = getEntrance(K, M, Z);
    int64_t possibleFloor = getFloor(K, M, Z);
    return possibleEntrance == P && possibleFloor == N;
}

int main() {
    int64_t K1, M, K2, P2, N2;

    cin >> K1 >> M >> K2 >> P2 >> N2;

    unordered_set<int64_t> possibleEntrances;
    unordered_set<int64_t> possibleFloors;
    for (int64_t Z = 1; Z <= 1'000'000; ++Z) {
        if (checkValidity(K2, M, P2, N2, Z)) {
            int64_t possibleEntrance = getEntrance(K1, M, Z);
            int64_t possibleFloor = getFloor(K1, M, Z);
            possibleEntrances.insert(possibleEntrance);
            possibleFloors.insert(possibleFloor);
        }
    }

    if (possibleEntrances.empty() && possibleFloors.empty()) {
        cout << "-1 -1";
    } else if (possibleEntrances.size() == 1 && possibleFloors.size() == 1) {
        cout << *possibleEntrances.begin() << ' ' << *possibleFloors.begin();
    } else if (possibleEntrances.size() == 1) {
        cout  << *possibleEntrances.begin() << " 0";
    } else if (possibleFloors.size() == 1) {
        cout << "0 " << *possibleFloors.begin();
    } else {
        cout << "0 0";
    }

    return 0;
}