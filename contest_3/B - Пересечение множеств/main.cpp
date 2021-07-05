#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <set>

using namespace std;

set<int> readSet () {
    string line;
    getline(cin, line);
    stringstream sstream (line);
    int number;
    set<int> result;
    while (sstream >> number) {
        result.insert(number);
    }
    return result;
}

int main () {

    const auto firstSet = readSet();
    const auto secondSet = readSet();
    vector<int> result;

    set_intersection(firstSet.begin(), firstSet.end(), secondSet.begin(), secondSet.end(), back_inserter(result));

    for (auto i : result){
    	cout << i << ' ';
    }

    return 0;
}