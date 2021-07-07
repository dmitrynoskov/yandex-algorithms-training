#include <iostream>
#include <cstdint>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

/*
    основная идея: отсортировать последовательности требуемых мощностей и цен кондиционеров, затем использовать метод двух указателей:
    одним указателем перебрать все требуемые мощности, вторым указателем найти модели кондиционеров с минимальной стоимостью, удовлетворяющие заданной мощности
*/

struct AirConditioning {
    int64_t power, price;
};

struct ConditionersComparator {
    bool operator()(const AirConditioning& lhs, const AirConditioning& rhs) const {
        return tie(lhs.price, rhs.power) < tie(rhs.price, lhs.power); //сортировка в порядке увеличения цены, для одинаковых цен - в порядке уменьшения мощности
    }
};

int main() {
    int64_t n, m;
    cin >> n;
    vector<int64_t> rooms;
    rooms.reserve(n);
    for (int64_t i = 0; i < n; ++i) {
        int64_t requiredPower;
        cin >> requiredPower;        
        rooms.push_back(requiredPower);
    }

    vector<AirConditioning> conditioners;
    cin >> m;
    conditioners.reserve(m);
    for (int64_t i = 0; i < m; ++i) {
        int64_t power, price;
        cin >> power >> price;        
        conditioners.push_back({power, price});
    }

    sort(rooms.begin(), rooms.end());
    sort(conditioners.begin(), conditioners.end(), ConditionersComparator()); 
    
    int64_t totalPrice = 0;
    auto itCond = conditioners.begin();
    for (auto itRooms = rooms.begin(); itRooms != rooms.end(); ++itRooms) {
        while (itCond->power < *itRooms) { //так как по условию гарантируется, что хотя бы один корректный выбор кондиционеров существует, 
        //и во всех классах можно установить подходящий кондиционер, мы никогда не дойдем до иератора end(), а в крайнем случае остановимся на самом дорогом кондиционере
            ++itCond;
        }
        totalPrice += itCond->price;
    }

    cout << totalPrice << '\n';


    return 0;
}