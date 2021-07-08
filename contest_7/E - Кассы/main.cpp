#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

/*
    метод решения - сортировка событий (метод сканириующей прямой)
    основная идея: "разрежем" все события (открытия, закрытия касс) на временной оси по полуночи и развернём в прямую с началом в 00:00 и концом в 24:00, получим полуинтервал [00:00, 24:00)
    добавим все события на прямую (если время событий совпадает, то сначала считаем, что касса сначала закрывается, а потом открывается) и отсортируем
    пройдёмся по событиям, обновляя текущее значение количества открытых касс
    будем добавлять к ответу длину отрезков между событиями, между которыми количество открытых касс равно общему количеству касс
*/

static const int MIDNIGHT = 60 * 24;

enum class EventType {
    CLOSE = -1,
    OPEN = 1
};

int main() {
    int N;
    cin >> N;

    vector<pair<int, EventType>> events;
    for (int i = 0 ; i < N ; ++i) {
        int hours1, minutes1, hours2, minutes2;
        cin >> hours1 >> minutes1 >> hours2 >> minutes2;
        int opening = hours1 * 60 + minutes1;
        int closing = hours2 * 60 + minutes2;
        if (opening == closing) {
            events.emplace_back(0, EventType::OPEN);
            events.emplace_back(MIDNIGHT, EventType::CLOSE);
        } else if (opening > closing) {
            events.emplace_back(0, EventType::OPEN);
            events.emplace_back(closing, EventType::CLOSE);
            events.emplace_back(opening, EventType::OPEN);
            events.emplace_back(MIDNIGHT, EventType::CLOSE);
        } else {
            events.emplace_back(opening, EventType::OPEN);
            events.emplace_back(closing, EventType::CLOSE);
        }
    }

    sort(events.begin(), events.end());

    int cashBoxCounter = 0;
    int summaryTime = 0;

    for (size_t i = 0; i < events.size(); ++i) {
        if (events[i].second == EventType::OPEN){
            ++cashBoxCounter;
        } else {
            if (cashBoxCounter == N) {
                summaryTime += events[i].first - events[i - 1].first;
            }
            --cashBoxCounter;
        }
    }

    cout << summaryTime << '\n';

    return 0;
}