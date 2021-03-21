/*
VPEX P4 - Etopika
Key Concepts: Lowest Common Ancestor (Binary Lifting), Dynamic Programming (Frog)
https://dmoj.ca/problem/vpex1p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5, MAXK = 17; 

struct Edge{int n, w;};

vector<Edge> adj[MAXN];
int height[MAXN], in[MAXN], out[MAXN], idx, up[MAXN][MAXK];

void dfs(int c, int p) {
    in[c] = idx++;
    up[c][0] = p;
    for (int i = 1; i < MAXK; i++) {
        up[c][i] = up[up[c][i-1]][i-1];
    }
    for (Edge t : adj[c]) {
        if (t.n == p) continue;
        height[t.n] = height[c] + t.w;
        dfs(t.n, c);
    }
    out[c] = idx++;
}

bool is_anc(int a, int b) {
    return (in[a] <= in[b] && out[b] <= out[a]);
}

int lca(int a, int b) {
    if (is_anc(a, b)) return a;
    if (is_anc(b, a)) return b;
    for (int i = MAXK-1; i >= 0; i--) {
        if (!is_anc(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}

int dist(int a, int b) {
    return height[a] + height[b] - 2 * height[lca(a, b)];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q; cin >> N >> Q;

    // initialize graph
    for (int i = 1, a, b, w; i < N; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    // initialize in, out, up, and height arrays
    dfs(1, 1);

    // answer queries
    int ac = 1, bc = 1;
    ll a0 = 0, b0 = 0;
    ll a1 = 0, b1 = 0;
    for (int i = 0, at, bt; i < Q; i++) {
        cin >> at >> bt;
        a1 = min(a0 + dist(ac, bt), b0 + dist(bc, bt)) + dist(bt, at);
        b1 = min(a0 + dist(ac, at), b0 + dist(bc, at)) + dist(at, bt);
        ac = at, bc = bt;
        a0 = a1, b0 = b1;
    }
    cout << min(a0, b0) << '\n';

    return 0;
}