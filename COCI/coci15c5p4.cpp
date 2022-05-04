/*
COCI '15 Contest 5 #4 Poplava
Key Concepts: Ad Hoc
https://dmoj.ca/problem/coci15c5p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, X; cin >> N >> X;
    
    if (X > (N-2)*(N-1)/2) {
        cout << "-1\n";
        return 0;
    }

    cout << N << ' ';

    int c = N-2;
    while (X > c) {
        cout << N-1-c << ' ';
        X -= c--;
    }
    cout << N-1-X << ' ' << N-1 << ' ';
    
    for (int i = 1; i <= c; i++) {
        if (i != X) cout << N-1-i << ' ';
    }

    cout << '\n';

    return 0;
}