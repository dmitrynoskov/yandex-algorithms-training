#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

/*
    метод решения - сортировка событий (метод сканириующей прямой)
    расположим всех преподавателей в виде двух событий (начало наблюдения, конец наблюдения) на одной прямой и отсортируем
    найдем количество студентов, находящихся под присмотром, линейным проходом над последовательностью
    при этом нужно аккуратно учесть студентов, за которыми одновременно наблюдают несколько преподавателей, чтобы не посчитать излишние повторы
*/

enum class EventType {
    START = 0,
    FINISH = 1
};

int main() {
    int64_t N, M;
    cin >> N >> M;
    vector<int64_t> startPos;
    vector<int64_t> stopPos;
    startPos.reserve(M);
    stopPos.reserve(M);
    for (int64_t i = 0; i < M; ++i) {
        int64_t pos1, pos2;
        cin >> pos1 >> pos2;
        startPos.push_back(pos1);
        stopPos.push_back(pos2);
    }

    vector<pair<int64_t, EventType>> events;
    events.reserve(2 * M);
    for (size_t i = 0; i < startPos.size(); ++i) {
        events.emplace_back(startPos[i], EventType::START);
        events.emplace_back(stopPos[i], EventType::FINISH);
    }
    sort(events.begin(), events.end());

    int64_t currentTeachers = 0;
    int64_t underControl = 0;

    for (size_t i = 0; i < events.size(); ++i) {
        //cout << "desk: " << events[i].first << ", event: " << static_cast<int64_t>(events[i].second) << '\n';
        if (events[i].second == EventType::FINISH && currentTeachers == 1) {
            underControl += events[i].first - events[i-1].first + 1;
        }
        if (events[i].second == EventType::FINISH && currentTeachers > 1) {
            underControl += events[i].first - events[i-1].first;
        }
        if (events[i].second == EventType::START && currentTeachers > 0) {
            underControl += events[i].first - events[i-1].first;
        }

        if (events[i].second == EventType::START) {
            ++currentTeachers;
        } else {
            --currentTeachers;
        }
    }


    cout << N - underControl << '\n';


    return 0;
}