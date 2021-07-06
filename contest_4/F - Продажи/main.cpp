#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cstdint>

using namespace std;

int main() {
    map<string, map<string, int64_t>> database;

    string inputLine;
    while(getline(cin, inputLine)) {
        stringstream ss(inputLine);
        string name;
        string goods;
        int64_t quantity;
        ss >> name >> goods >> quantity;
        database[move(name)][move(goods)] += quantity;
    }
    for (const auto& [name, map] : database) {
        cout << name << ":\n";
        for (const auto& [goods, quantity] : map) {
            cout << goods << ' ' << quantity << '\n';
        }
    }

    return 0;
}