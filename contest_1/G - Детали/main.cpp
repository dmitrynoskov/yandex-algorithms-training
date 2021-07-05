#include <iostream>

using namespase std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    int detali = 0;

    if ((N && K && M) && (N >= K) && (K >= M)) {
        while (N / K) {
            int zagotovki = N / K;
            N = N % K;
            detali += zagotovki * (K / M);
            N += zagotovki * (K % M);
        }
    }

    cout << detali << '\n';
    
    return 0;
}
