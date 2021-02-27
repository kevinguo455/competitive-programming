/*
CCC '21 S2 - Modern Art
Key Concepts: Implementation, Simple Math
https://dmoj.ca/problem/ccc21s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e6+5; 

bitset<MAXN> rc;
bitset<MAXN> cc;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, K; cin >> R >> C >> K;
    char d;
    int x;
    while (K--) {
        cin >> d >> x;
        if (d == 'R') rc[x] = !rc[x];
        else cc[x] = !cc[x];
    }

    cout << rc.count() * C + cc.count() * R - 2 * rc.count() * cc.count() << '\n';
    
    /*
    int ans = 0;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (rc[r] ^ cc[c]) ans++;
        }
    }
    cout << ans << '\n';
    */

    return 0;
}