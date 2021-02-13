/*
Markville Mock CCC '21 S1/J4 - Lineville
Key Concepts: Implementation
https://www.hackerrank.com/contests/mss-csec-mock-2021-senior/challenges/csec-2021-mock-impl
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; 

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, h; cin >> N >> M >> h;
    int ans = 0;
    while (N--) {
        int r = h, l = h, x;
        for (int i = 0; i < M; i++) {
            cin >> x;
            r = max(x, r);
            l = min(x, l);
        }
        if (r > h) ans += (r-h)*2;
        if (l < h) ans += (h-l)*2;
    }

    cout << ans << "\n";

    return 0;
}