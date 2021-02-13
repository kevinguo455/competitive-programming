/*
Chow Computing Contest 2019-2020 S3 — Don't Drop McKillop
Key Concepts: Graph Theory (BFS/DFS, Diameter)
https://www.hackerrank.com/contests/the-chow-computing-contest-2019-1/challenges/s2s3dont-drop-mckillop/problem
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+5; 

vector<int> adj[MAXN];
bool vis[MAXN];

int md, mn;

void dfs(int c, int dist) {
    if (dist > md) {
        md = dist;
        mn = c;
    }
    vis[c] = 1;
    for (int t : adj[c]) {
        if (!vis[t]) dfs(t, dist+1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int a, b;
    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1);
    md = 1;
    memset(vis, 0, sizeof vis);
    dfs(mn, 1);
    cout << md << "\n";

    return 0;
}