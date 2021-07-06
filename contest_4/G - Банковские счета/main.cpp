#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <cstdint>

using namespace std;

int main() {
    unordered_map<string,  int64_t> clientToCash;

    string inputLine;
    while(getline(cin, inputLine)) {
        stringstream ss(inputLine);
        string command;
        ss >> command;
        if (command == "DEPOSIT") {
            string name;
            int64_t sum;
            ss >> name >> sum;
            clientToCash[name] += sum;
        } else if (command == "WITHDRAW") {
            string name;
            int64_t sum;
            ss >> name >> sum;
            clientToCash[name] -= sum;
        } else if (command == "BALANCE") {
            string name;
            ss >> name;
            try {
                cout << clientToCash.at(name) << '\n';
            } catch (out_of_range&) {
                cout << "ERROR\n";
            }
        } else if (command == "TRANSFER") {
            string name1, name2;
            int64_t sum;
            ss >> name1 >> name2 >> sum;
            clientToCash[name1] -= sum;
            clientToCash[name2] += sum;
        } else if (command == "INCOME") {
            double p;
            ss >> p;
            for (auto&[client, cash] : clientToCash) {
                if (cash > 0) {
                    double income = cash * p / 100;
                    cash = cash + static_cast<int64_t>(income);
                }
            }
        }
    }

    return 0;
}