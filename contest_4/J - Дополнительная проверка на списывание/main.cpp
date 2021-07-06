#include <iostream>
#include <string>
#include <unordered_set>
#include <memory>
#include <unordered_map>
#include <cstdint>

using namespace std;

struct entryData {
    int64_t count = 0; 	// количество вхождений
    int64_t time = 0;	// "время" первого вхождения 
};

void makeLowerCase (string& word) {
    for (auto& c : word) {
        c = tolower(c);
    }
}

static const unordered_set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
static const unordered_set<char> upperCase = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
static const unordered_set<char> lowerCase = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '_'};

int main() {
    int N;
    cin >> N;
    string C, D;
    cin >> C >> D;

    bool isCaseSensitive = (C == "yes") ? true : false;
    bool isleadingNumbersAllowed = (D == "yes") ? true : false;

    unordered_set<char> possibleLeadingSymbols = lowerCase;
    unordered_set<char> possibleSymbols = lowerCase;

    for (auto c : numbers) {
        possibleSymbols.insert(c);
    }

    if (isleadingNumbersAllowed) {
        for (auto c : numbers) {
            possibleLeadingSymbols.insert(c);
        }
    }

    if (isCaseSensitive) {
        for (auto c : upperCase) {
            possibleLeadingSymbols.insert(c);
            possibleSymbols.insert(c);
        }
    }

    unordered_set<string> keywords;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        if (!isCaseSensitive) {
            makeLowerCase(word);
        }
        keywords.insert(move(word));
    }

    unordered_map<string, entryData> entries;
    string sequence;
    while(getline(cin, sequence)) {
        static int64_t current_time = 0;
        if (!isCaseSensitive) {
            makeLowerCase(sequence);
        }
        auto it1 = sequence.begin();
        while (it1 != sequence.end()) {
            while (it1 != sequence.end() && !possibleSymbols.count(*it1)) {
                ++it1;
            }
            auto it2 = it1 ;
            while (it2 != sequence.end() && possibleSymbols.count(*it2)) {
                ++it2;
            }
            string word(it1, it2);
            if (!word.empty() && word.find_first_not_of("0123456789") != string::npos && possibleLeadingSymbols.count(word[0])) {
                if (entries[word].count == 0) {
                    entries[word].time = current_time++;
                }
                entries[word].count++;
            }
            it1 = it2;
        }
    }

    for (auto& keyword : keywords) {
        entries.erase(keyword);
    }

    const string* mostFrequentIdentifier = &(entries.begin() -> first);
    for (const auto& [word, entryData] : entries) {
        if ((entryData.count == entries[*mostFrequentIdentifier].count) && entryData.time < entries[*mostFrequentIdentifier].time) {
            mostFrequentIdentifier = &word;
        } else if (entryData.count > entries[*mostFrequentIdentifier].count) {
            mostFrequentIdentifier = &word;
        }
    }

    cout << *mostFrequentIdentifier << '\n';

    return 0;
}