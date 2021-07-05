#include <iostream>

using namespace std;

int main() {
    
    int prevElement;
    int nextElement;
    cin >> prevElement;

    bool isIncreasing = true;

    while ((cin >> nextElement) && (isIncreasing)) {
        if (nextElement <= prevElement){
            isIncreasing = false;
        } else {
            prevElement = nextElement;
        }
    }

    if (isIncreasing) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}