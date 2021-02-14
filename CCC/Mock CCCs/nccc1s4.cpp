/*
Mock CCC '18 Contest 1 S4 - A Graph Problem
Key Concepts: Graph Theory (DFS/BFS), Discretizing
https://dmoj.ca/problem/nccc1s4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001; 

struct Edge{int a, b, t; bool r;};

bool cmp(Edge a, Edge b) {
    return a.t < b.t;
}

bool adj[MAXN][MAXN];

int N, M, K, S, T, ans;
vector<Edge> edges;

bool vis[MAXN];
void dfs(int c) {
    vis[c] = 1;
    for (int t = 1; t <= N; t++) {
        if (adj[c][t] && !vis[t]) dfs(t);
    }
}

bool eval() {
    memset(vis, 0, sizeof vis);
    dfs(S);
    return vis[T];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K >> S >> T;
    for (int i = 0, a, b, c, d; i < M; i++) {
        cin >> a >> b >> c >> d;
        edges.push_back({a, b, c, 1});
        edges.push_back({a, b, d+1, 0});
    }
    sort(edges.begin(), edges.end(), cmp);

    int t = 1;
    for (Edge e : edges) {
        if (eval()) ans += e.t-t;
        if (e.r) adj[e.a][e.b] = 1;
        else adj[e.a][e.b] = 0;
        t = e.t;
    }
    if (eval()) ans += K-t+1;

    cout << ans << '\n';

    return 0;
}