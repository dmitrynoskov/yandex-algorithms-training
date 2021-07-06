#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> keyToClick;

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;
        keyToClick[i] = c;    
    }
    
    int k;
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        int c;
        cin >> c;
        --keyToClick[c];    
    }

    for (auto [key, clicks] : keyToClick) {
        if(clicks < 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}