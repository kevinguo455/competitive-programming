/*
Appleby Contest '20 P2 - Playful Playdoughs
Key Concepts: Simulation (frequency array)
https://dmoj.ca/problem/ac20p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5; 

ll freq[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q; cin >> N >> Q;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        freq[x]++;
    }
    int op, x;
    while (Q--) {
        cin >> op >> x;
        if (op == 1) {
            if (x % 2 == 0) {
                freq[x/2] += freq[x]*2;
                freq[x] = 0;
            }
            else {
                freq[x/2] += freq[x];
                freq[x/2+1] += freq[x];
                freq[x] = 0;
            }
        }
        else {
            cout << freq[x] << '\n';
        }
    }

    return 0;
}