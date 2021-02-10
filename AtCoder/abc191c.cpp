/*
AtCoder Beginner Contest 191 Problem C - Digital Graffiti 
Key Concepts: Implementation
https://atcoder.jp/contests/abc191/tasks/abc191_c
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;

const int MAXN = 11; 

int R, C;
bool grid[MAXN][MAXN];

int ans;

pii dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
pii s = {-1, -1};

int mod(int n) {
    return (n+4)%4;
}

bool filled(pii c) {
    if (c.fi < 0 || c.se < 0 || c.fi >= R || c.se >= C) return 0;
    return grid[c.fi][c.se];
}

pii travel(pii c, int d) {
    return {c.fi + dir[d].fi, c.se + dir[d].se};
}

void scan(pii c, int d) {
    pii l = travel(c, mod(d-1));
    if (filled(l)) {
        ans++;
        if (c.fi == s.fi && c.se == s.se && ans > 1 && mod(d-1) == 0) return;
        scan(l, mod(d-1));
        return;
    }
    pii f = travel(c, d);
    if (filled(f)) {
        if (c.fi == s.fi && c.se == s.se && ans > 1 && d == 0) return;
        scan(f, d);
        return;
    }
    ans++;
    pii r = travel(c, mod(d+1));
    if (c.fi == s.fi && c.se == s.se && ans > 1 && mod(d+1) == 0) return;
    if (filled(r)) {
        scan(r, mod(d+1));
        return;
    }
    ans++;
    if (c.fi == s.fi && c.se == s.se && ans > 1 && mod(d+2) == 0) return;
    scan(c, mod(d+2));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;
    char c;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> c;
            if (c == '#') {
                grid[i][j] = 1;
                if (s.fi == -1) {
                    s.fi = i;
                    s.se = j;
                }
            }
        }
    }

    scan(s, 0);

    cout << ans << '\n';

    return 0;
}