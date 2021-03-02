/*
DWITE '11 R3 #4 - ABCA Maze
Key Concepts: Graph Theory, Implementation
https://dmoj.ca/problem/dwite11c3p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;

const int MAXN = 10;

int R, C;
string grid[MAXN];

bool inr(pii c) {
    return (c.fi >= 0 && c.fi < R && c.se >= 0 && c.se < C) && (grid[c.fi][c.se] != '#');
}

int dist(pii a, pii b) {
    bool vis[R][C];
    memset(vis, 0, sizeof vis);
    queue<pii> q;
    q.push(a);
    int d = 0;
    while (!q.empty()) {
        int s = q.size(); 
        while (s--) {
            pii c = q.front(); q.pop();
            if (vis[c.fi][c.se]) continue;
            if (!inr(c)) continue;
            if (c.fi == b.fi && c.se == b.se) return d;
            vis[c.fi][c.se] = 1;
            q.push({c.fi-1, c.se});
            q.push({c.fi+1, c.se});
            q.push({c.fi, c.se+1});
            q.push({c.fi, c.se-1});
        }
        d++;
    }
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int cases = 0; cases < 5; cases++) {
        cin >> R >> C;
        pii a, b, c;
        for (int i = 0; i < R; i++) {
            cin >> grid[i];
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 'A') a = {i, j};
                else if (grid[i][j] == 'B') b = {i, j};
                else if (grid[i][j] == 'C') c = {i, j};
            }
        }
        cout << dist(a, b) + dist(b, c) + dist(c, a) << '\n';
    }

    return 0;
}