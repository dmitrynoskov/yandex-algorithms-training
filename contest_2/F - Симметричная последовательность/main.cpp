#include <iostream>
#include <vector>
#include <memory>
#include <deque>
#include <optional>

using namespace std;

/*
	основная идея:
    - создать последовательность чисел в обратном порядке
    - сравнить попарно числа в прямой и обратной последовательности, при этом пропустить числа,
    у которых нет пары (для этого используется optional)
	- если есть несовпадения, сдвинуть обратную последовательность на 1 число вправо 
    (на первое место идёт nullopt элемент) и повторить предыдущий шаг 
	- в качестве ответа записать ту часть обратной последовательности, которая начинается 
    с первого несуществующего индекса прямой последовательности

	пример:
    
    	в начале алгоритма:
    	1 2 3 4 5 4 3 - входная последовательность
		3 4 5 4 3 2 1 - обратная последовательность
		
        после окончания алгоритма:
        1 2 3 4 5 4 3
    		3 4 5 4 3 2 1
    		+ + + + + ^ ^ - ответ 
        
        
        в начале алгоритма:
        2 3 4 5 6 6 8
		8 6 6 5 4 3 2
        
        после первой итерации:
        2 3 4 5 6 6 8
		  8 6 6 5 4 3 2
          
        после окончания алгоритма:
        2 3 4 5 6 6 8
            		8 6 6 5 4 3 2
            		+ ^ ^ ^ ^ ^ ^ - ответ

*/

pair<int, vector<int>> findLackingElements(const vector<int>& sequence) {
    int quantity = 0;
    vector<int> lackingElements;

    deque<optional<int>> reversedSequence(sequence.rbegin(), sequence.rend());

    for (int index = 0; index < sequence.size(); ++index) {
        if (reversedSequence[index].has_value() && reversedSequence[index] != sequence[index]){
            reversedSequence.push_front(nullopt);
            ++quantity;
            index = 0;
        }
    }

    for (int i = 0; i < quantity ; ++i) {
        lackingElements.push_back(reversedSequence[sequence.size() + i].value());
    }

    return {quantity, move(lackingElements)};
}

int main() {

    const vector<int> inputSequence = [] {
        vector<int> inputSequence;
        int N;
        cin >> N;
        inputSequence.reserve(N);
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            inputSequence.push_back(x);
        }
        return inputSequence;
    } ();

    auto [M, elements] = findLackingElements(inputSequence);

    cout << M << '\n';
    for (auto element: elements) {
        cout << element << ' ';
    }

    return 0;
}