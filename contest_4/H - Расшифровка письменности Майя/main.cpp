#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
	идея: создать словарь из char в количество вхождений для исходного слова W
    далее для каждых идущих подряд g символов в последовательности создать словарь и сравнить его 
    со словарём для W. при переходе к следующей букве последовательности не перестраивать словарь, а удалять самый 
    левый элемент и добавлять правый элемент "окна" строки

*/

int main() {

    int g, s;
    string word, inputSequence;
    cin >> g >> s;
    cin >> word >> inputSequence;

	unordered_map<char, int> wordMaya;
    for (auto c : word) {
        ++wordMaya[c];
    }

    int count = 0;
    unordered_map<char, int> window;
    for (int i = 0; i < word.size(); ++i) {
        ++window[inputSequence[i]];
    }
    auto it1 = inputSequence.begin();
    auto it2 = it1 + word.size() - 1;
    while (it2 != inputSequence.end()) {
        if (wordMaya == window) {
            ++count;
        }
        if (--window[*it1] == 0) {
            window.erase(*it1);
        }
        ++it1;
        ++it2;
        if (it2 != inputSequence.end()) {
            ++window[*it2];
        }
    }

    cout << count <<'\n';

    return 0;
}