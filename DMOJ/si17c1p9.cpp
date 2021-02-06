/*
Summer Institute '17 Contest 1 P9 - Safe Square
Key Concepts: Implementation
https://dmoj.ca/problem/si17c1p9
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101; 

int R, C;
string grid[MAXN];

bool scan(int r, int c) {
    if (grid[r][c] == 'S') return 0;
    int adj = -1;
    int snk = 0;
    for (int cr = r-1; cr <= r+1; cr++) {
        for (int cc = c-1; cc <= c+1; cc++) {
            if (cr >= 0 && cc >= 0 && cr < R && cc < C) {
                adj++;
                if (grid[cr][cc] == 'S') snk++;
            }
        }
    }
    return snk*2 < adj;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }

    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ans += scan(i, j);
        }
    }
    cout << ans << "\n";

    return 0;
}