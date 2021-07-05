#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;

    int firstMin = n + (n - 1) * a;
    int firstMax = firstMin + 2 * a;
    int secondMin = m + (m - 1) * b;
    int secondMax = secondMin + 2 * b;

    if ((firstMin > secondMax) || (secondMin > firstMax)) {
        cout << -1 << '\n';
    } else {
        int tMin = max(firstMin, secondMin);
        int tMax = min(firstMax, secondMax);  
        cout << tMin << ' ' << tMax << '\n';
    }

    return 0;
}
